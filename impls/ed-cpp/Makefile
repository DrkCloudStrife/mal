CXX=g++

LD=$(CXX)
AR=ar

DEBUG=-ggdb
CXXFLAGS=-O3 -Wall $(DEBUG) -std=c++11

MAINS=$(wildcard step*.cpp)
TARGETS=$(MAINS:%.cpp=%)

.PHONY:	all clean

.SUFFIXES: .cpp .o

all: $(TARGETS)

dist: mal

mal: stepA_mal
	cp $< $@

.deps: *.cpp *.h
	$(CXX) $(CXXFLAGS) -MM *.cpp > .deps

$(TARGETS): %: %.o
	$(LD) $^ -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGETS) .deps mal

-include .deps