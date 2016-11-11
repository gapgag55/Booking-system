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
    int ck;

    bookDB books = getBookingDB();
    bookDB updateBook;

    printf("-------------Cancle Booking Page-------------\n");

    if(STUDENT_ID) {
        printf("Enter the room: ");
        if(scanf("%d",&croom)!=EOF)
        {
            printf("Enter the date: ");
            if(scanf("%d",&cday)!=EOF)
            {
                printf("Enter the month: ");
                if(scanf("%s", cmonth)!=EOF)
                {
                    printf("Enter the start time: ");
                    if(scanf("%d",&cstr)!=EOF)
                    {
                        printf("Enter the end time: ");
                        if(scanf("%d",&cend)!=EOF)
                        {
                            for(i = 0; i < books.arrLength; i++)
                            {
                                if(books.room[i] == croom && books.day[i] == cday && books.startTime[i] == cstr && books.endTime[i] == cend && books.studentID[i] == STUDENT_ID)
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


                                    if(check)
                                        {
                                            printf("\nYou are successfully cancel the booking for the room No. %d between %d.00am/pm - %d.00am/pm.", croom, cstr, checkTime(cstr), cend, checkTime(cend));
                                        }

                                    } else
                                        {
                                            if(!check) printf("Please try again.");
                                        }
                            }

                        }

                }

            }
        }


    } else {
        printf("You are not logged!\n");
    }

    printf("\n\n");
    return 0;
}
