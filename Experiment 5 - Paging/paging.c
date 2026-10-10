#include <stdio.h>
int main() {
    int pageSize, n, logicalAddress;
    int pageNumber, offset, frameNumber, physicalAddress;
    int pageTable[10];
    printf("Enter page size: ");
    scanf("%d", &pageSize);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter frame number for each page:\n");
    for (int i=0; i < n; i++) {
        printf("Page %d: ", i);
        scanf("%d", &pageTable[i]);
    }
    printf("Enter logical address: ");
    scanf("%d", &logicalAddress);
    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;
    if (pageNumber >= n) {
        printf("Page Fault\n");
    } else {
        frameNumber = pageTable[pageNumber];
        physicalAddress = frameNumber * pageSize + offset;
    }
    printf("Page Number: %d\n", pageNumber);
    printf("Offset: %d\n", offset);
    printf("Frame Number: %d\n", frameNumber);
    printf("Physical Address: %d\n", physicalAddress);
    return 0;
}