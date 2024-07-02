cmake_minimum_required(VERSION 3.14)

project(FFMPEG)

find_package(PkgConfig REQUIRED)
pkg_check_modules(AVCODEC REQUIRED IMPORTED_TARGET libavcodec)
pkg_check_modules(AVFORMAT REQUIRED IMPORTED_TARGET libavformat)
pkg_check_modules(AVFILTER REQUIRED IMPORTED_TARGET libavfilter)
# pkg_check_modules(AVDEVICE REQUIRED IMPORTED_TARGET libavdevice)
pkg_check_modules(AVUTIL REQUIRED IMPORTED_TARGET libavutil)
pkg_check_modules(SWRESAMPLE REQUIRED IMPORTED_TARGET libswresample)
# pkg_check_modules(SWSCALE REQUIRED IMPORTED_TARGET libswrescale)


find_library(AVCODEC_LIBRARY avcodec)
find_library(AVFORMAT_LIBRARY avformat)
find_library(AVFILTER_LIBRARY avfilter)
find_library(AVDEVICE_LIBRARY avdevice)
find_library(AVUTIL_LIBRARY avutil)
find_library(SWRESAMPLE_LIBRARY swresample)
find_library(SWSCALE_LIBRARY swrescale)

message('avcode library = ${AVCODEC_LIBRARY}')
message('avformat library = ${AVFORMAT_LIBRARY}')
message('avfilter library = ${AVFILTER_LIBRARY}')
message('avdevice library = ${AVDEVICE_LIBRARY}')
message('avutil library = ${AVUTIL_LIBRARY}')
message('swresample library = ${SWRESAMPLE_LIBRARY}')
message('swrescale library = ${SWSCALE_LIBRARY}')




add_library(FFmpeg INTERFACE IMPORTED GLOBAL)


target_include_directories(FFmpeg INTERFACE
    ${AvCODEC_INCLUDE_DIRS}
    ${AVFORMAT_INCLUDE_DIRS}
    ${AVFILTER_INCLUDE_DIRS}
    ${AVDEVICE_INCLUDE_DIRS}
    ${AVUTIL_INCLUDE_DIRS}
    ${SWRESAMPLE_INCLUDE_DIRS}
    ${SWSCALE_INCLUDE_DIRS}
)

# target_link_options(FFmpeg INTERFACE
#     ${AvCODEC_LDFLAGS}
#     ${AVFORMAT_LDFLAGS}
#     ${AVFILTER_LDFLAGS}
#     ${AVDEVICE_LDFLAGS}
#     ${AVUTIL_LDFLAGS}
#     ${SWRESAMPLE_LDFLAGS}
#     ${SWSCALE_LDFLAGS}

# )
# message('${AVCODEC_INCLUDE_DIRS}')
# message('${AVFORMAT_INCLUDE_DIRS}')
# message('${AVFILTER_INCLUDE_DIRS}')
# message('${AVDEVICE_INCLUDE_DIRS}')
# message('${AVUTIL_INCLUDE_DIRS}')
# message('${SWRESAMPLE_INCLUDE_DIRS}')
# message('${SWSCALE_INCLUDE_DIRS}')

# target_link_libraries(${PROJECT_NAME} INTERFACE ${AVCODEC_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${AVFORMAT_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${AVFILTER_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${AVDEVICE_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${AVUTIL_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${SWRESAMPLE_LIBRARY})
# target_link_libraries(${PROJECT_NAME} ${SWSCALE_LIBRARY})
