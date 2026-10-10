#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_seek = 0;
    int current = head;

    printf("\nSeek Sequence: %d", current);

    for (int count = 0; count < n; count++)
    {
        int min_distance = INT_MAX;
        int index = -1;

        // Find the closest unvisited request
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                int distance = abs(current - request[i]);

                if (distance < min_distance)
                {
                    min_distance = distance;
                    index = i;
                }
            }
        }

        // Mark request as visited
        visited[index] = 1;

        // Calculate total seek time
        total_seek += min_distance;

        // Move disk head
        current = request[index];

        printf(" -> %d", current);
    }

    printf("\n\nTotal Seek Time: %d", total_seek);

    printf("\nAverage Seek Time: %.2f\n",
           (float)total_seek / n);

    return 0;
}