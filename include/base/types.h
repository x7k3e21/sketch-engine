
/**
 * @file base/types.h
 * @brief Platform-independent basic type definitions with exact widths
 * 
 * @version 2.0
 * 
 * @author x7k3e21
 * @date 2026-01-10
 */

#ifndef SK_BASE_TYPES_H
#define SK_BASE_TYPES_H

/** @brief Successfull program termination exit code */
#define EXIT_SUCCESS 0
/** @brief Unsuccessfull program termination exit code */
#define EXIT_FAILURE 1

/** @brief Compile-time assertion macro */
#ifndef __cplusplus
    #if __STDC_VERSION__ >= 202311L
        /** @brief Since C23 _Static_assert considered deprecated */
        #define STATIC_ASSERT static_assert
    #elif __STDC_VERSION__ >= 201112L
        /** @brief Built-in _Static_assert is supported since C11 */
        #define STATIC_ASSERT _Static_assert
    #else
        /** @brief Indicates that special workaround would be used */
        #define STATIC_ASSERT_WORKAROUND 1
    #endif
#else
    #if __cplusplus >= 201103L
        /** @brief Static assertion was introduced in C++11 standard */
        #define STATIC_ASSERT static_assert
    #else
        /** @brief Indicates that special workaround would be used */
        #define STATIC_ASSERT_WORKAROUND 1
    #endif
#endif

#ifdef STATIC_ASSERT_WORKAROUND
    /** @brief Fallback for compilers without static assertion support */
    #define STATIC_ASSERT(condition, message) \
        typedef char static_assert_##message[(condition) ? 1 : -1]
#endif

/** @brief 8-bit signed integer type */
typedef signed char i8;
/** @brief 16-bit signed integer type */
typedef signed short i16;
/** @brief 32-bit signed integer type */
typedef signed int i32;
/** @brief 64-bit signed integer type */
typedef signed long long i64;

/** @brief Static assertions for signed integer types */
#ifndef STATIC_ASSERT_WORKAROUND
    STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be exactly 1 byte");
    STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be exactly 2 bytes");
    STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be exactly 4 bytes");
    STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be exactly 8 bytes");
#else
    STATIC_ASSERT(sizeof(i8) == 1, expected_i8_to_be_exactly_1_byte);
    STATIC_ASSERT(sizeof(i16) == 2, expected_i16_to_be_exactly_2_bytes);
    STATIC_ASSERT(sizeof(i32) == 4, expected_i32_to_be_exactly_4_bytes);
    STATIC_ASSERT(sizeof(i64) == 8, expected_i64_to_be_exactly_8_bytes);
#endif

/** @brief 8-bit unsigned integer type */
typedef unsigned char u8;
/** @brief 16-bit unsigned integer type */
typedef unsigned short u16;
/** @brief 32-bit unsigned integer type */
typedef unsigned int u32;
/** @brief 64-bit unsigned integer type */
typedef unsigned long long u64;

/** @brief Static assertions for unsigned integer types */
#ifndef STATIC_ASSERT_WORKAROUND
    STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be exactly 1 byte");
    STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be exactly 2 bytes");
    STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be exactly 4 bytes");
    STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be exactly 8 bytes");
#else
    STATIC_ASSERT(sizeof(u8) == 1, expected_u8_to_be_exactly_1_byte);
    STATIC_ASSERT(sizeof(u16) == 2, expected_u16_to_be_exactly_2_bytes);
    STATIC_ASSERT(sizeof(u32) == 4, expected_u32_to_be_exactly_4_bytes);
    STATIC_ASSERT(sizeof(u64) == 8, expected_u64_to_be_exactly_8_bytes);
#endif

/** @brief 32-bit floating point number type */
typedef float f32;
/** @brief 64-bit floating point number type */
typedef double f64;

/** @brief Static assertions for floating point number types */
#ifndef STATIC_ASSERT_WORKAROUND
    STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be exactly 4 bytes");
    STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be exactly 8 bytes");
#else
    STATIC_ASSERT(sizeof(f32) == 4, expected_f32_to_be_exactly_4_bytes);
    STATIC_ASSERT(sizeof(f64) == 8, expected_f64_to_be_exactly_8_bytes);
#endif

/** @brief 8-bit boolean type */
#ifndef __cplusplus
    #if __STDC_VERSION >= 199901L
        /** @brief Uses built-in _Bool type for C99+ */
        typedef _Bool b8;
    #else
        /** @brief Fallback boolean type for pre-C99 compatibility */
        typedef unsigned char u8;
    #endif

    /** @brief Boolean true value */
    #define true 1
    /** @brief Boolean false value */
    #define false 0
#else
    /** @brief Uses native bool for C++ */
    typedef bool b8;
#endif

/** @brief Maximum value for i8 */
#define I8_MAX 0x7F
/** @brief Minimum value for i8 */
#define I8_MIN (-I8_MAX - 1)

/** @brief Maximum value for i16 */
#define I16_MAX 0x7FFF
/** @brief Minimum value for i16 */
#define I16_MIN (-I16_MAX - 1)

/** @brief Maximum value for i32 */
#define I32_MAX 0x7FFFFFFF
/** @brief Minimum value for i32 */
#define I32_MIN (-I32_MAX - 1)

/** @brief Maximum value for i64 */
#define I64_MAX 0x7FFFFFFFFFFFFFFFLL
/** @brief Minimum value for i64 */
#define I64_MIN (-I64_MAX - 1)

/** @brief Maximum value for u8 */
#define U8_MAX 0xFFU
/** @brief Minimum value for u8 */
#define U8_MIN 0x00U

/** @brief Maximum value for u16 */
#define U16_MAX 0xFFFFU
/** @brief Minimum value for u16 */
#define U16_MIN 0x0000U

/** @brief Maximum value for u32 */
#define U32_MAX 0xFFFFFFFFU
/** @brief Minimum value for u32 */
#define U32_MIN 0x00000000U

/** @brief Maximum value for u64 */
#define U64_MAX 0xFFFFFFFFFFFFFFFFULL
/** @brief Minimum value for u64 */
#define U64_MIN 0x0000000000000000ULL

#endif