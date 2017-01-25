CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

all: exercise1.2 chap2 chap3

exercise1.2: exercise1.2.cpp
	g++ exercise1.2.cpp -o exercise1.2.exec -g $(CFLAGS) $(LIBS) 

chap2: chap2.cpp
	g++ chap2.cpp -o chap2.exec -g $(CFLAGS) $(LIBS) 

chap3: chap3.cpp
	g++ chap3.cpp -o chap3.exec -g $(CFLAGS) $(LIBS) 
