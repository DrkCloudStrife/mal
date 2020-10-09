CXX=g++

LD=$(CXX)
AR=ar

DEBUG=-ggdb
CXXFLAGS=-O3 -Wall $(DEBUG) -std=c++11

LIBSOURCES=Reader.cpp
LIBOBJS=$(LIBSOURCES:%.cpp=%.o)

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

$(TARGETS): %: %.o libmal.a
	$(LD) $^ -o $@

libmal.a: $(LIBOBJS)
	$(AR) rcs $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGETS) .deps mal

-include .deps