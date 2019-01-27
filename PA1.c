/* Jonathan Chang
* CS 2303 C01 18
* Assignment 1
* AC1.c
*/

// Headers
#include<stdio.h>
#include<math.h>

// Function Prototypes
int getWeekDay(int year, int month, int day);
int isLeapYear(int year);
void printCalendar(int year, int startingDay);
int printMonth(int year, int month, int startingDay);
int printMonthName(int year, int month);
int getMonthNumberOfDays(int year, int month);

/**
* Prints out the calendar of a inputed year
* @return 1 if error, 0 for normal execution
*/
int main(void) {
  printf("MONTHLY CALENDAR\n\n");
  printf("Please enter year for this calendar:- ");

  int year; // Which year to print, in mordern international standard calender
  scanf("%d", &year);
  printf("\n");

  // Tests if the inputed year is invalid
  if(year <= 0) {
    // If invalid year
    printf("ERROR: %d is not a valid year.\n", year);
    return 1;
  }

  printCalendar(year, getWeekDay(year, 1, 1));
}

/**
* Prints out the calendar given the calendar year and starting week day
* @param year The year to print, in mordern international standard calendar
* @param startingDay The starting week day of the year (0 = Sunday, 6 = Saturday)
* @return void
*/
void printCalendar(int year, int startingDay) {
  printf("***   CALENDAR for %d   ***\n\n", year);

  // Pre-condition: No months are printed
  for(int month = 1; month < 13; month++) {
    // Loop Invariant: 1 <= month <= 12
    startingDay = printMonth(year, month, startingDay);
  }
  // Post-condition: All months are printed
}

/**
* Prints the month of the given year, given month, and given starting week day
* @param year The given year to print, in mordern international standard calendar
* @param month The given month in the year to print (Jan = 1, Dec = 12)
* @param startingDay The starting week day of that month (0 = Sunday, 6 = Saturday)
* @return The starting day of the next month (0 = Sunday, 6 = Saturday)
*/
int printMonth(int year, int month, int startingDay) {
  int maxDays = printMonthName(year, month); // Holds the total number of
    // days in the month

  printf("\n");
  printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");

  // Pre-condition: currently on new empty line
  for(int firstDay = 0; firstDay < startingDay; firstDay++) {
    // Loop Invariant: 0 <= firstDay < startingDay
    printf("     ");
  }
  // Post-condition: Blank spaces printed before first day

  // Pre-condition: Blank spaces printed before first day
  int printedSaturday; // Holds if printed Saturday - to avoid two empty lines
    // after a month that ends on Saturday
  for(int currentDay = 1; currentDay < maxDays + 1; currentDay++) {
    // Loop Invariant: 0 <= startingDay <= 6 && 1 <= currentDay <= maxDays
    printf(" %2d  ", currentDay);
    startingDay++;
    printedSaturday = 0;
    // Tests if roll over to next week
    if(startingDay == 7) {
      // If roll over to next week
      startingDay = 0;
      printedSaturday = 1;
      printf("\n");
    }
  }
  //Post-condition: All days are printed

  //Tests if just printed a Saturday
  if(!printedSaturday) {
    //If did not just printed a Saturday
    printf("\n");
  }
  printf("\n");

  return startingDay;
}

/**
* Prints the month name
* @param year The given year, in mordern international standard calendar
* @param month The given month to print (Jan = 1, Dec = 12)
* @return The number of days in the month
*/
int printMonthName(int year, int month) {
  switch(month) {
    case 1:
      printf("January %d\n", year);
      return 31;
    case 2:
      printf("February %d\n", year);
      // Tests if the year is a leap year
      if(isLeapYear(year)) {
        // If it is a leap year
        return 29;
      } else {
        // If not a leap year
        return 28;
      }
    case 3:
      printf("March %d\n", year);
      return 31;
    case 4:
      printf("April %d\n", year);
      return 30;
    case 5:
      printf("May %d\n", year);
      return 31;
    case 6:
      printf("June %d\n", year);
      return 30;
    case 7:
      printf("July %d\n", year);
      return 31;
    case 8:
      printf("August %d\n", year);
      return 31;
    case 9:
      printf("September %d\n", year);
      return 30;
    case 10:
      printf("October %d\n", year);
      return 31;
    case 11:
      printf("November %d\n", year);
      return 30;
    case 12:
      printf("December %d\n", year);
      return 31;
  }
  return 0;
}

/**
* Calculates the week day for a given year, given month, and given day
* @param year The year to get the week day of
* @param month The month to get the week day of (Jan = 1, Dec = 12)
* @param day The day of the month to get the week day of
* @return The starting day of the year (0 = Sunday, 6 = Saturday)
*/
int getWeekDay(int year, int month, int day) {
  // Test if the month is Jan or Feb.
  if(month == 1 || month == 2) {
    // If the month is Jan or Feb
    month += 10;
    year -= 1;
  } else {
    // If the month is another month
    month -= 2;
  }

  int century = floor(year / 100); // The century of the given year
  int centuryYear = year % 100; // The year of the century of the given year

  return (int) floor(day + floor((2.6 * month) - 0.2) - (2 * century) +
    centuryYear + floor(centuryYear / 4) + floor(century / 4)) % 7;
}

/**
* Determines whether or not a given year is a leap year
* @param year The year to determine in mordern international standard calendar
* @return 1 if the year is a leap year, 0 if not
*/
int isLeapYear(int year) {
  return ((year % 4 == 0 && year % 100 != 100) || year % 400 == 0);
}
