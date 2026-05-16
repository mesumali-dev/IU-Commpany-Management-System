#include <stdio.h>
#include <string.h>
#include "../include/dashboard.h"
#include "../include/auth.h"
#include "../include/task.h"
#include "../include/attendance.h"
#include "../include/salary.h"

void show_admin_dashboard() {
    int choice;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    do {
        printf("\n--- Admin Dashboard ---\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Assign Task\n");
        printf("4. Search Employee\n");
        printf("5. View Reports\n");
        printf("6. View Attendance\n");
        printf("7. View Tasks\n");
        printf("8. Logout\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            choice = 0;
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: 
                printf("Add Employee section coming soon!\n"); 
                break;
            case 2: 
                printf("Delete Employee section coming soon!\n"); 
                break;
            case 3: 
                assign_task(); 
                break;
            case 4: 
                printf("Search Employee section coming soon!\n"); 
                break;
            case 5: 
                printf("View Reports section coming soon!\n"); 
                break;
            case 6: 
                view_attendance(); 
                break;
            case 7:
                view_assign_task();
                break;
            case 8: 
                logout_user(); 
                break;
            default: 
                printf("Invalid Option!\n");
        }
    } while (choice != 8);
}

void show_accountant_dashboard() {
    int choice;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
    do {
        printf("\n--- Accountant Dashboard ---\n");
        printf("1. Add Transactions\n");
        printf("2. Calculate Salary\n");
        printf("3. View Salary Records\n");
        printf("4. Search Transactions\n");
        printf("5. Logout\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0;
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: 
                printf("Add Transactions coming soon!\n"); 
                break;
            case 2: 
                calculate_salary(); 
                break;
            case 3: 
                view_salary_records(); 
                break;
            case 4: 
                printf("Search Transactions coming soon!\n"); 
                break;
            case 5: 
                logout_user(); 
                break;
            default: 
                printf("Invalid Option!\n");
        }
    } while (choice != 5);
}

void show_employee_dashboard() {
    int choice;
    do {
        printf("\n--- Employee Dashboard ---\n");
        printf("1. Mark Attendance\n");
        printf("2. View Assign Task\n");
        printf("3. Update Your Task Status\n");
        printf("4. Logout\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0;
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: 
                mark_attendance(); 
                break;
            case 2: 
                view_assign_task(); 
                break;
            case 3: 
                update_task_status(); 
                break;
            case 4: 
                logout_user(); 
                break;
            default: 
                printf("Invalid Option!\n");
        }
    } while (choice != 4);
}

void show_dashboard(char *role) {
    if (strcmp(role, "Admin") == 0) {
        show_admin_dashboard();
    } else if (strcmp(role, "Accountant") == 0) {
        show_accountant_dashboard();
    } else if (strcmp(role, "Employee") == 0) {
        show_employee_dashboard();
    } else {
        printf("Error: Unknown role '%s'\n", role);
    }
}
