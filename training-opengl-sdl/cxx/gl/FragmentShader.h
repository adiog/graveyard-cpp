// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <gl/Shader.h>


namespace gl {
struct FragmentShader : public Shader
{
    FragmentShader(const std::string& fileName)
            : Shader(fileName + ".fs", GL_FRAGMENT_SHADER)
    {
    }
};
}
