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
            printf("Enter your room: ");
            scanf("%d", &room);


            printf("Enter your day: ");
            scanf("%d", &day);

            printf("Enter your month: ");
            scanf("%d", &month);

            printf("Enter your start time: ");
            scanf("%d", &startTime);

            printf("Enter your end time: ");
            scanf("%d", &endTime);

            if(room < 101 || room > 105) {
                check = 0;
                printf("\nRoom isn't available.\n\n");
            }

            if(startTime > endTime) {
                check=0;
                printf("\nCan't booking your time.\n\n");
            }
            
            if(startTime < 9 && startTime > 16 && endTime < 10 && endTime > 17)
            {
                check = 0;
                printf("\nCan't booking your time.\n\n");
            }


            if(check) {
                msg = saveBookingDB(room, day, month, startTime, endTime, STUDENT_ID);
                
                if(msg == 1) {
                    printf("\nYou are booking successfully\n\n");
                } else {
                    if(msg != 3) printf("\nRoom is not available.\n\n");
                }
                
                break;
            }
            check = 1;
        }

    } else {
        printf("You are not logged!\n");
    }

    return 0;
}
