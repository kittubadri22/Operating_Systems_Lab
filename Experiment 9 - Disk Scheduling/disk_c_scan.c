#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,j;
    int head, initial_head;
    int disk_size,direction;
    int total_seek=0;
    printf("Enter number of disk requests: ");
    scanf("%d",&n);
    int request[n];
    printf("Enter disk requests:\n");
    for (i=0; i<n; i++)
        scanf("%d",&request[i]);
    printf("Enter initial head position: ");
    scanf("%d",&head);
    initial_head=head;
    printf("Enter disk size: ");
    scanf("%d",&disk_size);
    printf("Enter direction (0=left, 1=right): ");
    scanf("%d",&direction);
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(request[i]>request[j])
            {
                int temp = request[i];
                request[i]=request[j];
                request[j]=temp;
            }
        }
    }
    printf("\nDisk Head Movement:\n");
    printf("%d", head);
    if(direction == 1)
    {
        for(i=0; i<n; i++)
        {
            if(request[i]>=initial_head)
            {
                total_seek+=abs(head-request[i]);
                head=request[i];
                printf(" -> %d",head);
            }
        }
        total_seek+=abs(head-(disk_size-1));
        head = disk_size-1;
        printf(" -> %d",head);
        total_seek+=abs(head-0);
        head = 0;
        printf(" -> %d", head);
        for(i=0; i<n; i++)
        {
            if(request[i]<initial_head)
            {
                total_seek+=abs(head-request[i]);
                head = request[i];
                printf(" -> %d",head);
            }
        }
    }
    else
    {
        for(i=n-1; i>=0; i--)
        {
            if(request[i]<=initial_head)
            {
                total_seek+=abs(head-request[i]);
                head=request[i];
                printf(" -> %d",head);
            }
        }
        total_seek+=abs(head-0);
        head = 0;
        printf(" -> %d",head);
        total_seek+=abs(head-(disk_size-1));
        head=disk_size-1;
        printf(" -> %d",head);
        for (i=n-1; i>=0; i--)
        {
            if(request[i]>initial_head)
            {
                total_seek+=abs(head-request[i]);
                head=request[i];
                printf(" -> %d",head);
            }
        }
    }
    printf("\n\nTotal Seek Time = %d",total_seek);
    printf("\nAverage Seek Time = %.2f\n", (float)total_seek/n);
    return 0;
}