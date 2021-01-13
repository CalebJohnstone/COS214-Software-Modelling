a: *.h *.cpp
	g++ *.cpp -o main

comp:
	g++ -std=c++17 *.cpp -o main
	
comprun:
	g++ -std=c++17 *.cpp -o main
	make run

run:
	./main 501561 427 first
	
clean:
	rm *.o main

tar: 
	tar -cvz *.h *.cpp makefile -f Upload.tar