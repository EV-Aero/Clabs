/*
 * DateCheckLab.h
 *
 *  Created on: 9 okt. 2019
 *      Author: adrianm
 */

#ifndef SRC_DATECHECKLAB_H_
#define SRC_DATECHECKLAB_H_
//defines for the raw date input string
#define YEAR 4
#define MONTH 7
#define DAY 10
#define TOTAL 10
#define SEPARATOR '-'
//defines for the input after they have been converted to int and split in different parts
#define YEARMAX 2019
#define MONTHMAX 12
#define DAYMAX 31
#define YEARMIN 1900
enum Months {january = 1, february, march, april, may, june, july, august, september, october, november, december};
//define days passed for each month
#define passedfeb 31
#define passedmar 59
#define passedapr 90
#define passedmay 120
#define passedjun 151
#define passedjul 181
#define passedaug 212
#define passedsep 243
#define passedoct 273
#define passednov 304
#define passeddec 334
//struct for the converted date
typedef struct{
	int year;
	int month;
	int day;
}Date;
//check the converted input if its within boundaries of a possible date
_Bool verifydate(Date y);

//checking leapyear by using the converted date,in this case analyzes the year input and checks if it is a leap year
_Bool leapyear(Date y);

//output function, takes the functions that calculates everything and puts it together and then prints output
//this is also where the dayspassed gets changed the last time depending on if its a leap year or not
void complete_output(_Bool verifydate,_Bool leapyear, Date y, int dayspassed);

//convert function, converts the input saved in date, and turns it from a string to int
Date convert_input(char date[]);

//input function, here is where the raw input is put in a string, it also checks that the input is done in the right format
void userinput(char date[]);
#endif /* SRC_DATECHECKLAB_H_ */

//days passed function, takes the days passed each month, taken from defines in H file, then adds the converted days
//and returns with the days passed in the year.
int dayspassedc(Date y);
