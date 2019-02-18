CC = gcc
CXXFLAGS = -O2 -std=c++14
CFLAGS = -O2
LDFLAGS = -lstdc++
OUT = primes
OBJDIR = obj
BINDIR = bin

all: directories $(OUT)

directories: $(OBJDIR) $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OUT): primes.o timemarker.o
	$(CC) $(OBJDIR)/primes.o $(OBJDIR)/timemarker.o -o $(BINDIR)/$(OUT) $(LDFLAGS)

primes.o: primes.cpp
	$(CC) -c primes.cpp $(CXXFLAGS) -o $(OBJDIR)/primes.o

timemarker.o: timemarker.cpp
	$(CC) -c timemarker.cpp $(CXXFLAGS) -o $(OBJDIR)/timemarker.o

