
/**
 * @file base/macros/compiler.h
 * @brief
 * 
 * @version 1.0
 * 
 * @author x7k3e21
 * @date 2026-01-17
 */

#ifndef SK_BASE_MACROS_COMPILER_H
#define SK_BASE_MACROS_COMPILER_H

/** @brief Represents Microsoft Visual C++ compiler */
#define COMPILER_ID_MSVC 0x01
/** @brief Represents GNU Compilers Collection compilers */
#define COMPILER_ID_GCC 0x02
/** @brief Represents Clang compiler */
#define COMPILER_ID_CLANG 0x03
/** @brief Represents Intel C++ Compiler compiler */
#define COMPILER_ID_INTEL 0x04

/** @brief Represents unknown or incorrectly detected compiler */
#define COMPILER_ID_UNKNOWN 0x00

#if defined(_MSC_VER)
    #define COMPILER_ID COMPILER_ID_MSVC

    #define COMPILER_VERSION_MAJOR (_MSC_VER / 100)
    #define COMPILER_VERSION_MINOR (_MSC_VER % 100)
#elif defined(__GNUC__)
    #define COMPILER_ID COMPILER_ID_GCC

    #define COMPILER_VERSION_MAJOR __GNUC__
    #define COMPILER_VERSION_MINOR __GNUC_MINOR__
#elif defined(__clang__)
    #define COMPILER_ID COMPILER_ID_CLANG

    #define COMPILER_VERSION_MAJOR __clang_major__
    #define COMPILER_VERSION_MINOR __clang_minor__
#elif defined(__INTEL_COMPILER)
    #define COMPILER_ID COMPILER_ID_INTEL

    #define COMPILER_VERSION_MAJOR (__INTEL_COMPILER / 100)
    #define COMPILER_VERSION_MINOR (__INTEL_COMPILER % 100)
#else
    #define COMPILER_ID COMPILER_ID_UNKNOWN

    #define COMPILER_VERSION_MAJOR 0
    #define COMPILER_VERSION_MINOR 0
#endif

/** @brief Compiler C standard detection */
#if defined(__STDC_VERSION__)
    #define COMPILER_C_STANDARD __STDC_VERSION__
#else

#endif

/** @brief Compiler C++ standard dectection */
#if defined(_MSVC_LANG)
    #define COMPILER_CPP_STANDARD _MSVC_LANG
#elif defined(__cplusplus)
    #define COMPILER_CPP_STANDARD __cplusplus
#else
    
#endif

/** @brief Macros for compiler-specific attributes and intrinsics */
#if COMPILER_ID == COMPILER_ID_MSVC
    
#elif COMPILER_ID == COMPILER_ID_GCC
     
#elif COMPILER_ID == COMPILER_ID_CLANG

#elif COMPILER_ID == COMPILER_ID_INTEL

#elif COMPILER_ID == COMPILER_ID_UNKNOWN

#else
    #error 
#endif

#endif