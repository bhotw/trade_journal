CC = gcc
CFLAGS = `pkg-config --cflags gtk4` -Iinclude
LIBS = `pkg-config --libs gtk4`
SRC = src/example-4.c
OBJ = $(SRC:.c=.o)
OUT = journal_app.exe
UI = src/builder.ui

all: $(OUT) $(UI)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(LIBS) -mwindows

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(UI):
	cp $(UI) $(OUT)

clean:
	rm -f $(OBJ) $(OUT)

