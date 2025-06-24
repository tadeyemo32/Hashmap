CC = clang
CFLAGS = -Wall -std=c99
SRC = main.c
OUT = main


$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) 


clean:
	rm -f $(OUT)