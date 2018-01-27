BUILD_DIR = _build

OPENCV_INCLUDE=-I/usr/local/opt/opencv@2/include/
OPENCV_LIBS=-L/usr/local/opt/opencv@2/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dpm -lopencv_face -lopencv_photo -lopencv_fuzzy -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core
CC_FLAGS = -std=c99 $(OPENCV_INCLUDE)
CC_LDFLAGS = $(OPENCV_LIBS)

all:
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/operators operators.c $(CC_LDFLAGS)
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/normalize_rgb normalize_rgb.c $(CC_LDFLAGS)
