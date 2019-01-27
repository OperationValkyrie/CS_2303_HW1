Jonathan Chang
CS 2303 C02 18
Assignment 1 - Calendar
PA1.c

This program is designed to create a Gregorian Calendar for any year. Note that this program will create a calendar for year less than 1582 (creation date for the Gregorian Calendar) using the Gregorian Calendar format. Also note that years must be greater than 0, if not an error message will print out.

This program can be compiled using the following command
gcc -Wall PA1.c -lm
or
gcc -Wall -o PA1 PA1.c -lm

This program can then be run with the following command
./a.out

Past Complications
While most issues were immediately taken care of, there were a few issues that stood out. Firstly, the intial iteration of the printMonth() function did not print out next lines so the first run produced all the dates in one line; while this was easily fixed, another error can aparent quickly - that the printMonth() function was printing one too many empty dates before the first day of the month. Another error that had to be solved was that if the last day of the month was a Saturday, an extra empty line was added; to resolve this issue a boolean flag was added that prevented the extra line from being created if the last day was a Saturday. Finally, an issue that was more of a boolean zen fix was that the isLeapyear() function used if else statements instead of a single expression; this was easier fixed but replacing the if else statements with the expression.

The algorithm that was used was copied from the University of Waterloo. This algorthim is the disparate variation of Gauss's algorithm, which does not require any lookup tables. This algorithm in full is: 
W = (k + [2.6 * m - 0.2] - 2 * C + Y + [Y/4] [C/4]) % 7. 
With:
W being the day of the week (Sun = 0, Sat = 6)
m being the month (1 = Mar, 10 = Dec, 11 = Jan, 12 = Feb)
C being the century of the year (1985 -> 19)
Y being the year of the century (1985 -> 85)
k being the day of the month
All values in brackets[] have the remainder dropped

The term [2.6 * m -0.2] compensates for the different months, creating values that correspond with the set months. These offsets account for the sequence of months which affect their starting day. The Y + [Y/4] gives the value of the century years - creating offsets from 0 to 6 depending on the given year. [C/4] - 2 * C compensates for the century which returns values of 5, 3, 1, or 0 depending on the C % 4 value. All of these terms shift the value of the day of the week around in order to compensate for leap years or just continuous year - forming an algorithm that can be used to calculate the day of week of any given date.

The algorithm can be found here.
https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
