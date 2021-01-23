#include <stdio.h>
#include <stdlib.h>

int main(){	
printf("*****Drawing Square Program*****\t\t\tBy Gorkem Yelken.");
printf("Description: This program draws a square with a square hole in it.\n\n");

int outer,inner,margin,i,j,k;

//Outer width
printf("Outer width = ");
scanf("%d",&outer);

//Inner width
printf("Inner width = ");
scanf("%d",&inner);

//Check outer width and inner width are odd numbers
//if not odd numbers
if(outer % 2 == 0 || inner % 2 == 0){
	printf("Warning!!! Outer width or inner width cannot be even numbers.\nThe program quits...");
}
//if odd numbers
else{
//Margin
printf("Margin = ");
scanf("%d",&margin);

//"*" from left and right
int formula = (outer-inner)/2;

//margin from top
for(k=1; k<=margin; k++){
	   printf("\n");}

//number of lines
for(i=1; i<=outer; i++)  
   {
   	
   	//margin from left
   	for(k=1; k<=margin; k++){
	   printf("  ");}
	
	//"*" and " " in (j)th row of line (i)
    for(j=1; j<=outer; j++)
       {
       	
       	//print of "*"
        if(i==1 || i <= formula || i > outer-formula || j==1 || j <= formula || j > outer-formula) 
        printf("* ");
        
        //print of " "
        else
        printf("  ");
       }
       
    //new line
    printf("\n");
}

//margin from bottom
for(k=1; k<=margin; k++){
	printf("\n");}
}
    return 0;
}


