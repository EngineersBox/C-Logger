# C-Logger
Simple logging macro for C projects

## Levels

* `ERROR`
* `WARN`
* `INFO`
* `DEBUG`
* `TRACE`

## Streams

* `STDOUT`
* `STDERR`

## Usage

```c
#include "logger.h"

int main(int argc, char* argv[]) {
    LOG(INFO, STDOUT, "Test log with %d params: [%s: %d]", 2, "test", 56135);
    // Prints: [22/31/32 8:7:2022] main:4 [ERROR] :: Test log with 2 params: [test1: 56135]
}
```