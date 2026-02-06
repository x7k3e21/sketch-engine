
/**
 * @file core/display/window.hpp
 * @brief 
 * 
 * @version 1.0
 * 
 * @author x7k3e21
 * @date 2026-01-21
 */

#ifndef SK_PLATFORM_COMMON_DISPLAY_WINDOW_HPP
#define SK_PLATFORM_COMMON_DISPLAY_WINDOW_HPP

#include "base/types.h"
#include "base/macros.h"

#include <string>

namespace sk
{
    struct SK_PUBLIC WindowConfig
    {
        /** @brief */
        u32 width;
        /** @brief */
        u32 height;

        /** @brief */
        i32 x;
        /** @brief */
        i32 y;

        /** @brief */
        std::string title;
    };

    class SK_PUBLIC Window
    {
        public:

        Window() = default;
        ~Window() = default;

        virtual b8 create(const WindowConfig& config) = 0;

        virtual void destroy() = 0;

        virtual void pollEvents() = 0;

        u32 getWidth() const { return m_Width; };
        u32 getHeight() const { return m_Height; };

        b8 isFullscreen() const { return m_Fullscreen; };

        protected:

        u32 m_Width = 0;
        u32 m_Height = 0;

        std::string m_Title;

        bool m_Fullscreen = false;
    };
}

#endif