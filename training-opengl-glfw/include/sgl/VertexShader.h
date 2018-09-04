// This file is a part of training-opengl-glfw project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <sgl/Shader.h>


namespace sgl {
struct VertexShader : public Shader
{
    VertexShader(const std::string &fileName)
            : Shader(fileName + ".vs", GL_VERTEX_SHADER)
    {
    }
};
}
