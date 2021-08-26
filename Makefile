CC := gcc
CFLAGS := -c
LDFLAGS := -lpthread

TASK_1 := test
TASK_2 := glob_number
TASK_3 := thread_shop

.PHONY: all $(TASK_1) $(TASK_2) $(TASK_3) clean

all: $(TASK_1) $(TASK_2) $(TASK_3) 

debug: CFLAGS += -g 
debug: all

$(TASK_1): $(TASK_1).c
	$(CC) $(CFLAGS) $(TASK_1).c -o $(TASK_1) $(LDFLAGS) 

$(TASK_2): $(TASK_2).c
	$(CC) $(CFLAGS) $(TASK_2).c -o $(TASK_2) $(LDFLAGS)

$(TASK_3):
	cd $(TASK_3) && make

clean:
	rm -rf $(TASK_1) $(TASK_2) && cd $(TASK_3)/ && make clean
