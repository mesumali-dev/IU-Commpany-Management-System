#include "include/auth.h"
#include <stdio.h>

int main() {

    int choice;

    while(1) {

        printf("\n===== Company Management System =====\n");

        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                login_user();
                break;

            case 2:
                register_user();
                break;

            case 3:
                printf("Program Closed\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}