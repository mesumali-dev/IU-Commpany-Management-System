#ifndef SALARY_H
#define SALARY_H

typedef struct {
    char username[50];
    int present_days;
    int total_salary;
} Salary;

void calculate_salary();
void view_salary_records();

#endif
