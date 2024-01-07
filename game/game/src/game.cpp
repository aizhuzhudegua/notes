
#include <game.h>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <string>
#include <Shader.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Camera.h>
using namespace std;

#pragma region Camera Declare
Camera camera(glm::vec3(0, 0, 3.0f), glm::radians(0.0f), glm::radians(0.0f), glm::vec3(0, 1.0f, 0));
#pragma endregion

#pragma region Input Declare
float lastX;
float lastY;
bool firstMouse = true;

void processInput(GLFWwindow* window) {

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.speedZ = 1.0f;
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.speedZ = -1.0f;
    }
    else
    {
        camera.speedZ = 0;
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        camera.speedY = 1.0f;
    }
    else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        camera.speedY = -1.0f;
    }
    else
    {
        camera.speedY = 0;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.speedX = -1.0f;
    }
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.speedX = 1.0f;
    }
    else
    {
        camera.speedX = 0;
    }
};
void mouse_callback(GLFWwindow* window, double xPos, double yPos) {

    if (firstMouse)
    {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }
    float deltaX, deltaY;
    deltaX = xPos - lastX;
    deltaY = yPos - lastY;

    lastX = xPos;
    lastY = yPos;

    camera.ProcessMouseMovement(deltaX, deltaY);
};

#pragma endregion

#pragma region Model Data
float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};

/*unsigned int indices[] = {
    0,1,2,
    2,3,0
};*/

glm::vec3 cubePositions[] = {
  glm::vec3(0.0f,  0.0f,  0.0f),
  glm::vec3(2.0f,  5.0f, -15.0f),
  glm::vec3(-1.5f, -2.2f, -2.5f),
  glm::vec3(-3.8f, -2.0f, -12.3f),
  glm::vec3(2.4f, -0.4f, -3.5f),
  glm::vec3(-1.7f,  3.0f, -7.5f),
  glm::vec3(1.3f, -2.0f, -2.5f),
  glm::vec3(1.5f,  2.0f, -2.5f),
  glm::vec3(1.5f,  0.2f, -1.5f),
  glm::vec3(-1.3f,  1.0f, -1.5f)
};
#pragma endregion

unsigned int LoadImageToGPU(const char * filename,GLint internalFormat,GLint format,int textureSlot) {
    unsigned int TexBuffer;
    glGenTextures(1, &TexBuffer);
    // 激活纹理槽位
    glActiveTexture(GL_TEXTURE0 + textureSlot);
    glBindTexture(GL_TEXTURE_2D, TexBuffer);

    int width, heigth, nrChannel;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filename, &width, &heigth, &nrChannel, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, heigth, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        cout << "load image failed." << endl;
    }
    stbi_image_free(data);
    return TexBuffer;
}

int main(void)
{

    #pragma region Open a Window
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
    // 隐藏鼠标
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window,mouse_callback);


    //Init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0,0,800,600);
    glEnable(GL_DEPTH_TEST);
#pragma endregion

    #pragma region Init Shader Program
    Shader testShader = Shader("C:/Users/王周凯/Desktop/知识仓库/game/game/src/vertexSource.vert","C:/Users/王周凯/Desktop/知识仓库/game/game/src/fragmentSource.frag");
#pragma endregion  

    #pragma region Init and load Models to VAO,VBO
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);


    //unsigned int EBO;
    //glGenBuffers(1, &EBO);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //顶点
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    //顶点色
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    //glEnableVertexAttribArray(1);
    

    //纹理
    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(3);

#pragma endregion

    #pragma region Init and load Textures
    unsigned int TexBufferA;
    TexBufferA = LoadImageToGPU("C:/Users/王周凯/Desktop/知识仓库/game/game/src/container.jpg",GL_RGB,GL_RGB,0);

    unsigned int TexBufferB;
    TexBufferB = LoadImageToGPU("C:/Users/王周凯/Desktop/知识仓库/game/game/src/awesomeface.png", GL_RGBA, GL_RGBA, 6);
#pragma endregion

    #pragma region Prepare MVP matrices
    // calculate our transformation matrix here.
    //glm::mat4 trans;
    //遵守trs的顺序
    //trans = glm::translate(trans,glm::vec3(0.5f, -0.5f,0));
    //trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0, 0, 1.0f));
    //trans = glm::scale(trans,glm::vec3(0.5f, 0.5f, 0.5f));
    glm::mat4 modelMat;
    //modelMat = glm::rotate(modelMat, glm::radians(-45.0f), glm::vec3(1.0f, 0, 0));
    glm::mat4 viewMat;
    //viewMat = glm::translate(viewMat,glm::vec3(0,0,-3.0f));
    glm::mat4 projMat;
    projMat = glm::perspective(glm::radians(45.0f),800.0f/600.0f,0.1f,100.0f);
    //Camera camera(glm::vec3(0,0,3.0f),glm::vec3(0,0,0),glm::vec3(0,1.0f,0));
#pragma endregion

    while (!glfwWindowShouldClose(window))
    {
        //process Input
        processInput(window);
      
        //trans = glm::translate(trans, glm::vec3(-0.01f, 0, 0));
        //glm::mat4 trans
        //trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0));
        //trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0, 0, 1.0f));
        
        //设置清屏颜色(事实上就是背景色)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 这和相机位置有关
        //viewMat = glm::translate(viewMat, glm::vec3(0, 0, -3.0f));
        viewMat = camera.GetViewMatrix();

        

        for (int i = 0; i < 10; i++)
        {
            // Set model matrix
            // 设置好位置
            modelMat = glm::translate(glm::mat4(1.0f), cubePositions[i]);
            // 随时间旋转
            //modelMat = glm::rotate(modelMat, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
           
            // Set Material -> Shader Program 
            testShader.use();
            // Set Materrial -> Textures
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TexBufferA);
            glActiveTexture(GL_TEXTURE3);
            glBindTexture(GL_TEXTURE_2D, TexBufferB);
            // Set Material -> Uniform
            //glUniform1i(glGetUniformLocation(testShader.ID, "ourTexture"), 0);
            //glUniform1i(glGetUniformLocation(testShader.ID, "ourFace"), 3);

            //Set MVP
            //glUniformMatrix4fv(glGetUniformLocation(testShader.ID,"transform"),1,GL_FALSE,glm::value_ptr(trans));
            glUniformMatrix4fv(glGetUniformLocation(testShader.ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
            glUniformMatrix4fv(glGetUniformLocation(testShader.ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
            glUniformMatrix4fv(glGetUniformLocation(testShader.ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
            glUniform3f(glGetUniformLocation(testShader.ID, "objColor"),1.0f,0.5f,0.31f );
            glUniform3f(glGetUniformLocation(testShader.ID, "ambientColor"), 0.2f, 0.1f,0.0f);
            glUniform3f(glGetUniformLocation(testShader.ID, "lightPos"), 10.0f, 10.0f, -5.0f);
            glUniform3f(glGetUniformLocation(testShader.ID, "lightColor"), 1.0f, 1.0f, 1.0f);
            glUniform3f(glGetUniformLocation(testShader.ID, "cameraPos"), camera.Position.x, camera.Position.y, camera.Position.z);
            // Set Model
            glBindVertexArray(VAO);
            //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            
            //draw call
            glDrawArrays(GL_TRIANGLES, 0, 36);
            // glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        }

        // Clean up,prepare for next render loop
        glfwSwapBuffers(window);
        glfwPollEvents();
        camera.UpdateCameraPos();
    }
    
    // exit
    glfwTerminate();
    return 0;
}

