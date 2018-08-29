// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <SDL2/SDL.h>


namespace sdl {
struct Context
{
    Context()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
    }

    ~Context()
    {
        SDL_Quit();
    }
};
}
