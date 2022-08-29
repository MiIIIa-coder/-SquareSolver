OBJECTS := main.o io.o solution.o compare.o testing.o
CC := g++

all: Sqr_Solv.exe run

Sqr_Solv.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o Sqr_Solv.exe

%.o : %.cpp
	$(CC) -c $< -o $@

clean:
	rm $(OBJECTS)

run:
	.\Sqr_Solv.exe
