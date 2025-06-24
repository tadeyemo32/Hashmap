#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 

#define Max_Students 100 //max number of students 


typedef enum {  // grades 
    A,
    B,
    C,
    D,
    F,
    empty,
} Grade;


typedef struct Student {// Student type 

char name[20];
Grade grade; 
}Student;

typedef struct Node { // buckets to hold the students and the ablity to link with other nodes 

Student *student;
struct Node * collisionptr; 

}Node;


    Node *StudentDirectory[Max_Students];

void init(){// initialize the list Indicies 
    for(int i = 0 ;i<Max_Students;i++){
        StudentDirectory[i] = NULL;
    }

}

int hash(Student *student) { // simple hash fuction using student name
    int sum = 0;
    for (int i = 0; student->name[i] != '\0'; i++) {
        sum += (int)student->name[i];
    }
    return sum % Max_Students;
}


int hashC(char name[20]) { // simple hash fuction using student name
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += (int)name[i];
    }
    return sum % Max_Students;
}

Student* createStudent(Grade grade ,char name[20]){ // create student ptr 
Student *newStudent =   malloc(sizeof(Student));
newStudent->grade = grade;
strcpy(newStudent->name, name);
return newStudent;
}

bool insert(Student *s){// insert student 
    int n = hash(s); // index based on hash 
    Node *newNode = malloc(sizeof(Node));// allocation of memory for each node 


    newNode->student = s; 
    newNode->collisionptr =NULL;

    if(StudentDirectory[n] == NULL){
        StudentDirectory[n] = newNode;
    }else{
        Node *current = StudentDirectory[n];
        // linked list travesal to ensure new node added to end of linked list in collision handeling
    while (current->collisionptr != NULL) {
            current = current->collisionptr;
        }
        current->collisionptr = newNode;

    }

return true;
}

Grade searchDicrectory(char name[20]) {
    int index = hashC(name);
    Node *curr = StudentDirectory[index];

    while (curr != NULL) {
        if (strcmp(curr->student->name, name) == 0) {
            printf("Student found Pos: %d\n", index);
            return curr->student->grade;
        }
        curr = curr->collisionptr;
    }

    printf("Student does not exist\n");
    return empty;
}






void printDirectory() {
    printf("=== Student Directory ===\n");
    for (int i = 0; i < Max_Students; i++) {
        Node *current = StudentDirectory[i];
        if (current != NULL) {
            printf("Bucket %d:\n", i);
            while (current != NULL) {
                printf("  Name: %-20s Grade: %d\n", current->student->name, current->student->grade);
                current = current->collisionptr;
            }
        }
    }
}


void freeDirectory() { 
    for (int i = 0; i < Max_Students; i++) {
        Node *current = StudentDirectory[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->collisionptr;
            free(temp->student);  // Free the student
            free(temp);           // Free the node
        }
    }
}


int main() {
    init(); 

    Student *s1 = createStudent(B,"Alex Walker ");
    Student *s2 = createStudent(F,"Ander Yang");
    Student *s3 = createStudent(B,"Stacy Mac ");
    Student *s4 = createStudent(A,"Herobrione MM");
    Student *s5 = createStudent(A,"Lex Luther");
    Student *s6 = createStudent(C,"Bruce Wayne");
 

    insert(s1);
    insert(s2);
    insert(s3);
    insert(s4);
    insert(s5);
    insert(s6);

    printDirectory();
    searchDicrectory("Bruce Wayne");
freeDirectory();


    return 0;
}
