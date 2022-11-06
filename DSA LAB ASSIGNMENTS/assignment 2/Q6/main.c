#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c)
{
    int m = (a >= b) ? a : b;
    return (c >= m) ? c : m;
}

int min(int a, int b, int c)
{
    int m = (a <= b) ? a : b;
    return (c <= m) ? c : m;
}

int median(int a, int b, int c)
{
    if ((a <= b && a >= c) || (a >= b && a <= c))
    {
        return a;
    }
    else if ((b <= c && b >= a) || (b >= c && b <= a))
    {
        return b;
    }
    else if ((c <= a && c >= a) || (c >= a && c <= a))
    {
        return c;
    }
}

int *max_sliding_window_filter(int *arr, int n)
{
    int *array_max_filtered = (int *)malloc(n * sizeof(int));
    int i;
    array_max_filtered[0] = max(0, arr[0], arr[1]);
    for (i = 1; i < n - 1; i++)
    {
        array_max_filtered[i] = max(arr[i - 1], arr[i], arr[i + 1]);
    }
    array_max_filtered[n - 1] = max(arr[n - 2], arr[n - 1], 0);

    return array_max_filtered;
}

int *min_sliding_window_filter(int *arr, int n)
{
    int *array_min_filtered = (int *)malloc(n * sizeof(int));
    int i;
    array_min_filtered[0] = min(0, arr[0], arr[1]);
    for (i = 1; i < n - 1; i++)
    {
        array_min_filtered[i] = min(arr[i - 1], arr[i], arr[i + 1]);
    }
    array_min_filtered[n - 1] = min(arr[n - 2], arr[n - 1], 0);

    return array_min_filtered;
}

int *median_sliding_window_filter(int *arr, int n)
{
    int *array_median_filtered = (int *)malloc(n * sizeof(int));
    int i;
    array_median_filtered[0] = median(0, arr[0], arr[1]);
    for (i = 1; i < n - 1; i++)
    {
        array_median_filtered[i] = median(arr[i - 1], arr[i], arr[i + 1]);
    }
    array_median_filtered[n - 1] = median(arr[n - 2], arr[n - 1], 0);

    return array_median_filtered;
}

int main()
{
    int n;
    printf("\nEnter the array length: ");
    scanf("%d", &n);
    int arr[n];
    int i;
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    int *max_filter_array = max_sliding_window_filter(arr, n);

    printf("\nThe array after MAX filter is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(max_filter_array + i));
    }

    int *min_filter_array = min_sliding_window_filter(arr, n);

    printf("\nThe array after MIN filter is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(min_filter_array + i));
    }

    int *median_filter_array = median_sliding_window_filter(arr, n);

    printf("\nThe array after MEDIAN filter is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(median_filter_array + i));
    }

    free(max_filter_array);
    free(min_filter_array);
    free(median_filter_array);

    return 0;
}