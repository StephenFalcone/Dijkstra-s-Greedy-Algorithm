main: dijkstra.o
	g++ -o main dijkstra.o
dijkstra.o: dijkstra.cpp
	g++ -c dijkstra.cpp
  
  	
clean:
	rm *.o