# -----------------------------------------------------------------------------
# Validation
# -----------------------------------------------------------------------------

GOAL_COUNT := $(words $(MAKECMDGOALS))

ifneq ($(GOAL_COUNT),1)
    ifneq ($(GOAL_COUNT),0)
        $(error You cannot specify more than 1 target \
(got $(GOAL_COUNT): $(MAKECMDGOALS)))
    endif
endif

# -----------------------------------------------------------------------------
# Public Settings
# -----------------------------------------------------------------------------

PREFIX ?= /usr/local
CC ?= gcc

DEBUG ?= 0

# -----------------------------------------------------------------------------
# Private Settings
# -----------------------------------------------------------------------------

LIB_NAME = genc

INSTALL_INCLUDE = include/genc.h
INSTALL_DIR = $(PREFIX)/include/$(LIB_NAME)

DEBUG_FLAG =
ifeq ($(DEBUG),1)
    DEBUG_FLAG = -g
endif

# -----------------------------------------------------------------------------
# Build Flags
# -----------------------------------------------------------------------------

# ---------------------------------------------------------
# Demo Flags
# ---------------------------------------------------------

DEMO_CFLAGS_STD = -std=c99
DEMO_CFLAGS_DEBUG = $(DEBUG_FLAG)
DEMO_CFLAGS_OPTIMIZATION = -O0
DEMO_CFLAGS_WARN = -Wall
DEMO_CFLAGS_MAKE = -MMD -MP
DEMO_CFLAGS_INCLUDE = -Iinclude

ifeq ($(DEBUG),1)
    DEMO_CFLAGS_WARN = -Wall -Wpedantic -Wextra
endif

DEMO_CFLAGS = -c $(DEMO_CFLAGS_STD) $(DEMO_CFLAGS_INCLUDE) \
$(DEMO_CFLAGS_MAKE) $(DEMO_CFLAGS_WARN) $(DEMO_CFLAGS_DEBUG) \
$(DEMO_CFLAGS_OPTIMIZATION)

# -----------------------------------------------------------------------------
# Targets
# -----------------------------------------------------------------------------

.PHONY: all clean install uninstall

all: demo

# demo ------------------------------------------------------------------------

demo: build/demo.o
	$(CC) build/demo.o -o $@

build/demo.o: demo.c
	@mkdir -p $(dir $@)
	$(CC) $(DEMO_CFLAGS) demo.c -o $@

-include build/demo.d

# install ---------------------------------------------------------------------

install:
	@mkdir -p $(INSTALL_DIR)
	cp $(INSTALL_INCLUDE) $(INSTALL_DIR)/

# uninstall -------------------------------------------------------------------

uninstall:
	rm -rf $(INSTALL_DIR)

# clean -----------------------------------------------------------------------

clean:
	rm -rf build
	rm -f demo
	rm -f compile_commands.json
