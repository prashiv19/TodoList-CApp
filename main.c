#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

void printMenu() {
    printf("To-Do List Menu:\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Delete Task\n");
    printf("5. Save Tasks\n");
    printf("6. Load Tasks\n");
    printf("7. Exit\n");
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice, taskId;
    char description[TASK_DESC_LENGTH];
    char filename[50];

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(description, TASK_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0;  // Remove newline character
                addTask(tasks, &taskCount, description);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                printf("Enter task ID to mark as completed: ");
                scanf("%d", &taskId);
                markTaskCompleted(tasks, taskCount, taskId);
                break;
            case 4:
                printf("Enter task ID to delete: ");
                scanf("%d", &taskId);
                deleteTask(tasks, &taskCount, taskId);
                break;
            case 5:
                printf("Enter filename to save tasks: ");
                scanf("%s", filename);
                saveTasks(tasks, taskCount, filename);
                break;
            case 6:
                printf("Enter filename to load tasks: ");
                scanf("%s", filename);
                loadTasks(tasks, &taskCount, filename);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
