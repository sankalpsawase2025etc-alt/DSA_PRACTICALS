#include <stdio.h>

void bubbleSort(int a[], int n);
void insertionSort(int a[], int n);
void selectionSort(int a[], int n);
void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void display(int a[], int n);

int main()
{
    int a[50], n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\n----- SORTING MENU -----\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            bubbleSort(a, n);
            printf("\nAfter Bubble Sort:\n");
            display(a, n);
            break;

        case 2:
            insertionSort(a, n);
            printf("\nAfter Insertion Sort:\n");
            display(a, n);
            break;

        case 3:
            selectionSort(a, n);
            printf("\nAfter Selection Sort:\n");
            display(a, n);
            break;

        case 4:
            mergeSort(a, 0, n - 1);
            printf("\nAfter Merge Sort:\n");
            display(a, n);
            break;

        case 5:
            quickSort(a, 0, n - 1);
            printf("\nAfter Quick Sort:\n");
            display(a, n);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

/* Bubble Sort */
void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/* Insertion Sort */
void insertionSort(int a[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

/* Selection Sort */
void selectionSort(int a[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

/* Merge Sort */
void mergeSort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int temp[50];
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}

/* Quick Sort */
void quickSort(int a[], int low, int high)
{
    int p;

    if(low < high)
    {
        p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = a[high];
    i = low - 1;

    for(j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

/* Display Array */
void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}
