# ----------------------------------------------------------------------------
# executable

# smoothing
add_executable (smoothing smoothing.cpp)
target_link_libraries (smoothing ${OpenCV_LIBS})

# smoothing_gpu
add_executable (smoothing_gpu smoothing_gpu.cpp)
target_link_libraries (smoothing_gpu ${OpenCV_LIBS})
