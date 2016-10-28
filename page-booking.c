int booking() {
    
    int room;
    int day;
    int month;
    int startTime;
    int endTime;
    
    
    bookDB booking = getBookingDB();
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
                printf("\nInvalid room\n");
                continue;
            }
            
            if(startTime > endTime) {
                printf("\nYour time is invalid\n");
                continue;
            }
            
            
            for (a = 0; a < booking.arrLength; a++) {
                if ((room == booking.room[a] && day == booking.day[a] && month == booking.month[a]) && (startTime == booking.startTime[a] || endTime == booking.endTime[a])) {
                    check = 0;
                    break;
                }
            }
            
            if(check) {
                msg = saveBookingDB(room, day, month, startTime, endTime, STUDENT_ID);
                if(msg) {
                    printf("You are booking successfully\n");
                }
            } else {
                printf("Room is not avilable\n");
            }
            
            break;
            
        }
        
    } else {
        printf("You are not logged!\n");
    }
    
    return 0;
}
