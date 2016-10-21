#include <stdio.h>

int registrationPage() {
    
    FILE *user_database;
    
    char fname[30];
    char lname[30];
    char ipass[30];
    char cpass[30];
    char mobile[30];
    int id;
    
    printf("Enter your first name: ");
    scanf("%s", &fname);
    
    printf("Enter your last name: ");
    scanf("%s", &lname);
    
    printf("Enter your student ID: ");
    scanf("%d", &id);
    
    printf("Enter your password: ");
    scanf("%s", &ipass);
    
    printf("Enter confirm password: ");
    scanf("%s", &cpass);
    
    printf("Enter your mobile phone: ");
    scanf("%s", &mobile);
    
    if(strlen(fname) <= 0 || strlen(lname) <= 0) {
        printf("Plase enter your full name");
    } else if(numlen(id) != 7) {
        printf("You can use only 7 digit numbers for studentID");
    } else if(strlen(ipass) < 8) {
        printf("You must use at least 8 characters for password");
    } else if(strcmp(ipass, cpass) != 0) {
        printf("These password don't match");
    } else if(strlen(mobile) != 10) {
        printf("You must use only 10 digit numbers for mobile phone");
    } else {
        user_database = fopen(USER_DB_PATH, "a+");
        fprintf(user_database, "%d %s %s %s %s\n", id, ipass, fname, lname, mobile);
        fclose(user_database);
    }
    
    return 0;
}
