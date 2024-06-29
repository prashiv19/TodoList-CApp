#include <stdio.h>
#include <string.h>
#include "todo.h"

void addTask(Task tasks[], int *taskCount, const char *description) {
    if (*taskCount < MAX_TASKS) {
        tasks[*taskCount].id = *taskCount + 1;
        strncpy(tasks[*taskCount].description, description, TASK_DESC_LENGTH - 1);
        tasks[*taskCount].completed = 0;
        (*taskCount)++;
    } else {
        printf("Task list is full.\n");
    }
}

void viewTasks(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n", tasks[i].id, tasks[i].completed ? 'x' : ' ', tasks[i].description);
    }
}

void markTaskCompleted(Task tasks[], int taskCount, int taskId) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            tasks[i].completed = 1;
            return;
        }
    }
    printf("Task not found.\n");
}

void deleteTask(Task tasks[], int *taskCount, int taskId) {
    int found = 0;
    for (int i = 0; i < *taskCount; i++) {
        if (tasks[i].id == taskId) {
            found = 1;
        }
        if (found && i < *taskCount - 1) {
            tasks[i] = tasks[i + 1];
        }
    }
    if (found) {
        (*taskCount)--;
    } else {
        printf("Task not found.\n");
    }
}

void saveTasks(Task tasks[], int taskCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%d;%s;%d\n", tasks[i].id, tasks[i].description, tasks[i].completed);
    }
    fclose(file);
}

void loadTasks(Task tasks[], int *taskCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file for reading");
        return;
    }
    char line[128];
    *taskCount = 0;
    while (fgets(line, sizeof(line), file) && *taskCount < MAX_TASKS) {
        sscanf(line, "%d;%99[^;];%d", &tasks[*taskCount].id, tasks[*taskCount].description, &tasks[*taskCount].completed);
        (*taskCount)++;
    }
    fclose(file);
}
