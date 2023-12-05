
#define GlEW_STATIC 
#include <game.h>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
using namespace std;

int main(void)
{
    //初始化GLFW函数库
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Open GLFW Window
    GLFWwindow* window = glfwCreateWindow(800,600,"myopengl",NULL,NULL);
    if (window==NULL)
    {
        cout << "open window failed!" << endl;
        //关闭GLFW函数库
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //Init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0,0,800,600);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}