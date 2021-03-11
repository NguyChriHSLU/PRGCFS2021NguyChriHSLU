#include <stdio.h>


int main(int argc, char *argv[] )
{
	if( argc != 3 ){
		// input is not valid
		printf("Usage:\n");
		printf("logicOperatiors Input 1 Input 2\n");
	}
	else
	{ 	// input is valid

		printf("Number of input arguments: %d\n", argc);
	
		for( int i = 0; i < argc; i++ )
		{
			printf("Argument %d was %s\n",i,  argv[i]);
		}	
		
	}
	return 0;
}
