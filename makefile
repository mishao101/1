book: task3.o 
	gcc -o book task3.o 

task3.o: task3.c
	gcc -c task3.c
clean: 
	rm  book task3.o 

