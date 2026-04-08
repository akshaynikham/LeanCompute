CC = gcc
CFLAGS = -Iinclude

SRC = src/main.c src/system_info.c src/detect_os_bitness.c src/system_info_init.c
OUT = leancompute

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
