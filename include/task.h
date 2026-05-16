#ifndef TASK_H
#define TASK_H

typedef struct {
    int id;
    char task_name[100];
    char assigned_to[50];
    char status[20];
    char deadline[20];
} Task;

void assign_task();
void view_assign_task();
void update_task_status();

#endif
