/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int checkscore(char std[]);
int hardestQuestion(char ans[][10], int stdCount);


char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};

int main() {
	int i;
	char ans[8][10] = {
		{'A','B','A','C','C','D','E','E','A','D'}, //7
		{'D','B','A','B','C','A','E','E','A','D'}, //6
		{'E','D','D','A','C','B','E','E','A','D'}, //5
		{'C','B','A','E','D','C','E','E','A','D'}, //4
		{'A','B','D','C','C','D','E','E','A','D'}, //8
		{'B','B','E','C','C','D','E','E','A','D'}, //7
		{'B','B','A','C','C','D','E','E','A','D'}, //7
		{'E','B','E','C','C','D','E','E','A','D'}  //7
	};

	for (i = 0; i < 8; i++) {
		printf("std %d => %d\n", i+1, checkscore(ans[i]));
	}

	printf("Hardest question => %d\n", hardestQuestion(ans, 8));


	return 0;
}


int checkscore(char std[]) {
	int i, score = 0;

	for (i = 0; i < 10; i++) {
		if (std[i] == keys[i])
			score++;
	}

	return score;
}


int hardestQuestion(char ans[][10], int stdCount) {
    int q, s;
    int minCorrect = stdCount + 1;
    int hardest = 1;
    int count;

    for (q = 0; q < 10; q++) {   
        count = 0;

        for (s = 0; s < stdCount; s++) {  
            if (ans[s][q] == keys[q])
                count++;
        }

        if (count < minCorrect) {
            minCorrect = count;
            hardest = q + 1; 
        }
    }

    return hardest;
}
