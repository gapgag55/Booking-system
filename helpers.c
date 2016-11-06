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
    
    switch (order) {
        case 0:
            month = "Jan";
            break;
        case 1:
            month = "Feb";
            break;
        case 2:
            month = "Mar";
            break;
        case 3:
            month = "Api";
            break;
        case 4:
            month = "May";
            break;
        case 5:
            month = "Jun";
            break;
        case 6:
            month = "Jul";
            break;
        case 7:
            month = "Aug";
            break;
        case 8:
            month = "Sep";
            break;
        case 9:
            month = "Oct";
            break;
        case 10:
            month = "Nov";
            break;
        case 11:
            month = "Dec";
            break;
        default:
            month = "Error";
            break;
    }
    
    return month;
}

// getMonthInt("Nov");

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
        return -1;
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
