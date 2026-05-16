#include "../include/task.h"
#include <stdio.h>
#include <string.h>
#include "../include/utils.h"


void assign_task() {
    FILE *fp;
    fp = fopen("data/tasks.csv", "a+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Task t;
    int last_id = 0;
    Task temp;
    
    rewind(fp);
    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &temp.id, temp.task_name, temp.assigned_to, temp.status, temp.deadline) != EOF) {
        if(temp.id > last_id) {
            last_id = temp.id;
        }
    }
    t.id = last_id + 1;

    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Enter task name: ");
    fgets(t.task_name, sizeof(t.task_name), stdin);
    clean_input(t.task_name);

    printf("Enter username of employee: ");
    fgets(t.assigned_to, sizeof(t.assigned_to), stdin);
    clean_input(t.assigned_to);

    printf("Enter deadline (date): ");
    fgets(t.deadline, sizeof(t.deadline), stdin);
    clean_input(t.deadline);

    strcpy(t.status, "Pending");

    fprintf(fp, "%d,%s,%s,%s,%s\n", t.id, t.task_name, t.assigned_to, t.status, t.deadline);
    printf("Task added successfully!\n");

    fclose(fp);
}

void view_assign_task() {
    FILE *fp;
    fp = fopen("data/tasks.csv", "r");
    if(fp == NULL) {
        printf("No tasks to show!\n");
        return;
    }

    Task t;
    printf("\n--- Task List ---\n");
    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &t.id, t.task_name, t.assigned_to, t.status, t.deadline) != EOF) {
        printf("ID: %d | Task: %s | For: %s | Status: %s | Deadline: %s\n", t.id, t.task_name, t.assigned_to, t.status, t.deadline);
    }
    fclose(fp);
}

void update_task_status() {
    FILE *fp, *ftemp;
    fp = fopen("data/tasks.csv", "r");
    if(fp == NULL) {
        printf("No tasks found!\n");
        return;
    }

    ftemp = fopen("data/temp.csv", "w");
    
    int search_id;
    printf("Enter task ID to mark as complete: ");
    scanf("%d", &search_id);

    Task t;
    int found = 0;
    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &t.id, t.task_name, t.assigned_to, t.status, t.deadline) != EOF) {
        if(t.id == search_id) {
            strcpy(t.status, "Completed");
            found = 1;
        }
        fprintf(ftemp, "%d,%s,%s,%s,%s\n", t.id, t.task_name, t.assigned_to, t.status, t.deadline);
    }

    fclose(fp);
    fclose(ftemp);

    remove("data/tasks.csv");
    rename("data/temp.csv", "data/tasks.csv");

    if(found == 1) {
        printf("Task updated to Completed!\n");
    } else {
        printf("Task not found!\n");
    }
}
