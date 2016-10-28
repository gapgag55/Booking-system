#define USER_DB_PATH "/Users/sarayutlawilai/Desktop/c/booking-system/booking-system/database/user.txt"
#define BOOKING_DB_PATH "/Users/sarayutlawilai/Desktop/c/booking-system/booking-system/database/booking.txt"

typedef struct {
    
    int room[1000];
    int day[1000];
    int month[1000];
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
        int stop = fscanf(file, "%d %d %d %d %d %d", &books.room[c], &books.day[c], &books.month[c], &books.startTime[c], &books.endTime[c], &books.studentID[c]);
        
        if(stop == EOF) break;
        
        books.arrLength = c + 1;
        c = books.arrLength;
    }
    
    fclose(file);
    
    return books;
}


int saveBookingDB(int room, int day, int month, int startTime, int endTime, int studentID) {
    FILE *file;

    file = fopen(BOOKING_DB_PATH, "a+");
    fprintf(file,"%d %d %d %d %d %d\n", room, day, month, startTime, endTime, studentID);

    fclose(file);
    
    return 1;
}

int updateBookingDB(bookDB update) {
    FILE *file;
    int i;
    
    file = fopen(BOOKING_DB_PATH, "w+");
    for(i = 0; i < update.arrLength; i++) {
        fprintf(file,"%d %d %d %d %d %d\n", update.room[i], update.day[i], update.month[i], update.startTime[i], update.endTime[i], update.studentID[i]);
    }
    
    return 1;
}

int saveUserDB(int id, char ipass[], char fname[], char lname[], char mobile[]) {
    FILE *file;
    
    file = fopen(USER_DB_PATH, "a+");
    fprintf(file, "%d %s %s %s %s\n", id, ipass, fname, lname, mobile);
    fclose(file);
    
    return 0;
}
