#include <stdio.h>

int main()
{
    int n, i, j, key, min, temp, max;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        min = i, max = i;
        for (j = i + 1; j < n ; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        if (max == i)
        {
           max=min;
        }
       
    }
  
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
