int bookingCancellation() {
    
    int croom;
    int cday;
    int cstr;
    int cend;
    int cmonth;
    
    char roomChar[4];
    char dayChar[3];
    char monthChar[3];
    char startTimeChar[3];
    char endTimeChar[3];
    
    char start[12];
    char end[12];
    
    int count = 0;
    int i;
    int at = 0;
    int check = 0;
    
    bookDB books = getBookingDB();
    bookDB updateBook;
    
    printf("-------------Cancle Booking Page-------------\n");
    
    if(STUDENT_ID) {
        
        while(1) {
            
            printf("Enter the room [101-105]: ");
            if(scanf("%s",roomChar)!=EOF)
            {
                printf("Enter the date: ");
                if(scanf("%s", dayChar)!=EOF)
                {
                    printf("Enter the month [1-12]: ");
                    if(scanf("%s", monthChar)!=EOF)
                    {
                        printf("Enter the start time [9-16]: ");
                        if(scanf("%s", startTimeChar)!=EOF)
                        {
                            printf("Enter the end time [10-17]: ");
                            if(scanf("%s",endTimeChar)!=EOF)
                            {
                                croom = atoi(roomChar);
                                cday = atoi(dayChar);
                                cmonth = atoi(monthChar);
                                cstr = atoi(startTimeChar);
                                cend = atoi(endTimeChar);
                                
                                if(croom == 0 || cday == 0 || cmonth == 0 || cstr == 0 || cend == 0) {
                                    printf("\nSomething wrong!!\n\n");
                                    continue;
                                }
                                
                                for(i = 0; i < books.arrLength; i++)
                                {
                                    if(books.room[i] == croom && books.day[i] == cday && books.month[i] == cmonth && books.startTime[i] == cstr && books.endTime[i] == cend && books.studentID[i] == STUDENT_ID)
                                    {
                                        count++;
                                        at=i;
                                    }
                                }
                                if(count==1)
                                {
                                    count = 0;
                                    for(i = 0; i < books.arrLength; i++)
                                    {
                                        if(i!=at)
                                        {
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
                                        sprintf(start, "%s", checkTime(cstr));
                                        sprintf(end, "%s", checkTime(cend));
                                        
                                        printf("\nYou are successfully cancel the booking for the room No. %d between %d%s - %d%s.", croom, timeClock(cstr), checkTime(cstr), timeClock(cend), checkTime(cend));
                                    }
                                    
                                } else {
                                    if(!check) printf("\nPlease try again.\n");
                                }
                                
                                break;
                            } else break;
                            
                        } else break;
                        
                    } else break;
                
                } else break;
                
            } else break;
        }
        
    } else {
        printf("You are not logged!\n");
    }
    
    printf("\n\n");
    return 0;
}
