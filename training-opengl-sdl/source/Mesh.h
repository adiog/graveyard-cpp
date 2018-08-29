// This file is a part of training_opengl_sdl project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include "Vertex.h"
#include <vector>
#include <GL/glew.h>


class Mesh
{
public:
    Mesh(std::vector<Vertex> vertices)
            : drawCount(static_cast<int>(vertices.size()))
            , vertices(vertices)
    {
        /*      glGenVertexArrays(1, &m_meshObject);
        glGenBuffers(1, &m_vertexArray);

        glBindVertexArray(m_meshObject);
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexArray);

        glBufferData(GL_ARRAY_BUFFER, drawCount * sizeof(Vertex), this->vertices.data(), GL_STATIC_DRAW);
*/

        // This will identify our vertex buffer
//        GLuint vertexbuffer;
        // Generate 1 buffer, put the resulting identifier in vertexbuffer
        glGenBuffers(1, &vertexbuffer);
        // The following commands will talk about our 'vertexbuffer' buffer
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        // Give our vertices to OpenGL.
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    }

    ~Mesh()
    {
        //        glDeleteVertexArrays(1, &m_meshObject);
    }

    void Draw()
    {
        /*
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
        glBindVertexArray(m_vertexArray);
        //glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, drawCount);
//        glDrawElementsBaseVertex(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0, 0);
        glDisableVertexAttribArray(0);
         */

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,         // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,         // size
            GL_FLOAT,  // type
            GL_FALSE,  // normalized?
            0,         // stride
            (void*)0   // array buffer offset
        );
        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 3);  // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);
    }

    enum
    {
        POSITION_VB
    };

    static const int NUM_BUFFERS = 4;

    std::vector<Vertex> vertices;

    //  GLuint m_meshObject;
    //  GLuint m_vertexArray;
    GLuint vertexbuffer;
    int drawCount;
};
