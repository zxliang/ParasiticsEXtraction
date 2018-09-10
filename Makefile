CXX	:= g++
CFLAGS	:= -std=c++11

TARGET	:= parser

#all:
#	@echo $(TARGET)


#main.o: main.cpp
#	$(CXX) -c main.cpp $(CFLAGS)

$(TARGET): main.cpp
	$(CXX) -o $(TARGET) main.cpp $(CFLAGS)

.PHONY	: clean
clean:
	rm -f $(TARGET) main.o
