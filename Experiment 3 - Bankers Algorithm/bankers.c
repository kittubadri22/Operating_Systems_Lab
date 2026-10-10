#include <stdio.h>

int main()
{
  int n, m;
  int i, j, k;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  printf("Enter number of resources: ");
  scanf("%d", &m);
  int allocation[n][m];
  int max[n][m];
  int need[n][m];
  int available[m];
  // Input Allocation Matrix
  printf("\nEnter Allocation Matrix:\n");

  for (i = 0; i < n; i++)
  {
    printf("P%d: ", i);

    for (j = 0; j < m; j++)
    {
      scanf("%d", &allocation[i][j]);
    }

  }

  // Input Maximum Matrix
  printf("\nEnter Maximum Matrix:\n");

  for (i = 0; i < n; i++)
  {
    printf("P%d: ", i);

    for (j = 0; j < m; j++)
    {
      scanf("%d", &max[i][j]);
    }
  }

  // Input Available Resources
  printf("\nEnter Available Resources:\n");

  for (j = 0; j < m; j++)
  {
    scanf("%d", &available[j]);
  }


  // Calculate Need Matrix
  // Need = Max - Allocation
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      need[i][j] = max[i][j] - allocation[i][j];
    }
  }

  // Display Need Matrix
  printf("\nNeed Matrix:\n");
  for (i = 0; i < n; i++)
  {
    printf("P%d: ", i);
    for (j = 0; j < m; j++)
    {
      printf("%d ", need[i][j]);
    }
    printf("\n");
  }

  int finish[n];
  int safeSequence[n];
  
  // Initially, no process is finished
  for (i = 0; i < n; i++)
  {
    finish[i] = 0;
  }
  int count = 0;
  // Banker's Algorithm
  while (count < n)
  {
    int found = 0;
    for (i = 0; i < n; i++)
    {
      if (finish[i] == 0)
      {
        int canExecute = 1;

        // Check Need <= Available
        for (j = 0; j < m; j++)
        {
          if (need[i][j] > available[j])
          {
            canExecute = 0;
            break;
          }
        }

        if (canExecute)
        {
          // Process finishes and releases resources
          for (k = 0; k < m; k++)
          {
            available[k] += allocation[i][k];
          }

          safeSequence[count] = i;
          count++;
          finish[i] = 1;
          found = 1;
        }
      }
    }

    // No process can execute
    if (found == 0)
    {
      break;
    }
  }
  // Check whether system is safe
  if (count == n)
  {
    printf("\nSystem is in SAFE state.\n");
    printf("Safe Sequence: ");
    for (i = 0; i < n; i++)
    {
      printf("P%d", safeSequence[i]);
      if (i != n - 1) printf(" -> ");
    }
    printf("\n");
  }
  else
  {
    printf("\nSystem is in UNSAFE state.\n");
  }
  return 0;
}