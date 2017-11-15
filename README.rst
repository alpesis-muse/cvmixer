##############################################################################
CV Mixer
##############################################################################

Prequisites

- OpenCV

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

==============================================================================
Getting Started
==============================================================================


::

    $ mkdir _build && cd _build
    $ cmake -DOpenCV_ROOT_DIR=<path/to/opencv> ..
    $ make
