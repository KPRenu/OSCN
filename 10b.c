#include <stdio.h>
#include <stdlib.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], sum = 0, p = 0;
    float avg;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);
    printf("Enter the position of the head: ");
    scanf("%d", &h);

    // Input tracks
    t[0] = 0; // Adding start of the disk
    printf("Enter the tracks: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    t[n + 1] = h; // Adding head position
    n += 2; // Adjust total number of tracks

    // Sort the tracks in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the position of the head
    for (i = 0; i < n; i++) {
        if (t[i] == h) {
            break;
        }
    }

    // SCAN direction: First go left, then right
    for (j = i; j >= 0; j--) {
        atr[p++] = t[j];
    }
    for (j = i + 1; j < n; j++) {
        atr[p++] = t[j];
    }

    // Calculate movements
    for (j = 0; j < n - 1; j++) {
        d[j] = abs(atr[j + 1] - atr[j]);
        sum += d[j];
    }

    // Calculate average
    avg = (float)sum / (n - 2);

    // Output results
    printf("\nTotal header movements: %d", sum);
    printf("\nAverage header movements: %.2f\n", avg);

    return 0;
}


// 5
// 50
// 10 20 30 70 90