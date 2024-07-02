cmake_minimum_required(VERSION 3.20.0)
project(videoapp)

set(PROJECT_NAME videoapp)

set(CMAKE_CXX_STANDARD 20)
 
if (WIN32)

    # list(APPEND EXTRA_LIBS "-lglu32 -lopengl32")
    # set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")

    message('************WIN32')
elseif(APPLE)
    message('************APPLE')
else()
    message('************something else')
endif()



add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)
add_subdirectory(lib/FFmpeg)

add_executable(${PROJECT_NAME} src/main.cpp)


find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    message("opengl found")
    message("include dir: ${OPENGL_INCLUDE_DIR}")
    message("link libraries: ${OPENGL_gl_LIBRARY}")
    target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})

else (OPENGL_FOUND)
    message("opengl not found")
endif()

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} FFmpeg)


target_link_libraries(${PROJECT_NAME} ${AVCODEC_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${AVFORMAT_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${AVFILTER_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${AVDEVICE_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${AVUTIL_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SWRESAMPLE_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${SWSCALE_LIBRARY})