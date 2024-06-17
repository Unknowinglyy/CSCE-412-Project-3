# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRCS = main.cpp request.cpp webserver.cpp loadbalancer.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = load

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)