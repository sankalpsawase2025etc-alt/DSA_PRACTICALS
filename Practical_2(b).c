#include <stdio.h>

int main()
{
    int a[50], n, key, i;
    int choice;
    int found = 0;
    int low, high, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            /* Linear Search */
            for(i = 0; i < n; i++)
            {
                if(a[i] == key)
                {
                    printf("Element found at position %d\n", i + 1);
                    found = 1;
                    break;
                }
            }

            if(found == 0)
            {
                printf("Element not found\n");
            }
            break;

        case 2:
            /* Binary Search */
            low = 0;
            high = n - 1;

            while(low <= high)
            {
                mid = (low + high) / 2;

                if(a[mid] == key)
                {
                    printf("Element found at position %d\n", mid + 1);
                    found = 1;
                    break;
                }
                else if(key < a[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            if(found == 0)
            {
                printf("Element not found\n");
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
