#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the Student struct
struct Student {
    int rollNumber;
    char name[50];
    char course[50];
    float marks;
    struct Student* next;
    struct Student* prev;
};

// Global variable to store the head of the linked list
struct Student* head = NULL;

// Function to create a new student record
struct Student* createStudent(int rollNumber, char name[], char course[], float marks) {
    // Allocate memory for a new student record
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));

    // Initialize the members of the new student record with the provided values
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    newStudent->marks = marks;

    // Set the next and prev pointers to NULL as this is a standalone node
    newStudent->next = NULL;
    newStudent->prev = NULL;

    // Return the pointer to the new student record
    return newStudent;
}

// Function to insert a student record at the end of the list
struct Student* insertFromLast(struct Student* head, int rollNumber, char name[], char course[], float marks) {
    // Create a new student node
    struct Student* newStudent = createStudent(rollNumber, name, course, marks);

    // Check if the list is empty
    if (head == NULL) {
        // If empty, the new student is the only node in the list
        return newStudent;
    }

    // Traverse the list to find the last node
    struct Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Set the next pointer of the last node to the new student
    temp->next = newStudent;
    // Set the previous pointer of the new student to the last node
    newStudent->prev = temp;

    // Return the head of the updated linked list
    return head;
}

// Function to delete a student record from the front of the list
struct Student* deleteFromFront(struct Student* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    // Create a temporary pointer and set it to the current head
    struct Student* temp = head;

    // Update the head to be the next node in the list
    head = head->next;

    // If the list is not empty, update the prev pointer of the new head to be NULL
    if (head != NULL) {
        head->prev = NULL;
    }

    // Free the memory occupied by the node pointed to by temp
    free(temp);

    // Print a message indicating that the student record has been deleted from the front
    printf("Student record deleted from the front.\n");

    // Return the updated head of the linked list
    return head;
}

// Function to display the student record at the front of the list
void showFront(struct Student* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Print the student record at the front of the list
    printf("Student Record at the Front:\n");
    printf("Roll Number: %d\n", head->rollNumber);
    printf("Name: %s\n", head->name);
    printf("Course: %s\n", head->course);
    printf("Marks: %.2f\n", head->marks);
}

// Function to search and display the student record at a given position
void searchRecordAtPosition(struct Student* head, int position) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty. No records to search.\n");
        return;
    }

    // Initialize temporary pointer and count
    struct Student* temp = head;
    int count = 1;

    // Traverse the list until the desired position is reached or the end of the list
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    // Check if the desired position is found
    if (temp != NULL) {
        // Print the student record information at the given position
        printf("Record at position %d:\n", position);
        printf("Roll Number: %d, Name: %s, Course: %s, Marks: %.2f\n",
               temp->rollNumber, temp->name, temp->course, temp->marks);
    } else {
        // Print a message if the given position exceeds the length of the list
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

// Function to update a student record with a given position
void updateRecord(struct Student** head, int position, char name[], int rollNumber, char course[], int marks) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty. No records to update.\n");
        return;
    }

    // Initialize temporary pointer and count
    struct Student *temp = *head;
    int count = 1;

    // Traverse the list until the desired position is reached or the end of the list
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    // Check if the desired position is found
    if (temp != NULL) {
        // Update the information for the student at the given position
        strcpy(temp->name, name);
        temp->rollNumber = rollNumber;
        strcpy(temp->course, course);
        temp->marks = marks;

        // Print a message indicating that the student record has been updated successfully
        printf("Record at position %d updated successfully.\n", position);
    } else {
        // Print a message if the given position exceeds the length of the list
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

// Function to display all student records in the list
void display(struct Student* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Initialize temporary pointer
    struct Student* temp = head;

    // Print a header for the student records
    printf("Student Records:\n");

    // Traverse the list and print information for each student
    while (temp != NULL) {
        printf("Roll Number: %d, Name: %s, Course: %s, Marks: %.2f\n",
               temp->rollNumber, temp->name, temp->course, temp->marks);
        temp = temp->next;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student struct and functions (insertFromLast, deleteFromFront, showFront, searchRecordAtPosition, updateRecord, display)

int main() {
    int choice, rollNumber, position;
    float marks;
    char name[50], course[50];
    struct Student* head = NULL;

    do {
        // Display menu
        printf("\nStudent Record Management System Menu:\n");
        printf("1. Insert Student Record from Last\n");
        printf("2. Delete Student Record from Front\n");
        printf("3. Show Student Record (Front)\n");
        printf("4. Search Student Record by Position\n");
        printf("5. Update Student Record\n");
        printf("6. Display All Student Records\n");
        printf("0. Exit\n");

        // Prompt user for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice using switch statement
        switch (choice) {
            case 1:
                // Insert student record from last
                // Get user input for rollNumber, name, course, and marks
                printf("Enter Roll Number: ");
                scanf("%d", &rollNumber);
                printf("Enter Name: ");
                getchar(); 
                fgets(name, sizeof(name), stdin); 
                name[strcspn(name, "\n")] = '\0';
                printf("Enter Course (CSE/AIML/DS/IT/ECE)): ");
                scanf("%s", course);  
                printf("Enter Marks: ");
                scanf("%f", &marks);
                // Call insertFromLast function
                head = insertFromLast(head, rollNumber, name, course, marks);
                break;
                break;

            case 2:
                // Delete student record from front
                // Call deleteFromFront function
                head = deleteFromFront(head);
                break;

            case 3:
                // Show student record at front
                // Call showFront function
                showFront(head);
                break;


            case 4:
                // Search student record by position
                printf("Enter Position to Search: ");
               // Get user input for position
                scanf("%d", &position);
               // Call searchRecordAtPosition function
                searchRecordAtPosition(head, position);
                break;

            case 5:
                // Update student record
                // Get user input for position, rollNumber, name, course, and marks
                printf("Enter position to Update: ");
                scanf("%d", &position);
                printf("Enter new Roll Number: ");
                scanf("%d", &rollNumber);
                printf("Enter new name: ");
                getchar(); 
                fgets(name, sizeof(name), stdin); 
                name[strcspn(name, "\n")] = '\0';
                printf("Enter new course (CSE/AIML/DS/IT/ECE): ");
                scanf("%s", course);  
                printf("Enter new marks: ");
                scanf("%f", &marks);
                // Call updateRecord function
                updateRecord(&head, position, name, rollNumber, course, marks);
                break;

            case 6:
                // Display all student records
                // Call display function
                display(head);
                break;

            case 0:
                // Exit program
                printf("Exiting program.\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
