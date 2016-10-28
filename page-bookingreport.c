#define id 5988014

int bookingReport() {
    
    printf("-------------Booking page-------------\n\n");
    
    if(id) {
        bookDB booking = getBookingDB();
        bookDB bookUser;
        char head[4][5] = {"Room", "Date", "Time"};
        char room[6];
        int i;
        int a,b,c;
        int has = 0;
        int row = 0;
        char name[7];
        
        for(i = 0; i < booking.arrLength; i++) {
            if(booking.studentID[i] == id) {
            
                bookUser.room[row]      = booking.room[i];
                bookUser.day[row]       = booking.day[i];
                bookUser.month[row]     = booking.month[i];
                bookUser.startTime[row] = booking.startTime[i];
                bookUser.endTime[row]   = booking.endTime[i];
                
                has = 1;
                ++row;
                
                if(!name[0]) {
                    sprintf(name, "%s", "Kopkap");
                }
            }
        }
        
        if(has) {
            i = -1;
            printf("Name: %s\n", name);
            for(a = 0; a < (row * 2) + 3; a++) {
                for(b = 0; b < 3; b++) {
                    printf("|");
                    if(a % 2 == 0) {
                        if(b == 0) {
                            for(c = 0; c < 10; c++) {
                                printf("-");
                            }
                        } else {
                            for(c = 0; c < 15; c++) {
                                printf("-");
                            }
                        }
                    } else {
                        if(a == 1) {
                            if(b == 0) {
                                printf("%7s   ", head[b]);
                            } else {
                                printf("%10s     ", head[b]);
                            }
                        } else {
                            // GET ROOM
                            if(b == 0) {
                                sprintf(room, "IT%d", bookUser.room[i]);
                                printf("%7s   ", room);
                            } else if(b == 1) {
                                printf("%7d %3s    ", bookUser.day[i], getMonth(bookUser.month[i]));
                            } else {
                                printf("%4d.00-%d.00  ", bookUser.startTime[i], bookUser.endTime[i]);
                            }
                        }
                    }
                }
                if(a % 2 != 0) {
                    ++i;
                }
                printf("|\n");
            }
        } else {
            printf("You are not booking yet");
        }

    } else {
         printf("You are not logged!");
    }
    printf("\n");
    return 0;
}
