// This file is a part of training-opengl-glfw project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once


namespace sgl {
struct OpenGl
{
    OpenGl()
    {
        glfwSetErrorCallback(error_callback);
        if (!glfwInit())
        {
            exit(EXIT_FAILURE);
        }
    }

    ~OpenGl() { glfwTerminate(); }

private:
    static void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }
};
}
