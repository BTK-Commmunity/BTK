CC ?= gcc

SRCDIR = src
BUILDDIR ?= build


CFLAGS ?= -Wall -Wextra `pkg-config --cflags glfw3` -std=c99 -I$(SRCDIR)/external/
LDFLAGS = `pkg-config --libs --static glfw3` -lGL



SRCS = $(wildcard $(SRCDIR)/*.c)
SRCS += $(wildcard $(SRCDIR)/external/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

LIBNAME = libbtk

LIBTYPE ?= static

ifeq ($(LIBTYPE), static)
    TARGET = $(BUILDDIR)/$(LIBNAME).a
    ARFLAGS = rcs
    BUILD_CMD = ar $(ARFLAGS) $(TARGET) $(OBJS)
else ifeq ($(LIBTYPE), shared)
    TARGET = $(BUILDDIR)/$(LIBNAME).so
    CFLAGS += -fPIC
    LDFLAGS += -shared
    BUILD_CMD = $(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)
endif

all: $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJS)
	$(BUILD_CMD)


clean:
	rm -rf $(BUILDDIR)


install: $(TARGET)
	mkdir -p /usr/local/include/btk/
	cp $(TARGET) /usr/local/lib/
	cp $(wildcard $(SRCDIR)/*.h) /usr/local/include/btk/

uninstall:
	rm -f /usr/local/lib/$(LIBNAME).*
	rm -rf /usr/local/include/btk
