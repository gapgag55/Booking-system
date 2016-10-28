#include <stdio.h>

int loginPage() {
    userDB user = getUserDB(1);
    int student_id = 0;
    char password[100];
    int check = 0;
    int a;
    
    printf("Login Page\n");
    
    do {
        printf("\nStudent ID: ");
        scanf("%d", &student_id);
        
        printf("Password: ");
        scanf("%s", password);
        
        for(a = 0; a < user.arrLength; a++) {
            if(student_id == user.studentID[a]) {
                if(strcmp(password, user.password[a])) {
                    check = 1;
                    student_id = user.studentID[a];
                    break;
                }
            }
        }
        
        if(!check) {
            printf("Wrong: Student ID or Password");
        } else {
            printf("\nNow you can start using the system");
        }
    
        
    } while (!check);
    
    printf("\n\n");
    return student_id;
}
