#ifndef TODO_H
#define TODO_H

#define MAX_TASKS 100
#define TASK_DESC_LENGTH 100

typedef struct {
    int id;
    char description[TASK_DESC_LENGTH];
    int completed;
} Task;

void addTask(Task tasks[], int *taskCount, const char *description);
void viewTasks(Task tasks[], int taskCount);
void markTaskCompleted(Task tasks[], int taskCount, int taskId);
void deleteTask(Task tasks[], int *taskCount, int taskId);
void saveTasks(Task tasks[], int taskCount, const char *filename);
void loadTasks(Task tasks[], int *taskCount, const char *filename);

#endif
