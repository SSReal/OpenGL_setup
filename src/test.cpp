#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//function prototypes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main() {

    glfwInit();
    //ensuring the version of OpenGL to be 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //use the core profile, without backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //for apple
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //creating window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "Sajaltest", NULL, NULL);
    if(window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //initialize glad
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //setting the viewport
    glViewport(0,0,800,600);

    //set the function to call for resizing the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   
    

    //render loop
    while(!glfwWindowShouldClose(window)) {
        
        //input
        processInput(window);

        //rendering commands here
        //set the clear color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    //terminate and clean up
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width, height);
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, true);
}