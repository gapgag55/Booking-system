int bookingCancellation() {
    
    int croom;
    int cday;
    int cstr;
    int cend;
    char cmonth[3];
    int count = 0;
    int i;
    int at = 0;
    int check = 0;
    
    bookDB books = getBookingDB();
    bookDB updateBook;
    
    printf("-------------Cancle Booking page-------------\n");
    
    if(STUDENT_ID) {
        printf("Enter your room: ");
        scanf("%d",&croom);
        
        printf("Enter your day: ");
        scanf("%d",&cday);
        
        printf("Enter you month: ");
        scanf("%s", cmonth);
        
        printf("Enyer your start time: ");
        scanf("%d",&cstr);
        
        printf("Enter your end time: ");
        scanf("%d",&cend);
        
        
        for(i = 0; i < books.arrLength; i++) {
            if(books.room[i] == croom && books.day[i] == cday && books.startTime[i] == cstr && books.endTime[i] == cend && books.studentID[i] == STUDENT_ID)
            {
                count++;
                at=i;
            }
        }
        if(count==1) {
            count = 0;
            for(i = 0; i < books.arrLength; i++) {
                if(i!=at) {
                    updateBook.room[count] = books.room[i];
                    updateBook.day[count] = books.day[i];
                    updateBook.month[count] = books.month[i];
                    updateBook.startTime[count] = books.startTime[i];
                    updateBook.endTime[count] = books.endTime[i];
                    updateBook.studentID[count] = books.studentID[i];
                    
                    ++count;
                }
            }
            updateBook.arrLength = count;
            check = updateBookingDB(updateBook);
            
            if(check) {
                printf("you success fully canclel booking for the room no. %d at time %d.00am - %d.00am",croom,cstr,cend);
            }
        
        } else {
            if(!check) printf("please try again");
        }

    } else {
        printf("You are not logged!\n");
    }
    
    printf("\n\n");
    return 0;
}
