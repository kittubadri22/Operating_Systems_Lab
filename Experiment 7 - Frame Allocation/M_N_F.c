#include <stdio.h>

int main()
{
    int n, i, total = 0;
    int pages[20], frames[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid number of processes.\n");
        return 1;
    }

    printf("Enter pages required by each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &pages[i]);

        if (pages[i] <= 0)
        {
            printf("Invalid page requirement.\n");
            return 1;
        }

        frames[i] = 1;
        total += frames[i];
    }

    printf("\nMinimum one frame per process:\n");
    for (i = 0; i < n; i++)
        printf("P%d: %d frame(s)\n", i + 1, frames[i]);

    printf("Total minimum frames = %d\n", total);

    return 0;
}