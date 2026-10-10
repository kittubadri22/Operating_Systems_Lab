#include <stdio.h>

// 1. Define the struct first so the compiler knows it exists
struct Process
{
  int id;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
};

// 2. Declare the function prototype below the struct definition
void fcfsWithAT(struct Process p[], int n);

int main()
{
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  struct Process p[n];
  for (int i = 0; i < n; i++)
  {
    p[i].id = i + 1;
    printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
    scanf("%d %d", &p[i].at, &p[i].bt);
  }

  fcfsWithAT(p, n);
  return 0;
}

void fcfsWithAT(struct Process p[], int n)
{
  // Sort by Arrival Time
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (p[j].at > p[j + 1].at)
      {
        struct Process temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }

  int currentTime = 0;
  float totalTAT = 0, totalWT = 0;

  for (int i = 0; i < n; i++)
  {
    if (currentTime < p[i].at)
    {
      currentTime = p[i].at;  // CPU handles idle time gap
    }

    p[i].ct = currentTime + p[i].bt;
    currentTime = p[i].ct;

    p[i].tat = p[i].ct - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;

    totalTAT += p[i].tat;
    totalWT += p[i].wt;
  }

  printf("\n--- FCFS (WITH ARRIVAL TIME) ---\n");
  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++)
  {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct,
           p[i].tat, p[i].wt);
  }

  printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
  printf("Average Waiting Time    = %.2f\n", totalWT / n);
}