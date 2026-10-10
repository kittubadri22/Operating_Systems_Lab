#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20];
    int ct[20], wt[20], tat[20];
    int shortest;
    float avgWT = 0, avgTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        if (at[i] < 0 || bt[i] <= 0)
        {
            printf("Invalid arrival or burst time.\n");
            return 1;
        }

        rt[i] = bt[i];
    }

    while (completed < n)
    {
        shortest = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (shortest == -1 ||
                    rt[i] < rt[shortest])
                {
                    shortest = i;
                }
            }
        }

        if (shortest == -1)
        {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if (rt[shortest] == 0)
        {
            completed++;
            ct[shortest] = time;
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           avgWT / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           avgTAT / n);

    return 0;
}
