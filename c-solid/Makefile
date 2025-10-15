CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2 -Iinclude -Iinclude/presentation -Iinclude/infra -Iinclude/utils -Iinclude/domain
LDFLAGS :=

BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)

INFRA_SRCS := infra/io.c
UTILS_SRCS := utils/parse.c
PRESENTATION_SRCS := presentation/runner_array.c presentation/runner_range.c presentation/runner_strings.c
DOMAIN_SRCS := domain/linked_list_solution.c domain/return_smallest_solution.c domain/six_sided_solution.c domain/odd_numbers_solution.c domain/anagram_solution.c
MAIN_SRCS := main/linked_list_main.c main/return_smallest_main.c main/six_sided_main.c main/odd_numbers_main.c main/anagram_main.c

ALL_SRCS := $(INFRA_SRCS) $(UTILS_SRCS) $(PRESENTATION_SRCS) $(DOMAIN_SRCS) $(MAIN_SRCS)
ALL_OBJS := $(ALL_SRCS:%.c=$(BUILD_DIR)/%.o)

APPS := linked_list return_smallest six_sided odd_numbers anagram
TARGETS := $(APPS:%=$(BIN_DIR)/%)

all: $(TARGETS)

$(BIN_DIR)/linked_list: $(BUILD_DIR)/main/linked_list_main.o $(BUILD_DIR)/domain/linked_list_solution.o $(BUILD_DIR)/infra/io.o $(BUILD_DIR)/utils/parse.o $(BUILD_DIR)/presentation/runner_array.o
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)/return_smallest: $(BUILD_DIR)/main/return_smallest_main.o $(BUILD_DIR)/domain/return_smallest_solution.o $(BUILD_DIR)/infra/io.o $(BUILD_DIR)/utils/parse.o $(BUILD_DIR)/presentation/runner_array.o
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)/six_sided: $(BUILD_DIR)/main/six_sided_main.o $(BUILD_DIR)/domain/six_sided_solution.o $(BUILD_DIR)/infra/io.o $(BUILD_DIR)/utils/parse.o $(BUILD_DIR)/presentation/runner_array.o
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)/odd_numbers: $(BUILD_DIR)/main/odd_numbers_main.o $(BUILD_DIR)/domain/odd_numbers_solution.o $(BUILD_DIR)/infra/io.o $(BUILD_DIR)/utils/parse.o $(BUILD_DIR)/presentation/runner_range.o
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)/anagram: $(BUILD_DIR)/main/anagram_main.o $(BUILD_DIR)/domain/anagram_solution.o $(BUILD_DIR)/infra/io.o $(BUILD_DIR)/utils/parse.o $(BUILD_DIR)/presentation/runner_strings.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)


