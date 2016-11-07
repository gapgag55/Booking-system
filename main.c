#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int STUDENT_ID = 0;

#include "database.c"
#include "helpers.c"

#include "page-registerstration.c"
#include "page-login.c"
#include "page-logout.c"
#include "page-room.c"
#include "page-booking.c"
#include "page-bookingcancle.c"
#include "page-bookingreport.c"


int main() {

    char choice[5];

    while(1) {
    	printf("\t\tICT MEETING ROOM SYSTEM\n\n");

    	menus('r', 'R', "user registration");
    	menus('i', 'I', "login");
    	menus('o', 'O', "logout");
    	menus('a', 'A', "room availability");
    	menus('b', 'B', "booking");
    	menus('c', 'C', "booking cancellation");
    	menus('p', 'P', "booking report");


        printf("\nEnter menu: ");
        scanf("  %s", choice);
        
        if(atoi(choice)) {
            continue;
        }

            if(strcmp(choice, "r") == 0 || strcmp(choice, "R") == 0) {
                registrationPage();

            } else if(strcmp(choice, "i") == 0 || strcmp(choice, "I") == 0) {
                STUDENT_ID = loginPage();

            } else if(strcmp(choice, "o") == 0 || strcmp(choice, "O") == 0) {
                STUDENT_ID = logoutPage();

            } else if(strcmp(choice, "a") == 0 || strcmp(choice, "A") == 0) {
                roomAbilityPage();

            } else if(strcmp(choice, "b") == 0 || strcmp(choice, "B") == 0) {
                booking();

            } else if(strcmp(choice, "c") == 0 || strcmp(choice, "C") == 0) {
                bookingCancellation();

            } else if(strcmp(choice, "p") == 0 || strcmp(choice, "P") == 0) {
                bookingReport();

            } else {
                printf("Invalid menu\n");
            }
    }

    return 0;
}
