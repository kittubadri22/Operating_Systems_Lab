#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[20], p[20], priority[20];
    int wt[20], tat[20];
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter burst time and priority for P%d: ", p[i]);
        scanf("%d %d", &bt[i], &priority[i]);

        if (bt[i] <= 0 || priority[i] < 0)
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t%d\t%d\n",
               p[i], priority[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
