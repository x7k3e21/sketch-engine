
/**
 * @file logging/levels.hpp
 * @brief Contains code for handling different levels of log messages
 * 
 * @version 1.0
 * 
 * @author
 * @date 2026-01-17
 */

#ifndef SK_LOGGING_LEVELS_HPP
#define SK_LOGGING_LEVELS_HPP

#include "base/types.h"

namespace sk
{
    namespace Log
    {
        /** @brief Represents all possible importance levels of log messages */
        enum class Level: u8
        {
            /** 
             * @brief Represents "FATAL" log level
             * 
             * @details Indicates critical problems with application,
             * execution should stop immediately
             */
            LOG_LEVEL_FATAL = 0,
            /** 
             * @brief Represents "ERROR" log level
             * 
             * @details Indicates critical problems with the application 
             * that cause it to run improperly or crash
             */
            LOG_LEVEL_ERROR = 1,
            /** 
             * @brief Represents "WARN" log level
             * 
             * @details Indicates non-critical problems with the application
             * that cause it to run suboptimally
             */
            LOG_LEVEL_WARN = 2,
            /** 
             * @brief Represents "INFO" log level
             * @details Used for delivering execution proccess statistics
             */
            LOG_LEVEL_INFO = 3,
            /** 
             * @brief Represents "DEBUG" log level
             * @details Used for debugging purposes
             */
            LOG_LEVEL_DEBUG = 4,
            /** 
             * @brief Represents "TRACE" log level
             * @details Used for verbose debugging purposes
             */
            LOG_LEVEL_TRACE = 5
        };
    }
}

#endif