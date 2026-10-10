#include <stdio.h>

// 1. Define the struct first so the compiler knows it exists
struct Process
{
  int id;
  int bt;
  int ct;
  int tat;
  int wt;
};

// 2. Declare the function prototype below the struct definition
void fcfsWithoutAT(struct Process p[], int n);

int main()
{
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);

  struct Process p[n];
  for (int i = 0; i < n; i++)
  {
    p[i].id = i + 1;
    printf("Enter Burst Time for Process P%d: ", i + 1);
    scanf("%d", &p[i].bt);
  }

  fcfsWithoutAT(p, n);
  return 0;
}

void fcfsWithoutAT(struct Process p[], int n)
{
  p[0].ct = p[0].bt;
  p[0].tat = p[0].ct;
  p[0].wt = 0;

  float totalTAT = p[0].tat, totalWT = p[0].wt;

  for (int i = 1; i < n; i++)
  {
    p[i].ct = p[i - 1].ct + p[i].bt;
    p[i].tat = p[i].ct;            
    p[i].wt = p[i].tat - p[i].bt;  

    totalTAT += p[i].tat;
    totalWT += p[i].wt;
  }

  printf("\n--- FCFS (WITHOUT ARRIVAL TIME) ---\n");
  printf("PID\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++)
  {
    printf("P%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].ct, p[i].tat,
           p[i].wt);
  }

  printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
  printf("Average Waiting Time    = %.2f\n", totalWT / n);
}