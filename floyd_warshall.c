#include <stdio.h>

#define INF 9999

int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int dist[n][n];
    printf("Enter the cost matrix (use 9999 for no direct road):\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    // Floyd–Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
