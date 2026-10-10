#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, head;

    printf("Roll No:25071A6217\n");
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of requests.\n");
        return 1;
    }

    int request[n];

    printf("Enter disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort requests in ascending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (request[j] > request[j + 1])
            {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

    // Find first request >= head
    int split = 0;

    while (split < n && request[split] < head)
    {
        split++;
    }

    int current = head;
    long long total_seek = 0;

    printf("\nSeek Sequence: %d", current);

    // Service requests to the right
    for (int i = split; i < n; i++)
    {
        total_seek += abs(current - request[i]);
        current = request[i];

        printf(" -> %d", current);
    }

    // Circular jump to the smallest request
    if (split > 0)
    {
        total_seek += abs(current - request[0]);
        current = request[0];

        printf(" -> %d", current);

        // Service remaining requests
        for (int i = 1; i < split; i++)
        {
            total_seek += abs(current - request[i]);
            current = request[i];

            printf(" -> %d", current);
        }
    }

    printf("\n\nTotal Seek Time: %lld\n", total_seek);

    printf("Average Seek Time: %.2f\n",
           (double)total_seek / n);

    return 0;
}
