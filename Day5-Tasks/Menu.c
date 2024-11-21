#include <stdio.h>
#include "conio.h"
#define UP 65
#define DOWN 66
#define EXTEND 27
#define BACK 127
#define ENTER 10
#define SIZE 100

typedef struct Employee {
    int id;
    char name[20];
    int salary;
} Employee;



void homePage(){
    clrscr();
    printf("\033[%d;%dH Home Page ", 5,0);
    printf("\033[%d;%dH Display ", 10,0);
    printf("\033[%d;%dH New", 15,0);
    printf("\033[%d;%dH Modify", 20,0);
    printf("\033[%d;%dH Exit", 25,0);
}

void displayEmployees(Employee emp[], int *numOfEmp) {
    clrscr();
    if (numOfEmp == 0) {
        printf("No employees to display.\n");
    } else {
        printf("All Employees:\n");
        for (int i = 0; i < numOfEmp; i++) {
            if (emp[i].id > 0){
            printf("%d. ID: %d, Name: %s, Salary: %d\n", i + 1, emp[i].id, emp[i].name, emp[i].salary);
            printf("\n-------------------------------------------------------\n");
        }
        }

    }
    printf("\nPress BackSpace key to return to the menu.");
}

void modifyEmployee(Employee emp[], int numOfEmp) {
    clrscr();
    int idToModify;
    for (int i = 0; i < numOfEmp; i++) {
    if (emp[i].id > 0){
    printf("Employee found: ID: %d, Name: %s, Salary: %d\n", emp[i].id, emp[i].name, emp[i].salary);
    }
    }
    printf("Enter the ID of the employee you want to modify: ");

    scanf("%d", &idToModify);

    // Find the employee by ID
    int found = 0;
    for (int i = 0; i < numOfEmp; i++) {
        if (emp[i].id == idToModify) {
            found = 1;
            printf("Employee found: ID: %d, Name: %s, Salary: %d\n", emp[i].id, emp[i].name, emp[i].salary);
            printf("Choose what to modify:\n");
            printf("1. Modify Name\n");
            printf("2. Modify ID\n");
            printf("3. Modify Salary\n");
            printf("4. Delete Employee\n");
            printf("Enter your choice (1-4): ");
            
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Enter new name: ");
                scanf("%s", emp[i].name);
            } else if (choice == 2) {
                printf("Enter new ID: ");
                scanf("%d", &emp[i].id);
            } else if (choice == 3) {
                printf("Enter new salary: ");
                scanf("%d", &emp[i].salary);
            } else if (choice == 4) {
                for (int j = i; j < numOfEmp - 1; j++) {
                    emp[j] = emp[j + 1];
                }
                char last = numOfEmp -1 ;
                emp[last].id = 0;
   
                numOfEmp--;
                printf("Employee deleted successfully.\n");
                i = numOfEmp;
            }
            i = numOfEmp;
        }
    }
    
    if (!found) {
        printf("Employee not found.\n");
    }
    printf("Press BackSpace key to return to the menu.");
}

int main() {
    char content = 'h';
    char line = 1;
    Employee emp[SIZE];
    int numOfEmp = 0;

    homePage();

    while(1) {
        char col = line * 5 + 5;
        if (content == 'h') {
            homePage();
            if (line == 1) {
                printf("\033[%d;%dH \033[1;35m Display \033[0m", col,0);
            } else if (line == 2) {
                printf("\033[%d;%dH \033[1;35m New \033[0m", col,0);
            } else if (line == 3) {
                printf("\033[%d;%dH \033[1;35m Modify \033[0m", col,0);
            } else if (line == 4) {
                printf("\033[%d;%dH \033[1;35m Exit \033[0m", col,0);
            }
        }

        char choice = getch();

        if (choice == EXTEND) {
            if (!kbhit()) {
                clrscr();
                return 0;
            }
            choice = getch();
            choice = getch();
        }

        switch(choice) {
        case UP:
            if (content == 'h') {
                line--;
                if (line == 0) line = 4;
            }
            break;

        case DOWN:
            if (content == 'h') {
                line++;
                if (line == 5) line = 1;
            }
            break;

        case ENTER:
            if (content == 'h') {
                clrscr();
                if (line == 1) {
                    content = 'd';
                    displayEmployees(emp, numOfEmp);
                } else if (line == 2) {
                    content = 'n';
                    char loopExit = 0;
                    while (loopExit == 0) {
                        printf("ID: ");
                        scanf("%d", &emp[numOfEmp].salary);
                        printf("Name: ");
                        scanf("%s", emp[numOfEmp].name);
                        printf("Salary: ");
                        scanf("%d", &emp[numOfEmp].salary);
                        numOfEmp++;
                        printf("Do you want to enter another one? [0 for no]: ");
                        scanf("%d", &loopExit);
                    }
                    content = 'h';
                    line = 1;
                } else if (line == 3) {
                    content = 'm';
                    modifyEmployee(emp, numOfEmp);
                    content = 'h';
                    line = 1;
                } else if (line == 4) {
                    clrscr();
                    return 0;
                }
            }
            break;

        case BACK:
            if (content == 'i') {
                clrscr();
                content = 'h';
            } else if (content != 'h') {
                clrscr();
                content = 'h';
                line = 1;
            } else {
                clrscr();
                printf("Invalid Input (BackSpace to back to menu)\n");
                content = 'i';
            }
            break;

        default:
            clrscr();
            printf("Invalid Input (BackSpace to back to menu) \nUp, Down, Enter Only accepted & BackSpace to back");
            if (content != 'i') {
                content = 'i';
            }
            break;
        }
    }
}
