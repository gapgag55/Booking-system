#include <stdio.h>

int logoutPage() {
    printf("---------Logout Page---------\n");
    if(STUDENT_ID) {

        printf("Goodbye!!!");

    } else {

        printf("You cannot logout because you are not currently logged-in.\n");
    }

    return 0;
}
