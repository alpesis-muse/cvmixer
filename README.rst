##############################################################################
CV Mixer
##############################################################################

Prequisites

- Ubuntu 14.04
- OpenCV 2.4 (CUDA support)

OpenCV Installation:

::

    $ git clone https://github.com/opencv/opencv
    $ cd opencv
    $ mkdir _build
    # ref: https://www.learnopencv.com/install-opencv3-on-ubuntu/

    # config cmake
    $ cp /path/to/opencv/_build/OpenCVConfig.cmake /path/to/cmake
    $ cp /path/to/opencv/_build/OpenCVModules.cmake /path/to/cmake
    $ export OpenCV3_DIR=/path/to/opencv
    # export OpenCV2_DIR=/path/to/opencv2

==============================================================================
Getting Started
==============================================================================

How it runs

::

    $ mkdir _build && cd _build
    $ cmake ..
    $ make
