PROJECT_NAME     := epsdk_example_blinky
TARGETS          := nrf52840_xxaa
OUTPUT_DIRECTORY := _build
BOARD_TYPE       := DBOARD_AGORA

SDK_ROOT := ../nrf_sdk_17_1_condensed
PROJ_ROOT := ../

$(OUTPUT_DIRECTORY)/nrf52840_xxaa.out: \
  LINKER_SCRIPT  := ep_blinky_gcc_nrf52.ld

# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(SDK_ROOT)/components/boards/boards.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(SDK_ROOT)/components/libraries/bsp/bsp.c \
  $(SDK_ROOT)/components/libraries/experimental_section_vars/nrf_section_iter.c \
  $(SDK_ROOT)/components/libraries/fifo/app_fifo.c \
  $(SDK_ROOT)/components/libraries/libuarte/nrf_libuarte_async.c \
  $(SDK_ROOT)/components/libraries/libuarte/nrf_libuarte_drv.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(SDK_ROOT)/components/libraries/memobj/nrf_memobj.c \
  $(SDK_ROOT)/components/libraries/queue/nrf_queue.c \
  $(SDK_ROOT)/components/libraries/scheduler/app_scheduler.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
  $(SDK_ROOT)/components/libraries/timer/app_timer_freertos.c \
  $(SDK_ROOT)/components/libraries/uart/retarget.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/freertos/source/list.c \
  $(SDK_ROOT)/external/freertos/source/portable/MemMang/heap_4.c \
  $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52/port_cmsis.c \
  $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52/port_cmsis_systick.c \
  $(SDK_ROOT)/external/freertos/portable/GCC/nrf52/port.c \
  $(SDK_ROOT)/external/freertos/source/queue.c \
  $(SDK_ROOT)/external/freertos/source/stream_buffer.c \
  $(SDK_ROOT)/external/freertos/source/tasks.c \
  $(SDK_ROOT)/external/freertos/source/timers.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_clock.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_clock.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_ppi.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_rtc.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_saadc.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_timer.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_wdt.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52840.c \
  
# Required Embedded Planet Source Files
SRC_FILES += \
  $(PROJ_ROOT)/source/main.c \

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/components/libraries/atomic \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/bsp \
  $(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/components/libraries/experimental_task_manager \
  $(SDK_ROOT)/components/libraries/fifo \
  $(SDK_ROOT)/components/libraries/fstorage \
  $(SDK_ROOT)/components/libraries/gpiote \
  $(SDK_ROOT)/components/libraries/hardfault \
  $(SDK_ROOT)/components/libraries/libuarte \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/components/libraries/pwm \
  $(SDK_ROOT)/components/libraries/queue \
  $(SDK_ROOT)/components/libraries/scheduler \
  $(SDK_ROOT)/components/libraries/strerror \
  $(SDK_ROOT)/components/libraries/timer \
  $(SDK_ROOT)/components/libraries/uart \
  $(SDK_ROOT)/components/libraries/util \
  $(SDK_ROOT)/components/softdevice/s140/headers \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/external/fprintf \
  $(SDK_ROOT)/external/freertos/portable/CMSIS/nrf52 \
  $(SDK_ROOT)/external/freertos/portable/GCC/nrf52 \
  $(SDK_ROOT)/external/freertos/source/include \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/integration/nrfx/legacy \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/modules/nrfx/mdk \

# Required Embedded Planet Source Files
INC_FOLDERS += \
  $(PROJ_ROOT)/config \
  $(PROJ_ROOT)/source \
  $(PROJ_ROOT)/libFileHeaders/epBSPHeaders \
  $(PROJ_ROOT)/libFileHeaders/epUtilityHeaders \

# Libraries needed
LIB_FILES += \
  $(PROJ_ROOT)/libFiles/epBlinkyLibrary.a \

# Optimization flags
OPT = -O2 -gdwarf-4
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -$(BOARD_TYPE)
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -DFREERTOS
CFLAGS += -DNDEBUG
CFLAGS += -DNRF52840_XXAA
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums

# C++ flags common to all targets
CXXFLAGS += $(OPT)
# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -$(BOARD_TYPE)
ASMFLAGS += -DFREERTOS
ASMFLAGS += -DNDEBUG
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52840_XXAA

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# printf floats
LDFLAGS += -u _printf_float
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# memory stats flag
LDFLAGS += -Wl,--print-memory-usage
# use newlib in nano version
LDFLAGS += --specs=nano.specs

nrf52840_xxaa: CFLAGS += -D__HEAP_SIZE=8192
nrf52840_xxaa: CFLAGS += -D__STACK_SIZE=8192
nrf52840_xxaa: ASMFLAGS += -D__HEAP_SIZE=8192
nrf52840_xxaa: ASMFLAGS += -D__STACK_SIZE=8192

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys
# Add in math library
LIB_FILES += -lm

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc

include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))