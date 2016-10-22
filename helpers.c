#include <stdio.h>

char menus(char lower, char upper, char text[]) {
    
    printf("\tEnter %c or %c for\t%s\n\n", lower, upper, text);
    return 0;
}

int numlen(int num) {
    int count = 0;
    
    while(num > 0) {
        num = num / 10;
        ++count;
    }
    return count;
}

char *getMonth(int order) {
    char *month;
    
    switch (order) {
        case 1:
            month = "Jan";
            break;
        case 2:
            month = "Feb";
            break;
        case 3:
            month = "Mar";
            break;
        case 4:
            month = "Api";
            break;
        case 5:
            month = "May";
            break;
        case 6:
            month = "Jun";
            break;
        case 7:
            month = "July";
            break;
        case 8:
            month = "Aug";
            break;
        case 9:
            month = "Sep";
            break;
        case 10:
            month = "Oct";
            break;
        case 11:
            month = "Nov";
            break;
        case 12:
            month = "Dec";
            break;
        default:
            month = "Error";
            break;
    }
    
    return month;
}

