#include <stdio.h>

int main()
{
    int n, totalFrames, i, totalPages = 0;
    int pages[20], allocation[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    if (n <= 0 || n > 20 || totalFrames < 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter memory size (pages) for each process:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &pages[i]);

        if (pages[i] <= 0)
        {
            printf("Invalid page count.\n");
            return 1;
        }

        totalPages += pages[i];
    }

    printf("\nProportional Frame Allocation:\n");

    for (i = 0; i < n; i++)
    {
        allocation[i] =
            (int)((long long)totalFrames * pages[i] / totalPages);

        printf("P%d: %d frame(s)\n", i + 1, allocation[i]);
    }

    return 0;
}
