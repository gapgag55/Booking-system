#include <stdio.h>

int logoutPage() {
    
    if(STUDENT_ID) {
    printf("Logout page\n");
    printf("Goodbye!!!");
    
    printf("\n\n");
    } else {
        printf("You are not logged!\n");
    }
    return 0;
}
