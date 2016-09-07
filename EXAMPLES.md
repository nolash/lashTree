Example code
============

This is some sample code

# Simple add, remove and dump test

    #include <stdio.h>
    #include <stdlib.h>
    
    #include "../lash_tree3.h"
    #include "../lash_tree3_dump.h"

    typedef struct treeitem {
    	char *something;
    	lash_tree_key_t val;
    } treeitem;
    
    typedef struct treeitem2 {
    	lash_tree_key_t val;
    	char *something;
    } treeitem2;
    
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
    	
    	// if key is not passed, it uses the first position of the struct as the key pointer
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


### Output:

    'treetwo' size 0 (dump of both trees):
    'treeone' size 2 (dump of both trees):
    i: 0 v: 10
    i: 1 v: 20
    'treeone' size 1 (dump of specified tree):
    i: 0 v: 20

Sources for these examples are also to be found in the _tests_ subfolder
