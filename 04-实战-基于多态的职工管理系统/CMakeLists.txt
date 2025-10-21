# 1. 指定最低CMake版本（3.10及以上兼容主流环境）
cmake_minimum_required(VERSION 3.10)

# 2. 定义项目名称（可自定义，如EmployeeManagementSystem）
project(EmployeeSystem)

# 3. 设置C++标准（默认C++11，兼容多数编译器）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. 添加可执行程序：目标名(main) + 所有源文件
add_executable(
    main
    main.cpp
    worker_manager.cpp
    employee.cpp
    manager.cpp
    boss.cpp
)