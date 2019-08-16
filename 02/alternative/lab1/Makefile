CC = gcc
CXXFLAGS = -O2 -std=c++14
CFLAGS = -O2
LDFLAGS = -lstdc++.dll
DLL = complex.dll
LIBIMP = libcomplex.dll.a
OBJDIR = obj
BINDIR = bin

all: directories $(DLL)

directories: $(OBJDIR) $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

complex.o: complex.cpp
	$(CC) -c complex.cpp $(CXXFLAGS) -o $(OBJDIR)/complex.o

$(DLL): complex.o
	$(CC) -shared -o $(BINDIR)/$(DLL) $(OBJDIR)/complex.o $(LDFLAGS)
