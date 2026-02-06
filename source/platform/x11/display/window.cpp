
/**
 * @file platform/x11/display/window.cpp
 * @brief 
 * 
 * @version 1.0
 * 
 * @author x7k3e21
 * @date 2026-01-21
 */

#include "platform/x11/display/window.hpp"

namespace sk
{
    b8 X11Window::create(const WindowConfig& config)
    {
        this->m_Width = config.width;
        this->m_Height = config.height;

        this->m_Title = config.title;

        this->m_Display = ::XOpenDisplay(NULL);

        if(this->m_Display == NULL)
        {
            return EXIT_FAILURE;
        }

        i32 defaultScreenID = ::XDefaultScreen(this->m_Display);

        ::Window rootWindow = ::XRootWindow(this->m_Display, defaultScreenID);

        u32 borderWidth = 0;

        i32 windowDepth = CopyFromParent;
        u32 windowClass = InputOutput;

        ::Visual* windowVisual = CopyFromParent;

        i32 attributeValueMask = CWBackPixel | CWEventMask;

        ::XSetWindowAttributes windowAttributes = { };
        windowAttributes.background_pixel = 0x00000000;

        windowAttributes.event_mask =
            KeyPressMask |
            KeyReleaseMask |
            ButtonPressMask |
            ButtonReleaseMask |
            PointerMotionMask |
            ExposureMask |
            StructureNotifyMask;

        this->m_Window = XCreateWindow(
            this->m_Display,
            rootWindow,

            config.x, config.y, 

            this->m_Width,
            this->m_Height,

            borderWidth,

            windowDepth,
            windowClass,

            windowVisual,

            attributeValueMask,
            &windowAttributes
        );

        if(this->m_Window == 0)
        {
            return EXIT_FAILURE;
        }

        ::XStoreName(this->m_Display, this->m_Window, this->m_Title.c_str());
        
        ::XMapWindow(this->m_Display, this->m_Window);

        ::XFlush(this->m_Display);

        return EXIT_SUCCESS;
    }

    void X11Window::destroy()
    {
        if(this->m_Window != 0)
        {
            ::XDestroyWindow(this->m_Display, this->m_Window);
            this->m_Window = 0;
        }

        if(this->m_Display != NULL)
        {
            ::XCloseDisplay(this->m_Display);
            this->m_Display = NULL;
        }
    }

    void X11Window::pollEvents()
    {
        ::XEvent genericEvent;

        while(::XPending(this->m_Display) > 0)
        {
            ::XNextEvent(this->m_Display, &genericEvent);

            switch(genericEvent.type)
            {
                default:
                    break;
            }
        }
    }
}