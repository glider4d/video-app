#include <iostream>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[]){


    GLFWwindow* window;

    if (!glfwInit()){
        std::cout<<"Couldn't init GLFW"<<"\n";
        return 1;
    }

    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        std::cout<<"Couldn't open window \n";
        return 1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)){
        glfwWaitEvents();
    }

    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}