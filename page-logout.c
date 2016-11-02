#include <stdio.h>

int logoutPage() {
    
    if(STUDENT_ID) {
        printf("Logout page\n");
        printf("Goodbye!!!");
        
    } else {
        printf("You aren't logged");
    }
    
    printf("\n\n");
    return 0;
}
