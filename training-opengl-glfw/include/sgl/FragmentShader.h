// This file is a part of training-opengl-glfw project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <sgl/Shader.h>


namespace sgl {
struct FragmentShader : public Shader
{
    FragmentShader(const std::string& fileName)
            : Shader(fileName + ".fs", GL_FRAGMENT_SHADER)
    {
    }
};
}
