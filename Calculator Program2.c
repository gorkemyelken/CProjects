#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// atof function
float my_atof(char *value)
{
    float result= 0.0;
    int len = strlen(value);
    int dotPosition = 0;
	int i;
    for (i = 0; i < len; i++)
    {
        if (value[i] == '.')
        {
          dotPosition = len - i  - 1;
        }
        else
        {
          result = result * 10.0 + (value[i]-'0');
        }
      }

      while (dotPosition--)
      {
        result /= 10.0;
      }

    return result;
}

float calculate(float value1f, char operatorr, float value2f, unsigned short *flagptr)
{

    float result;
    // addition
    if(operatorr == '+')
    {
	result = value1f + value2f;
    }
    // subtraction
    else if(operatorr == '-')
    {
	result = value1f - value2f;
    }
    // multiplication
    else if(operatorr == '*')
    {
	result = value1f * value2f;
    }
    // division
    else if(operatorr == '/')
    {
	if (value2f != 0)
                    result = (float)value1f/value2f;
                else
                    {
                       printf("Divide by zero error. ");
                       *flagptr = 0;
                    }
    }
    return result;
}


int main(){
	char *value1;
    char *value2;
	float value1f,value2f;
    char operatorr;
    int k;
    unsigned short flag = 1;   // flag which indicates any error in input
 	unsigned short *flagptr = &flag; // pointer to the above flag
    printf("*****Calculator Program*****\t\t\tBy Gorkem Yelken.\n\n\n");
	// Descriptions
	printf("Decription : It will take the characters in the string and do the math operations.\n\n");
	// The string will be read from user input. The maximum string length is 250.
	char operation[251];
    printf("Operation : ");
    gets(operation);
    for (k = 0; k < strlen(operation); k++) { // check operator
        if (operation[k] == '+' || operation[k] == '-' || operation[k] == '*' || operation[k] == '/' ) {
        operatorr = operation[k];
        break;
        } 
    }
    if (operatorr == '+' || operatorr == '-' || operatorr == '*' || operatorr == '/' ) { // separate values
    if(operation[k] == '+'){
    	value1=strtok(operation,"+");
    	value2=strtok(NULL,"+");
	}
    else if(operation[k] == '-'){
    	value1=strtok(operation,"-");
    	value2=strtok(NULL,"-");
	}
	else if(operation[k] == '*'){
    	value1=strtok(operation,"*");
    	value2=strtok(NULL,"*");
	}
	else if(operation[k] == '/'){
    	value1=strtok(operation,"/");
    	value2=strtok(NULL,"/");
	}
	value1f = my_atof(value1); // string to float
    value2f = my_atof(value2); // string to float
 	float result;
 	result = calculate(value1f, operatorr, value2f, flagptr);
 	if (flag == 1){ // no error in input
    	printf("Result = %.2f\n", result);
    }
 	else{ // error in input
    	printf("Undefined result.\n");
	}
	}
	else{ // if it includes letters, special characters etc.
		printf("Warning!!! It includes letters, special characters etc.");
	}
    
}
