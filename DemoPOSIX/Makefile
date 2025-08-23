CC = gcc
CFLAGS = -I../FreeRTOS-Kernel/include \
         -I../FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix \
         -I. \
         -Wall -Wextra -g

SRC = main.c \
      ../FreeRTOS-Kernel/tasks.c \
      ../FreeRTOS-Kernel/list.c \
      ../FreeRTOS-Kernel/queue.c \
      ../FreeRTOS-Kernel/timers.c \
      ../FreeRTOS-Kernel/event_groups.c \
      ../FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix/port.c \
      ../FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c \
      ../FreeRTOS-Kernel/portable/MemMang/heap_4.c

# Build directory
BUILD_DIR = build
OBJS = $(SRC:%.c=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/freertos_demo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lpthread

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
