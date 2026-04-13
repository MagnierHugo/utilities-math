# utilities-math

A C++ library of mathematical utilities.

## Features

| Feature | Header | Status |
|---|---|---|
| Geometry    | `include/Geometry/geometry.hpp`      | ✅ Stable      |
| N-D Tensors | `include/Tensor/tensor.hpp`          | 📋 Planned     |
| Quaternions | `include/Quaternion/quaternion.hpp`  | 📋 Planned     |

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
