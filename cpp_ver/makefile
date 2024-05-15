CXX = g++
CXXFLAGS = -Wall
EXE = bin/play1 bin/play bin/create1 bin/create_set bin/create_jgraph bin/make_move

all: $(EXE)

bin/create1: src/create1.cpp src/Generator.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/create_set: src/create_set.cpp src/Generator.cpp 
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/play1: src/play1.cpp src/ColorSort.cpp 
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/play: src/play.cpp src/ColorSort.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/create_jgraph: src/create_jgraph.cpp src/ColorSort.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/make_move: src/make_move.cpp src/ColorSort.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f bin/*
