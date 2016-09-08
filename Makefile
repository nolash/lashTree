INCLUDE = ./include
LIBS = ./
SHAREDOBJECTDIR = ./
TESTDIR = ./tests/

all: shared obj test

shared:
	$(CC) -Wall -I$(INCLUDE) -o lash_tree_lib.o -fPIC -c lash_tree3.c
	$(CC) -Wall -I$(INCLUDE) -o lash_tree_dump_lib.o -fPIC -c lash_tree3_dump.c
	$(CC) -shared -Wl,-soname,liblash.so.0 -o $(SHAREDOBJECTDIR)liblash.so lash_tree_lib.o lash_tree_dump_lib.o
	
obj:
	$(CC) -Wall -I$(INCLUDE)  -g -o lash_tree3.o -c lash_tree3.c
	$(CC) -Wall -I$(INCLUDE)  -g -o lash_tree3_dump.o -c lash_tree3_dump.c		

test:
	$(CC) -Wall -I$(INCLUDE)  -g -o $(TESTDIR)tree3.o -c $(TESTDIR)tree3.c
	$(CC) -Wall -I$(INCLUDE) -L$(LIBS) -o $(TESTDIR)tree3_bin $(TESTDIR)tree3.o lash_tree3.o lash_tree3_dump.o
	
	$(CC) -Wall -I$(INCLUDE)  -g -o $(TESTDIR)tree3_console.o -c $(TESTDIR)tree3_console.c
	$(CC) -Wall -I$(INCLUDE) -L$(LIBS) -o $(TESTDIR)tree3_console_bin $(TESTDIR)tree3_console.o lash_tree3_dump.o lash_tree3.o 
	
clean:
	rm -rf *.o tests/*_bin *.so
