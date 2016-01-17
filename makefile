# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall 
LFLAGS  = -L/usr/lib

# All Targets
all: client

# Tool invocations
# Executable "cyber" depends on the files cyber.o and run.o.
cyber: bin/cyberpc.o bin/cyberworm.o bin/cyberdns.o bin/cyberexpert.o bin/main.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	$(CC) $(CFLAGS) -o bin/cyber bin/cyberpc.o bin/cyberworm.o bin/cyberdns.o bin/cyberexpert.o bin/main.o $(LFLAGS)
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/cyberdns.o: src/cyberdns.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberdns.o src/cyberdns.cpp
bin/cyberexpert.o: src/cyberexpert.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberexpert.o src/cyberexpert.cpp
bin/cyberworm.o: src/cyberworm.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberworm.o src/cyberworm.cpp
bin/cyberpc.o: src/cyberpc.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberpc.o src/cyberpc.cpp
bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/main.o src/main.cpp

#Clean the build directory
clean: 
	rm -f bin/*
