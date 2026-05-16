#include "../include/transaction.h"
#include <stdio.h>
#include <string.h>
#include "../include/utils.h"


void add_transaction() {
    FILE *fp;
    fp = fopen("data/transactions.csv", "a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Transaction t;
    Transaction temp;
    int last_id = 0;
    
    rewind(fp);
    while (fscanf(fp, "%d,%[^,],%f,%[^\n]\n", &temp.id, temp.date, &temp.amount, temp.description) != EOF) {
        if (temp.id > last_id) {
            last_id = temp.id;
        }
    }
    t.id = last_id + 1;

    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Enter date (dd-mm-yyyy): ");
    fgets(t.date, sizeof(t.date), stdin);
    clean_input(t.date);

    printf("Enter amount: ");
    scanf("%f", &t.amount);
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Enter description: ");
    fgets(t.description, sizeof(t.description), stdin);
    clean_input(t.description);

    fprintf(fp, "%d,%s,%.2f,%s\n", t.id, t.date, t.amount, t.description);
    printf("Transaction added successfully!\n");

    fclose(fp);
}

void search_transaction() {
    FILE *fp;
    fp = fopen("data/transactions.csv", "r");
    if (fp == NULL) {
        printf("No transactions found!\n");
        return;
    }

    char keyword[50];
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    
    printf("Enter date or description to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    clean_input(keyword);

    Transaction t;
    int found = 0;
    printf("\n--- Search Results ---\n");
    while (fscanf(fp, "%d,%[^,],%f,%[^\n]\n", &t.id, t.date, &t.amount, t.description) != EOF) {
        if (strstr(t.date, keyword) != NULL || strstr(t.description, keyword) != NULL) {
            printf("ID: %d | Date: %s | Amount: %.2f | Desc: %s\n", t.id, t.date, t.amount, t.description);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching transactions found.\n");
    }

    fclose(fp);
}

void view_all_transactions() {
    FILE *fp;
    fp = fopen("data/transactions.csv", "r");
    if (fp == NULL) {
        printf("No transactions found!\n");
        return;
    }

    Transaction t;
    printf("\n--- All Transactions ---\n");
    while (fscanf(fp, "%d,%[^,],%f,%[^\n]\n", &t.id, t.date, &t.amount, t.description) != EOF) {
        printf("ID: %d | Date: %s | Amount: %.2f | Desc: %s\n", t.id, t.date, t.amount, t.description);
    }

    fclose(fp);
}
