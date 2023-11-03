#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// ANSI escape codes for color formatting
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RED "\x1b[31m"

// Define a unique name for the enum
typedef enum {
    MY_INT,
    MY_CHAR,
    MY_FLOAT,
    MY_USER_STRUCT
} DataType;

// Define a user-defined struct
struct UserStruct {
    int id;
    char name[20];
};

// Structure to represent data along with its type
struct DataWithDataType {
    DataType type;
    union {
        int intData;
        char charData;
        float floatData;
        struct UserStruct userStructData;
    } data;
};

// A structure to represent a stack
struct StackNode {
    struct DataWithDataType data;
    struct StackNode* next;
};

// Function prototypes
struct StackNode* newNode(struct DataWithDataType data);
void push(struct StackNode**, struct DataWithDataType, int);
void pop(struct StackNode**, struct DataWithDataType*);
void peek(struct StackNode*);
int isEmpty(struct StackNode*);
int isFull(struct StackNode*, int, size_t);
void freeStack(struct StackNode*);
void clearScreen();
int usedStackSize(struct StackNode*);
int freeStackSize(int, int);

// Driver program to test above functions
int main() {
    struct StackNode* root = NULL;
    int maxStackSize;

    clearScreen();
    while (1) {
        printf("Enter the maximum stack size: ");
        scanf("%d", &maxStackSize);

        if (maxStackSize <= 0) {
            clearScreen();
            printf("Invalid stack size. Please enter a positive value.\n");
        } else {
            break;
        }
    }

    // Define variables for user input
    char choice;
    int intData;
    char charData;
    float floatData;
    struct UserStruct userStructData;

    // Menu-driven program
    while (1) {
        int usedSize = usedStackSize(root);
        int freeSize = freeStackSize(maxStackSize, usedSize);
        clearScreen();
        printf("\n");
        printf("%s*****************************************\n", ANSI_COLOR_YELLOW);
        printf("**              Stack Menu             **\n");
        printf("*****************************************\n");
        printf("%s1. %sPush\n", ANSI_COLOR_YELLOW, ANSI_COLOR_GREEN);
        printf("%s2. %sPop\n", ANSI_COLOR_YELLOW, ANSI_COLOR_GREEN);
        printf("%s3. %sPeek\n", ANSI_COLOR_YELLOW, ANSI_COLOR_GREEN);
        printf("%s4. %sUpdate Max Size\n", ANSI_COLOR_YELLOW, ANSI_COLOR_GREEN);
        printf("%s5. %sCheck if Stack is Full\n", ANSI_COLOR_YELLOW, ANSI_COLOR_GREEN);
        printf("%s6. %sCheck if Stack is Empty\n", ANSI_COLOR_YELLOW, ANSI_COLOR_GREEN);
        printf("%s7. %sExit%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RED, ANSI_COLOR_RESET);
        printf("%s*****************************************\n", ANSI_COLOR_YELLOW);
        printf("%sTotal Stack Size: %d\n", ANSI_COLOR_GREEN, maxStackSize);
        printf("%sUsed Stack Size: %d\n", ANSI_COLOR_GREEN, usedSize);
        printf("%sFree Stack Size: %d\n", ANSI_COLOR_GREEN, freeSize);
        printf("%s*****************************************%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

        printf("Enter your choice: ");
        scanf(" %c", &choice);
        while(getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case '1':
                clearScreen();
                printf("%sEnter data: %s", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
                char input[50];
                scanf(" %[^\n]", input);
                struct DataWithDataType data;
                struct UserStruct userStruct;
                  
                // Check if the input contains a dot, indicating it's a float
                if (strchr(input, '.') != NULL) {
                    float tempFloat;
                    if (sscanf(input, "%f", &tempFloat) == 1) {
                        data.data.floatData = tempFloat;
                        data.type = MY_FLOAT;
                        push(&root, data, maxStackSize);
                    } else {
                        clearScreen();
                        printf("%sInvalid input. Please enter valid data.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                    }
                }
                
                // Check if the input contains a space, indicating it's a user-defined struct
                else if (sscanf(input, "%d %19s", &userStruct.id, userStruct.name) == 2) {
                    data.data.userStructData = userStruct;
                    data.type = MY_USER_STRUCT;
                    push(&root, data, maxStackSize);
                }

                // Try interpreting the input as an integer
                else if (sscanf(input, "%d", &data.data.intData) == 1) {
                    data.type = MY_INT;
                    push(&root, data, maxStackSize);
                }
                // Try interpreting the input as a character
                else if (strlen(input) == 1) {
                    data.data.charData = input[0];
                    data.type = MY_CHAR;
                    push(&root, data, maxStackSize);
                }
                // If not an integer, character, or float, treat it as a user-defined struct
                else {
                    clearScreen();
                    printf("%sInvalid input. Please enter valid data.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                }
                system("pause");
                break;
            case '2':
                clearScreen();
                printf("%sPopping from the stack...%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
                if (!isEmpty(root)) {
                    struct DataWithDataType poppedData;
                    pop(&root, &poppedData);
                    switch (poppedData.type) {
                    case MY_INT:
                        printf("%sPopped integer data: %d%s\n\n", ANSI_COLOR_GREEN, poppedData.data.intData, ANSI_COLOR_RESET);
                        break;
                    case MY_CHAR:
                        printf("%sPopped character data: %c%s\n\n", ANSI_COLOR_GREEN, poppedData.data.charData, ANSI_COLOR_RESET);
                        break;
                    case MY_FLOAT:
                        printf("%sPopped float data: %f%s\n\n", ANSI_COLOR_GREEN, poppedData.data.floatData, ANSI_COLOR_RESET);
                        break;
                    case MY_USER_STRUCT:
                        printf("%sPopped user-defined struct data (id: %d, name: %s)%s\n\n", ANSI_COLOR_GREEN, poppedData.data.userStructData.id, poppedData.data.userStructData.name, ANSI_COLOR_RESET);
                        break;
                    default:
                        printf("Invalid data type.\n");
                    }
                } else {
                    printf("%sStack is empty.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                }
                system("pause");
                break;
            case '3':
                clearScreen();
                printf("%sPeeking at the stack...%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
                if (!isEmpty(root)) {
                    peek(root);
                } else {
                    printf("%sStack is empty.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                }
                system("pause");
                break;
            case '4':
                clearScreen();
                while (1) {
                    printf("Enter the new maximum stack size: ");
                    scanf("%d", &maxStackSize);

                    if (maxStackSize <= 0) {
                        clearScreen();
                        printf("%sInvalid stack size. Please enter a positive value.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                    } else {
                        break;
                    }
                }
                break;
            case '5':
                clearScreen();
                if (isFull(root, maxStackSize, sizeof(struct DataWithDataType))) {
                    printf("%sThe stack is full.%s\n\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
                } else {
                    printf("%sThe stack is not full.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                }
                system("pause");
                break;
            case '6':
                clearScreen();
                if (isEmpty(root)) {
                    printf("%sThe stack is empty.%s\n\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
                } else {
                    printf("%sThe stack is not empty.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                }
                system("pause");
                break;
            case '7':
                freeStack(root);
                clearScreen();
                printf("%sExiting...%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                exit(0);
            default:
                clearScreen();
                printf("%sInvalid choice, please try again.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
                system("pause");
            }
    }

    return 0;
}

// Clear screen
void clearScreen() {
    system("cls"); // For Windows
    system("clear"); // For Linux and Mac OS
}

// Function to add an element x in the stack
struct StackNode* newNode(struct DataWithDataType data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return !top;
}

// Function to check if the stack is full
int isFull(struct StackNode* top, int maxStackSize, size_t dataSize) {
    int count = 0;
    struct StackNode* current = top;
    while (current != NULL) {
        count += dataSize;
        current = current->next;
    }
    return (count >= maxStackSize * dataSize);
}

// Function to add an element x in the stack
void push(struct StackNode** top, struct DataWithDataType data, int maxStackSize) {
    if (isFull(*top, maxStackSize, sizeof(struct DataWithDataType))) {
        printf("%sStack is full. Cannot push data.%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        return;
    }
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *top;
    *top = stackNode;
    printf("%sData pushed to stack!%s\n\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
}

// Function to remove an element from the stack
void pop(struct StackNode** top, struct DataWithDataType* poppedData) {
    if (isEmpty(*top)) {
        return;
    }
    struct StackNode* temp = *top;
    *top = (*top)->next;
    *poppedData = temp->data;
    free(temp); // Free the memory allocated for the node.
}

// Function to return the top from stack without removing it
void peek(struct StackNode* top) {
    if (isEmpty(top)) {
        return;
    }

    switch (top->data.type) {
        case MY_INT:
            printf("%sPeeked integer data: %d%s\n\n", ANSI_COLOR_GREEN, top->data.data.intData, ANSI_COLOR_RESET);
            break;
        case MY_CHAR:
            printf("%sPeeked character data: %c%s\n\n", ANSI_COLOR_GREEN, top->data.data.charData, ANSI_COLOR_RESET);
            break;
        case MY_FLOAT:
            printf("%sPeeked float data: %f%s\n\n", ANSI_COLOR_GREEN, top->data.data.floatData, ANSI_COLOR_RESET);
            break;
        case MY_USER_STRUCT:
            printf("%sPeeked user-defined struct data (id: %d, name: %s)%s\n\n", ANSI_COLOR_GREEN, top->data.data.userStructData.id, top->data.data.userStructData.name, ANSI_COLOR_RESET);
            break;
        default:
            printf("Invalid data type.\n");
    }
}

// Function to free the entire stack
void freeStack(struct StackNode* top) {
    while (top != NULL) {
        struct StackNode* temp = top;
        top = top->next;
        free(temp);
    }
}

// Function to calculate the used stack size
int usedStackSize(struct StackNode* top) {
    int count = 0;
    struct StackNode* current = top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to calculate the free stack size
int freeStackSize(int maxStackSize, int usedSize) {
    return (maxStackSize - usedSize);
}
