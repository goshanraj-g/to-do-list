#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tasks;
int option;
int numTasks = 0;

#define MAX_LEN 100
#define MAX_TASKS 100

void addTasks()
{
    while (1)
    {
        printf("Enter Task #%d, type 1 to quit\n", numTasks + 1);
        tasks[numTasks] = malloc(MAX_LEN * sizeof(char));
        fgets(tasks[numTasks], MAX_LEN, stdin);
        tasks[numTasks][strcspn(tasks[numTasks], "\n")] = 0;

        if (strcmp(tasks[numTasks], "1") == 0)
        {
            free(tasks[numTasks]);
            return;
        }

        numTasks++;
    }
}

void viewTasks()
{
    for (int i = 0; i < numTasks; i++)
    {
        printf("Task #%d: %s", i + 1, tasks[i]);
        if (i < numTasks - 1)
        {
            printf("\n");
        }
    }
}
void deleteTasks()
{
}

int main(void)
{
    tasks = malloc(MAX_TASKS * sizeof(char *));

    while (1)
    {
        printf("\nTO-DO List\n");
        printf("[1] Add Tasks\n");
        printf("[2] View Tasks\n");
        printf("[3] Quit\n");

        scanf("%d", &option);
        getchar();

        if (option == 1)
        {
            addTasks();
        }
        else if (option == 2)
        {
            viewTasks();
        }
        else if (option == 3)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid option. Try again.\n");
        }
    }

    for (int i = 0; i < numTasks; i++)
    {
        free(tasks[i]);
    }
    free(tasks);

    return 0;
}