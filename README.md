# C-Logger
Simple logging macro for C projects

## Levels

* `LL_ERROR`
* `LL_WARN`
* `LL_INFO`
* `LL_DEBUG`
* `LL_TRACE`

## Streams

* `STDOUT`
* `STDERR`

## Macros

* `LOG(level, stream, msg, ...`
* `ERROR(msg, ...)`
* `WARN(msg, ...)`
* `INFO(msg, ...)`
* `DEBUG(msg, ...)`
* `TRACE(msg, ...)`

## Minimum Level

You can configure the minimum log level by setting `__min_log_level__` to any of the levels

## Usage

```c
#include "logger.h"

int main(int argc, char* argv[]) {
    LOG(INFO, STDOUT, "Test log with %d params: [%s: %d]", 3, "test", 56135);
    // Prints: [8/7/2022 22:31:32] main:4 [ERROR] :: Test log with 2 params: [test1: 56135]
    
    WARN("Test %d for some %s", 2, "value");
    // Prints: [8/7/2022 22:31:32] main:7 [WARN ] :: Test 2 for some value
}
```