
CXXFLAGS = -O3 -g -Wall

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^
