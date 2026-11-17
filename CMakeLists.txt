cmake_minimum_required (VERSION 3.24)

project ("hashbench" LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 23)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_ARCHITECTURES native)

# Add source to this project's executable.
add_executable (hashbench
  src/main.cpp
  src/locks/Lock.hpp  
  src/locks/BaseHashSet.hpp
  src/runner.cpp
  src/runner.hpp  
)

target_include_directories(hashbench PRIVATE src)
target_compile_options(hashbench PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:-lineinfo> )

# TODO: Add tests and install targets if needed.
