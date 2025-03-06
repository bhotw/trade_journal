CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -Iinclude
LIBS = `pkg-config --libs gtk+-3.0`
SRC = src/main.c src/ui.c src/storage.c
OUT = journal_app.exe

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LIBS)

