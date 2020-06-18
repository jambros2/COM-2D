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

# Tests

TEST_TARGETS= circleTest rectangleTest triangleTest semiCircleTest multiShapeTest parserTest

test: $(LIBS) $(TEST_TARGETS) $(addprefix run-,$(TEST_TARGETS))

BOOST_TEST_LIBS = boost_unit_test_framework

%: testing/%.cpp
	$(CXX) -o $@ $^ -l$(BOOST_TEST_LIBS) $(LIBS)
	mv $@ bin

run-%: bin/%
	-./$^ --log_level=test_suite

clean:
	rm -f bin/* obj/* lib/*
