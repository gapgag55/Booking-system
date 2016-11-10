#include <stdio.h>

int logoutPage() {
    
    if(STUDENT_ID) {
        printf("Logout page\n");
        printf("Goodbye!!!");
        
    } else {
        printf("You have not logged");
    }

    return 0;
}
