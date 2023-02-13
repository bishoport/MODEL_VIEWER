#include "Engine.h"

#define GLEW_STATIC
#include "GLEW/glew.h"

#define GLFW_INCLUDE_GLU
#include "GLFW/glfw3.h"


// Define these only in *one* .cc file.
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
// #define TINYGLTF_NOEXCEPTION // optional. disable exception handling.
#include "TINY_GLTF/tiny_gltf.h"



#include <iostream>

namespace engine {

    //OPENGL VARS
    GLFWwindow* window;

    //callback func mainLoop
    void (*delegateMainLoopfunc)() = nullptr;
    void (*delegateKeypressedfunc)(int key) = nullptr;



	void engine::PrintVersion()
	{
		std::cout << "Engine V1.0" << std::endl;
	}

    void ResizeWindow(int newWidth, int newHeight)
    {
        std::cout << "RESIZE TO " << newWidth << " x " << newHeight << std::endl;
        int width = newWidth;
        int height = newHeight;

        glfwSetWindowSize(window, width, height);
    }


    void engine::InitializeEngine(int initialWindowWidth, int initialWindowHeight, void (*delegateMainLoop)(),void (*delegateKeyPressed)(int key))
	{
        delegateMainLoopfunc = delegateMainLoop;
        delegateKeypressedfunc = delegateKeyPressed;

        /* Initialize the library */
        if (!glfwInit())
        {
            std::cout << "GLFW OK" << std::endl;
        }

        glewInit();

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(initialWindowWidth, initialWindowHeight, "CAPTURE", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            std::cout << "WINDOW ERROR" << std::endl;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        InitializeMainLoop();

    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            if (delegateKeypressedfunc != nullptr)
            {
                delegateKeypressedfunc(key);
            }
        }
    }


    void InitializeMainLoop()
    {
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();

            glfwSetKeyCallback(window, key_callback);

            if (delegateMainLoopfunc != nullptr)
            {
                delegateMainLoopfunc();
            }
        }

        glfwTerminate();
    }
	
}



