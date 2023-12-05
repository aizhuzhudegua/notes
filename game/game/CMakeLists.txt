# CMakeList.txt: game 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。

#添加头文件搜索路径
include_directories("include")
# 将源代码添加到此项目的可执行文件。
add_executable (game "src/game.cpp" "src/game.h" "include/glad/glad.h" "include/GLFW/glfw3.h" "include/GLFW/glfw3native.h" "include/KHR/khrplatform.h" "src/glad.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET game PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
