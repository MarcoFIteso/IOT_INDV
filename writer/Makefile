CC ?= gcc
CXX ?= g++
CPP ?= g++
APP_NAME1= writer
APP_NAME2 = reader
OBJ1 = writer.o
OBJ2 = reader.o
LIB_DIRS = .

all: $(APP_NAME1) $(APP_NAME2)
$(APP_NAME1): $(OBJ1)
	$(CC) $^ -o $@ -L$(LIB_DIRS)
%.o: %.c
	$(CC) -c $^ -o $@ -g
clean:
	rm *.o  $(APP_NAME1)	
$(APP_NAME2): $(OBJ2)
	$(CC) $^ -o $@ -L$(LIB_DIRS)	
%.o: %.c
	$(CC) -c $^ -o $@ -g
clean:
	rm *.o  $(APP_NAME2)
fresh:
	make clean
	make all
