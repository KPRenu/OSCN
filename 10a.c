#include <stdio.h>
#include <stdlib.h> 

int main() {
    int queue[100], visited[100] = {0}, head, seek = 0, n, i, j, min_index;
    float avg_seek;

    printf("*** SSTF Disk Scheduling Algorithm ***\n");
    printf("Enter the size of Queue: ");
    scanf("%d", &n);

    printf("Enter the Queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence is:\n");
    for (i = 0; i < n; i++) {
        int min_distance = 1e9; 
        for (j = 0; j < n; j++) {
            if (!visited[j]) { 
                int distance = abs(head - queue[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_index = j;
                }
            }
        }

        visited[min_index] = 1;
        seek += abs(head - queue[min_index]);
        head = queue[min_index];
        printf("%d ", head);
    }

    avg_seek = (float)seek / n;
    printf("\n\nTotal Seek Time: %d", seek);
    printf("\nAverage Seek Time: %.2f\n", avg_seek);

    return 0;
}
