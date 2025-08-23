CC = gcc
CFLAGS = -I../FreeRTOS-Kernel/include \
         -I../FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix \
         -I. \
         -Wall -Wextra -g

# Kernel sources
KERNEL_SRC = ../FreeRTOS-Kernel/tasks.c \
             ../FreeRTOS-Kernel/list.c \
             ../FreeRTOS-Kernel/queue.c \
             ../FreeRTOS-Kernel/timers.c \
             ../FreeRTOS-Kernel/event_groups.c \
             ../FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix/port.c \
             ../FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c \
             ../FreeRTOS-Kernel/portable/MemMang/heap_4.c

# Select demo (default = main.c)
DEMO ?= main.c
DEMO_NAME := $(basename $(notdir $(DEMO)))

# Build directory and target
BUILD_DIR = build
OBJS = $(KERNEL_SRC:%.c=$(BUILD_DIR)/%.o) $(BUILD_DIR)/$(DEMO:.c=.o)
TARGET = $(BUILD_DIR)/$(DEMO_NAME)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lpthread

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) FreeRTOS-Kernel