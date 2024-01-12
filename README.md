# datetime 
## 2.0
---
Version 2.0 of the original datetime lib from pcannon09!

---

1. Include:
```cpp
#include "dt.hpp"
```

2. Get version:

Definition in hpp file:
```cpp
extern const char *version;
```

How to get version
```cpp
const char *datetimeVersion = dt::version;
```

3. Get current time
Definition of **sysClock** type in hpp file
```cpp
typedef std::chrono::time_point<std::chrono::system_clock> sysClock;
```

Definition in hpp file:
```cpp
sysClock get();
```
Howto get current time
```cpp
sysClock timeNow = dt::get();
```

4. Set 24h or 12h clock
Definition in hpp file:
```cpp
bool set24h(bool x);
```

How to set 12h or 24h:
```cpp
// This code will set the hour format to 12h
// There is an optional variable to save the value of the 'set24h' function that was called
bool optionalVariable = set24h(false);
// This code will set the hout format to 24h
bool optionalVariable = set24h(true);
```
