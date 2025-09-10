CC ?= gcc
CXX ?= g++
CPP ?= g++
APP_NAME = stream_char_test
OBJFILES = stream_char_test.o
LIB_DIRS = .

all: $(APP_NAME)
$(APP_NAME): $(OBJFILES)
	$(CC) $^ -o $@ -L$(LIB_DIRS)
%.o: %.c
	$(CC) -c $^ -o $@ -g
clean:
	rm *.o  $(APP_NAME)
fresh:
	make clean
	make all
