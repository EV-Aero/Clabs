/*
 * DateCheckLab.h
 *
 *  Created on: 9 okt. 2019
 *      Author: adrianm
 */

#ifndef SRC_DATECHECKLAB_H_
#define SRC_DATECHECKLAB_H_
//defines for the date input array
#define YEAR 4
#define MONTH 7
#define DAY 10
#define TOTAL 10
#define SEPARATOR '-'
//defines for the input after they have been converted to int and split in different parts
#define YEARMAX 2019
#define MONTHMAX 12
#define DAYMAX 31
#define YEARMIN 1950
enum Months {january = 1, february, march, april, may, june, july, august, september, october, november, december};
#define days_in_january 31
//this will be the base, but changed if its a leap year.
#define days_in_february 28
#define days_in_march 31
#define days_in_april 30
#define days_in_may 31
#define days_in_june 30
#define days_in_july 31
#define days_in_august 31
#define days_in_september 30
#define days_in_october 31
#define days_in_november 30
#define days_in_december 31

//struct for the date
typedef struct{
	int year;
	int month;
	int day;
}Date;
//check date within limits
_Bool verifydate(Date y);

//check leapyear
_Bool leapyear(Date y);

//output function
void complete_output(_Bool verifydate,_Bool leapyear, Date y);

//convert function
Date convert_input(char date[]);

//input function
void userinput(char date[]);
#endif /* SRC_DATECHECKLAB_H_ */
