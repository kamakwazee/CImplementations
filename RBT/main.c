#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"


int main(int argc, char** argv)
{

	if(argc < 2)
	{
		printf("Usage: %s [integers...]\n", argv[0]);
		return 1;
	}

	RBT tree = NULL;

	int nums[argc-1];
	int n;
	for(int i = 1; i < argc; i++)
	{

		n = atoi(argv[i]);
		if(n == 0 && strcmp(argv[i], "0") != 0)
		{
			printf("Usage: %s [integers...]\n", argv[0]);
			return 2;
		}
		nums[i-1] = n;

	}

	tree = insert(tree, nums[0]);
	for(int i = 1; i < argc-1; i++)
	{
		
		printf("ay %i\n", i);
		tree = insert(tree, nums[i]);
	}
	//tree = removeNode(tree, nums[2]);
	//printf("Traverse\n");
	printf("\n\n");
	dump(tree, 0, 2);
	printf("\n\n");
	Traverse(tree);
	dispose(tree);
	return 0;

}
