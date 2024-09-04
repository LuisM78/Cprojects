# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = calculator

# Source files
SRCS = calculator.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
