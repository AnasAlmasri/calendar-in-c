
// This program takes in a month and a year
// finds and outputs the month's calendar

// include needed header files
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function prototype inclusions
int first_day(int k, int m, int c, int y);
void tabulate(int d, int mc, int status);

int main(int day){ // function main() starts execution
    // declare variables
    char month[10];
    int i, century, year, month_code, leap=0;

    // prompt user to input month and year
    printf("Enter the month: ");
    scanf("%s", month);
    printf("Enter the year: ");
    scanf("%d", &year);

    // determine if year is a leap year and set value of variable 'leap'
    if (year%100==0){ // if year is a century year
        if (year%400==0 || year%4==0){
            leap = 1;
        }
    }
    century = year/100; // find century value (first two digits to the left)//

    // loop to make input months in uppercase to ease comparisons
    for (i=0; i<10; i++){
        month[i] = toupper(month[i]);
    }

    // determine month and set corresponding values
    if (strcmp("MARCH", month)==0){ // if month is March
            day = first_day(1,1,century,(year%100)); // call function first_day and assign return value to 'day'
            month_code = 1; // following Gregorian tables
    } else if (strcmp("APRIL", month)==0){ // if month is April
            day = first_day(1,2,century,(year%100)); // call function first_day and assign return value to 'day'
            month_code = 2; // following Gregorian tables
    } else if (strcmp("MAY", month)==0){
            day = first_day(1,3,century,(year%100));
            month_code = 3;
    } else if (strcmp("JUNE", month)==0){
            day = first_day(1,4,century,(year%100));
            month_code = 4;
    } else if (strcmp("JULY", month)==0){
            day = first_day(1,5,century,(year%100));
            month_code = 5;
    } else if (strcmp("AUGUST", month)==0){
            day = first_day(1,6,century,(year%100));
            month_code = 6;
    } else if (strcmp("SEPTEMBER", month)==0){
            day = first_day(1,7,century,(year%100));
            month_code = 7;
    } else if (strcmp("OCTOBER", month)==0){
            day = first_day(1,8,century,(year%100));
            month_code = 8;
    } else if (strcmp("NOVEMBER", month)==0){
            day = first_day(1,9,century,(year%100));
            month_code = 9;
    } else if (strcmp("DECEMBER", month)==0){
            day = first_day(1,10,century,(year%100));
            month_code = 10;
    } else if (strcmp("JANUARY", month)==0){ // if month is January
            year--; // following Gregorian rules
            century--; // following Gregorian rules
            day = first_day(1,11,century,(year%100)); // call function first_day and assign return value to 'day'
            month_code = 11; // following Gregorian tables
    } else if (strcmp("FEBRUARY", month)==0){ // if month is February
            year--; // following Gregorian rules
            century--; // following Gregorian rules
            day = first_day(1,12,century,(year%100)); // call function first_day and assign return value to 'day'
            month_code = 12; // following Gregorian tables
    } else { // if input is not valid for this program
            printf("Invalid input.\n");
            return 0; // end program
    }// end if statements

    // call function tabulate() to display output
    tabulate(day,month_code,leap);

    return 0; // to indicate successful execution
}


// function first_day()
// takes in 4 inputs and uses the formula
// determines and returns day of the week
int first_day(int k, int m, int c, int y){
    // declare variables
    int p1, p2, p3, hold, w;

    // if year is equal to zero set it to a hundred (for century years)
    if (y==0){
        y=100;
    }

    // divide the formula into three parts for floating-point chunking
    p1 = 2.6*m - 0.2;
    p2 = y/4;
    p3 = c/4;
    hold = k + p1 - (c*2) + y + p2 + p3;
    w = hold%7; // find weekday

    // if weekday has a negative value, add 7 to it
    if (w<0){
        w += 7;
    }

    return w; // return weekday value
} // function first_day() ends execution


// function tabulate()
// takes in three inputs
// outputs calendar in table form
void tabulate(int d, int mc, int status){
    // declare variables
    int i, count=1;

    // set value of Sunday to 7 to ease calculation
    if (d==0){
        d=7;
    }
    printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n"); // output table header

    // loop to output in table form
    for (i=1; i<=41; i++){
        // loop to skip places before the first day of the month
        if (i<d){
            printf("\t");
            continue;
        }
        printf("%-8d", count); // output day of the month
        // if loop is at the end of the row, make a new line
        if (i%7==0){
            printf("\n");
        }
        if (mc==12){ // if month code indicates February
            if (status==1){ // if year is a leap year
                if (count==29){
                    break; // stop at day 29
                }
            } else if (count==28){ // if year is not a leap year
                break; // stop at day 28
            }
        } else if (mc==2 || mc==4 || mc==7 || mc==9){ // if month is a 30-day month
            if (count==30){
                break; // stop at day 30
            }
        } else if (count==31){ // if month is a 31-day month
            break; // stop at day 31
        }
        ++count; // increment day and keep looping until loop reaches end of the month
    } // output loop ends
} // function result() ends execution
