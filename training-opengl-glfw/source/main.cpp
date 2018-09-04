#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <sgl/FragmentShader.h>
#include <sgl/OpenGl.h>
#include <sgl/ProgramShader.h>
#include <sgl/VertexShader.h>
#include <sgl/Window.h>


static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
    {
        {-0.6f, -0.4f, 1.f, 0.f, 0.f},
        {0.6f, -0.4f, 0.f, 1.f, 0.f},
        {0.f, 0.6f, 0.f, 0.f, 1.f}};


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


int main()
{
    GLuint vertex_buffer;
    GLint mvp_location, vpos_location, vcol_location;

    sgl::OpenGl openGl;
    sgl::Window window;

    window.setKeyCallback(key_callback);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    sgl::ProgramShader programShader;
    programShader.emplace(sgl::VertexShader("./resource/shader"));
    programShader.emplace(sgl::FragmentShader("./resource/shader"));
    programShader.initialize();
    programShader.Bind();

    mvp_location = programShader.getUniformLocation("MVP");
    vpos_location = programShader.getAttribLocation("vPos");
    vcol_location = programShader.getAttribLocation("vCol");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 2));

    while (!window.isActive())
    {
        float ratio;
        int width, height;
        glm::mat4 m, p, mvp;
        window.getSize(width, height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        m = glm::rotate(static_cast<float>(glfwGetTime()), glm::vec3{0.0, 0.0, 1.0});
        p = glm::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mvp = p * m;
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
        glDrawArrays(GL_TRIANGLES, 0, 3);
        window.swapBuffers();
        glfwPollEvents();
    }

    exit(EXIT_SUCCESS);
}
