int registrationPage() {

    char fname[30];
    char lname[30];
    char ipass[30];
    char cpass[30];
    char mobile[30];
    char id[30];
    int c = 0;
    int check = 0;

   printf("---------Registration Page---------\n");
    if(!STUDENT_ID)
    {



    printf("Enter your first name: ");
    if(scanf("%s", fname) == EOF) { return 0; }

    printf("Enter your last name: ");
    if(scanf("%s", lname) == EOF) { return 0; }


    while(strlen(id) != 7) {
        if(c) printf("You can use only 7 digit numbers for studentID\n");
        printf("Enter your student ID: ");
        if(scanf("%s", id) == EOF) { return 0; }
        ++c;
        if(strlen(id) == 7) {
            c = 0;
            break;
        }
    }

    while(strlen(ipass) < 8) {
        if(c) printf("You must use at least 8 characters for password\n");
        printf("Enter your password: ");
        if(scanf("%s", ipass)== EOF) { return 0; }
        ++c;
        if(strlen(ipass) >= 8) {
            c = 0;
            break;
        }
    }


    while(strcmp(ipass, cpass) != 0) {
        if(c) printf("These password don't matches.\n");
        printf("Enter confirm password: ");
        if(scanf("%s", cpass) == EOF) { return 0; }
        ++c;
        if(strcmp(ipass, cpass) == 0) {
            c = 0;
         break;
        }
    }


    while (strlen(mobile) != 10) {
        if(c) printf("You must use only 10 digit numbers for phone number.\n");
        printf("Enter your phone number.: ");
        if(scanf("%s", mobile) == EOF ) { return 0 ;}
        ++c;
        if(strlen(mobile) == 10) {
            c = 0;
            break;
        }
    }


       check = saveUserDB(id, ipass, fname, lname, mobile);

    if(check) {
        printf("\nYou are successfully registered.\n");
        printf("Now you can start using the system.\n\n");
        return atoi(id);
    } else {

        printf("\nYour student ID is not available.\n\n");
    }

    return 0;
    }else{

        printf("You are logged!\n");
        return STUDENT_ID;
    }
}
