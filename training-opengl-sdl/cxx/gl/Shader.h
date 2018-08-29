// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <GL/glew.h>


namespace gl {
struct Shader
{
    Shader(const std::string& fileName, GLenum shaderType)
    {
        std::string text = LoadShader(fileName);

        m_shader = glCreateShader(shaderType);

        if (m_shader == 0)
        {
            std::cerr << "Error: shader creation failed" << std::endl;
        }

        const GLchar* shaderSourceStrings = text.c_str();
        GLint shaderSourceStringLengths = text.size();

        glShaderSource(m_shader, 1, &shaderSourceStrings, &shaderSourceStringLengths);
        glCompileShader(m_shader);

        CheckShaderError(m_shader, GL_COMPILE_STATUS, "Error: Shader compilation failed: ");
    }

    virtual ~Shader()
    {
//        glDeleteShader(m_shader);
    }

    void Attach(GLuint program)
    {
        glAttachShader(program, m_shader);
    }

    void Detach(GLuint program)
    {
        glDetachShader(program, m_shader);
    }

    static std::string LoadShader(const std::string& fileName)
    {
        std::ifstream file;
        file.open((fileName).c_str());

        std::string output;
        std::string line;

        if (file.is_open())
        {
            while (file.good())
            {
                getline(file, line);
                output.append(line + "\n");
            }
        }
        else
        {
            std::cerr << "Unable to load shader: " << fileName << std::endl;
        }

        return output;
    }

    void CheckShaderError(GLuint shader, GLuint flag, const std::string& errorMessage)
    {
        GLint success = 0;
        GLchar error[1024] = {0};

        glGetShaderiv(shader, flag, &success);

        if (success == GL_FALSE)
        {
            glGetShaderInfoLog(shader, sizeof(error), nullptr, error);
            std::cerr << errorMessage << ": '" << error << "'" << std::endl;
        }
    }

    GLuint m_shader;
};
}
