BINFOLDER := bin/
INCFOLDER := inc/
SRCFOLDER := src/
OBJFOLDER := obj/

CC := gcc
CFLAGS := -Wall
FLAGS := -pthread

SRCFILES := $(wildcard $(SRCFOLDER)*.c)

all: $(SRCFILES:$(SRCFOLDER)%.c=$(OBJFOLDER)%.o)
	$(CC) $(CFLAGS) $(OBJFOLDER)*.o -o $(BINFOLDER)main $(FLAGS)

$(OBJFOLDER)%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./$(INCFOLDER) $(FLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJFOLDER)*
	rm -rf $(BINFOLDER)*

run:
		$(BINFOLDER)main
