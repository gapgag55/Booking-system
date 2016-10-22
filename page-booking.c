#include <stdio.h>

int booking() {
    
    int room;
    int day;
    int month;
    int year;
    int startTime;
    int endTime;
    
    
    bookDB booking = getBookingDB();
    int check = 1;
    int a;
    
    printf("-------------Booking page-------------\n");
    

    if(STUDENT_ID == 0) {
        
        while (1) {
            printf("Enter your room: ");
            scanf("%d", &room);

            
            printf("Enter your day: ");
            scanf("%d", &day);
            
            printf("Enter your month: ");
            scanf("%d", &month);
            
            printf("Enter your year: ");
            scanf("%d", &year);
            
            printf("Enter your start time: ");
            scanf("%d", &startTime);
            
            printf("Enter your end time: ");
            scanf("%d", &endTime);
            
            if(room < 101 || room > 105) {
                printf("\nInvalid room\n");
                continue;
            }

            
            for (a = 0; a < booking.arrLength; a++) {
                if ((room == booking.room[a] && day == booking.day[a] && month == booking.month[a] && year == booking.year[a]) && (startTime == booking.startTime[a] || endTime == booking.endTime)) {
                    check = 0;
                    break;
                }
            }
            
            if(check) {
                saveBookingDB(room, day, month, year, startTime, endTime, STUDENT_ID);
            } else {
                printf("Room is not avilable");
            }
            
            break;
        
        }
        
    } else {
        printf("You are not logged!");
    }
    
    return 0;
}
