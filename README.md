# Booking-system
when you downloaded or cloned this project. you have to change PATH OF DATABASE in database.c to your local path of folder database

# Notes
1. STUDENT_ID: Global variable which must be examined by whole functions excepts login page and register page
2. Every files are included in main.c, you can write your code in your file(assignment)

# Database
- user: register and login
- booking: booking, booking cancellation, booking report

# Pages
- page-registerstration.c
- page-login.c
- page-logout.c
- page-room.c
- page-booking.c
- page-bookingcancle.c
- page-bookingreport.c

# Helpers functions
- meuns: Prints menu
- numlen: Check length intergers

# Methods library
- strcmp<string.h>
  compare between 2 string and It will be returned to 0 if they are qualation. Ex if(strcmp("haha", "haha") == 0) will be true.
