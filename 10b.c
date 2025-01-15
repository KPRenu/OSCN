#include<stdio.h>
#include<stdlib.h> 
int main() {
    int t[20], d[20], h, i, j, n, temp, atr[20], sum = 0, p = 0;
    printf("*** SCAN Disk Scheduling Algorithm ***\n");
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    printf("Enter the position of head: ");
    scanf("%d", &h);
    
    t[0] = 0; 
    t[1] = h; 
    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            break;
        }
    }

    for (j = i; j >= 0; j--) { 
        atr[p++] = t[j];
    }
    for (j = i + 1; j < n + 2; j++) { 
        atr[p++] = t[j];
    }

    for (j = 0; j < p - 1; j++) {
        d[j] = abs(atr[j + 1] - atr[j]);
        sum += d[j];
    }

    printf("\nTrack traversal order: ");
    for (j = 0; j < p; j++) {
        printf("%d ", atr[j]);
    }
    printf("\nTotal head movements: %d", sum);
    printf("\nAverage head movements: %.2f\n", (float)sum / n);

    return 0;
}

