# C-Logger
Simple logging macro for C projects

## Defines

* `ENABLE_LOGGING`: Enables logging
* `LOG_DATETIME_PREFIX`: Enables the datetime prefix in logs
* `LOGS_DIR(char*)`: Tee logging output to a file within a specified directory (argument)
* `MIN_LOG_LEVEL`: Set the minimum log level, defaults to `LL_TRACE`

## Levels

* `LL_FATAL` (Exits with code 1 after logging)
* `LL_ERROR`
* `LL_WARN`
* `LL_INFO`
* `LL_DEBUG`
* `LL_TRACE`

## Macros

* `LOG(level, msg, ...)`
* `FATAL(msg, ...)`
* `ERROR(msg, ...)`
* `WARN(msg, ...)`
* `INFO(msg, ...)`
* `DEBUG(msg, ...)`
* `TRACE(msg, ...)`

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

Tee'd output to a file
```c
#define ENABLE_LOGGING
#define LOG_DATETIME_PREFIX
#include "logger.h"
LOGS_DIR("/tmp/example/logs");

int main(int argc, char* argv[]) {
    LOG(INFO, "Test log with %d params: [%s: %d]", 3, "test", 56135);
    // Prints: [8/7/2022 22:31:32] main(example.c:7) [ERROR] :: Test log with 2 params: [test1: 56135]
    
    TRACE("Test %d for some %s", 2, "value");
    // Prints: [8/7/2022 22:31:32] main(example.c:10) [TRACE] :: Test 2 for some value
    
    INFO("No variadic example");
    // Prints: [8/7/2022 22:31:32] main(example.c:13) [INFO ] :: No variadic example
}
```
Log output at `/tmp/example/logs/log_8-7-2022_22-31-32.log`
```
[8/7/2022 22:31:32] main(example.c:7) [ERROR] :: Test log with 2 params: [test1: 56135]
[8/7/2022 22:31:32] main(example.c:10) [TRACE] :: Test 2 for some value
[8/7/2022 22:31:32] main(example.c:13) [INFO ] :: No variadic example
```