#include <stdio.h>

int logoutPage() {
    printf("---------Logout Page---------\n");
    if(STUDENT_ID) {

        printf("Goodbye!!!\n\n");

    } else {

        printf("\nYou cannot logout because you are not currently logged-in.\n\n");
    }

    return 0;
}
