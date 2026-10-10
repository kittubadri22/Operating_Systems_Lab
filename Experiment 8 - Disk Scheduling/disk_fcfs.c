#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, i;
    int total_seek = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of requests.\n");
        return 1;
    }

    int request[n];

    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Head Movement:\n");
    printf("%d", head);

    for (i = 0; i < n; i++)
    {
        total_seek += abs(head - request[i]);
        head = request[i];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", total_seek);
    printf("\nAverage Seek Time = %.2f\n",
           (float)total_seek / n);

    return 0;
}