#include <stdio.h>
#include <stdlib.h>

int main() {
	
	printf("Drawing a Triangle Program\n\n");
	
	int i,j,k,z,outer_space = 3,inner_space = 0;
	
	//number of lines
	for(i=0;i<4;i++){
		
		//number of outer space
		for(j=0;j<outer_space;j++){
			printf(" ");
		}
		//left edge
		printf("/");
		
		//number of inner space
		for(j=0;j<inner_space;j++){
			printf(" ");
		}
		//right edge
		printf("\\");
		printf("\n");
		
		outer_space--;
		inner_space+=2;
}
	
	//base
	for(k=1;k<9;k++){
		printf("-");
	}
	
	printf("\n\n\n");
	printf("By Gorkem Yelken.\n");
	
	
	return 0;
}
