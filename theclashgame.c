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

//https://infoc.eet.bme.hu/jegyzet/c_puska.pdf

Patient* createPatient(char *name, int age, int room);
void addPatient(Patient **head, Patient *newPatient);
void printPatients(Patient *head);
void freePatients(Patient *head);
int getOldestPatient(Patient *head);
//Se debe definir el idioma para todo el programa no tener ing y esp
//se debe definir tambien el formato de la notacion  this_is_an_identifer vs camelCase. C utiliza this_is_an_identifer.
void newAgeForPatients(Patient *head,int max_age,int aguaDeLaVida);
void dar_de_alta(Patient **head, int identificador_habitacion);

int main() {
    Patient *head = NULL;
    Patient *newPatient;
    int maxAge = 0;

    // Create three patient records
    newPatient = createPatient("Manuel", 32, 6);
    addPatient(&head, newPatient);

    newPatient = createPatient("Alejandro", 45, 12);
    addPatient(&head, newPatient);

    newPatient = createPatient("Rocio", 22, 54);
    addPatient(&head, newPatient);

    newPatient = createPatient("Amparo", 22, 53);
    addPatient(&head, newPatient);

    // Print the list of patients
    printPatients(head);
    
    //Print the oldes age.
    maxAge = getOldestPatient(head);
    newAgeForPatients(head,maxAge,20);


    printPatients(head);    

    //Dar de alta
    dar_de_alta(&head,12);
    
    printPatients(head);   

    // Free the memory used by the patients
    freePatients(head);

    system("pause");
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
int getOldestPatient(Patient *head){
    int maxAge = 0;
    char nombre[20];
    Patient *current = head;
    while (current != NULL) {
        if ( maxAge < current->age ){
           maxAge = current->age;
           strcpy(nombre, current->name);
        }
        current = current->next;
    }
    printf("The oldest patient is %s with %d years old\n\n\n",nombre,maxAge);
    return maxAge;
}

void newAgeForPatients(Patient *head,int max_age,int aguaDeLaVida){
     Patient *current = head;
     while (current != NULL) {
           if ( current->age == max_age) {
              current->age = current->age - aguaDeLaVida;
           }
           current = current->next;
     }     
}

// Funcion Eliminar elemento de la lista (simple)
void dar_de_alta(Patient **head, int identificador_habitacion) {
     Patient *current = *head;
     Patient *anterior = NULL;
     
     //Caso con el Head o inicio
     if (current != NULL && current->room == identificador_habitacion) {
        *head = current->next; // se cambia el inicio o head
        free(current);        // Free memory
        return;
    }
     
    // Se busca para eliminar guardando el elemento previo.
    while (current != NULL && current->room != identificador_habitacion) {
        anterior = current;
        current = current->next;
    }

    // Si no se encuentra el valor buscado.
    if (current == NULL) {
        printf("No se encuentra la habilitación");
        return;
    }

    // Se desvinculado los elementos de la lista antes de eliminar.
    printf("El paciente %s de la habitacion %d es dado de alta\n\n",current->name,identificador_habitacion);
    anterior->next = current->next;
    free(current); // Free memory  
     
          
}
     
