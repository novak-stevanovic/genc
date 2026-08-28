# =============================================================================
# PUBLIC
# =============================================================================

LIB := genc

PREFIX := /usr/local
PC_PREFIX := $(PREFIX)/lib/pkgconfig

CC := gcc

# ---------------------------------------------------------
# Demo
# ---------------------------------------------------------

DEMO_CFLAGS := -Iinclude -std=c99 -O0 -Wall -Wextra -Wpedantic -g

# =============================================================================
# PRIVATE
# =============================================================================

LIB_PC := $(LIB).pc
INSTALL_INCLUDE := include/genc.h

PC_INCLUDEDIR := $${prefix}/include
PC_NAME := $(LIB)
PC_DESCRIPTION := Generic data structures library
PC_VERSION := 1.0.0
PC_CFLAGS := -I$${includedir}/$(LIB)

# =============================================================================
# TARGETS
# =============================================================================

.PHONY: all install uninstall clean

all:

# ---------------------------------------------------------
# demo
# ---------------------------------------------------------

demo: demo.c
	$(CC) $(DEMO_CFLAGS) $< -o $@

# ---------------------------------------------------------
# pkgconf
# ---------------------------------------------------------

$(LIB_PC):
	@echo 'prefix=$(PREFIX)' > $@
	@echo 'includedir=$(PC_INCLUDEDIR)' >> $@
	@echo '' >> $@
	@echo 'Name: $(PC_NAME)' >> $@
	@echo 'Description: $(PC_DESCRIPTION)' >> $@
	@echo 'Version: $(PC_VERSION)' >> $@
	@echo 'Cflags: $(PC_CFLAGS)' >> $@

# ---------------------------------------------------------
# install
# ---------------------------------------------------------

install: $(LIB_PC)
	install -d $(PREFIX)/include/$(LIB)
	install -m 644 $(INSTALL_INCLUDE) $(PREFIX)/include/$(LIB)/
	install -d $(PC_PREFIX)
	install -m 644 $(LIB_PC) $(PC_PREFIX)/$(LIB_PC)

# ---------------------------------------------------------
# uninstall
# ---------------------------------------------------------

uninstall:
	rm -rf $(PREFIX)/include/$(LIB)
	rm -f $(PC_PREFIX)/$(LIB_PC)

# ---------------------------------------------------------
# clean
# ---------------------------------------------------------

clean:
	rm -f demo
	rm -f $(LIB_PC)
	rm -f compile_commands.json
	rm -f gdb.txt
