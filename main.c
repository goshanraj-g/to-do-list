#include <stdio.h>

char **tasks;
int option;

#define MAX_LEN 100

void addTasks()
{
    int counter = 1;
    while (1)
    {
        printf("Enter Task #%d, type 1 to quit\n", counter);
        tasks[counter] = malloc(MAX_LEN * sizeof(char));
        fgets("%s", tasks[counter]);
        printf("%s", tasks[counter]);
    }
}

void viewTasks()
{
    char **tasks;
    while ((sizeof(tasks) / (sizeof(tasks[0]))) > 0)
    {
        for (int i = 0; i < sizeof(tasks) / sizeof(tasks[0]); i++)
        {
            printf("%s", tasks[i]);
        }
    }
}
void deleteTasks()
{
}

int main(void)
{
    printf("TO-DO List\n");
    printf("[1] Add Tasks\n");
    printf("[2] Delete Tasks\n");
    printf("[3] Quit\n");

    scanf("%d", &option);

    if (option == 1)
    {
        addTasks();
    }
    else if (option == 2)
    {
    }
    else if (option == 3)

        return 0;
}