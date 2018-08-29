// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <sdl/Window.h>


namespace sdl {
struct GlContext
{
    GlContext(Window& window)
    {
        m_glContext = SDL_GL_CreateContext(window.m_window);
    }

    ~GlContext()
    {
        SDL_GL_DeleteContext(m_glContext);
    }

private:
    SDL_GLContext m_glContext;
};
}
