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
    printf("\n");

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

// --- Sol 1: Linear Search ---
int searchNum(int numAr[], int numArSize, int target) {
    int i, found = 0;
    for (i = 0; i < numArSize; i++) {
        if (numAr[i] == target) {
            found = 1; 
            break;
        }
    }
    return found;
}

int random1to100() {
    int random_num = (rand() % 100) + 1;
  
    printf("[%d] ", random_num); 
    return random_num;
}
