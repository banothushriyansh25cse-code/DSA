#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Song
{
    char name[50];
    int duration;
};

struct Song playlist[50];
int n = 0;

/* Get String Input */
void getString(char str[], int size)
{
    while (1)
    {
        fgets(str, size, stdin);

        str[strcspn(str, "\n")] = '\0';

        if (strlen(str) == 0)
        {
            printf("Input cannot be empty. Enter again: ");
        }
        else
        {
            break;
        }
    }
}

/* Get Integer Input */
int getInt()
{
    char input[50];
    int i;

    while (1)
    {
        fgets(input, sizeof(input), stdin);

        for (i = 0; input[i] != '\0' && input[i] != '\n'; i++)
        {
            if (!isdigit(input[i]))
            {
                printf("Please enter a valid integer: ");
                break;
            }
        }

        if (input[i] == '\n' || input[i] == '\0')
        {
            return atoi(input);
        }
    }
}

/* Add Song */
void addSong()
{
    if (n >= 50)
    {
        printf("\nPlaylist is full!\n");
        return;
    }

    printf("\nEnter song name: ");
    getString(playlist[n].name, 50);

    printf("Enter duration (minutes): ");
    playlist[n].duration = getInt();

    n++;

    printf("\nSong added successfully!\n");
}

/* Display Songs */
void displaySongs()
{
    int i;

    if (n == 0)
    {
        printf("\nPlaylist is empty!\n");
        return;
    }

    printf("\n========== MUSIC PLAYLIST ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\n%d. %s", i + 1, playlist[i].name);
        printf("\n   Duration: %d minutes\n", playlist[i].duration);
    }
}

/* Linear Search */
void searchSong()
{
    char name[50];
    int i, found = 0;

    printf("\nEnter song name to search: ");
    getString(name, 50);

    for (i = 0; i < n; i++)
    {
        if (strcmp(playlist[i].name, name) == 0)
        {
            printf("\nSong Found!");
            printf("\nName: %s", playlist[i].name);
            printf("\nDuration: %d minutes\n", playlist[i].duration);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSong not found!\n");
    }
}

/* Bubble Sort */
void sortSongs()
{
    int i, j;
    struct Song temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(playlist[j].name,
                       playlist[j + 1].name) > 0)
            {
                temp = playlist[j];
                playlist[j] = playlist[j + 1];
                playlist[j + 1] = temp;
            }
        }
    }

    printf("\nPlaylist sorted alphabetically!\n");
}

/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n\n===== MUSIC PLAYLIST MANAGER =====");
        printf("\n1. Add Song");
        printf("\n2. Display Songs");
        printf("\n3. Search Song");
        printf("\n4. Sort Songs");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        choice = getInt();

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                displaySongs();
                break;

            case 3:
                searchSong();
                break;

            case 4:
                sortSongs();
                break;

            case 5:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice! Enter 1-5.\n");
        }

    } while (choice != 5);

    return 0;
}