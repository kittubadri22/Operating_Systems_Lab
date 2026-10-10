#include <stdbool.h>
#include <stdio.h>


struct Process
{
  int id;
  int at;
  int bt;
  int ct;
  // Arrival Time
  // Burst Time
  // Completion Time
  int remaining_bt;
  int tat;
  // Remaining Burst Time
  // Turnaround Time
  int wt;
};

// Waiting Time
void roundRobin(struct Process p[], int n, int tq)
{
  int queue[100];
  int front = 0, rear = 0;
  bool visited[100] = {false};
  int currentTime = 0;

  int completed = 0;
  float totalTAT = 0, totalWT = 0;
  // Sort processes by Arrival Time initially for clean queue initialization
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
  // Initialize remaining burst time
  for (int i = 0; i < n; i++)
  {
    p[i].remaining_bt = p[i].bt;
  }
  // Push first process(es) arriving at t=0 or earliest arrival time
  queue[rear++] = 0;
  visited[0] = true;
  currentTime = p[0].at;

  while (front < rear)
  {
    int idx = queue[front++];  // Pop process from front of queue
    if (p[idx].remaining_bt > tq)
    {
      p[idx].remaining_bt -= tq;
      currentTime += tq;
    }
    else
    {
      currentTime += p[idx].remaining_bt;
      p[idx].remaining_bt = 0;
      p[idx].ct = currentTime;
      p[idx].tat = p[idx].ct - p[idx].at;
      p[idx].wt = p[idx].tat - p[idx].bt;
      totalTAT += p[idx].tat;
      totalWT += p[idx].wt;
      completed++;
    }
    // Push newly arrived processes to queue
    for (int i = 0; i < n; i++)
    {
      if (p[i].at <= currentTime && !visited[i] && p[i].remaining_bt > 0)
      {
        queue[rear++] = i;
        visited[i] = true;
      }
    }
    // If current process is not finished, re-add it to the end of queue
    if (p[idx].remaining_bt > 0)
    {
      queue[rear++] = idx;
    }
    // Handle CPU idle state if queue is empty but processes remain
    if (front == rear && completed < n)
    {
      for (int i = 0; i < n; i++)
      {
        if (p[i].remaining_bt > 0)
        {
          currentTime = p[i].at;
          queue[rear++] = i;
          visited[i] = true;
          break;
        }
      }
    }
  }

  // Output Table
  printf("\n--- ROUND ROBIN SCHEDULING (TQ=%d) RESULTS---\n", tq);
  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++)
  {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct,
           p[i].tat, p[i].wt);
  }
  printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
  printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
}


int main()
{
  int n, tq;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  struct Process p[n];
  for (int i = 0; i < n; i++)
  {
    p[i].id = i + 1;
    printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
    scanf("%d %d", &p[i].at, &p[i].bt);
  }
  printf("Enter Time Quantum: ");
  scanf("%d", &tq);
  roundRobin(p, n, tq);
  return 0;
}