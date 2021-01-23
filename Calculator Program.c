#include <stdio.h>
#include <stdlib.h>

int main() {
	
	printf("Calculator Program\n\n");
	
	float number1,number2;
	char symbol;
	
	//input
	scanf("%f%c%f",&number1,&symbol,&number2);
	
	//addition
	if(symbol=='+'){
		printf("%.2f + %.2f = %.2f",number1,number2,number1+number2);
	}
	
	//subtraction
	else if(symbol=='-'){
		printf("%.2f - %.2f = %.2f",number1,number2,number1-number2);
	}
	
	//multiplication
	else if(symbol=='*'){
		printf("%.2f * %.2f = %.2f",number1,number2,number1*number2);
	}
	
	//division
	else if(symbol=='/'){
		printf("%.2f / %.2f = %.2f",number1,number2,number1/number2);
	}
	
	printf("\n\n\n");
	
	return 0;
}
