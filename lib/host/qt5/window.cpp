/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License (https://opensource.org/licenses/MIT)
=============================================================================*/
#include <elements/window.hpp>
#include <elements/support.hpp>
#include <functional>
#include <vector>
#include <QApplication>
#include <QMainWindow>
#include <QScreen>

namespace elements = cycfi::elements;

namespace cycfi { namespace elements
{
   struct host_window
   {
      QMainWindow* host = nullptr;
      std::vector<std::function<void()>> on_activate;
   };

   extern std::vector<std::function<void()>> on_activate;
   QApplication* get_app();
   bool app_is_activated();

   QMainWindow* get_window(host_window& h)
   {
      return h.host;
   }

   void on_window_activate(host_window& h, std::function<void()> f)
   {
      h.on_activate.push_back(f);
   }

   float get_scale()
   {
      // TODO: double to float??
      QScreen *screen = QGuiApplication::primaryScreen();
      return screen->devicePixelRatio();
   }

   window::window(std::string const& name, int style_, rect const& bounds)
    :  _window(new host_window)
   {
      // Chicken and egg. GTK wants us to create windows only
      // after the app is activated. So we have a scheme to
      // defer actions. If the app is not activated make_window is
      // added to the on_activate vector, otherwise, it is called
      // immediately.

      auto make_window =
         [this, name, style_, bounds]()
         {
            QMainWindow* win = new QMainWindow;

            win->setWindowTitle(QString::fromStdString(name));
            _window->host = win;

            for (auto f : _window->on_activate)
               f();

            win->show();

            position(bounds.top_left());
            size(bounds.bottom_right());
         };

      if (app_is_activated())
         make_window();
      else
         on_activate.push_back(make_window);
   }

   window::~window()
   {
      delete _window;
   }

   point window::size() const
   {
      QSize s = _window->host->size();
      auto scale = get_scale();
      return { float(s.width()) / scale, float(s.height()) / scale };
   }

   void window::size(point const& p)
   {
      auto scale = get_scale();
      _window->host->resize(p.x * scale, p.y * scale);
   }

   void window::limits(view_limits limits_)
   {
      auto set_limits =
         [this, limits_]()
         {
            constexpr float max = 10E6;

            int min_width = limits_.min.x;
            int max_width = std::min<int>(limits_.max.x, max);
            int min_height = limits_.min.y;
            int max_height = std::min<int>(limits_.max.y, max);

            _window->host->setMinimumSize(min_width, min_height);
            _window->host->setMaximumSize(max_width, max_height);
         };

      if (app_is_activated())
         set_limits();
      else
         on_activate.push_back(set_limits);
   }

   point window::position() const
   {
      QPointF qpos(_window->host->mapToGlobal(_window->host->pos()));
      point pos(qpos.x(), qpos.y());
      return pos;
   }

   void window::position(point const& p)
   {
      auto set_position =
         [this, p]()
         {
            auto scale = get_scale();
            _window->host->move(p.x * scale, p.y * scale);
         };

      if (app_is_activated())
         set_position();
      else
         on_activate.push_back(set_position);
   }
}}

