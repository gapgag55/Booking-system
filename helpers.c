char menus(char lower, char upper, char text[]) {

    printf("\tEnter %c or %c for\t%s\n", lower, upper, text);
    return 0;
}

int numlen(int num) {
    int count = 0;
    int mod;

    while(num > 0) {
        num = num / 10;
        mod = num % 1;

        num = num - mod;
        ++count;
    }
    return count;
}

char *getMonth(int order) {
    char *month;
    char months[][] = {"Jan", "Feb", "Mar", "Api", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    if(1 <= order && order <= 12)
        month = months[order-1];
    else   
        month = "Error";

    return month;
}


int getMonthInt(char m[]) {

    if(strcmp(m,"Jan") == 0 || strcmp(m, "jan") == 0) {
        return 1;
    } else if(strcmp(m,"Feb") == 0 || strcmp(m, "feb") == 0) {
        return 2;
    } else if(strcmp(m,"Mar") == 0 || strcmp(m, "mar") == 0) {
        return 3;
    } else if(strcmp(m,"Api") == 0 || strcmp(m, "api") == 0) {
        return 4;
    } else if(strcmp(m,"May") == 0 || strcmp(m, "may") == 0) {
        return 5;
    } else if(strcmp(m,"Jun") == 0 || strcmp(m, "jun") == 0) {
        return 6;
    } else if(strcmp(m,"Jul") == 0 || strcmp(m, "jul") == 0) {
        return 7;
    } else if(strcmp(m,"Aug") == 0 || strcmp(m, "aug") == 0) {
        return 8;
    } else if(strcmp(m,"Sep") == 0 || strcmp(m, "sep") == 0) {
        return 9;
    } else if(strcmp(m,"Oct") == 0 || strcmp(m, "oct") == 0) {
        return 10;
    } else if(strcmp(m,"Nov") == 0 || strcmp(m, "nov") == 0) {
        return 11;
    } else if(strcmp(m,"Dec") == 0 || strcmp(m, "dec") == 0) {
        return 12;
    } else {
        return 0;
    }
}

int getRoom(int id) {
    int room;

    switch (id) {
        case 1:
            room = 101;
            break;
        case 2:
            room = 102;
            break;
        case 3:
            room = 103;
            break;
        case 4:
            room = 104;
            break;
        default:
            room = 105;
            break;
    }

    return room;
}

int printMonth(char m[]) {

    if(strcmp(m,"Jan") == 0 || strcmp(m,"jan") == 0) {
        printf("The monthly view of all meeting room on January 2016\n");
    } else if(strcmp(m,"Feb") == 0 || strcmp(m,"feb") == 0) {
        printf("The monthly view of all meeting room on February 2016\n");
    } else if(strcmp(m,"Mar") == 0 || strcmp(m,"mar") == 0) {
        printf("The monthly view of all meeting room on March 2016\n");
    } else if(strcmp(m,"Api") == 0 || strcmp(m,"api") == 0) {
        printf("The monthly view of all meeting room on April 2016\n");
    } else if(strcmp(m,"May") == 0 || strcmp(m,"may") == 0) {
        printf("The monthly view of all meeting room on May 2016\n");
    } else if(strcmp(m,"Jun") == 0 || strcmp(m,"jun") == 0) {
        printf("The monthly view of all meeting room on June 2016\n");
    } else if(strcmp(m,"Jul") == 0 || strcmp(m,"jul") == 0) {
        printf("The monthly view of all meeting room on July 2016\n");
    } else if(strcmp(m,"Aug") == 0 || strcmp(m,"aug") == 0) {
        printf("The monthly view of all meeting room on August 2016\n");
    } else if(strcmp(m,"Sep") == 0 || strcmp(m,"sep") == 0) {
        printf("The monthly view of all meeting room on September 2016");
    } else if(strcmp(m,"Oct") == 0 || strcmp(m,"oct") == 0) {
        printf("The monthly view of all meeting room on October 2016\n");
    } else if(strcmp(m,"Nov") == 0 || strcmp(m,"nov") == 0) {
        printf("The monthly view of all meeting room on November 2016\n");
    } else if(strcmp(m, "Dec") == 0 || strcmp(m,"dec") == 0){
        printf("The monthly view of all meeting room on December\n");
    } else {
        return 0;
    }
    return 1;
}

int checkDay(int m) {
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    } else if(m == 2) {
        return 29;
    } else {
        return 30;
    }
}

char *checkTime(int Time) {
    char *time;

    if(Time < 12) {
        time = "am";
    } else {
        time = "pm";
    }

    return time;
}

int timeClock(int Time) {
    if(Time > 12) {
        Time = Time - 12;
    }
    
    return Time;
}

int checkSunday(int day, int month) {
    int startMonth[12] = {5,1,2,5,1,3,5,1,4,6,2,4};
    month = month - 1;

    int week = 7 - startMonth[month];
    int days = day - week;
    int sunday = days % 7;

    if(sunday == 1) {
        return 1;
    }
    return 0;
}
int printMonth2(char m[]) {

    if(strcmp(m,"Jan") == 0 || strcmp(m,"jan") == 0) {
        printf("January 2016");
    } else if(strcmp(m,"Feb") == 0 || strcmp(m,"feb") == 0) {
        printf("February 2016\n");
    } else if(strcmp(m,"Mar") == 0 || strcmp(m,"mar") == 0) {
        printf("March 2016\n");
    } else if(strcmp(m,"Api") == 0 || strcmp(m,"api") == 0) {
        printf("April 2016\n");
    } else if(strcmp(m,"May") == 0 || strcmp(m,"may") == 0) {
        printf("May 2016\n");
    } else if(strcmp(m,"Jun") == 0 || strcmp(m,"jun") == 0) {
        printf("June 2016\n");
    } else if(strcmp(m,"Jul") == 0 || strcmp(m,"jul") == 0) {
        printf("July 2016\n");
    } else if(strcmp(m,"Aug") == 0 || strcmp(m,"aug") == 0) {
        printf("August 2016\n");
    } else if(strcmp(m,"Sep") == 0 || strcmp(m,"sep") == 0) {
        printf("September 2016");
    } else if(strcmp(m,"Oct") == 0 || strcmp(m,"oct") == 0) {
        printf("October 2016\n");
    } else if(strcmp(m,"Nov") == 0 || strcmp(m,"nov") == 0) {
        printf("November 2016\n");
    } else if(strcmp(m, "Dec") == 0 || strcmp(m,"dec") == 0){
        printf("December\n");
    } else {
        return 0;
    }
    return 1;
}
