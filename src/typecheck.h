#pragma once

#ifndef C_LOGGER_TYPECHECK_H
#define C_LOGGER_TYPECHECK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef typename

enum t_typename {
    T_BOOL,
    T_UNSIGNED_CHAR,
    T_CHAR,
    T_SIGNED_CHAR,
    T_UNSIGNED_SHORT_INT,
    T_SHORT_INT,
    T_UNSIGNED_INT,
    T_INT,
    T_UNSIGNED_LONG_INT,
    T_LONG_INT,
    T_UNSIGNED_LONG_LONG_INT,
    T_LONG_LONG_INT,
    T_FLOAT,
    T_DOUBLE,
    T_LONG_DOUBLE,
    T_POINTER_TO_CHAR,
    T_POINTER_TO_VOID,
    T_POINTER_TO_INT,
    T_DEFAULT
};

#define typename(x) _Generic((x), \
    _Bool: T_BOOL, \
    unsigned char: T_UNSIGNED_CHAR, \
    char: T_CHAR, \
    signed char: T_SIGNED_CHAR, \
    unsigned short int: T_UNSIGNED_SHORT_INT, \
    short int: T_SHORT_INT, \
    unsigned int: T_UNSIGNED_INT, \
    int: T_INT, \
    unsigned long int: T_UNSIGNED_LONG_INT, \
    long int: T_LONG_INT, \
    unsigned long long int: T_UNSIGNED_LONG_LONG_INT, \
    long long int: T_LONG_LONG_INT, \
    float: T_FLOAT, \
    double: T_DOUBLE, \
    long double: T_LONG_DOUBLE, \
    char*: T_POINTER_TO_CHAR, \
    void*: T_POINTER_TO_VOID, \
    int*: T_POINTER_TO_INT, \
    default: T_DEFAULT)
#endif

#ifdef __cplusplus
};
#endif

#endif //C_LOGGER_TYPECHECK_H
