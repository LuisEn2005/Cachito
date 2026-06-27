CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = cachito
OBJ = main.o scenes.o cup.o screen/createjoin.o screen/gameplay.o \
			screen/mainmenu.o screen/options.o \
			RaylibTools/utils/rng.o \
			RaylibTools/utils/text.o \
			RaylibTools/buttons/button.o \
			RaylibTools/buttons/textbutton.o \
			RaylibTools/buttons/texturebutton.o 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
