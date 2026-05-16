#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef struct {
    int id;
    char date[20];
    float amount;
    char description[100];
} Transaction;

void add_transaction();
void search_transaction();

#endif
