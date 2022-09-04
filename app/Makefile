CXX = g++
INCLUDE = lib
CXXFLAGS = -g3 -Wall -I$(INCLUDE) -std=c++20
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

utils.o: directorios src/utils.cpp
	$(CXX) $(CXXFLAGS) -c src/utils.cpp -o build/utils.o

compilador.o: directorios src/compilador.cpp
	$(CXX) $(CXXFLAGS) -c src/compilador.cpp -o build/compilador.o

monomio.o: directorios src/monomio.cpp
	$(CXX) $(CXXFLAGS) -c src/monomio.cpp -o build/monomio.o

polinomio.o: directorios src/polinomio.cpp
	$(CXX) $(CXXFLAGS) -c src/polinomio.cpp -o build/polinomio.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o utils.o compilador.o monomio.o polinomio.o
	$(CXX) $(CXXFLAGS) -o dist/programa \
	build/main.o build/utils.o build/compilador.o build/monomio.o build/polinomio.o \
	$(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all
