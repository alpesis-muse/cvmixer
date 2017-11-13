# ----------------------------------------------------------------------------

add_subdirectory (imgproc)

# ----------------------------------------------------------------------------

# image_read
add_executable (image_read image_read.cpp)
target_link_libraries (image_read ${OpenCV_LIBS})
