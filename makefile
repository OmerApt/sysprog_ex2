
all: my_graph my_Knapsack

my_knapsack.o: my_knapsack.c
	gcc -Wall -g -c my_knapsack.c

my_mat.o: my_mat.c my_mat.h
	gcc -Wall -g -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -g -c my_graph.c

my_graph: my_graph.o my_mat.o 
	gcc -Wall -g -o my_graph my_mat.o my_graph.o

my_Knapsack: my_knapsack.o 
	gcc -Wall -g -o my_Knapsack my_knapsack.o

clean: 
	rm -f *.a *.o *.so my_graph my_Knapsack
