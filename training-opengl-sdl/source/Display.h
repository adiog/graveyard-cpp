// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>

#include <SDL2/SDL.h>

#include <sdl/Context.h>
#include <sdl/GlContext.h>
#include <sdl/Window.h>


class Display
{
public:
    Display(const std::string& title, int width, int height)
            : sdlContext{}
            , sdlWindow(title, width, height)
            , sdlGlContext(sdlWindow)
    {
        auto status = glewInit();

        if (status != GLEW_OK)
        {
            std::cout << "Glew failed to initialize!" << std::endl;
        }
    }

    void Update()
    {
        SwapBuffers();

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isClosedFlag = true;
            }
        }
    }

    void Clear(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void SwapBuffers()
    {
        sdlWindow.swap();
    }

    bool isClosed()
    {
        return isClosedFlag;
    }

private:
    sdl::Context sdlContext;
    sdl::Window sdlWindow;
    sdl::GlContext sdlGlContext;

    bool isClosedFlag = false;
};
