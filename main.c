#include <stdio.h>
#include <string.h>

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
    
    int STUDENT_ID = 0;
    
    char choice;
    
    printf("\t\tICT MEETING ROOM SYSTEM\n\n");
    
    menus('r', 'R', "user registration");
    menus('i', 'I', "login");
    menus('o', 'O', "logout");
    menus('a', 'A', "room availability");
    menus('b', 'B', "booking");
    menus('c', 'C', "booking cancellation");
    menus('p', 'P', "booking report");
    
    while(1) {
        printf("\nEnter menu: ");
        scanf(" %c", &choice);
        
        if(choice == 'r' || choice == 'R') {
            registrationPage();
            
        } else if(choice == 'i' || choice == 'I') {
            loginPage();
            
        } else if(choice == 'o' || choice == 'O') {
            logoutPage();
            
        } else if(choice == 'a' || choice == 'A') {
            roomAbilityPage();
            
        } else if(choice == 'b' || choice == 'B') {
            booking();
            
        } else if(choice == 'c' || choice == 'C') {
            bookingCancellation();
            
        } else if(choice == 'p' || choice == 'P') {
            bookingReport();
            
        } else {
            printf("Invalid menu");
        }
        
    }
    
    return 0;
    
    printf("\n\n\n");
    return 0;
}
