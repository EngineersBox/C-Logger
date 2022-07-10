#pragma once

#ifndef C_LOGGER__LOGGING_H
#define C_LOGGER__LOGGING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <time.h>

#include "typecheck.h"

#ifndef ENABLE_LOGGING
#define LOG(level, stream, msg, ...) ({})
#else

enum LogLevel {
    LL_ERROR = 0,
    LL_WARN = 1,
    LL_INFO = 2,
    LL_DEBUG = 3,
    LL_TRACE = 4
};

static int __min_log_level__ = LL_DEBUG;

static inline char* logLevelToString(int level) {
    if (level == LL_ERROR)  {
        return "ERROR";
    } else if (level == LL_WARN) {
        return "WARN ";
    } else if (level == LL_INFO) {
        return "INFO ";
    } else if (level == LL_DEBUG) {
        return "DEBUG";
    } else if (level == LL_TRACE) {
        return "TRACE";
    }
    return "INFO ";
}

// Log streams
#define STDOUT stdout
#define STDERR stderr

#define LOG(level, msg, ...) { \
    if (typename(level) != T_INT) { \
        fprintf(STDERR, "Expected integer log level");\
        exit(1);
    } \
    if (level <= __min_log_level__) {   \
        time_t rawtime; \
        struct tm* timeinfo; \
        time(&rawtime); \
        timeinfo = localtime(&rawtime); \
        fprintf(level == LL_ERROR ? STDERR : STDOUT, "[%d/%d/%d %d:%d:%d] %s:%d [%s] :: " msg "\n", \
            timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, \
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
            __func__, __LINE__, \
            logLevelToString(level), \
            ##__VA_ARGS__ \
        ); \
        fflush(level == LL_ERROR ? STDERR : STDOUT); \
    } \
}

//#define LOG(level, msg, ...) printf(msg "\n", ##__VA_ARGS__)

#define ERROR(msg, ...) (LOG(LL_ERROR, msg, __VA_ARGS__))
#define WARN(msg, ...) (LOG(LL_WARN, msg, __VA_ARGS__))
#define INFO(msg, ...) (LOG(LL_INFO, msg, __VA_ARGS__))
#define DEBUG(msg, ...) (LOG(LL_DEBUG, msg, __VA_ARGS__))
#define TRACE(msg, ...) (LOG(LL_TRACE, msg, __VA_ARGS__))

#endif // ENABLE_LOGGING

#ifdef __cplusplus
};
#endif

#endif //C_LOGGER_LOGGING_H
