/*
 * DateCheckLabMain.c
 *
 *  Created on: 9 okt. 2019
 *      Author: adrianm
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "DateCheckLab.h"

int main(){
	char date[TOTAL+ 1];
	int string_length;
	_Bool V;
	_Bool L;
	int M;
	do{
		fseek(stdin,0,SEEK_END); // NEED TO FIND A BETTER WAY TO "FLUSH" THE INPUT FOR EACH LOOP
		setbuf(stdout, NULL);
		//get user input
		printf("\n\n Enter a date between 1900 and 2019 in format YYYY-MM-DD  ");
		userinput(date);

		string_length = strlen(date);

		if(string_length == TOTAL){
			printf("\n Processing... \n");
		}
		else{
			printf("\n The input %s is not in the correct format! \n", date);
		}
			//call on functions
		Date x = convert_input(date);
		V = verifydate(x);
		L = leapyear(x);
		M = dayspassedc(x);
		complete_output(V, L, x, M);
}while(V == false);

	return 0;
}
