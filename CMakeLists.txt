#===============================================================================
# G L O B A L   P R O J E C T   C O N F I G U R A T I O N

cmake_minimum_required( VERSION 2.8 )

project( camera_feed )

if ( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE )
endif ( NOT CMAKE_BUILD_TYPE )

set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pthread -std=c++11" )
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -pthread -std=c++1 -O3" )

#===============================================================================
# C A T K I N   C O N F I G U R A T I O N

find_package( catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    message_generation
    message_runtime
    image_transport
    cv_bridge

)

find_package( OpenCV REQUIRED )

# Declare this project as a catkin package and export the necessary build flags
catkin_package(
    INCLUDE_DIRS src
    LIBRARIES
    CATKIN_DEPENDS roscpp std_msgs
    image_transport
    cv_bridge

)

#===============================================================================
# I N C L U D E   F I L E S

set( camera_feed_SRC_DIR "src" )

# Get all the files of the projects.
file( GLOB_RECURSE camera_feed_HDR_FILES "${camera_feed_SRC_DIR}/*.h" )
file( GLOB_RECURSE camera_feed_SRC_FILES
    "${camera_feed_SRC_DIR}/*.cc"
    "${camera_feed_SRC_DIR}/*.h"
    )

# Include all the directories where source can be found.
include_directories(
    ${camera_feed_SRC_DIR}
    ${catkin_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

#==========================================================================
# C R E A T E   E X E C U T A B L E

set( TARGET_NAME camera_feed_node )

# Create a CXX file from the given sources
add_executable( ${TARGET_NAME}
    ${camera_feed_HDR_FILES}
    ${camera_feed_SRC_FILES}
    )

target_link_libraries( ${TARGET_NAME}
    ${catkin_LIBRARIES}
    ${OpenCV_LIBS}
    )
