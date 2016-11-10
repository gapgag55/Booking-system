char *writeRoom(int roomId, int day, char m[], int justLast) {
    char *text = malloc(20);
    int month = getMonthInt(m);
    bookDB booking = getBookingDB();
    int morning = 3;
    int afternoon = 5;
    int room;

    int a;
    int check = 1;

    room = getRoom(roomId);

    for(a = 0; a < booking.arrLength; a++) {
        if(booking.room[a] == room && booking.day[a] == day && booking.month[a] == month) {
            while(booking.startTime[a]!=booking.endTime[a])
            {
              if(booking.startTime[a]<12) {
                morning -= 1;
            } else {
                if(booking.startTime[a]>=12) {
                    afternoon -= 1;
                }
            }
                booking.startTime[a]+=1;
            }
            check = 0;
        } else {
            if(check != 0) check = 1;
        }
    }


    if(check) {
        if(justLast) {
            sprintf(text,"%s", "8(M,A)");
        } else {
            sprintf(text, " IT%3d 8(M,A) ", room);
        }
    } else {
        if(morning > 0 && afternoon > 0) {
            if(justLast) {
                sprintf(text, "%d%s", morning + afternoon, "(M,A)");
            } else {
                sprintf(text, " IT%3d %d%s ", room, morning + afternoon, "(M,A)");
            }
        } else if (morning > 0) {
            if(justLast) {
                sprintf(text, "%d%s  ", morning + afternoon, "(M)");
            } else {
                sprintf(text, " IT%3d %d%s   ", room, morning + afternoon, "(M)");
            }
        } else if(afternoon > 0){
            if(justLast) {
                sprintf(text, "%d%s   ", morning + afternoon, "(A)");
            } else {
                sprintf(text, " IT%3d %d%s   ", room, morning + afternoon, "(A)");
            }
        } else
        {
            if(justLast) {
                text=" FULL ";
            } else {
                sprintf(text, " IT%3d FULL   ", room);
            }
        }
    }
    return text;
}

int getCalendar(char m[]) {

    char days[7][4] = {"Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int startMonth[12] = {5,1,2,5,1,3,5,1,4,6,2,4};
    int maxDays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    int first_s = startMonth[getMonthInt(m) - 1];
    int start = first_s;
    int maxDay = maxDays[getMonthInt(m) - 1];
    int countDay = 1;
    int roomDay = 1;

    int column = 7;
    int subRow = 7;
    float row = (maxDay + start) / 7;
    float remain = (maxDay + start) % 7;
    
    if(row >= 5 && remain != 0) {
        row = 6;
    } else {
        row = 5;
    }


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
                                    printf("%s ", writeRoom(b, roomDay, m, 0));
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

int getDailyView(int day, int month) {
    int row = 6;
    int column = 10;
    char textRoom[6];
    char head[10][12] = {"ROOM", "09:00-10:00", "10:00-11:00", "11:00-12:00", "12:00-13:00", "13:00-14:00", "14:00-15:00", "15:00-16.00","16:00-17.00", "Summary"};
    bookDB booking = getBookingDB();

    int a,b,c;
    int check = 0;

    printf("\nYou are looking: %d %s\n\n", day, getMonth(month));

    for(a = 0; a < row; a++) {

        // HEAD
        printf("|");
        for(b = 0; b < column; b++) {
            for(c = 0; c < 11; c++) {
                printf("-");
            }
            printf("|");
        }
        printf("\n");

        // INFO
            for(b = 0; b < column; b++) {
                printf("|");
                if(a == 0) {
                    if(b == 0 || b == column - 1) {
                        printf("%8s   ", head[b]);
                    } else {
                        printf("%s", head[b]);
                    }
                } else {
                    if(b == 0) {
                        sprintf(textRoom, "IT%d", getRoom(a));
                        printf("%8s   ",textRoom);
                    } else {
                        for(c = 0; c < booking.arrLength; c++) {
                            if(booking.room[c] == getRoom(a) && booking.day[c] == day && booking.month[c] == month) {
                                if(booking.startTime[c] == (8+b)&&booking.startTime[c]!= booking.endTime[c]) {
                                    printf("     X     ");
                                    booking.startTime[c]=booking.startTime[c]+1;
                                    check = 1;
                                    break;
                                }
                            }
                        }
                        if(check == 0 && b != 9) {
                            printf("           ");
                        } else if(b == 9) {
                            printf("   %s  ",  writeRoom(a, day, getMonth(month), 1));
                        }
                    }
                    check = 0;
                }
            }
        printf("|");
        printf("\n");

        if(a == row - 1) {
            printf("|");
            for(b = 0; b < column; b++) {
                for(c = 0; c < 11; c++) {
                    printf("-");
                }
                printf("|");
            }
            printf("\n");
        }
    }

    return 0;
}

int roomAbilityPage() {
    char month[3];
    char day[10];
    int dayInt;
    int monthInt;
    char view[1];
    int ck=0;

    if(STUDENT_ID) {
        printf("Room Ability page\n");

        printf("Please select a style to show the available meeting rooms: monthly view (m or M) and daily view (d or D):");

        if(scanf("%s",&view) == EOF)
        {
            printf("\n");
            return 0;

        } else if (strcmp(view, "m") == 0 || strcmp(view, "M") == 0) {
            printf("Enter your month [Jan, Feb, Mar, Api, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec]: ");

            if(scanf("%s", month) != EOF)
            {
                printf("\n");

                if(strlen(month) != 3) {
                    printf("invalid input");
                } else {
                    if(getMonthInt(month)) {

                        printMonth(month);
                        getCalendar(month);

                    } else {
                        printf("invalid input");
                    }
                }
            }
        } else if(strcmp(view, "d") == 0 || strcmp(view, "D") == 0) {
            do {

                printf("Enter your date [Eg. 10 Jan]: ");

                if(scanf("%s", day) == EOF)
                {   ck = 1;
                    break;
                }
                dayInt = atoi(day);

                scanf("%s", month);
                monthInt = getMonthInt(month);

            } while (dayInt < 1 || !monthInt);

            if(ck == 0) {
                getDailyView(dayInt, monthInt);
            }

        } else {
            printf("\nNo matching\n");
        }



    } else {
        printf("You are not logged!");
    }

    printf("\n\n");

    return 0;
}
