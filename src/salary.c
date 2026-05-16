#include "../include/salary.h"
#include <stdio.h>
#include <string.h>

void clean_input(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void calculate_salary() {
    FILE *f_att;
    f_att = fopen("data/attendance.csv", "r");
    if (f_att == NULL) {
        printf("No attendance records found to calculate salary!\n");
        return;
    }

    Salary s;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter username to calculate salary: ");
    fgets(s.username, sizeof(s.username), stdin);
    clean_input(s.username);

    char user[50], date[20], status[20];
    s.present_days = 0;
    while (fscanf(f_att, "%[^,],%[^,],%[^\n]\n", user, date, status) != EOF) {
        if (strcmp(user, s.username) == 0 && strcmp(status, "Present") == 0) {
            s.present_days++;
        }
    }
    fclose(f_att);

    if (s.present_days == 0) {
        printf("No present days found for user %s.\n", s.username);
        return;
    }

    int daily_rate = 2000;
    s.total_salary = s.present_days * daily_rate;

    printf("User %s was present for %d days.\n", s.username, s.present_days);
    printf("Total Salary: %d\n", s.total_salary);

    FILE *f_sal;
    f_sal = fopen("data/salary.csv", "a");
    if (f_sal != NULL) {
        fprintf(f_sal, "%s,%d,%d\n", s.username, s.present_days, s.total_salary);
        fclose(f_sal);
        printf("Salary record saved successfully!\n");
    }
}

void view_salary_records() {
    FILE *fp;
    fp = fopen("data/salary.csv", "r");
    if (fp == NULL) {
        printf("No salary records found!\n");
        return;
    }

    Salary s;
    printf("\n--- Salary Records ---\n");
    while (fscanf(fp, "%[^,],%d,%d\n", s.username, &s.present_days, &s.total_salary) != EOF) {
        printf("User: %s | Days: %d | Total Salary: %d\n", s.username, s.present_days, s.total_salary);
    }
    fclose(fp);
}
