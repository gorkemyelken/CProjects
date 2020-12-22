#include <stdio.h>
#include <stdlib.h>

// Count the number of characters in the string
int counterChar(char str[])
{
 	int i=0;
 	while(str[i] != '\0'){
 		i++;
	}
 	return i;
}

// Count the number of words in the string
int counterWord(char str[])
{
	int counter=0,countWord=1;
 	while(str[counter] != '\0'){
 		// Increase countWord by 1 in each space
 		if(str[counter] == ' '){
 			countWord++;
		}
 		counter++;
 	}
 	return countWord;
}

int previousSpace(char str[],int startChar)
{
	while(str[startChar] != ' ' && startChar != '\0')
	{
		startChar--;
	}
	return startChar;
}

// Convert first character of each word to uppercase.
void capitalized(char str[]){
	// Capitalize the first character
	if(str[0] >= 'a' && str[0]<='z'){
 			str[0] -= 32;
 			}
 	// Capitalize other words' initials
	int counter = 1;
 	while(str[counter] != '\0'){
 		if(str[counter] == ' '){
 			if(str[counter+1] >= 'a' && str[counter+1]<='z'){
 			str[counter+1] -= 32;
 			}
 		}
 		counter++;
 	}
 	printf("%s",str);
}

// Reverse the order of words in the string in-place and display.
void reverse(char str[])
{
	int i,counter=0,startPosition,finishPosition,countChar;
	// Number of char
	countChar = counterChar(str);
	// Position of last character = Number of characters
 	finishPosition = countChar;
 	while(countChar >= 0 ){ 
 		// Last space
		startPosition = previousSpace(str,countChar);
 		countChar = startPosition-1;
 		if(startPosition>0){
 			startPosition +=1;
		}
 		// Output: Between start position and finish position
 		for(i=startPosition;i<finishPosition;i++){
 			printf("%c",str[i]);
		}
		// Space between words
 		printf(" ");
 		// New finish position
 		finishPosition = countChar + 1 ;
}
}

// main function
int main()
{
	printf("*****Word Processor Program*****\t\t\tBy Gorkem Yelken.\n\n\n");
	// Descriptions
	printf("Decription for number of characters: It will count the number of characters in the string.\n\n");
	printf("Decription for number of words: It will count the number of words in the string. The delimiter is a whitespace, ''  ''.\n\n");
	printf("Decription for reverse: It will reverse the order of words in the string in-place and display.\n\n");
	printf("Decription for capitalize: It will convert first character of each word to uppercase.\n\n");
	// The string will be read from user input. The maximum string length is 250.
 	char str[250];
 	printf("String : ");
 	gets(str);
 	// Output: Number of characters
 	printf("Number of characters : %d\n",counterChar(str));
 	// Output: Number of words
 	printf("Number of words : %d\n",counterWord(str));
 	// Output: Reversed string
 	printf("Reversed : ");
	reverse(str);
	// Output: Capitalized string
	printf("\nCapitalized : ");
	capitalized(str);
 	return 0;
}
