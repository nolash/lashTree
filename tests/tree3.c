#include <stdio.h>
#include <stdlib.h>

#include "liblash/lash_tree3.h"
#include "liblash/lash_tree3_dump.h"

typedef struct treeitem {
	char *something;
	lash_tree_key_t val;
} treeitem;

typedef struct treeitem2 {
	lash_tree_key_t val;
	char *something;
} treeitem2;

// Simple push and pull  test

int main() {
	lash_tree_t *tree = NULL;
	lash_tree_t *tree2 = NULL;
	treeitem passitem;
	treeitem2 passitem2;
	void *resultitem;
	
	char teststring[255];
	char teststring2[255];
	
	tree = lash_treeInit(tree, 10);
	if (tree == NULL)
		return 1;

	tree2 = lash_treeInit(tree2, 10);
	if (tree2 == NULL)
		return 1;
		
	lash_treeDumpInit(2);
	lash_treeDumpAdd(tree2, "treetwo");
	lash_treeDumpAdd(tree, "treeone");
	
	sprintf(teststring, "one");
	sprintf(teststring2, "two");
	
	passitem.val = 20;
	passitem.something = teststring2;
	
	passitem2.val = 10;
	passitem2.something = teststring;
	
	lash_treePush(tree, &passitem2, NULL);
	lash_treePush(tree, &passitem, &passitem.val);
	
	lash_treeDump(NULL, "dump of both trees");
	
	lash_treeShift(tree, &resultitem);

	lash_treeDump(tree, "dump of specified tree");

	lash_treeDumpFree();
	
	lash_treeFree(tree);
	lash_treeFree(tree2);
	
	return 0;
}
