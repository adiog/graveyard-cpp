// This file is a part of training-opengl-glfw project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <iostream>
#include <string>
#include <vector>

//#include <GL/glew.h>

#include <sgl/Shader.h>


namespace sgl {
struct ProgramShader {
    ProgramShader()
    {}
    /*
    ProgramShader(std::vector<Shader>& shadersVector)
            : m_shaders(std::move(shadersVector))
    {
       // initialize();
    }

    template <typename... ShadersEllipsis>
    ProgramShader(ShadersEllipsis... shadersEllipsis): m_shaders{std::move(shadersEllipsis)...}
    {
        //initialize();
    }*/
    template<typename Shader>
    void emplace(Shader &&shader)
    {
        m_shaders.push_back(std::move(shader));
    }

    void initialize()
    {
        m_program = glCreateProgram();

        for (auto& shader : m_shaders)
        {
            shader.Attach(m_program);
        }

        //glBindAttribLocation(m_program, 0, "position");

        glLinkProgram(m_program);
        CheckProgramError(m_program, GL_LINK_STATUS, "Error: Program linking failed: ");

        glValidateProgram(m_program);
        CheckProgramError(m_program, GL_VALIDATE_STATUS, "Error: Program is invalid: ");
    }

    GLint getUniformLocation(const char* loc)
    {
        return glGetUniformLocation(m_program, loc);
    }

    GLint getAttribLocation(const char* loc)
    {
        return glGetAttribLocation(m_program, loc);
    }

    ~ProgramShader()
    {
//        std::cout << "ACHTUNG" << std::endl;
        for (auto& shader : m_shaders)
        {
            shader.Detach(m_program);
        }
        glDeleteProgram(m_program);
    }

    void Bind()
    {
        glUseProgram(m_program);
    }

    void CheckProgramError(GLuint shader, GLuint flag, const std::string& errorMessage)
    {
        GLint success = 0;
        GLchar error[1024] = {0};

        glGetProgramiv(shader, flag, &success);

        if (success == GL_FALSE)
        {
            glGetProgramInfoLog(shader, sizeof(error), nullptr, error);
            std::cerr << errorMessage << ": '" << error << "'" << std::endl;
        }
    }


    GLuint m_program;
    std::vector<Shader> m_shaders;
};
}
