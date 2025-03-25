#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tasks;
int option;
int numTasks = 1;

#define MAX_LEN 100

void addTasks()
{
    tasks = malloc(100 * sizeof(char *));
    while (1)
    {
        printf("Enter Task #%d, type 1 to quit\n", numTasks);
        tasks[numTasks] = malloc(MAX_LEN * sizeof(char));
        fgets(tasks[numTasks], MAX_LEN, stdin);
        if (strcmp(tasks[numTasks], "1\n") == 0)
        {
            free(tasks[numTasks]);
            for (int i = 0; i < numTasks; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            numTasks--;
            return;
        }
        else
        {
            numTasks++;
        }
    }
}

void viewTasks()
{
    for (int i = 0; i < numTasks; i++)
    {
        printf("Task #%d: %s", i + 1, tasks[i]);
    }
}
void deleteTasks()
{
}

int main(void)
{
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