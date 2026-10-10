#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], priority[20];
    int ct[20], wt[20], tat[20];
    int highest;
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
        printf("Enter arrival time, burst time and priority for P%d: ",
               i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);

        if (at[i] < 0 || bt[i] <= 0 || priority[i] < 0)
        {
            printf("Invalid input.\n");
            return 1;
        }

        rt[i] = bt[i];
    }

    while (completed < n)
    {
        highest = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (highest == -1 ||
                    priority[i] < priority[highest])
                {
                    highest = i;
                }
            }
        }

        if (highest == -1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if (rt[highest] == 0)
        {
            ct[highest] = time;
            completed++;
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], priority[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
