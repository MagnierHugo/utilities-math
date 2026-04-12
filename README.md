# utilities-math

A C++ library of mathematical utilities.

## Features

| Feature | Header | Status |
|---|---|---|
| N-D Tensors | `include/tensor.hpp` | 🚧 In progress |
| Quaternions | `include/quaternion.hpp` | 📋 Planned |

> Status legend: ✅ Stable · 🚧 In progress · 📋 Planned

## Requirements

- CMake 4.3.1+
- A C++23 compatible compiler

## Build & Test

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```