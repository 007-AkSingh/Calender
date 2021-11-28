#include <stdio.h>
#include <stdlib.h>
// Initialize all the necessary header files required further

int get_1st_weekday(int year){ // Variable to know the starting day of the year and week i.e january
// To convert the gregorian date to week day as im using Gregorian Standard Calender to make the project

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;  // As we need only January first day of week this is the logic for it.
  return d;
}

int main()
{
   system("Color 2F");  // 2->BG COLOR i.e. Green , F-->Text Color i.e. White  // This function is included in stdlib header file
   int year,month,day,daysInMonth,weekDay=0,startingDay; // creating those variables we require in our project
   printf("\nEnter your desired year:");  // Ask user for which year calender to be printed
   scanf("%d",&year);  // scanning the users input of year

   char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};  // Creating the character array for all the months
   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31}; // creating no. of month days variable

   if((year%4==0&&year%100!=0)||year%400==0)  // when the year is divisible by 4 & not 100 or divisible by 400
       monthDay[1]=29;  // Replacing 1st element of month day i.e. 28 with 29

   startingDay=get_1st_weekday(year); // This will give the first day i.e 1st January of any year and store it in  a new variable named startingDay

   for(month=0;month<12;month++){ // month = 0-12 for printing all 12 months one by one

      daysInMonth=monthDay[month];  //It will increment from 0-12 months like in january 31 days and it will store in variable daysInMonth
      printf("\n\n---------------%s-------------------\n",months[month]);// It will print month one after the other
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");// It will print Week Days after every month

      for(weekDay=0;weekDay<startingDay;weekDay++) // To add the space between previous months end day and new month starting day
        printf("     "); // 5 spaces are given as padding between 2 numbers is 5

      for(day=1;day<=daysInMonth;day++){  // looping for loop of day from 1 to days in month
        printf("%5d",day);  // 5d is just for spacing or padding between two consecutive numbers or in our case day

        if(++weekDay>6){  // To align week days as per the names of days for this increment ++weekDay from 0-6 i.e Sunday to Saturday
            printf("\n");  // Once the limit of 6 i.e Saturday is reached it will again start with Sunday i.e. change the line by using /n
            weekDay=0;  // To print it again and again from 0 i.e Sunday, once Saturday i.e. 0 is reached
        }
        startingDay=weekDay; // This will give the startingDay to weekday so it will increment after 1st january in a proper sequence like 2nd,3rd january so on and so forth
      }

   }


}
