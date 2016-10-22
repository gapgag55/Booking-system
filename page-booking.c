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
        
        do {
            printf("Enter your room: ");
            scanf("%d", &room);
        } while (room < 101 || room > 105);
        
        do {
            printf("Enter your day: ");
            scanf("%d", &day);
        } while (day < 1 || day > 31);
        
        do {
            printf("Enter your month: ");
            scanf("%d", &month);
        } while (month < 1 || month > 12);
        
        do {
            printf("Enter your year: ");
            scanf("%d", &year);
        } while (year < 2016);
        
        do {
            printf("Enter your start time: ");
            scanf("%d", &startTime);
        } while (startTime < 9 || startTime > 17);
        
        do {
            printf("Enter your end time: ");
            scanf("%d", &endTime);
        } while (startTime >= endTime || endTime < 9 || endTime > 17);

        
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
        
        
    } else {
        printf("You are not logged!");
    }
    
    return 0;
}
