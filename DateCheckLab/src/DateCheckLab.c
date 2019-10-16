/*
 * DateCheckLab.c
 *
 *  Created on: 9 okt. 2019
 *      Author: adrianm
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "DateCheckLab.h"
//check if date is within plausible limits
_Bool verifydate(Date y){
int daymax;
switch(y.month){
case january: case march: case may: case july: case august: case october: case december:
	daymax = 31;
	break;
case february:
	if (leapyear(y) == true)
	{daymax = 29;}
	else{
	daymax = 28;
	}
	break;
case april: case june: case september: case november:
	daymax = 30;
	break;
}
	if(y.year<= YEARMAX && y.year >= YEARMIN && y.month<= MONTHMAX && y.day<= daymax){
		return true;
	}
	else{
		printf("\n Thats not a possible date.");
		return false;
	}
}
//check if entered year is a leapyear
_Bool leapyear(Date y){
	if(y.year<= YEARMAX && y.year >= YEARMIN)
	{
		if(y.year%4 == 0)
		{
			if( y.year%100 == 0)
			{
				// year is divisible by 400, hence the year is a leap year
				if ( y.year%400 == 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return true;
			}
		}
		else
		return false;
	}
	else
	return false;
}

void userinput(char date[])
{
	unsigned char temp;
	_Bool stop = false;
	int x=0;
	do{
		temp = getchar();
		if(isdigit(temp)){
			date[x++] = temp;
		}
		if(x==YEAR || temp=='\n'){
			stop = true;
		}
		if(temp=='\n'){
			break;
		}
	}while(!stop);
	stop = false;

	do{
		temp = getchar();
		if(temp==SEPARATOR){
			date[x++] = temp;
			stop = true;
		}
		if(temp != SEPARATOR){
			break;
		}
	}while(!stop);
	stop = false;

	do{
		temp = getchar();
		if(isdigit(temp)){
			date[x++] = temp;
		}
		if(x==MONTH || temp=='\n'){
			stop = true;
		}
		if(temp=='\n'){
			break;
		}
	}while(!stop);
	stop = false;

	do{
		temp = getchar();
		if(temp==SEPARATOR){
			date[x++] = temp;
			stop = true;
		}
		if(temp=='\n'){
			stop = true;
		}
		if(temp=='\n'){
			break;
		}
	}while(!stop);
	stop = false;

	do{
		temp = getchar();
		if(isdigit(temp)){
			date[x++] = temp;
		}
		if(x==DAY || temp=='\n'){
			stop = true;
		}
		if(temp=='\n'){
			break;
		}
	}while(!stop);

	date[x] = '\0';
}

Date convert_input(char date[]){
	// Part out the complete string into separate strings for each of the variables
	char * yearstr = strtok(date,"-");
	char * monthstr = strtok(NULL,"-");
	char * daystr = strtok(NULL,"-");

	//Convert the stringtokens to int and put them in Date (struct)
	Date y;
	y.year=atoi(yearstr);
	y.month=atoi(monthstr);
	y.day=atoi(daystr);
	return y;
}
void complete_output(_Bool verifydate,_Bool leapyear, Date y,int dayspassed){
	//Check that if the input date was accepted
	if(verifydate == true){
		//check if date is leap year and print it if so.
		if(leapyear == true){
			printf("\n The date saved is a leap year, the date saved is: %4d-%02d-%02d", y.year, y.month, y.day);
			if(y.month > 2){
			printf("\n The days passed in the year is: %d",++dayspassed);
			}
			else{
			printf("\n The days passed in the year is: %d", dayspassed);
			}
		}
		//if its not a leap year, this will be the output
		else {
			printf("\n The date saved is not a leap year, the date saved is: %4d-%02d-%02d", y.year, y.month, y.day);
			printf("\n The days passed in the year is: %d",dayspassed);
		}
	}
	//if the date was not accepted we will print this
	else {
		printf("\n something went wrong, try again.");
	}
}
//This function will use the saved day and month(s) max day to calculate the days passed.
int dayspassedc(Date y){

	int dayspassed;
	switch(y.month){
	case january:{
		dayspassed =  y.day;
		break;
	}
	case february:{
		dayspassed = passedfeb + y.day;
		break;
	}
	case march:{
		dayspassed = passedmar + y.day;
		break;
	}
	case april:{
		dayspassed = passedapr + y.day;
		break;
	}
	case may:{
		dayspassed = passedmay + y.day;
		break;
	}
	case june:{
		dayspassed = passedjun + y.day;
		break;
	}
	case july:{
		dayspassed = passedjul + y.day;
		break;
	}
	case august:{
		dayspassed = passedaug + y.day;
		break;
	}
	case september:{
		dayspassed = passedsep + y.day;
		break;
	}
	case october:{
		dayspassed = passedoct + y.day;
		break;
	}
	case november:{
		dayspassed = passednov + y.day;
		break;
	}
	case december:{
		dayspassed = passeddec + y.day;
		break;
	}
	}
	return dayspassed;
}
