INCLUDE = ./include
SCR = ./scr
PROGRAM = ./program

all: lisrun
	
lisrun:
	g++ $(SCR)/Sorting.cpp $(SCR)/main.cpp -I $(INCLUDE) -o $(PROGRAM)/teste

run:
	start $(PROGRAM)/teste

clean:
	rm $(PROGRAM)/teste