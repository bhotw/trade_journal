CC ?= gcc
PKGCONFIG = pkg-config
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4)
LIBS = $(shell $(PKGCONFIG) --libs gtk4)
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)

SRC_DIR = src
UI_DIR = ui
SRC = $(SRC_DIR)/journal_app.c $(SRC_DIR)/journal_appwin.c $(SRC_DIR)/main.c
BUILT_SRC = $(SRC_DIR)/resources.c

OBJS = $(BUILT_SRC:.c=.o) $(SRC:.c=.o)

all: journalapp.exe

$(SRC_DIR)/resources.c: $(SRC_DIR)/journalapp.gresource.xml $(UI_DIR)/window.ui
	$(GLIB_COMPILE_RESOURCES) $(SRC_DIR)/journalapp.gresource.xml --target=$@ --sourcedir=$(SRC_DIR) --sourcedir=$(RSC_DIR) --generate-source

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

journalapp.exe: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

clean:
	del /Q $(BUILT_SRC) $(OBJS) journalapp.exe
