// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#include <iostream>
#include <vector>

#include "Display.h"
#include "Mesh.h"
#include "Texture.h"
#include "Vertex.h"

#include <gl/FragmentShader.h>
#include <gl/ProgramShader.h>
#include <gl/VertexShader.h>


int main()
{
    Display display("Hello", 640, 480);

    std::vector<Vertex> vertices = {
        Vertex(glm::vec3{0.5, 0, 0}),
        Vertex(glm::vec3{0, 0.5, 0}),
        Vertex(glm::vec3{0, 1.0, 0})};

    Mesh mesh(vertices);

    gl::ProgramShader programShader(gl::VertexShader("./res/3.3.shader"),
                                    gl::FragmentShader("./res/3.3.shader"));

    //Texture texture("./res/stripes.jpg");

    while (!display.isClosed())
    {
        display.Clear(0.5, 0.8, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        programShader.Bind();
        mesh.Draw();
        display.Update();
    }

    return 0;
}