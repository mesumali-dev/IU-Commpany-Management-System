#include "../include/auth.h"
#include "../include/dashboard.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char username[50];
    char password[50];
    char role[50];
} User;

void clean_input(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void register_user() {
    FILE *fp;
    fp = fopen("data/users.csv", "a+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    User u, temp_u;
    int last_id = 0;
    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &temp_u.id, temp_u.name, temp_u.username, temp_u.password, temp_u.role) != EOF){
        if(temp_u.id >= last_id) {
            last_id = temp_u.id;
        }
    }
    u.id = last_id + 1;
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    
    printf("Enter name: ");
    fgets(u.name, sizeof(u.name), stdin);
    clean_input(u.name);

    int username_exists;
    do {
        username_exists = 0;
        printf("Enter username: ");
        fgets(u.username, sizeof(u.username), stdin);
        clean_input(u.username);

        rewind(fp); 
        while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &temp_u.id, temp_u.name, temp_u.username, temp_u.password, temp_u.role) != EOF){
            if(strcmp(u.username, temp_u.username) == 0){
                printf("Error! Username already exists. Please choose another.\n");
                username_exists = 1;
                break;
            }
        }
    } while(username_exists);

    printf("Enter password: ");
    fgets(u.password, sizeof(u.password), stdin);
    clean_input(u.password);

    int choice = 0;
    while(1){
        printf("\n--- Select User Role ---\n");
        printf("1. Admin\n");
        printf("2. Accountant\n");
        printf("3. Employee\n");
        printf("Enter choice (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            printf("Invalid input! Please enter numbers only.\n");
            continue;
        }
        
        if (choice == 1) { strcpy(u.role, "Admin"); break; }
        else if (choice == 2) { strcpy(u.role, "Accountant"); break; }
        else if (choice == 3) { strcpy(u.role, "Employee"); break; }
        else { printf("Invalid Option! Please choose 1, 2, or 3.\n"); }
    }
    
    fprintf(fp, "%d,%s,%s,%s,%s\n", u.id, u.name, u.username, u.password, u.role);
    printf("User registered successfully!\n");
    fclose(fp);
}

void login_user() {
    char input_username[50];
    char input_password[50];
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    
    FILE *fp; 
    User u;
    int login_success = 0; 
    
    printf("Enter username: ");
    fgets(input_username, sizeof(input_username), stdin);
    clean_input(input_username); 

    printf("Enter password: ");
    fgets(input_password, sizeof(input_password), stdin);
    clean_input(input_password); 

    fp = fopen("data/users.csv", "r");
    if(fp == NULL) {
        printf("Error opening file! Pehle register karein.\n");
        return;
    }

    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &u.id, u.name, u.username, u.password, u.role) != EOF) {
        if(strcmp(input_username, u.username) == 0 && strcmp(input_password, u.password) == 0) {
            login_success = 1; 
            break; 
        }
    }
    
    fclose(fp); 
    if (login_success == 1) {
        printf("User logged in successfully! Welcome %s (%s)\n", u.name, u.role);
        show_dashboard(u.role);
    } else {
        printf("Invalid credentials!\n");
    }
}

void logout_user() {
    printf("Logging out user...\n");
}

void search_employee() {
    FILE *fp;
    fp = fopen("data/users.csv", "r");
    if (fp == NULL) {
        printf("No users found!\n");
        return;
    }

    char keyword[50];
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Enter name or username to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    clean_input(keyword);

    User u;
    int found = 0;
    printf("\n--- Search Results ---\n");
    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &u.id, u.name, u.username, u.password, u.role) != EOF) {
        if (strstr(u.name, keyword) != NULL || strstr(u.username, keyword) != NULL) {
            printf("ID: %d | Name: %s | Username: %s | Role: %s\n", u.id, u.name, u.username, u.role);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching users found.\n");
    }

    fclose(fp);
}
