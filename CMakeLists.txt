cmake_minimum_required (VERSION 2.8)

# ----------------------------------------------------------------------------

project (CVMIXER)


# ----------------------------------------------------------------------------

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")


find_package (OpenCV REQUIRED)

# ----------------------------------------------------------------------------

add_subdirectory (cvmixer)

