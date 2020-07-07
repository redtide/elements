/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License (https://opensource.org/licenses/MIT)
=============================================================================*/
#include <elements/base_view.hpp>
#include <Qt>

namespace cycfi { namespace elements
{
   key_code translate_key(unsigned key)
   {
      constexpr auto print_screen_key = Qt::Key_Print;

      switch (key)
      {
         default:    return key_code::unknown;

         case Qt::Key_0:  return key_code:: _0;
         case Qt::Key_1:  return key_code:: _1;
         case Qt::Key_2:  return key_code:: _2;
         case Qt::Key_3:  return key_code:: _3;
         case Qt::Key_4:  return key_code:: _4;
         case Qt::Key_5:  return key_code:: _5;
         case Qt::Key_6:  return key_code:: _6;
         case Qt::Key_7:  return key_code:: _7;
         case Qt::Key_8:  return key_code:: _8;
         case Qt::Key_9:  return key_code:: _9;

         case Qt::Key_A:  return key_code::a;
         case Qt::Key_B:  return key_code::b;
         case Qt::Key_C:  return key_code::c;
         case Qt::Key_D:  return key_code::d;
         case Qt::Key_E:  return key_code::e;
         case Qt::Key_F:  return key_code::f;
         case Qt::Key_G:  return key_code::g;
         case Qt::Key_H:  return key_code::h;
         case Qt::Key_I:  return key_code::i;
         case Qt::Key_J:  return key_code::j;
         case Qt::Key_K:  return key_code::k;
         case Qt::Key_L:  return key_code::l;
         case Qt::Key_M:  return key_code::m;
         case Qt::Key_N:  return key_code::n;
         case Qt::Key_O:  return key_code::o;
         case Qt::Key_P:  return key_code::p;
         case Qt::Key_Q:  return key_code::q;
         case Qt::Key_R:  return key_code::r;
         case Qt::Key_S:  return key_code::s;
         case Qt::Key_T:  return key_code::t;
         case Qt::Key_U:  return key_code::u;
         case Qt::Key_V:  return key_code::v;
         case Qt::Key_W:  return key_code::w;
         case Qt::Key_X:  return key_code::x;
         case Qt::Key_Y:  return key_code::y;
         case Qt::Key_Z:  return key_code::z;

         case Qt::Key_Apostrophe:   return key_code::apostrophe;
         case Qt::Key_Backslash:    return key_code::backslash;
         case Qt::Key_Comma:        return key_code::comma;
         case Qt::Key_Equal:        return key_code::equal;
// TODO: case Qt::Key_???           return key_code::grave_accent;
         case Qt::Key_BracketLeft:  return key_code::left_bracket;
         case Qt::Key_Minus:        return key_code::minus;
         case Qt::Key_Period:       return key_code::period;
         case Qt::Key_BracketRight: return key_code::right_bracket;
         case Qt::Key_Semicolon:    return key_code::semicolon;
         case Qt::Key_Slash:        return key_code::slash;

         case Qt::Key_Backspace:    return key_code::backspace;
         case Qt::Key_Delete:       return key_code::_delete;
         case Qt::Key_End:          return key_code::end;

         case Qt::Key_Return:
         case Qt::Key_Enter:        return key_code::enter;

         case Qt::Key_Escape:       return key_code::escape;
         case Qt::Key_Home:         return key_code::home;
         case Qt::Key_Insert:       return key_code::insert;
         case Qt::Key_Menu:         return key_code::menu;
         case Qt::Key_PageDown:     return key_code::page_down;
         case Qt::Key_PageUp:       return key_code::page_up;
         case Qt::Key_Pause:        return key_code::pause;
         case Qt::Key_Space:        return key_code::space;

         case Qt::Key_Tab:
         case Qt::Key_Backtab:      return key_code::tab;

         case Qt::Key_CapsLock:     return key_code::caps_lock;
         case Qt::Key_NumLock:      return key_code::num_lock;
         case Qt::Key_ScrollLock:   return key_code::scroll_lock;

         case Qt::Key_F1:     return key_code::f1;
         case Qt::Key_F2:     return key_code::f2;
         case Qt::Key_F3:     return key_code::f3;
         case Qt::Key_F4:     return key_code::f4;
         case Qt::Key_F5:     return key_code::f5;
         case Qt::Key_F6:     return key_code::f6;
         case Qt::Key_F7:     return key_code::f7;
         case Qt::Key_F8:     return key_code::f8;
         case Qt::Key_F9:     return key_code::f9;
         case Qt::Key_F10:    return key_code::f10;
         case Qt::Key_F11:    return key_code::f11;
         case Qt::Key_F12:    return key_code::f12;
         case Qt::Key_F13:    return key_code::f13;
         case Qt::Key_F14:    return key_code::f14;
         case Qt::Key_F15:    return key_code::f15;
         case Qt::Key_F16:    return key_code::f16;
         case Qt::Key_F17:    return key_code::f17;
         case Qt::Key_F18:    return key_code::f18;
         case Qt::Key_F19:    return key_code::f19;
         case Qt::Key_F20:    return key_code::f20;
         case Qt::Key_F21:    return key_code::f21;
         case Qt::Key_F22:    return key_code::f22;
         case Qt::Key_F23:    return key_code::f23;
         case Qt::Key_F24:    return key_code::f24;

// TODO: QKeyEvent::nativeScanCode() for L or R keys
// see https://stackoverflow.com/questions/11283276/qt-left-ctrl-key-code
/*
         case Qt::Key_AltL:      return key_code::left_alt;
         case Qt::Key_Control_L: return key_code::left_control;
         case Qt::Key_Shift_L:   return key_code::left_shift;
*/
         case Qt::Key_Super_L:   return key_code::left_super;
         case print_screen_key:  return key_code::print_screen;
/*
         case Qt::Key_Alt_R:     return key_code::right_alt;
         case Qt::Key_Control_R: return key_code::right_control;
         case Qt::Key_Shift_R:   return key_code::right_shift;
*/
         case Qt::Key_Super_R:   return key_code::right_super;
         case Qt::Key_Down:      return key_code::down;
         case Qt::Key_Left:      return key_code::left;
         case Qt::Key_Right:     return key_code::right;
         case Qt::Key_Up:        return key_code::up;

// TODO: Qt::KeypadModifier
/*
         case Qt::Key_KP_0:  return key_code::kp_0;
         case Qt::Key_KP_1:  return key_code::kp_1;
         case Qt::Key_KP_2:  return key_code::kp_2;
         case Qt::Key_KP_3:  return key_code::kp_3;
         case Qt::Key_KP_4:  return key_code::kp_4;
         case Qt::Key_KP_5:  return key_code::kp_5;
         case Qt::Key_KP_6:  return key_code::kp_6;
         case Qt::Key_KP_7:  return key_code::kp_7;
         case Qt::Key_KP_8:  return key_code::kp_8;
         case Qt::Key_KP_9:  return key_code::kp_9;
         case Qt::Key_KP_Add:       return key_code::kp_add;
         case Qt::Key_KP_Decimal:   return key_code::kp_decimal;
         case Qt::Key_KP_Divide:    return key_code::kp_divide;
         case Qt::Key_KP_Enter:     return key_code::kp_enter;
         case Qt::Key_KP_Equal:     return key_code::kp_equal;
         case Qt::Key_KP_Multiply:  return key_code::kp_multiply;
         case Qt::Key_KP_Subtract:  return key_code::kp_subtract;
*/
      }
   }
}}
