# 寻找vs自带的OpenGL
find_package(OpenGL REQUIRED)

# 设置静态库的搜索路径
link_directories(lib)

# 设置头文件的搜索路径
include_directories(include)

# 设置源文件的搜索路径
aux_source_directory(src DIR_SRCS)


# 将源代码添加到此项目的可执行文件。
add_executable (game ${DIR_SRCS})

# 链接
target_link_libraries(game PRIVATE opengl32 glfw3)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)