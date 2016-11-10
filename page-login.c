#include <stdio.h>

int loginPage() {
    userDB user = getUserDB(1);
    int student_id = 0;
    char password[100];
    int check = 0;
    int a;

    if(!STUDENT_ID) {

        printf("Login Page\n");

        do {
            printf("\nStudent ID: ");
            if(scanf("%d", &student_id)==EOF)
            {
                break;
            }

            printf("Password: ");
            if(scanf("%s", password)==EOF)
            {
                break;
            }

            if(numlen(student_id) != 7) {
                printf("Either Student ID or Password is wrong.\n");
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
                printf("Wrong Student ID or Password.");
            } else {
                printf("\nYou can now start using the system.");
                break;
            }


        } while (!check);

    } else {
        printf("You are logged!");
    }


    printf("\n\n");
    return student_id;
}
