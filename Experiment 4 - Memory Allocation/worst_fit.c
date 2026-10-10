#include <stdio.h>
int main()
{
    int partitions, processes;
    int partitionSize[20], processSize[20];
    int allocation[20];
    printf("Enter number of partitions: ");
    scanf("%d", &partitions);
    printf("Enter size of each partition:\n");
    for (int i=0; i < partitions; i++)
    {
        printf("Partition %d: ", i + 1);
        scanf("%d", &partitionSize[i]);
    }
    printf("\nEnter number of processes: ");
    scanf("%d", &processes);
    printf("Enter size of each process:\n");
    for (int i=0; i < processes; i++)
    {
        printf("Process %d: ", i+1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
    for (int i=0; i < processes; i++)
    {
        int worst = -1;
        for (int j=0; j < partitions; j++)
        {
            if (partitionSize[j] >= processSize[i])
            {
                if (worst == -1 || partitionSize[j] > partitionSize[worst])
                {
                    worst = j;
                }
            }
        }
        if (worst != -1)
        {
            allocation[i] = worst;
            partitionSize[worst] -= processSize[i];
        }
    }
    printf("\nProcess\tProcess Size\tPartition\tRemaining Space\n");
    for (int i=0; i < processes; i++)
    {
        if (allocation[i] != -1)
        {
            printf("P%d\t%d\t\t%d\t\t%d\n", i+1, processSize[i], allocation[i] + 1, partitionSize[allocation[i]]);
        }
        else
        {
            printf("P%d\t%d\t\tNot Allocated\t-\n", i+1, processSize[i]);
        }
    }
    return 0;
}