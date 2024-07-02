#include <iostream>
#include <GLFW/glfw3.h>
#include <gl\GL.h> 

int main(int argc, char* argv[]) {


    GLFWwindow* window;

    if (!glfwInit()) {
        std::cout << "Couldn't init GLFW" << "\n";
        return 1;
    }

    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        std::cout << "Couldn't open window \n";
        return 1;
    }

    //{ new unsigned char[100 * 100 * 3] };
    std::unique_ptr<unsigned char[]> uData = std::make_unique<unsigned char[]>(100 * 100 * 3);
    //unsigned char* data = new unsigned char[100 * 100 * 3];
    for ( int y = 0; y < 100; ++y ) {
        for (int x = 0; x < 100; ++x ) {
            uData[y * 100 * 3 + x * 3] = 0xff;
            uData[y * 100 * 3 + x * 3 + 1] = 0x00;
            uData[y * 100 * 3 + x * 3 + 2] = 0x00;

            //data[y * 100 * 3 + x * 3] = 0xff;
            //data[y * 100 * 3 + x * 3 + 1] = 0x00;
            //data[y * 100 * 3 + x * 3 + 2] = 0x00;

        }
    }


    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, uData.get());
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }


//    delete [] data;



    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}