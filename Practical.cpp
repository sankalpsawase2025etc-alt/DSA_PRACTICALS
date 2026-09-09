#include <stdio.h>
#include <string.h>

int length(char[]);
void compare(char[], char[]);
void palindrom(char[]);
void substring(char[], char[]);
void copy(char[], char[]);
void reverse(char[]);
void displayMenu();

int i, j;

int main()
{
    int choice;
    char str[50];
    char str2[50];
    int exit = 0;

    displayMenu();

    do
    {
        printf("\nENTER CHOICE (7 for Display Menu): ");
        scanf("%d", &choice);
        getchar(); // Remove newline after scanf

        if (choice >= 1 && choice <= 6)
        {
            printf("Enter String: ");
            fgets(str, 50, stdin);
            str[strcspn(str, "\n")] = '\0';
        }

        switch (choice)
        {
            case 1:
                printf("Length of the String is %d\n\n", length(str));
                break;

            case 2:
                printf("Enter second String: ");
                fgets(str2, 50, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                copy(str, str2);
                break;

            case 3:
                reverse(str);
                break;

            case 4:
                palindrom(str);
                break;

            case 5:
                printf("Enter Substring: ");
                fgets(str2, 50, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                substring(str, str2);
                break;

            case 6:
                printf("Enter second String: ");
                fgets(str2, 50, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                compare(str, str2);
                break;

            case 7:
                displayMenu();
                break;

            case 8:
                exit = 1;
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (exit == 0);

    return 0;
}

void displayMenu()
{
    printf("\n-----------MENU-----------\n");
    printf("1. Length\n");
    printf("2. Copy String\n");
    printf("3. Reverse String\n");
    printf("4. Check Palindrome\n");
    printf("5. Check Substring\n");
    printf("6. Compare Strings\n");
    printf("7. Display Menu\n");
    printf("8. Exit\n");
}

int length(char a[])
{
    int len = 0;

    while (a[len] != '\0')
    {
        len++;
    }

    return len;
}

void compare(char str[], char str2[])
{
    i = 0;

    while (str[i] == str2[i])
    {
        if (str[i] == '\0')
        {
            printf("Both Strings are Equal\n\n");
            return;
        }

        i++;
    }

    printf("Both Strings are Not Equal\n\n");
}

void palindrom(char a[])
{
    int l = length(a);
    int flag = 0;

    for (i = 0, j = l - 1; i < j; i++, j--)
    {
        if (a[i] != a[j])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("String is Palindrome\n\n");
    else
        printf("String is Not Palindrome\n\n");
}

void substring(char a[], char b[])
{
    int al = length(a);
    int bl = length(b);
    int flag = 0;

    if (bl > al)
    {
        printf("The String B is not a substring of A\n\n");
        return;
    }

    for (i = 0; i <= al - bl; i++)
    {
        for (j = 0; j < bl; j++)
        {
            if (a[i + j] != b[j])
                break;
        }

        if (j == bl)
            flag++;
    }

    if (flag > 0)
        printf("The String B is a substring of A and occurs %d time(s)\n\n", flag);
    else
        printf("The String B is not a substring of A\n\n");
}

void copy(char a[], char b[])
{
    int bl = length(b);

    for (i = 0; i <= bl; i++)
    {
        a[i] = b[i];
    }

    printf("Copied String: %s\n\n", a);
}

void reverse(char a[])
{
    int al = length(a);
    char temp;

    for (i = 0, j = al - 1; i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    printf("Reversed String: %s\n\n", a);
}
