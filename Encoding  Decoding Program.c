#include <stdio.h>
#include <stdlib.h>

/*
In this program;
number % 3 = 0 also ASCII(number) % 3 = 0;
number % 3 = 1 also ASCII(number) % 3 = 1;
number % 3 = 2 also ASCII(number) % 3 = 2;

Type casting is not required because it is.
*/

// Number of digits
int counter(char number[15]){
    int i;
    for(i=0; number[i]!='\0'; ++i);
       return i;
}

// Encoding
int encoding(char number[5]){
	int i,j;
	// For each digit
	for(i=0;i<5;i++){
		// Digit % 3 = 1
		if(number[i]%3==1){
			for(j=0;j<2;j++){
				printf("%c",number[i]);
			}
		}
		// Digit % 3 = 2
		else if(number[i]%3==2){
			for(j=0;j<3;j++){
				printf("%c",number[i]);
			}
		}
		// Digit % 3 = 0
		else if(number[i]%3==0){
			for(j=0;j<1;j++){
				printf("%c",number[i]);
			}
		}
	}
}

// Decoding
int decoding(char number[5]){
	int i,j,k,count;
	// Call the counter function
	count = counter(number);
	// For each digit
	for(i=0;i<count;i++){
		// Digit % 3 = 1 AND Digit == Previous Digit
		if(number[i,i+1]%3==1){
			for(j=i+1;j<count;j++){
				number[j]=number[j+1];
			}
			printf("%c",number[i]);
		}
		// Digit % 3 = 2 AND Digit == Previous Digit and Digit == Before The Previous Digit
		else if(number[i,i+1,i+2]%3==2){
			for(k=0;k<2;k++){
				for(j=i+1;j<count;j++){
					number[j]=number[j+1];
				}
			}
			printf("%c",number[i]);
		}
		// Digit % 3 = 0
		else if(number[i]%3==0){
			printf("%c",number[i]);
		}
	}	
}



// Display encoding
int encoding_menu(){
	char number[5];
	printf("Enter the number : ");
	scanf("%s",&number);
	// Call the encoding function
	encoding(number);
}

// Display decoding
int decoding_menu(){
	char number[15];
	printf("Enter the number : ");
	scanf("%s",&number);
	int i = 0;
	int count = counter(number);
	// Number Is Decodable or Not ?
	while(i<count){
		if(number[i] % 3 == 2 && number[i] == number[i+1] && number[i] == number[i+2]){
			i += 3;
		}
		else if(number[i] % 3 == 1 && number[i] == number[i+1]){
			i += 2;
		}
		else if(number[i] == '\0' || number[i] %3 == 0){
			i += 1;
		}
		else{
			printf("Number is not decodable!");
			exit (1);
		}
	}
	// Call the decoding function
	decoding(number);	
}

// Main function
int main() {
	printf("*****Encoding / Decoding Program*****\t\t\tBy Gorkem Yelken\n\n\n");
	printf("Description for Encoding: It takes a number, and for each digit, it should create a new number by for each digit, taking the modulus of that digit by 3 and repeating the value of the digits as many times as the remainder(in addition to the digit itself).\n");
    printf("\nDescription for Decoding: It takes a number, and create a new number by applying the inverse operation of encoding.\n");
	printf("\n1- Type 'e' or 'E' to encode.\n2- Type 'd' or 'D' to decode.\n3- Type 'q' or 'Q' to exit.\n\n");
	char option;
	while(1){
	// Option
    printf("Option: ");
    scanf("%s", &option);
    // If Option = Encoding
    if(option == 'E' || option == 'e'){
    	printf("\n***ENCODING***\n");
    	encoding_menu();
    	break;
	}
	// If Option = Decoding
	else if(option == 'D' || option == 'd'){
		printf("\n***DECODING***\n");
    	decoding_menu();
		break;
	}
	// If Option = Quit The Program
	else if(option == 'Q' || option == 'q'){
		printf("Exiting!");
		break;
	}
	// If Option = Invalid
	else{
		printf("Invalid option. Please try again.\n");
	}
}
	return 0;
}
