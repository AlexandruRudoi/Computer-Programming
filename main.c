#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <setjmp.h>

// Define a global buffer
static jmp_buf exception_buffer;

// Define a macro for TRY-CATCH
#define TRY if (setjmp(exception_buffer) == 0)
#define CATCH else
#define END_TRY

// Define color escape sequences
#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1B[32m"
#define YELLOW_TEXT "\x1B[33m"
#define RESET_COLOR "\x1B[0m"

// Prototypes of functions
void clearScreen();
void continueProgram(char **buffer);
void clearInputBuffer();
void handleException();
void printBuffer(char *text);
void menu(char **buffer);
int enterText(char **text);
int deleteBuffer(char **text);
int replaceWord(char **text, char *word, char *replacement);
int searchWord(const char *text, const char *word);
void saveToFile(char **buffer);
char* loadFromFile();

// Main function
int main(){
    char *buffer = NULL;
    while(1){
        menu(&buffer);
    }
    return 0;
}

// Clear Screen
void clearScreen(){
    system("clear");
    system("cls");
}

// Custom function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Handle Exception
void handleException() {
    longjmp(exception_buffer, 1);
}

// Continue
void continueProgram(char **buffer) {
    char choice;

    printf("\nWould you like to continue? (y/n): ");
    scanf(" %c", &choice);

    clearInputBuffer(); // Clear any remaining characters in the input buffer

    if (choice == 'n' || choice == 'N') {
        clearScreen();
        printf("Exiting...\n");
        if (*buffer != NULL) {
            free(*buffer); // Free the buffer before exiting
        }
        exit(0);
    } else if (choice == 'y' || choice == 'Y') {
        menu(buffer);
    } else {
        printf("Invalid choice!\n");
        continueProgram(buffer);
    }
    system("pause");
}

// Print Buffer
void printBuffer(char *text){
    if (text == NULL) {
        printf("Buffer is empty.\n");
        return;
    }
    printf("Buffer: %s\n", text);
}

// Enter Text
int enterText(char **text) {
    int max_size = 10; // Initial allocation size
    int current_size = 0;
    
    // Determine the length of the existing text (if any)
    int existing_length = (*text != NULL) ? strlen(*text) : 0;

    // Calculate the new total size (existing text + new text)
    int total_size = existing_length + max_size;

    // Allocate memory for the new text
    char *new_text = (char *)malloc(total_size * sizeof(char));

    if (new_text == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Copy the existing text (if any) to the new buffer
    if (*text != NULL) {
        strcpy(new_text, *text);
        free(*text); // Free the memory for the old text
    }

    // Update the pointer to the new text
    *text = new_text;

    char c;
    printf("Enter text: ");
    
    // Start writing new text after the existing text (if any)
    current_size = existing_length;
    
    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            (*text)[current_size] = '\0';
            break;
        }

        (*text)[current_size] = c;
        current_size++;

        if (current_size >= total_size) {
            // Expand the total size to accommodate more text
            total_size *= 2;
            *text = (char *)realloc(*text, total_size * sizeof(char));

            if (*text == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                return 1;
            }
        }
    }

    return 0;
}


// Search for a Word
int searchWord(const char *text, const char *word) {
    if (text == NULL || word == NULL) {
        return -1; // Invalid input
    }

    int text_length = strlen(text);
    int word_length = strlen(word);
    int count = 0;

    for (int i = 0; i <= text_length - word_length; i++) {
        int match = 1;

        // Check if the current portion of the text matches the word exactly
        for (int j = 0; j < word_length; j++) {
            if (text[i + j] != word[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            // Check word boundaries
            if ((i == 0 || !isalnum(text[i - 1])) && (i + word_length == text_length || !isalnum(text[i + word_length]))) {
                count++; // Increment the count of occurrences
                i += word_length - 1; // Skip the word in the text
            }
        }
    }
    return count;
}

// Replace a Word
int replaceWord(char **text, char *word, char *replacement) {
    if (*text == NULL) {
        return 1;
    }

    const int text_length = strlen(*text);
    const int word_length = strlen(word);
    const int replacement_length = strlen(replacement);

    char *result = (char *)malloc(text_length + 1); // +1 for the null terminator
    if (result == NULL) {
        return 1; // Memory allocation failed
    }

    int i = 0; // Index for the original text
    int j = 0; // Index for the result text

    while (i < text_length) {
        int match = 1;

        // Check if the current portion of the text matches the word
        for (int k = 0; k < word_length; k++) {
            if ((*text)[i + k] != word[k]) {
                match = 0;
                break;
            }
        }

        if (match) {
            // Word found, copy the replacement into the result
            for (int k = 0; k < replacement_length; k++) {
                result[j++] = replacement[k];
            }

            i += word_length;
        } else {
            // Copy the current character from the original text to the result
            result[j++] = (*text)[i++];
        }
    }

    result[j] = '\0'; // Null-terminate the result string

    free(*text); // Free the old text
    *text = result; // Update the text pointer with the new result

    return 0;
}

// Delete Buffer
int deleteBuffer(char **text) {
    if (*text == NULL) {
        return 1;
    }
    free(*text);
    *text = NULL;
    return 0;
}

// Save to File
void saveToFile(char **buffer) {
    FILE *fp;
    fp = fopen("text.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "%s", *buffer);
    fclose(fp);
}

// Read from File
char* loadFromFile() {
    FILE *fp;
    char line[4096]; // A temporary buffer for reading lines
    char *buffer = NULL;
    size_t buffer_size = 0;
    size_t buffer_capacity = 0;

    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        size_t line_length = strlen(line);

        // Remove the newline character, if present
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
            line_length--;
        }

        // Resize the buffer if necessary
        if (buffer_size + line_length + 1 > buffer_capacity) {
            while (buffer_size + line_length + 1 > buffer_capacity) {
                buffer_capacity = (buffer_capacity == 0) ? 4096 : buffer_capacity * 2;
            }
            buffer = (char *)realloc(buffer, buffer_capacity);
            if (buffer == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(1);
            }
        }

        // Append the line to the buffer
        strcpy(buffer + buffer_size, line);
        buffer_size += line_length;
    }

    fclose(fp);

    return buffer;
}

// Menu function - to display the menu and call the appropriate functions
void menu(char **buffer){
    char choice;
    
    clearScreen();
printf("Text Editor\n");
printf("-----------\n");
printf(GREEN_TEXT "1. Print Buffer\n" RESET_COLOR);
printf(GREEN_TEXT "2. Enter Text\n" RESET_COLOR);
printf(GREEN_TEXT "3. Search for a Word\n" RESET_COLOR);
printf(GREEN_TEXT "4. Replace a Word\n" RESET_COLOR);
printf(GREEN_TEXT "5. Delete Buffer\n" RESET_COLOR);
printf(GREEN_TEXT "6. Save to File\n" RESET_COLOR);
printf(GREEN_TEXT "7. Load from File\n" RESET_COLOR);
printf(RED_TEXT "8. Exit\n" RESET_COLOR);

printf("\n------------------\n");
printf("Enter your choice: ");
scanf(" %c", &choice);
    
    clearInputBuffer(); // Clear any remaining characters in the input buffer

    switch(choice){
        case '1':
            clearScreen();
            if (*buffer == NULL) {
                printf("Buffer is empty.\n");
            } else {
                printBuffer(*buffer);
            }
            break;
        case '2':
            clearScreen();
            if (enterText(buffer) == 0) {
                printf("Text entered successfully.\n");
            } else {
                printf("Text entry failed.\n");
            }
            break;
        case '3':
            clearScreen();
            if (*buffer == NULL) {
                printf("Buffer is empty.\n");
            } else {
                printBuffer(*buffer);

                char word[100];
                printf("Enter the word to be searched: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0'; // Remove the newline character
                
                int count = searchWord(*buffer, word);
                if (count > 0) {
                    printf("Word '%s' occurs %d times in the text.\n", word, count);
                } else {
                    printf("Word '%s' does not occur in the text.\n", word);
                }
            }
            break;
        case '4':
            clearScreen();
            if (*buffer == NULL) {
                printf("Buffer is empty.\n");
            } else {
                printBuffer(*buffer);
                
                char word[100];
                char replacement[100];
                
                printf("Enter the word to be replaced: ");
                scanf("%s", word);
                printf("Enter the replacement word: ");
                scanf("%s", replacement);
                
                if (replaceWord(buffer, word, replacement) == 0) {
                    printf("Word replaced successfully.\n");
                } else {
                    printf("Word replacement failed.\n");
                }
            }
            break;
        case '5':
            clearScreen();
            if (deleteBuffer(buffer) == 0) {
                printf("Buffer deleted successfully.\n");
            } else {
                printf("Buffer is already empty.\n");
            }
            break;
        case '6':
            clearScreen();
            TRY {
                if (*buffer == NULL) {
                    printf("Buffer is empty.\n");
                    handleException();
                } else {
                    saveToFile(buffer);
                    printf("Buffer saved to file.\n");
                }
            } CATCH {
                printf("Buffer is empty.\n");
            } END_TRY
            break;
        case '7':
            clearScreen();
           TRY {
                char *loaded_buffer = loadFromFile();
                if (*buffer != NULL) {
                    free(*buffer); // Free the old buffer
                }
                *buffer = loaded_buffer;
                printf("Buffer loaded from file.\n");
            } CATCH {
                printf("Error loading buffer from file.\n");
            } END_TRY

            break;
        case '8':
            clearScreen();
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    continueProgram(buffer);
}