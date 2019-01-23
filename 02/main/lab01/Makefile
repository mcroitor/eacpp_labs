CC = gcc
CXXFLAGS = -O2 -std=c++14
CFLAGS = -O2
LDFLAGS = -lstdc++.dll
OUT = notebook
DLL = notebook.dll
LIBIMP = libnotebook.dll.a
OBJDIR = obj
BINDIR = bin

all: directories $(OUT)

directories: $(OBJDIR) $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OUT): $(DLL) main.o
	$(CC) $(OBJDIR)/main.o -o $(BINDIR)/$(OUT) $(LDFLAGS) -L$(BINDIR) -lnotebook.dll

entry.o: entry.cpp
	$(CC) -c entry.cpp $(CXXFLAGS) -o $(OBJDIR)/entry.o

notebook.o: notebook.cpp
	$(CC) -c notebook.cpp $(CXXFLAGS) -o $(OBJDIR)/notebook.o

$(DLL): entry.o notebook.o
	$(CC) -shared -o $(BINDIR)/$(DLL) $(OBJDIR)/notebook.o $(OBJDIR)/entry.o $(LDFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CXXFLAGS) -o $(OBJDIR)/main.o