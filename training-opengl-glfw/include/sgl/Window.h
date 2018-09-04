// This file is a part of training-opengl-glfw project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once


namespace sgl {
struct Window
{
    Window()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        window = glfwCreateWindow(640, 480, "Simple texample", nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
    }

    ~Window()
    {
        glfwDestroyWindow(window);
    }

    bool isActive()
    {
        return glfwWindowShouldClose(window);
    }

    template <typename T>
    void setKeyCallback(T key_callback)
    {
        glfwSetKeyCallback(window, key_callback);
    }

    void getSize(int &width, int &height)
    {
        glfwGetFramebufferSize(window, &width, &height);
    }

    void swapBuffers()
    {
        glfwSwapBuffers(window);
    }

    GLFWwindow *window;
};
}
