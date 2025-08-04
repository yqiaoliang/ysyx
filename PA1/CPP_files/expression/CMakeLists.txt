

# 1. 声明 CMake 最低版本要求（必须放在最前面）
cmake_minimum_required(VERSION 3.10)

# 2. 定义项目名称（必须在 cmake_minimum_required 之后）
project(PA1_App)

# 3. 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. 收集源文件（确保当前目录有 .cpp 文件）
# 注意：如果源文件在子目录，需要调整路径（例如 ./src/*.cpp）
file(GLOB cpp_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 检查是否找到源文件
if(NOT cpp_files)
    message(FATAL_ERROR "未找到任何 .cpp 源文件，请检查路径是否正确！")
endif()

# 5. 添加头文件搜索路径（如果有 include 目录）
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 6. 设置输出目录（确保路径正确，无多余空格）
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../build")

# 7. 创建可执行文件（使用收集到的源文件）
add_executable(expression.app ${cpp_files})
install(TARGETS expression.app
        RUNTIME DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/../install"  # 明确指定路径
)