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
