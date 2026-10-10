#include <stdio.h>

int main()
{
    int n, totalFrames, i;
    int allocation[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    if (n <= 0 || n > 20 || totalFrames < 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        allocation[i] = totalFrames / n;

    printf("\nEqual Frame Allocation:\n");

    for (i = 0; i < n; i++)
        printf("P%d: %d frame(s)\n", i + 1, allocation[i]);

    printf("Unallocated remainder frames: %d\n", totalFrames % n);

    return 0;
}
