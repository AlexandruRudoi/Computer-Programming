#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Prototypes
void generateMatrix(int n, int m, int** arr);
void createMatrix(int n, int m, int** arr);
void printMatrix(int n, int m, int** arr);
void bubbleSort(int* v, int n);
void MatrixToVector(int** arr, int n, int m, int* v);
void ToSpiral(int m, int n, int* v, int** arr, int index, int row, int col);

int main(){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    // Time start
    // Read the matrix's dimensions
    int n, m;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &n, &m);
    
    // Create the matrix
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m * sizeof(int));
    }
    createMatrix(n, m, arr);
    
    // Move the matrix's elements to a vector and sort it
    int v[n*m];
    MatrixToVector(arr, n, m, v);
    bubbleSort(v, n*m);
    
    // Move the vector's elements to the matrix in spiral order
    ToSpiral(n, m, v, arr, 0, 0, 0);

    // Print the matrix
    printf("\nSorted matrix: \n");
    printMatrix(n, m, arr);

    // Free dynamically allocated memory
    for (int i=0; i<n; i++) {
        free(arr[i]);
    }
    free(arr);

    // Time end
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nProgram took %f seconds to execute \n", cpu_time_used);

    return 0;
}

// Generate matrix
void generateMatrix(int n, int m, int** arr){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = (rand() % 100) + 1;
        }
    }
}

// Create the matrix
void createMatrix(int n, int m, int** arr){
    // Ask the user if he wants to enter the matrix manually or generate it randomly
    int k;
    do{
        printf("\nChoose [0] if you want to enter the matrix manually or [1] if you want to generate a matrix randomly: ");
        scanf("%d", &k);
    } while(k != 0 && k != 1);

    // Generate the matrix by user's choice
    if (k == 1) {
        srand(time(NULL));
        generateMatrix(n, m, arr);
        printf("\nGenerated matrix: \n");
        printMatrix(n, m, arr);
    } else {
        printf("\nEnter the elements of the matrix: \n");
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
    }
}

// Print matrix
void printMatrix(int n, int m, int** arr){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Bubble sort
void bubbleSort(int* v, int n){
    int aux;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

// Convert matrix to vector
void MatrixToVector(int** arr, int n, int m, int* v){
    int k = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            v[k] = arr[i][j];
            k++;
        }
    }
}

// Convert vector to spiral matrix
void ToSpiral(int m, int n, int* v, int** arr, int index, int row, int col) {
    if (row >= m || col >= n) {
        return;
    }

    // Print the first row from the remaining rows
    for (int i = col; i < n; ++i) {
        arr[row][i] = v[index];
        index++;
    }
    row++;

    // Print the last column from the remaining columns
    for (int i = row; i < m; ++i) {
        arr[i][n - 1] = v[index];
        index++;
    }
    n--;

    // Print the last row from the remaining rows
    if (row < m) {
        for (int i = n - 1; i >= col; --i) {
            arr[m - 1][i] = v[index];
            index++;
        }
        m--;
    }

    // Print the first column from the remaining columns
    if (col < n) {
        for (int i = m - 1; i >= row; --i) {
            arr[i][col] = v[index];
            index++;
        }
        col++;
    }

    // Recursive call for the remaining submatrix
    ToSpiral(m, n, v, arr, index, row, col);
}