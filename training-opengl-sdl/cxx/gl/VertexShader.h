// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <gl/Shader.h>


namespace gl {
struct VertexShader : public Shader
{
    VertexShader(const std::string &fileName)
            : Shader(fileName + ".vs", GL_VERTEX_SHADER)
    {
    }
};
}
