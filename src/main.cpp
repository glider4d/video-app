#include <iostream>
#include <GLFW/glfw3.h>
#include <gl\GL.h> 
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <inttypes.h>
}

bool load_frame(const char* filename, int* width, int* height, unsigned char** data) {
    AVFormatContext* av_format_ctx = avformat_alloc_context();
    return false;
}

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

    std::unique_ptr<unsigned char[]> uData = std::make_unique<unsigned char[]>(100 * 100 * 3);
    for ( int y = 0; y < 100; ++y ) {
        for (int x = 0; x < 100; ++x ) {
            uData[y * 100 * 3 + x * 3] = 0xff;
            uData[y * 100 * 3 + x * 3 + 1] = 0x00;
            uData[y * 100 * 3 + x * 3 + 2] = 0x00;

        }
    }


    for (int y = 25; y < 75; ++y) {
        for (int x = 25; x < 75; ++x) {
            uData[y * 100 * 3 + x * 3] = 0x00;
            uData[y * 100 * 3 + x * 3 + 1] = 0x00;
            uData[y * 100 * 3 + x * 3 + 2] = 0xff;

        }
    }

    glfwMakeContextCurrent(window);

    GLuint tex_handle;

    int tex_width = 100;
    int tex_height = 100;
    
    glGenTextures(1, &tex_handle);
    glBindTexture(GL_TEXTURE_2D, tex_handle);
  //  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, uData.get());


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, uData.get());

        //Set up orphographic projection
        int window_width, window_height;
        glfwGetFramebufferSize(window, &window_width, &window_height);
        std::cout << "window_width = " << window_width << std::endl;
        std::cout << "window height = " << window_height << std::endl;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, window_width, 0, window_height, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        // Render whatever you want
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex_handle);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(0, 0);
            glTexCoord2f(1, 0); glVertex2f(tex_width, 0);
            glTexCoord2f(1, 1); glVertex2f(tex_width, tex_height);
            glTexCoord2f(0, 1); glVertex2f(0, tex_height);
        glEnd();

        glDisable(GL_TEXTURE_2D);

        glfwSwapBuffers(window);
        glfwWaitEvents();
    }



    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}