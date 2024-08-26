CC = gcc

SRC_DIR = .
BUILD_DIR = build
INCLUDE_DIR = include

TARGET = $(BUILD_DIR)/termcolor

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/termcolor.c

CFLAGS = -Wall -Wextra -Wpedantic -Wformat -Wnull-dereference -Wuninitialized -fstack-protector-all -g -I$(INCLUDE_DIR)

all: $(TARGET)

$(TARGET): $(SRCS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all
