cmake_minimum_required (VERSION 2.8)

# ----------------------------------------------------------------------------
# project

project (CVMIXER)


# ----------------------------------------------------------------------------
# cmake module

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include (OpenCVConfig)


include_directories (${OpenCV_INCLUDE_DIRS})


# ----------------------------------------------------------------------------
# subdirectoires

add_subdirectory (cvmixer)
