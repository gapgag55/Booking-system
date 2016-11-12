#include <stdio.h>

int loginPage() {
    userDB user = getUserDB(1);
    int student_id = 0;
    char password[100];
    int check = 0;
    int checkFunc = 0;
    int a;
    printf("---------Login Page---------\n");
   
    if(!STUDENT_ID) {

        do {
            printf("\nStudent ID: ");
            if(scanf("%d", &student_id)==EOF)
            {
                return 0;
            }

            printf("Password: ");
            if(scanf("%s", password)==EOF)
            {
                return 0;
            }

            if(numlen(student_id) != 7) {
                printf("Wrong Student ID or Password.\n");
                continue;
            }

            for(a = 0; a < user.arrLength; a++) {
                if(student_id == user.studentID[a]) {
                    if(strcmp(password, user.password[a]) == 0) {
                        check = 1;
                        student_id = user.studentID[a];
                        break;
                    }
                }
            }

            if(!check) {
                printf("Wrong Student ID or Password.\n");
            } else {
                printf("\nYou can now start using the system.");
                printf("\n\n");
                return student_id;

            }


        } while (!check);

    } else {
        printf("You are logged!\n\n");
        checkFunc = 1;
    }
    
    if(checkFunc) {
        return STUDENT_ID;
    } else {
        return 0;
    }
}
