<<<<<<< HEAD
cmake_minimum_required(VERSION 3.3)
project(camera_feed)

find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

set(SOURCE_FILES main.cpp Webcam.cpp Webcam.h)
add_executable(camera_feed ${SOURCE_FILES})
target_link_libraries( camera_feed ${OpenCV_LIBS} )
set_target_properties( camera_feed PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin" )
