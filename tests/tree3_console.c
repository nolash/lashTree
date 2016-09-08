#include <stdlib.h>
#include <stdio.h>

#include "liblash/lash_tree3.h"
#include "liblash/lash_tree3_dump.h"

// commands
// p = push (will ask for value)
// s = shift
// d = toggle dump
// q = quit

typedef struct teststructure {
	lash_tree_key_t val;
	char *nothing;
} teststructure;

int main(int argc, char **argv) {
	int run = 1;
	int dump = 1;
	char buf[1024];
	int pushes = 0;
	
	lash_tree_t *tree = NULL;
	tree = lash_treeInit(tree, 100);
	if (tree == NULL)
		return 1;
	
	teststructure *ts = (teststructure*)malloc(sizeof(teststructure)*1000);
	if (ts == NULL)
		return 1;
		
	teststructure *result;
		
	lash_treeDumpInit(1);
	lash_treeDumpAdd(tree, "tree");
	
	while (run) {
		char cmd;
		long int val1 = -1;
		unsigned int pos = 0;
		printf(">> ");
		fflush(stdout);
		fgets(buf, 1024, stdin);
		sscanf(buf, "%c", &cmd);
		
		switch(cmd) {
			case 'p':
				printf("value: ");
				fflush(stdout);
				fgets(buf, 1024, stdin);
				sscanf(buf, "%li", &val1);
				if (val1 != -1) {
					(ts+pushes)->val = val1;
					pos = lash_treePush(tree, (ts+pushes), NULL);
					printf("pos: %u\n", pos);
					pushes++;
				}
				break;
			case 's':
				if (tree->count == 0) {
					printf("Nothing to shift\n");
				} else {
					lash_treeShift(tree, (void**)&result);
					printf("val1: %li, val2: %p\n", result->val, result);
				}
				break;
			case 'd':
				dump ^= 1;
				printf(dump ? "(Dump on)\n" : "(Dump off)\n");
				break;
			case 'q':
				run = 0;
				break;
		}
		
		if (dump)
			lash_treeDump(tree, NULL);
	}
	return 0;
}
