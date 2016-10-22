#define USER_DB_PATH "/Users/sarayutlawilai/Desktop/c/booking-system/booking-system/database/user.txt"
#define BOOKING_DB_PATH "/Users/sarayutlawilai/Desktop/c/booking-system/booking-system/database/booking.txt"

typedef struct {
    
    int room[1000];
    int day[1000];
    int month[1000];
    int year[1000];
    int startTime[1000];
    int endTime[1000];
    int studentID[1000];
    int arrLength;
    
} bookDB;

bookDB getBookingDB() {
    FILE *file;
    int c = 0;
    bookDB books;
    
    file = fopen(BOOKING_DB_PATH, "r");
    
    while (1) {
        int stop = fscanf(file, "%d %d %d %d %d %d %d", &books.room[c], &books.day[c], &books.month[c], &books.year[c], &books.startTime[c], &books.endTime[c], &books.studentID[c]);
        
        if(stop == EOF) break;
        
        books.arrLength = c + 1;
        c = books.arrLength;
    }
    
    fclose(file);
    
    return books;
}


int saveBookingDB(int room, int day, int month, int year, int startTime, int endTime, int studentID) {
    FILE *file;

    file = fopen(BOOKING_DB_PATH, "a+");
    fprintf(file,"%d %d %d %d %d %d %d\n", room, day, month, year, startTime, endTime, studentID);
    fclose(file);
    
    return 0;
}

int saveUserDB(int id, char ipass[], char fname[], char lname[], char mobile[]) {
    FILE *file;
    
    file = fopen(USER_DB_PATH, "a+");
    fprintf(file, "%d %s %s %s %s\n", id, ipass, fname, lname, mobile);
    fclose(file);
    
    return 0;
}
