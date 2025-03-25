CC ?= gcc
PKGCONFIG = pkg-config
CFLAGS = -g -Wall -Wextra $(shell $(PKGCONFIG) --cflags gtk4)
LIBS = $(shell $(PKGCONFIG) --libs gtk4)
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)

# Use full path to the project directory
PROJECT_DIR := $(shell pwd)

SRC_DIR = src
VIEWS_DIR = $(SRC_DIR)/views
INCLUDE_DIR = include
VIEWS_INCLUDE_DIR = $(INCLUDE_DIR)/views
UI_DIR = $(PROJECT_DIR)/ui

SRC = $(SRC_DIR)/journal_app.c \
      $(SRC_DIR)/journal_appwin.c \
      $(SRC_DIR)/main.c \
      $(VIEWS_DIR)/dashboard_view.c \
      $(VIEWS_DIR)/feed_view.c \
      $(VIEWS_DIR)/add_trade_view.c \
      $(VIEWS_DIR)/add_journal_view.c

BUILT_SRC = $(SRC_DIR)/resources.c

OBJS = $(BUILT_SRC:.c=.o) $(SRC:.c=.o)

all: journalapp.exe

# Modify resource generation
$(BUILT_SRC): $(SRC_DIR)/journalapp.gresource.xml $(UI_DIR)/window.ui
	$(GLIB_COMPILE_RESOURCES) $(SRC_DIR)/journalapp.gresource.xml \
		--target=$@ \
		--sourcedir=$(PROJECT_DIR) \
		--generate-source

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

journalapp.exe: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f $(BUILT_SRC) 
	rm -f $(OBJS) 
	rm -f journalapp.exe

.PHONY: all clean