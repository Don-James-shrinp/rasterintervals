OS := $(shell uname)
ifeq ($(OS),Darwin)
        #CC      = /usr/local/opt/llvm/bin/clang++
        #CFLAGS  = -O3 -mavx -std=c++14 -w -march=native -I/usr/local/opt/llvm/include -fopenmp 
        #LDFLAGS = -L/usr/local/opt/llvm/lib
	CC      = g++
        CFLAGS  = -O3 -g -mavx -std=c++14 -w -march=native -I/usr/local/opt/libomp/include -fopenmp
        LDFLAGS = -L/usr/local/opt/libomp/lib
else
        CC      = g++
        CFLAGS  = -O3 -std=c++14 -g -w -fopenmp 
        LDFLAGS =
endif

SOURCE = ./transfer.cpp
EXE = transfer	

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(SOURCE) -o $(EXE) $(LDADD)

debug: $(OBJECTS)
	$(CC) -g $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(SOURCE) -o $(EXE) $(LDADD)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.cc.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ./*.o
	rm -rf $(EXE)
