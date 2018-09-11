CXX	:= g++
CFLAGS	:= -std=c++11

INC	:= -I ./include

TARGET	:= ./bin/myParser

all:	main.o parser.o $(TARGET)
#	@echo $(TARGET)

main.o: main.cpp
	$(CXX) $(INC) -c main.cpp $(CFLAGS)

parser.o: parser.cpp
	$(CXX) $(INC) -c parser.cpp $(CFLAGS)

$(TARGET): main.o parser.o
	$(CXX) -o $(TARGET) main.o parser.o $(CFLAGS)

.PHONY	: clean
clean:
	rm -f $(TARGET) main.o parser.o
