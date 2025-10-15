CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2

BUILD_DIR := build
BIN := $(BUILD_DIR)/app

SRCS := main.c io.c solution.c
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)

.PHONY: all exec clean

all: $(BIN) exec

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

exec: $(BIN)
	$(BIN)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all

