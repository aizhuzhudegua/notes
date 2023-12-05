// game.cpp: 定义应用程序的入口点。
//

#include "game.h"

using namespace std;

//main.cpp
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
int main(void)
{
    float vertices[] = {
        0.5f,0.5f,0.0f,  //右上
        0.5f,-0.5f,0.0f, //右下
        -0.5f,-0.5f,0.0f,//左下
        -0.5f,0.5f,0.0f //左上
    };

    unsigned int indices[] = {
        0,1,3, //第一个三角形
        1,2,3 //第二个三角形
    };

    //生成立方体的VAO、VBO和EBO
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    //绑定VAO
    glBindVertexArray(VAO);
    //绑定VBO并传入顶点数据
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //绑定EBO并传入索引数据
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    //设置顶点属性指针
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    //解绑VBO
    glBindBuffer(GL_ARRAY_BUFFER,0);
    //注意不要解绑EBO，因为EBO存储在VAO中
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    //解绑VAO
    glBindVertexArray(0);

    //渲染时
    //使用之前连接好的着色器程序
    glUseProgram(glShaderProgram);
    //绑定VAO(实际上不需要每次绑定)
    glBindVertexArray(VAO);
    //用EBO绘制四边形
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

    return 0;
}