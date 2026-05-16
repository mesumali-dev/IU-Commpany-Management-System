#include "../include/attendance.h"
#include <stdio.h>
#include <string.h>

void clean_input(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void mark_attendance() {
    FILE *fp;
    fp = fopen("data/attendance.csv", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Attendance a;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter your username: ");
    fgets(a.username, sizeof(a.username), stdin);
    clean_input(a.username);

    printf("Enter today's date (dd-mm-yyyy): ");
    fgets(a.date, sizeof(a.date), stdin);
    clean_input(a.date);

    strcpy(a.status, "Present");

    fprintf(fp, "%s,%s,%s\n", a.username, a.date, a.status);
    printf("Attendance marked successfully for %s on %s!\n", a.username, a.date);

    fclose(fp);
}

void view_attendance() {
    FILE *fp;
    fp = fopen("data/attendance.csv", "r");
    if (fp == NULL) {
        printf("No attendance records found!\n");
        return;
    }

    Attendance a;

    printf("\n--- Attendance Records ---\n");
    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n", a.username, a.date, a.status) != EOF) {
        printf("User: %s | Date: %s | Status: %s\n", a.username, a.date, a.status);
    }
    fclose(fp);
}
