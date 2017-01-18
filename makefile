CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

all: testocv.cpp
	g++ testocv.cpp -o prgm.exec $(CFLAGS) $(LIBS) 
