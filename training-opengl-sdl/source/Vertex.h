// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <glm/glm.hpp>


class Vertex
{
public:
    Vertex(glm::vec3 pos)
            : pos(pos)
    {
    }
    glm::vec3 pos;
};
