#include "../include/reports.h"
#include <stdio.h>
#include <string.h>

void view_reports() {
    FILE *fp;
    int user_count = 0;
    int task_count = 0;
    int total_salary = 0;
    float total_transactions = 0;

    // Count Users
    fp = fopen("data/users.csv", "r");
    if (fp != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strlen(buffer) > 1) user_count++;
        }
        fclose(fp);
    }

    // Count Tasks
    fp = fopen("data/tasks.csv", "r");
    if (fp != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strlen(buffer) > 1) task_count++;
        }
        fclose(fp);
    }

    // Sum Salary
    fp = fopen("data/salary.csv", "r");
    if (fp != NULL) {
        char user[50];
        int days, sal;
        while (fscanf(fp, "%[^,],%d,%d\n", user, &days, &sal) != EOF) {
            total_salary += sal;
        }
        fclose(fp);
    }

    // Sum Transactions
    fp = fopen("data/transactions.csv", "r");
    if (fp != NULL) {
        int id;
        char date[20], desc[100];
        float amount;
        while (fscanf(fp, "%d,%[^,],%f,%[^\n]\n", &id, date, &amount, desc) != EOF) {
            total_transactions += amount;
        }
        fclose(fp);
    }

    printf("\n--- Company System Report ---\n");
    printf("Total Registered Users: %d\n", user_count);
    printf("Total Tasks Assigned: %d\n", task_count);
    printf("Total Salary Distributed: %d\n", total_salary);
    printf("Total Financial Transactions: %.2f\n", total_transactions);
}
