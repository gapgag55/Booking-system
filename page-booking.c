int booking() {

    int room;
    int day;
    int month;
    int startTime;
    int endTime;
    
    char roomChar[4];
    char dayChar[3];
    char monthChar[3];
    char startTimeChar[3];
    char endTimeChar[3];
    
    int msg;
    int check = 1;

    printf("-------------Booking Page-------------\n");


    if(STUDENT_ID) {

        while (1) {
            printf("Enter the room [101-105]: ");
            if(scanf("%s", roomChar)==EOF)
            {
                break;
            }
            printf("Enter the date: ");
            if(scanf("%s", dayChar)==EOF)
            {
                break;
            }
            printf("Enter the month [1-12]: ");
            if(scanf("%s", monthChar)==EOF)
            {
                break;
            }
            printf("Enter the start time [9-16]: ");
            if(scanf("%s", startTimeChar)==EOF)
            {
                break;
            }
            printf("Enter the end time [10-17]: ");
            if(scanf("%s", endTimeChar)==EOF)
            {
                break;
            }
            
            room = atoi(roomChar);
            day = atoi(dayChar);
            month = atoi(monthChar);
            startTime = atoi(startTimeChar);
            endTime = atoi(endTimeChar);
            
            if(room == 0 || day == 0 || month == 0 || startTime == 0 || endTime == 0) {
                printf("\nSomething wrong!!\n");
                continue;
            }

            if((day<1||day>checkDay(month)) || (month<1||month>12) || (room < 101 || room > 105) || (startTime >= endTime) || (startTime < 9 || startTime > 16 || endTime < 10 || endTime > 17)) {
                check = 0;
            }

            if(check) {
                if(!checkSunday(day, month)) {
                    msg = saveBookingDB(room, day, month, startTime, endTime, STUDENT_ID);

                    if(msg == 1) {
                        printf("\nYou are successfully booked.\n");
                        printf("You have booked room no. %d on date %d %s, from %d%s - %d%s\n\n", room, day, getMonth(month), timeClock(startTime), checkTime(startTime), timeClock(endTime), checkTime(endTime));
                    }
                    break;
                } else {
                    printf("\nYou can't book at %d %s (Sunday)\n\n", day, getMonth(month));
                }
            } else {
                printf("\nInvalid booking\n\n");
            }
            check = 1;
        }

    } else {

        printf("You are not logged!\n");
    }

    return 0;
}
