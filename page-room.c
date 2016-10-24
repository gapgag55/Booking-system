#include <stdio.h>
#include <time.h>

char *writeRoom(int roomId, int day, char m[]) {
    char *text[20];
    int month = getMonthInt(m);
    int room;
    
    switch (roomId) {
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
    
    sprintf(text, " IT%3d %2d(M,A)", room, day);
    return text;
}

int getCalendar(char m[]) {
    
    char days[7][4] = {"Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int startMonth[12] = {5,1,2,5,1,3,5,1,4,6,2,4};
    int maxDays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int month = getMonthInt(m);
    
    int first_s = startMonth[getMonthInt(m)];
    int start = first_s;
    int maxDay = maxDays[getMonthInt(m)];
    int countDay = 1;
    int roomDay = 1;
    
    int column = 7;
    int subRow = 7;
    int row = (maxDay + start) / 7;
    if(row >= 5) row = 6;
    else row = 5;
    
    
    /*======= HEAD =======*/
    int a,b,c,d;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 7; b++) {
            if (a == 0 || a == 2) {
                if (b == 0) {
                    printf("|");
                    for(c = 0; c < 4; c++) {
                        printf("-");
                    }
                } else {
                    for(c = 0; c < 15; c++) {
                        printf("-");
                    }
                }
            } else {
                if (b == 0) {
                    printf("| %2s", days[b]);
                } else {
                    printf("%9s      ", days[b]);
                }
            }
            printf("|");
        }
        printf("\n");
    }
    
    
    // DAYS
    for(a = 0; a < row; a++) {
        for(b = 0; b < subRow; b++) {
            if(a == 0) {
                start = first_s;
                roomDay = 1;
            } else {
                roomDay += 1;
            }
            for(c = 0; c < column; c ++) {
                    if(start == 0) {
                        if(b == 0) {
                            if(c == 0) {
                                if(countDay <= maxDay) {
                                    printf("| %2d ", countDay);
                                } else {
                                    printf("|    ");
                                }
                            } else {
                                if(countDay <= maxDay) {
                                    printf("%9d      ", countDay);
                                } else {
                                    printf("               ");
                                }
                            }
                            ++countDay;
                        } else if(b < 6) {
                            if(c == 0) {
                                printf("|    ");
                            } else {
                                
                                // EDIT HERE
                                if(roomDay <= maxDay) {
                                    printf("%s ", writeRoom(b, roomDay, m));
                                } else {
                                    printf("               ");
                                }
                                ++roomDay;
                            }
                        } else {
                            if(c == 0) {
                                printf("|");
                                for(d = 0; d < 4; d++) {
                                    printf("-");
                                }
                            } else {
                                for(d = 0; d < 15; d++) {
                                    printf("-");
                                }
                            }
                            printf("|");
                        }
                    } else {
                        if(b == 6) {
                            if(c == 0) {
                                printf("|");
                                for(d = 0; d < 4; d++) {
                                    printf("-");
                                }
                            } else {
                                for(d = 0; d < 15; d++) {
                                    printf("-");
                                }
                            }
                            printf("|");
                        } else {
                            if(c == 0) {
                                printf("|    ");
                            } else {
                                printf("               ");
                            }
                        }
                    }
                    --start;
                    if(start < 1) start = 0;
                    if(b != 6) printf("|");
            }
            roomDay = countDay - 7;
            if(b != 6 ) printf("\n");
        }
        printf("\n");
    }
    
    
    return 0;
}


int roomAbilityPage() {
    
    char month[3];
    
    printf("Room Ability page\n");
    printf("Enter your month [Jan, Feb, Mar, Api, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec]: ");
    scanf("%s", month);
    printf("\n");
    getCalendar(month);
    
    return 0;
}
