#ifndef ATTENDANCE_H
#define ATTENDANCE_H

typedef struct {
    char username[50];
    char date[20];
    char status[20];
} Attendance;

void mark_attendance();
void view_attendance();

#endif
