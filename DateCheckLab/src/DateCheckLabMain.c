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
	do{
		setbuf(stdout, NULL);
		//get user input
		printf("\n Enter a date between 1950 and 2019 in format YYYY-MM-DD  ");
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
			_Bool L = leapyear(x);
			complete_output(V,L, x);
}while(V == false);

	return 0;
}
