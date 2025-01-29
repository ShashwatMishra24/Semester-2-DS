#include <stdio.h>


int findMedian(int arr[]) {
    for (int i = 0; i < 9 - 1; i++) {
        for (int j = 0; j < 9 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // Bubble Sort
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr[4]; 
}

int main() {
    int n;
    printf("Enter n for the square matrix: ");
    scanf("%d", &n);

    int a[n][n], b[n][n];

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
            b[i][j] = a[i][j]; 
        }
        printf("\n");
    }
    printf("\n");

    
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int temp[9], idx = 0;

           
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    temp[idx++] = a[i + r][j + c];
                }
            }

           
            b[i + 1][j + 1] = findMedian(temp);
        }
    }

   
    printf("\nFiltered Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
