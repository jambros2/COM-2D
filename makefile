CXXFLAGS := -O3 -g -Wall
SRCS := $(wildcard src/*.cpp)
LIB_OBJS := $(patsubst src/%.cpp, obj/%.o, $(SRCS))

LIBS = lib/libshape.a
TARGET = bin/com

all: $(LIBS) $(TARGET)

$(TARGET): obj/com.o $(LIBS)
	$(CXX) -o $@ $^

obj/com.o: driver/com.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

lib/libshape.a: $(LIB_OBJS)
	ar -rv $@ $^

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f bin/* obj/* lib/*
