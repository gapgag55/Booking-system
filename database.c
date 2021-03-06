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

typedef struct {

    int studentID[1000];
    char password[1000][100];
    char fname[1000][100];
    char lname[1000][100];
    char mobile[1000][10];
    int arrLength;

} userDB;

userDB getUserDB(int studentID);

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
    bookDB books = getBookingDB();
    int i;
    int check = 0;


    for(i = 0; i < books.arrLength; i++) {
        if(room == books.room[i] && day == books.day[i] && month == books.month[i]) {


            if(endTime>books.startTime[i]&&startTime<books.endTime[i]) {
                printf("\nTime: %d.00 - %d.00: is not available\n", books.startTime[i],books.endTime[i]);
                check = 1;
            }
        }
    }

    if (check) {
        printf("\nPlease try again.\n\n");
        return 2;
    }

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
    fclose(file);

    return 1;
}

int saveUserDB(char id[], char ipass[], char fname[], char lname[], char mobile[]) {
    FILE *file;
    userDB users = getUserDB(1);
    int i;

    for(i = 0; i < users.arrLength; i++) {
        if(users.studentID[i] == atoi(id)) {
            return 0;
        }
    }

    file = fopen(USER_DB_PATH, "a+");
    fprintf(file, "%s %s %s %s %s\n", id, ipass, fname, lname, mobile);
    fclose(file);

    return 1;
}

userDB getUserDB(int studentID) {
    FILE *file;
    int c = 0;
    userDB users;
    userDB user;
    int stop, i = 0;

    file = fopen(USER_DB_PATH, "r");

    // FOR LOGIN
    while (1) {
        stop = fscanf(file, "%d %s %s %s %s", &users.studentID[c], users.password[c], users.fname[c], users.lname[c], users.mobile[c]);

        if(stop == EOF) break;

        users.arrLength = c + 1;
        c = users.arrLength;
    }
    fclose(file);

    if(studentID != 1) {
        while(i < users.arrLength) {
            if(users.studentID[i] == studentID) {
                sprintf(user.fname[0], "%s", users.fname[i]);
                sprintf(user.lname[0], "%s", users.lname[i]);

                break;
            }
            i++;
        }
        return user;
    }


    return users;
}
