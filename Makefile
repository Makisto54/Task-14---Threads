CC := gcc
CFLAGS := -c
LDFLAGS := -lpthread

.PHONY: all test glob_number clean

all: test glob_number

debug: CFLAGS += -g 
debug: all

test: test.c
	$(CC) $(CFLAGS) test.c -o test $(LDFLAGS) 

glob_number: glob_number.c
	$(CC) $(CFLAGS) glob_number.c -o glob_number $(LDFLAGS)

clean:
	rm -rf test glob_number