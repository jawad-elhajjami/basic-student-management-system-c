#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LIMIT 50

struct NotesEtudiant {
    float noteMath;
    float noteCS;
    float noteANG;
};

struct Etudiant {
    int cne;
    char nom[MAX_LIMIT];
    char prenom[MAX_LIMIT];
    int age;
    char filiere[30];
    char classe[MAX_LIMIT];
    struct NotesEtudiant notes;
};

// Function to calculate the total grade of a student
float calculerNoteGenerale(struct Etudiant e) {
    float sum = e.notes.noteMath + e.notes.noteCS + e.notes.noteANG;
    return sum / 3;
}

// function to return a single student
void single_studuent(struct Etudiant single_etduiant){
    printf("Full name: %s %s\t", single_etduiant.prenom, single_etduiant.nom);
    printf("CNE: %d\t", single_etduiant.cne);
    printf("Age: %d\t", single_etduiant.age);
    printf("Major: %s\t", single_etduiant.filiere);
    printf("Class: %s\t", single_etduiant.classe);
    printf("General grade: %.2f\n", calculerNoteGenerale(single_etduiant));
    printf("###############\n\n");
}

// Function to show all students
void voirEtudiants(struct Etudiant etudiants[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Postition : %d \t", i+1);
        single_studuent(etudiants[i]);
    }
}



// Function to enable the user to add multiple students to an array
void ajouterEtudiant(struct Etudiant etudiants[], int size) {
    for (int i = 0; i < size; i++) {
        getchar(); // Clear the input buffer before reading strings
        printf("Enter student[%d] first name: ", i + 1);
        fgets(etudiants[i].prenom, sizeof(etudiants[i].prenom), stdin);
        etudiants[i].prenom[strcspn(etudiants[i].prenom, "\n")] = '\0'; // Remove newline

        printf("Enter student[%d] last name: ", i + 1);
        fgets(etudiants[i].nom, sizeof(etudiants[i].nom), stdin);
        etudiants[i].nom[strcspn(etudiants[i].nom, "\n")] = '\0';

        printf("Enter student[%d] CNE: ", i + 1);
        scanf("%d", &etudiants[i].cne);

        printf("Enter student[%d] age: ", i + 1);
        scanf("%d", &etudiants[i].age);

        getchar(); // Clear the newline left in the input buffer

        printf("Enter student[%d] major: ", i + 1);
        fgets(etudiants[i].filiere, sizeof(etudiants[i].filiere), stdin);
        etudiants[i].filiere[strcspn(etudiants[i].filiere, "\n")] = '\0';

        printf("Enter student[%d] class: ", i + 1);
        fgets(etudiants[i].classe, sizeof(etudiants[i].classe), stdin);
        etudiants[i].classe[strcspn(etudiants[i].classe, "\n")] = '\0';

        printf("###############\n\n Student added successfully!\n\n");
    }
}

// specify grades
void ajouter_notes(struct Etudiant etudiants[], int size){
    int pos, current;
    float math,cs,ang;
    printf("Enter student position : ");
    scanf("%d", &pos);
    if(pos > size){
        printf("There has been an error !");
        printf("\n\n");
        return;
    }else{
        for(int i=0;i<size;i++){
            current = i + 1;
            if(pos == current){
                printf("Specify grades for %s %s \n\n", etudiants[i].nom, etudiants[i].prenom);
                printf("====================================== \n\n");
                printf("Enter math grade : ");
                scanf("%f", &math);
                printf("Enter Computer science grade : ");
                scanf("%f", &cs);
                printf("Enter English grade : ");
                scanf("%f", &ang);
                etudiants[i].notes.noteANG = ang;
                etudiants[i].notes.noteCS = cs;
                etudiants[i].notes.noteMath = math;
            }
        }
        printf("Position not found !! \n\n");
    }
}


// function to search for student
void search_students(struct Etudiant etudiants[], int size){
    getchar();
    int choice,cne;
    char lastname[MAX_LIMIT];
    printf("Search by 1.CNE or 2.Last name ===> ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("Enter cne : ");
        scanf("%d", &cne);
        // search students by cne
        for(int i=0;i<size;i++){
            if(etudiants[i].cne == cne){
                printf("Student found !!! \n ========================= \n");
                single_studuent(etudiants[i]);
                printf("========================= \n");
                return;
            }else{
                printf("Student NOT found !!!");
            }
        }
    }else if(choice == 2){
        getchar();
        printf("Enter last name : ");
        fgets(lastname, sizeof(lastname), stdin);
        lastname[strcspn(lastname,"\n")] = '\0';
        for(int i=0;i<size;i++){
            if(strcmp(etudiants[i].nom, lastname) == 0){
                printf("Student found !!! \n ========================= \n");
                single_studuent(etudiants[i]);
                printf("========================= \n");
                return;
            }
        }
        printf("Student NOT found !!!");
    }else{
        printf("You can only choose 1 or 2 !! \n");
    }
}

int main() {
    int choice = -1;
    int pos;
    int num_students = 0;
    const int MAX_ETUDIANTS = 40;
    struct Etudiant etudiantsArray[MAX_ETUDIANTS];

    printf("\n\nWelcome to student management SYSTEM:\n");
    printf("============================================\n");

    while (choice != 0) {
        printf("1. View All students\n");
        printf("2. Search for a student\n");
        printf("3. Add new student\n");
        printf("4. Remove student\n");
        printf("5. Specify student grades \n");
        printf("0. Exit\n");
        printf("Enter your choice (1, 2, 3, 4, or 0 to exit):\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_students > 0) {
                    voirEtudiants(etudiantsArray, num_students);
                } else {
                    printf("No students to display!\n\n");
                }
                break;
            case 2:
                search_students(etudiantsArray, num_students);
                break;
            case 3:
                printf("How many students do you want to add? ===> ");
                int add_count;
                scanf("%d", &add_count);
                if (num_students + add_count <= MAX_ETUDIANTS) {
                    ajouterEtudiant(&etudiantsArray[num_students], add_count);
                    num_students += add_count;
                } else {
                    printf("You are not allowed to add this many students into the list!\n\n");
                }
                break;
            case 4:
                printf("Enter position to delete : ");
                scanf("%d", &pos);
                // determine if deletion is possible
                if(pos > num_students){
                    printf("Deletion is NOT possible ! \n");
                    break;
                }else{
                    for(int i=pos-1;i<num_students;i++){
                        etudiantsArray[i] = etudiantsArray[i+1];
                    }
                    num_students--;
                    printf("Student deleted successfully !\n\n");
                }
                break;
            case 5:
                ajouter_notes(etudiantsArray, num_students);
                break;
            case 0:
                printf("Come back soon!\n");
                break;
            default:
                printf("Unknown case!!\n");
                break;
        }
    }

    return 0;
}