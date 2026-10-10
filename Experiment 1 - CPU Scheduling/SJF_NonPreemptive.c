#include <stdio.h>
int main()
{
  int n, i, j;
  int bt[20], wt[20], tat[20], p[20];
  int temp;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  // Input burst times
  printf("Enter Burst Time for each process:\n");
  for (i = 0; i < n; i++)
  {
    p[i] = i + 1;
    printf("P%d: ", p[i]);
    scanf("%d", &bt[i]);
  }
  // Sort processes according to burst time
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (bt[i] > bt[j])
      {
        // Swap burst time
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;
        // Swap process number
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
  // Calculate Waiting Time
  wt[0] = 0;
  for (i = 1; i < n; i++)
  {
    wt[i] = wt[i - 1] + bt[i - 1];
  }
  // Calculate Turnaround Time
  float avgWT = 0, avgTAT = 0;
  for (i = 0; i < n; i++)
  {
    tat[i] = wt[i] + bt[i];
    avgWT += wt[i];
    avgTAT += tat[i];
  }
  // Display Results
  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++)
  {
    printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
  }
  printf("\nAverage Waiting Time = %.2f", avgWT / n);
  printf("\nAverage Turnaround Time = %.2f", avgTAT / n);
  return 0;
}