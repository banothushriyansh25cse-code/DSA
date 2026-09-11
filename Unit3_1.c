#include <stdio.h>
#include <stdlib.h>

struct Node {
    int rollNumber;
    struct Node* next;
};

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("\n[Status] The list is currently empty.\n\n");
        return;
    }
    struct Node* temp = head;
    printf("\nUpdated Roll Numbers: ");
    while (temp != NULL) {
        printf("%d -> ", temp->rollNumber);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int roll) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNumber = roll;
    newNode->next = *head;
    *head = newNode;
    printf("\nSuccessfully inserted %d at the beginning.", roll);
    display(*head);
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int roll) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNumber = roll;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nSuccessfully inserted %d at the end.", roll);
    display(*head);
}

// Function to search for a roll number
void search(struct Node* head, int roll) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->rollNumber == roll) {
            printf("\n[Found] Roll number %d is at position %d.\n\n", roll, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("\n[Not Found] Roll number %d is not available in the list.\n\n", roll);
}

// Function to delete a specified roll number
void deleteNode(struct Node** head, int roll) {
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->rollNumber == roll) {
        *head = temp->next;
        free(temp);
        printf("\nSuccessfully deleted roll number %d.", roll);
        display(*head);
        return;
    }

    while (temp != NULL && temp->rollNumber != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\n[Error] Roll number %d is not available for deletion.\n\n", roll);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\nSuccessfully deleted roll number %d.", roll);
    display(*head);
}

int main() {
    struct Node* head = NULL;
    int choice, roll;

    while (1) {
        printf("=== Student Roll Number Management ===\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search Roll Number\n");
        printf("4. Delete Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter roll number to insert at beginning: ");
                scanf("%d", &roll);
                insertAtBeginning(&head, roll);
                break;
            case 2:
                printf("Enter roll number to insert at end: ");
                scanf("%d", &roll);
                insertAtEnd(&head, roll);
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(head, roll);
                break;
            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteNode(&head, roll);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                // Free remaining memory before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n\n");
        }
    }
    return 0;
}
