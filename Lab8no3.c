/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random1to100();
void printAr(int numAr[], int numArSize);
int checkNum(int numAr[], int numArSize);
int searchNum(int numAr[], int numArSize, int target);

int main() {
    int N, i;
    int A[100];
    printf("Enter N (max 100): ");
    scanf("%d", &N);
    if (N > 100) N = 100;

    srand(time(NULL));
    
    
    for (i = 0; i < N; i++) {
        A[i] = checkNum(A, i);
    }

    printf("\nFinal Array:\n");
    printAr(A, N);
   

    return 0;
}

void printAr(int numAr[], int numArSize) {
		int i;	
    for ( i = 0; i < numArSize; i++)
        printf("%d ", numAr[i]);
}

int checkNum(int numAr[], int numArSize) {
    int rnum;
    rnum = random1to100();
   
    while (searchNum(numAr, numArSize, rnum)) {
        rnum = random1to100();
    }
    return rnum;
}

void sortAr(int numAr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (numAr[j] < numAr[min_idx]) min_idx = j;
        temp = numAr[min_idx];
        numAr[min_idx] = numAr[i];
        numAr[i] = temp;
    }
}

// --- Sol 2: Binary Search ---
int searchNum(int numAr[], int numArSize, int target) {
   
    sortAr(numAr, numArSize); 
    
    int low = 0, high = numArSize - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (numAr[mid] == target) return 1;
        if (numAr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}


int random1to100() {
    int random_num = (rand() % 100) + 1;

    printf("[%d] ", random_num); 
    return random_num;
}
