// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <SDL2/SDL.h>


namespace sdl {
struct Window
{
    Window(const std::string& title, int width, int height)
    {
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    }

    ~Window()
    {
        SDL_DestroyWindow(m_window);
    }

    void swap()
    {
        SDL_GL_SwapWindow(m_window);
    }

    SDL_Window* m_window;
};
}
