#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "HelperFunctions/HelperFunctionsOpenGL.h"

int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW init failed\n";
        return -1;
    }

#ifdef __APPLE__
    // macOS supports up to OpenGL 4.1; request a forward-compatible core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else
    // Request modern core profile on other platforms
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    int width = 1280;
    int height = 720;
    GLFWwindow* window =
        glfwCreateWindow(width, height, "Vehicle Dynamics Simulator", nullptr, nullptr);

    if (!window)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    std::cout << "OpenGL Version: "
        << glGetString(GL_VERSION)
        << std::endl;
    
    while (!glfwWindowShouldClose(window)) // render loop
    {
        glClearColor(0.6f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}