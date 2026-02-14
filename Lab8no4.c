/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void findBestThree_Method1(int scores[], int n) {
    int best[3];
    int tempScores[4];
    		int i,j;
 
    for(i = 0; i < n; i++) tempScores[i] = scores[i];

    for( i = 0; i < 3; i++) { 
        int maxIdx = 0;
        for( j = 1; j < n; j++) {
            if(tempScores[j] > tempScores[maxIdx]) {
                maxIdx = j;
            }
        }
        best[i] = tempScores[maxIdx]; 
        tempScores[maxIdx] = -1;      
    }

    printf("Best 3 scores (Method 1): %d, %d, %d\n", best[0], best[1], best[2]);
}


void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) { 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void findBestThree_Method2(int scores[], int n) {
    int tempScores[4];
    int i;
    for( i = 0; i < n; i++) tempScores[i] = scores[i];

    sortArray(tempScores, n); 

    printf("Best 3 scores (Method 2): %d, %d, %d\n", 
            tempScores[3], tempScores[2], tempScores[1]);
}

int main() {
    int myScores[4] = {85, 92, 78, 95};
    
    printf("Original scores: 85, 92, 78, 95\n");
    
    findBestThree_Method1(myScores, 4);
    findBestThree_Method2(myScores, 4);

    return 0;
}
