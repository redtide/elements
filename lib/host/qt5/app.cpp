/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <elements/app.hpp>
#include <elements/support/font.hpp>
#include <elements/support/resource_paths.hpp>
#include <infra/filesystem.hpp>
#include <string>
#include <functional>
#include <vector>
#include <QApplication>

namespace cycfi { namespace elements
{
   // Some app globals
   int argc = 0;
   char** argv = nullptr;
   QApplication* the_app = nullptr;
   bool is_activated = false;

   std::vector<std::function<void()>> on_activate;

   QApplication* get_app()
   {
      return the_app;
   }

   bool app_is_activated()
   {
      return is_activated;
   }

   fs::path find_resources()
   {
      const fs::path app_path = fs::path(argv[0]);
      const fs::path app_dir = app_path.parent_path();

      if (app_dir.filename() == "bin")
      {
         fs::path path = app_dir.parent_path() / "share" / app_path.filename() / "resources";
         if (fs::is_directory(path))
            return path;
      }

      const fs::path app_resources_dir = app_dir / "resources";
      if (fs::is_directory(app_resources_dir))
         return app_resources_dir;

      return fs::current_path() / "resources";
   }

   app::app(
      int         argc_
    , char*       argv_[]
    , std::string // name
    , std::string id
   )
   {
      argc = argc_;
      argv = argv_;
      the_app = new QApplication(argc, argv);
      the_app->setApplicationName(QString::fromStdString(id));
      _app = the_app;
      is_activated = true;
   }

   app::~app()
   {
   }

   void app::run()
   {
      _app->exec();
   }

   void app::stop()
   {
      _app->quit();
   }
}}

