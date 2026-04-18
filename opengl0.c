#include <stdio.h>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>

#define true 1
#define false 0

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
int main(void){ /* void huh very fitting get it because the window is just a void of colour (yes im british) */
    
    glfwInit(); /* Initialize GLFW */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); /* Set the required OpenGL version to 3.3 */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); /* Set the required OpenGL version to 3.3 (we have to do it again okay i guess)*/
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); /* Set the OpenGL profile to core */
    GLFWwindow* window = glfwCreateWindow(800,600, "Window", NULL, NULL); /* Create a windowed mode window and its OpenGL context */
    if(window == NULL){ /* Checks if the window shits itself */
        fprintf(stderr, "Failed to open window\n"); /* well you fucked up */
        glfwTerminate(); /* Murder the window!! */
        return 1; /* returns uno */
    }
    glfwMakeContextCurrent(window); /* Make the window's context current (well no shit) */ 
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            fprintf(stderr, "Failed to load GLAD\n"); /* bro forgot to enable the correct compiler flags lol */
            return 2; /* returns dos */
    }
    glViewport(0, 0, 800, 600); /* Set the viewport (kindof obvious) */
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); /* Register the framebuffer size callback function  (i have no idea what this does)*/
    while(!glfwWindowShouldClose(window)){
        processInput(window);

        glClearColor(0.2, 0.3, 0.3, 1.0); /* im the alpha 1.0 in this town */
        glClear(GL_COLOR_BUFFER_BIT); /* this does that thing */ 

        glfwSwapBuffers(window);
        glfwPollEvents(); /* processes all pending input */ 
    }
    glfwTerminate(); /* Murder the window!! */
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height); /* Adjust the viewport when the window size changes */ 
}
void processInput(GLFWwindow* window){ /* Process input from the user */
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){ /* Check if the Escape key is pressed */
        glfwSetWindowShouldClose(window, true); /* Set the window to close when the Escape key is pressed */
    }
} 

