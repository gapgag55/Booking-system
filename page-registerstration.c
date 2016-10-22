#include <stdio.h>

int registrationPage() {
    
    FILE *user_database;
    
    char fname[30];
    char lname[30];
    char ipass[30];
    char cpass[30];
    char mobile[30];
    int id;
    int c = 0;
    
    printf("Enter your first name: ");
    scanf("%s", &fname);
    
    printf("Enter your last name: ");
    scanf("%s", &lname);
    
    
    while(numlen(id) != 7) {
        if(c) printf("You can use only 7 digit numbers for studentID\n");
        printf("Enter your student ID: ");
        scanf("%d", &id);
        ++c;
        if(numlen(id) == 7) {
            c = 0;
            break;
        }
    }
    
    while(strlen(ipass) < 8) {
        if(c) printf("You must use at least 8 characters for password\n");
        printf("Enter your password: ");
        scanf("%s", &ipass);
        ++c;
        if(strlen(ipass) >= 8) {
            c = 0;
            break;
        }
    }
    
    
    while(strcmp(ipass, cpass) != 0) {
        if(c) printf("These password don't match\n");
        printf("Enter confirm password: ");
        scanf("%s", &cpass);
        ++c;
        if(strcmp(ipass, cpass) == 0) {
            c = 0;
            break;
        }
    }
    

    while (strlen(mobile) != 10) {
        if(c) printf("You must use only 10 digit numbers for mobile phone\n");
        printf("Enter your mobile phone: ");
        scanf("%s", &mobile);
        ++c;
        if(strlen(mobile) == 10) {
            c = 0;
            break;
        }
    }
    
    
    saveUserDB(id, ipass, fname, lname, mobile);
    
    return 0;
}
