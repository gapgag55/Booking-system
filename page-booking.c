int booking() {

    int room;
    int day;
    int month;
    int startTime;
    int endTime;
    int msg;
    int check = 1;
    int a;

    printf("-------------Booking page-------------\n");


    if(STUDENT_ID) {

        while (1) {
            printf("Enter the room [101-105]: ");
            if(scanf("%d", &room)==EOF)
            {
                break;
            }
            printf("Enter the day: ");
            if(scanf("%d", &day)==EOF)
            {
                break;
            }
            printf("Enter the month [1-12]: ");
            if(scanf("%d", &month)==EOF)
            {
                break;
            }
            printf("Enter the start time [9-16]: ");
            if(scanf("%d", &startTime)==EOF)
            {
                break;
            }
            printf("Enter the end time [10-17]: ");
            if(scanf("%d", &endTime)==EOF)
            {
                break;
            }

            if((day<1||day>checkDay(month)) || (month<1||month>12) || (room < 101 || room > 105) || (startTime > endTime) || (startTime < 9 || startTime > 16 || endTime < 10 || endTime > 17)) {
                check = 0;
            }

            if(check) {
                if(!checkSunday(day, month)) {
                    if(check) {
                        msg = saveBookingDB(room, day, month, startTime, endTime, STUDENT_ID);

                        if(msg == 1) {
                            printf("\nYour booking successful.\n");
                            printf("You habe booked room no. %d on date %d %s, from %d%s - %d%s\n\n", room, day, getMonth(month), startTime, checkTime(startTime), endTime, checkTime(endTime));
                        }
                        break;
                    }
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
