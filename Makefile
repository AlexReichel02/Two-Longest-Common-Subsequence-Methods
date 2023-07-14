main_print: main.o LCSMethodOne.o LCSMethodTwo.o
	g++ -O3 -Wall -o $@ $^

main.o: main.cpp
	g++ -O3 -Wall -c $^

LCSMethodOne.o: LCSMethodOne.cpp
	g++ -O3 -Wall -c $^

LCSMethodTwo.o: LCSMethodTwo.cpp
	g++ -O3 -Wall -c $^

clean:
	rm -f *.o main_print