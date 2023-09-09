#include "stdio.h"
#include "stdlib.h"

//define data
float SIP_data[5][5] = {
    {0.013, 0.015, 0.017, 0.019, 0.021},
    {0.015, 0.017, 0.019, 0.021, 0.023},
    {0.017, 0.019, 0.021, 0.023, 0.027},
    {0.019, 0.021, 0.023, 0.025, 0.030},
    {0.021, 0.023, 0.025, 0.027, 0.069}
};

// struct employee
typedef struct employee
{
    char Account[64];
    int Age;
    char Department[20];
    int SPR; // Supervisor performance rating
    int PPR; // Peer performance rating
    float BaseSalary;
    float FinalSalary;
} Employee;

// link node
typedef struct node{
    struct employee data;
    struct node *next;
} Node; 


Node *head = NULL, *p = NULL;


// define function
void InputEmployee(Employee *employee); // input account - age - department - SPR - PPR - base salary
void OutputEmployee(Employee *employee,int index); // output account - age - department - SPR - PPR - base salary - final salary
void CalculateSalary(Employee *employee);
void ShowListEmployee();


// main function
int main(){
    // interface for user
    int choice;

    Employee employee;

    do{
        printf("\n --->Show selection list:\n");
        printf("1. Add new employee\n");
        printf("2. Show list employee after calculate Salary\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InputEmployee(&employee);
            break;
        case 2:
            ShowListEmployee();
            break;
        case 3:
            printf("Exit program\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }while(choice != 3);

    
    return 0;
}
// create node

Node *createNode(Employee *employee){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = *employee;
    newNode->next = NULL;
    return newNode;
}

// add employee
void AddEmployee(Employee *employee){
    Node *newNode = createNode(employee);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = newNode;
}


// define function
void InputEmployee(Employee *employee){

    printf("Input account: ");
    scanf("%s", employee->Account);
    printf("Input age: ");
    scanf("%d", &employee->Age);
    printf("Input department: ");
    scanf("%s", employee->Department);
    printf("Input SPR: ");
    scanf("%d", &employee->SPR);
    printf("Input PPR: ");
    scanf("%d", &employee->PPR);
    printf("Input base salary: ");
    scanf("%f", &employee->BaseSalary);
    CalculateSalary(employee);
    AddEmployee(employee);
}

// print employee
void OutputEmployee(Employee *employee,int index){
    printf("%d. ", index);
    printf("%s ", employee->Account);
   // printf("- %d ", employee->Age);
    printf("- %s ", employee->Department);
    printf("- %.0f ", employee->BaseSalary);
    printf("- %.3f ", SIP_data[employee->SPR - 1][employee->PPR - 1]);
    printf("- %.0f \n", employee->FinalSalary);
}


// calculate salary
void CalculateSalary(Employee *employee){
    int i, j;
    float SIP;
    i = employee->SPR - 1;
    j = employee->PPR - 1;
    SIP = SIP_data[i][j];
    employee->FinalSalary = employee->BaseSalary + employee->BaseSalary * SIP;
}

// show list employee
void ShowListEmployee(){
    Node *p = head;
    int i = 1;
    printf("==========> List employee: (Account - Department - Base salary - SIP - Final salary)\n");
    while(p != NULL){
        OutputEmployee(&p->data, i++);
        p = p->next;
    }
}
