//There is no error checking in day_of_year or month_day. Remedy this defect.
//invalid month, invalid day, negative year, 
#include<stdio.h>

char daytab[][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int day_of_year(int month, int day, int year){
    if(year < 0) year = -year;
    char leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(day > 31) return -1;
            else break;
        case 2: 
            if( (!leap) && day >28) return -1;
            else if(leap && day > 29) return -1;
            else break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day > 30) return -1;
            else break;
        default:
            return -1;
    }
    for(int i = 1; i < month; ++i){
        day += daytab[leap][i];
    }

    return day;
}

void month_day(int year, int day_in_year, int* day, int* month){
    if(year < 0) year = -year;
    char leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if((leap && day_in_year > 366) || ((!leap) && day_in_year > 365)) return -1; 
    int i;
    *day = day_in_year;
    for(i = 1; *day > daytab[leap][i]; ++i){
        *day -= daytab[leap][i];
    }

    *month = i;
}

int main(){
    int today_in_year;
    printf("%d\n", today_in_year = day_of_year(3,30,2024));
    int today_month;
    int today_day;
    month_day(2024, today_in_year, &today_day, &today_month);
    printf("%d %d", today_day, today_month);
}   



