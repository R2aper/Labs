lib:
	g++ -c src/lib.cpp -o  obj/lib.o

prog1:
	g++ -c src/FromText.cpp -o obj/FromText.o
	g++ obj/FromText.o obj/lib.o -o prog1


prog2:
	g++ -c src/FromBin.cpp -o obj/FromBin.o
	g++ obj/FromBin.o obj/lib.o -o prog2

clean:
	rm prog1.exe
	rm prog2.exe
	rm obj/*.o	