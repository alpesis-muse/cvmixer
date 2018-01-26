BUILD_DIR = _build

CC_FLAGS = -std=c99
CC_LDFLAGS = `pkg-config --cflags --libs opencv`

all:
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/operators operators.c $(CC_LDFLAGS)
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/normalize_rgb normalize_rgb.c $(CC_LDFLAGS)
