
/**
 * @file platform/x11/display/window.hpp
 * @brief 
 * 
 * @version 1.0
 * 
 * @author x7k3e21
 * @date 2026-01-21
 */

#ifndef SK_PLATFORM_X11_DISPLAY_WINDOW_HPP
#define SK_PLATFORM_X11_DISPLAY_WINDOW_HPP

#include "platform/common/display/window.hpp"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace sk
{
    class SK_PUBLIC X11Window : public Window
    {
        public:

        X11Window() = default;
        ~X11Window() = default;

        virtual b8 create(const WindowConfig& config) override;

        virtual void destroy() override;

        virtual void pollEvents() override;

        private:

        ::Display* m_Display = NULL;
        ::Window m_Window = 0;
    };    
}

#endif