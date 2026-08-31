#include <stdio.h>

int main() {
    int n, i, searchID, low, high, mid, found = 0, comparisons = 0;

    // Input total number of employees
    printf("Enter the number of employees (n): ");
    scanf("%d", &n);

    int empIDs[n];

    // Input employee IDs in ascending order
    printf("Enter %d employee IDs in ascending order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &empIDs[i]);
    }

    // Input the ID to search
    printf("Enter the employee ID to search: ");
    scanf("%d", &searchID);

    // Initialize binary search variables
    low = 0;
    high = n - 1;

    while (low <= high) {
        comparisons++;
        mid = low + (high - low) / 2;

        if (empIDs[mid] == searchID) {
            found = 1;
            break;
        } else if (empIDs[mid] < searchID) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Display the results
    if (found) {
        printf("\nResult: Successful Search\n");
        printf("Employee ID %d found at position %d (index %d).\n", searchID, mid + 1, mid);
    } else {
        printf("\nResult: Unsuccessful Search\n");
        printf("Employee ID %d is absent from the list.\n", searchID);
    }

    printf("Total number of comparisons: %d\n", comparisons);

    return 0;
}
