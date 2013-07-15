/*
	Jamie Lowder 
	July 2013
	C file finds the factorial of a positive number 
	To run this file copy the contents and paste into a text editor.  Go to the terminal.
	Go into the directory that contains THIS file. Once in the proper folder type:
		 gcc factorial.c
	(the line above will compile the code)
	Then type
		./a.out
*/
#include <stdio.h>

/*
The important piece of the program.  This method finds the factorial of a number
Parameters include a given integer and the method returns an int
*/
int factorial (int number){
	if (number == 1){
		return 1;
	}
	
	else {
		return number * factorial(number-1);
	}
}
//Asks the user to enter a number, returns the number
int userNumber(){
	int number;
	printf("Enter an number greater than 0 to be factored: ");
	scanf("%i", &number);
	//Error checking if number is less than 0
	if(number < 0){
		number = userNumber();
	}
	return number;
}

//Main method calls and reports the factorial of a number
int main(int arg, char **argv) {
	char status = 'N';
	
	do{
		int total = -1;
		int num= userNumber();
		
		if(num < 0){	//Error checking if number is less than 0
			num = userNumber();
		}

		total = factorial(num);//this method will return the result of the factorial
		printf("Total is: %i\n", total);

		//Try again statements
		printf("Do you want to do this again? (Y/N)");
		status = getchar();//end of line character
		status = getchar();
		if(status == 'T' || status == 't' || status == 'y'){
			status = 'Y';
		}
	}while(status == 'Y');
}