#include <stdio.h>
#include <stdlib.h>

int bookingCancellation() {
    int croom,cdate,cstr,cend,count=0,i,at;
    bookDB text = getBookingDB();
    printf("%d",text.arrLength);
    scanf("%d",&croom);
    scanf("%d",&cdate);
    scanf("%d",&cstr);
    scanf("%d",&cend);
    for(i=0;i<text.arrLength;i++)
    {
        if(text.day[i]==cdate&&text.room[i]==croom&&text.startTime[i]==cstr&&text.endTime[i]==cend&&text.studentID[i]==studentid)
        {
            count++;
            at=i;
        }
    }
    if(count==1)
    {
        FILE *file;
        file = fopen(BOOKING_DB_PATH, "w");
        for(i=0;i<text.arrLength;i++)
        {
            if(i!=at)
            {
                fprintf(file,"%d %d %d %d %d %d %d\n",text.room[i],text.day[i],text.month[i], text.year[i],text.startTime[i], text.endTime[i], text.studentID[i]);
            }
        }

    fclose(file);
    printf("you success fully canclel booking for the room no. %d at time %d.00am-%d.00am",croom,cstr,cend);
    }else
    {
        printf("please try again");
    }
    printf("%d",text.arrLength);
    return 0;
}
