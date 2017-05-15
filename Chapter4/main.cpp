//
//  main.cpp
//  Chapter4
//
//  Created by Raul Diaz on 2/7/16.
//  Copyright © 2016 Raul Diaz. All rights reserved.
//

#include <iostream>

using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
void getDate(int& month, int& day, int& year);
int getDay(int month,int day,int year);
void output(int dayOfWeek);

int main(){
 
	int month, day, year, dayOfWeek;
	getDate(month, day, year);
	dayOfWeek = getDay(month, day, year);
	cout << "\n The date " << month << "/" << day << "/" << year << " is a ";
	output(dayOfWeek);

	return 0;
}

void getDate(int& month, int& day, int&year){
	cout << " Please enter a month: ";
	cin >> month;
	cout << endl;
	cout << " Please enter a day: ";
	cin >> day;
	cout << endl;
	cout << " Please enter a year: ";
	cin >> year;
}

void get_input(int month, int day, int year){
	cout << endl;
	cout << " Please enter a month: ";
	cin >> month;
	cout << endl;
	cout << " Please enter a day: ";
	cin >> day;
	cout << endl;
	cout << " Please enter a year: ";
	cout << endl;
	cin >> year;
}

bool isLeapYear(int year){
	return (((year % 400) == 0) ||(((year % 4) == 0) && ((year % 100) != 0)));
}

int getCenturyValue(int year){
	int century;
	int remainder;
	century = year/100;
	remainder = (century % 4);
	return ((3 - remainder) * 2);
}

int getYearValue(int year){
	int sinceCentury;
	sinceCentury = year % 100;
	return (sinceCentury + (sinceCentury/4));
}

int getMonthValue(int month, int year){
	int result = 0;
	switch (month) {
		case 1:
			if (isLeapYear(year)){
				result = 6;
			} else {
				result = 0;
			}
			break;
		case 2:
			if (isLeapYear(year)){
				result = 2;
			} else {
				result = 3;
			}
			break;
		case 3:
			result = 3;
			break;
		case 4:
			result = 6;
			break;
		case 5:
			result = 1;
			break;
		case 6:
			result = 4;
			break;
		case 7:
			result = 6;
			break;
		case 8:
			result = 2;
			break;
		case 9:
			result = 5;
			break;
		case 10:
			result = 0;
			break;
		case 11:
			result = 3;
			break;
		case 12:
			result = 5;
			break;
	}
	return result;
	
}

int getDay(int month,int day,int year){
	return (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;
}

void output(int dayOfWeek){

	switch (dayOfWeek) {
		case 0:
			cout << "Sunday.";
			break;
		case 1:
			cout << "Monday.";
			break;
		case 2:
			cout << "Tuesday.";
			break;
		case 3:
			cout << "Wednesday.";
			break;
		case 4:
			cout << "Thursday.";
			break;
		case 5:
			cout << "Friday.";
			break;
		case 6:
			cout << "Saturday.";
			break;
	}
	cout << endl;
}