# C-Logger
Simple logging macro for C projects

## Defines

* `ENABLE_LOGGING`: Enables logging
* `LOG_DATETIME_PREFIX`: Enables the datetime prefix in logs

## Levels

* `LL_ERROR`
* `LL_WARN`
* `LL_INFO`
* `LL_DEBUG`
* `LL_TRACE`

## Macros

* `LOG(level, msg, ...`
* `ERROR(msg, ...)`
* `WARN(msg, ...)`
* `INFO(msg, ...)`
* `DEBUG(msg, ...)`
* `TRACE(msg, ...)`

## Minimum Level

You can configure the minimum log level by setting `__min_log_level__` to any of the levels

## Usage

With datetime prefix
```c
#define ENABLE_LOGGING
#define LOG_DATETIME_PREFIX
#include "logger.h"

int main(int argc, char* argv[]) {
    LOG(INFO, "Test log with %d params: [%s: %d]", 3, "test", 56135);
    // Prints: [8/7/2022 22:31:32] main(example.c:7) [ERROR] :: Test log with 2 params: [test1: 56135]
    
    TRACE("Test %d for some %s", 2, "value");
    // Prints: [8/7/2022 22:31:32] main(example.c:10) [TRACE] :: Test 2 for some value
    
    INFO("No variadic example");
    // Prints: [8/7/2022 22:31:32] main(example.c:13) [INFO ] :: No variadic example
}
```

Without datetime prefix
```c
#define ENABLE_LOGGING
//#define LOG_DATETIME_PREFIX
#include "logger.h"

int main(int argc, char* argv[]) {
    LOG(INFO, "Test log with %d params: [%s: %d]", 3, "test", 56135);
    // Prints: main(example.c:7) [ERROR] :: Test log with 2 params: [test1: 56135]
    
    TRACE("Test %d for some %s", 2, "value");
    // Prints: main(example.c:10) [TRACE] :: Test 2 for some value
    
    INFO("No variadic example");
    // Prints: main(example.c:13) [INFO ] :: No variadic example
}
```