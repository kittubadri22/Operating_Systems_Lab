#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f;
    int i, j, k;
    int pageFaults = 0;
    int found;
    int pos;
    int farthest;
    int future;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initially all frames are empty
    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check if page is already present
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        // Page fault
        if(found == 0)
        {
            pageFaults++;

            // Check for empty frame
            pos = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // If empty frame exists
            if(pos != -1)
            {
                frames[pos] = pages[i];
            }

            // If all frames are full
            else
            {
                farthest = -1;
                pos = 0;

                for(j = 0; j < f; j++)
                {
                    future = -1;

                    // Look into the future
                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            future = k;
                            break;
                        }
                    }

                    // Page is never used again
                    if(future == -1)
                    {
                        pos = j;
                        break;
                    }

                    // Find page used farthest in future
                    if(future > farthest)
                    {
                        farthest = future;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
            }
        }

        // Display frames
        printf("\nPage %d: ", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if(found)
            printf("  Hit");
        else
            printf("  Fault");
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}