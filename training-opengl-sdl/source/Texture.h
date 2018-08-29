// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <string>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Texture
{
public:
    Texture(const std::string& fileName)
    {
        SDL_Surface* image = SDL_LoadBMP(fileName.c_str());

        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int MODE = (image->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, /*border*/ 0, MODE, GL_UNSIGNED_BYTE, image->pixels);

        SDL_FreeSurface(image);
    }

    ~Texture()
    {
        glDeleteTextures(1, &m_texture);
    }

    void Bind(unsigned int unit)
    {
        glActiveTexture(GL_TEXTURE0 + unit);
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }

private:
    GLuint m_texture;
};
