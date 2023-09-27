#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition
typedef struct patient {
    char name[20];
    int age;
    int room;
    struct patient *next;
} Patient;

Patient* createPatient(char *name, int age, int room);
void addPatient(Patient **head, Patient *newPatient);
void printPatients(Patient *head);
void freePatients(Patient *head);
void getOldestPatient(Patient *head);

int main() {
    Patient *head = NULL;
    Patient *newPatient;

    // Create three patient records
    newPatient = createPatient("Manuel", 32, 6);
    addPatient(&head, newPatient);

    newPatient = createPatient("Alejandro", 45, 12);
    addPatient(&head, newPatient);

    newPatient = createPatient("Rocio", 22, 53);
    addPatient(&head, newPatient);

    newPatient = createPatient("Amparo", 22, 53);
    addPatient(&head, newPatient);

    // Print the list of patients
    printPatients(head);

    // Free the memory used by the patients
    freePatients(head);

    return 0;
}

// Function to create a new patient record
Patient* createPatient(char *name, int age, int room) {
    Patient *newPatient = (Patient*)malloc(sizeof(Patient));
    strcpy(newPatient->name, name);
    newPatient->age = age;
    newPatient->room = room;
    newPatient->next = NULL;
    return newPatient;
}

// Function to add a new patient to the list
void addPatient(Patient **head, Patient *newPatient) {
    if (*head == NULL) {
        *head = newPatient;
    } else {
        Patient *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPatient;
    }
}

// Function to print the list of patients
void printPatients(Patient *head) {
    printf("List of patients:\n");
    Patient *current = head;
    while (current != NULL) {
        printf("Name: %s, age: %d, Room number: %d.\n", current->name, current->age, current->room);
        current = current->next;
    }
}

// Function to free the list of patienes
void freePatients(Patient *head) {
    Patient *current = head;
    while (current != NULL) {
        Patient *next = current->next;
        free(current);
        current = next;
    }
}
// Function for get the oldest patient
void getOldestPatient(Patient *head){
    int maxAge = 0;
    Patient *current = head;
    while (current != NULL) {
        if ( maxAge < current->age )
           maxAge = current->age;
        current = current->next;
    }
}

