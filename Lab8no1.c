/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// Function Prototypes
void printAr(int myAr[], int size);
void addone(int number[], int add[], int sizeNum);
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos);
void addthree(int number[], int pos[][2], int sizePos);

int main() {
    int number[5] = {20, 50, 100, 199, 9};
    int add_val[5] = {1, 2, 3, 4, 5};
    int positions[3] = {1, 3, 4}; // ตำแหน่งที่ต้องการเพิ่มค่า (index 1, 3, 4)
    
    // สำหรับ 1.3: เก็บ {ตำแหน่ง, ค่าที่เพิ่ม} เช่น {0, 10} คือตำแหน่ง 0 เพิ่มค่า 10
    int pos_with_val[2][2] = {{0, 10}, {2, 50}}; 

    printf("--- Original Array ---\n");
    printAr(number, 5);

    // 1.1 เพิ่มค่าตามลำดับ
    addone(number, add_val, 5);
    printf("\n");
    printAr(number, 5);

    // 1.2 เพิ่มค่า x เฉพาะตำแหน่งที่กำหนด
    addtwo(number, positions, 5, 5, 3);
    printf("\n");
    printAr(number, 5);

    // 1.3 เพิ่มค่าตามตำแหน่งและค่าที่กำหนดใน 2D Array
    addthree(number, pos_with_val, 2);
    printf("\n");
    printAr(number, 5);

    return 0;
}

// แก้ไข B: รองรับอาร์เรย์ไม่รู้ขนาดโดยการส่ง size เข้าไปด้วย
void printAr(int myAr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("number[%d] : %d\n", i, myAr[i]);
    }
}

// 1.1: เพิ่มค่าสมาชิกตามลำดับ
void addone(int number[], int add[], int sizeNum) {
    for(int i = 0; i < sizeNum; i++) {
        number[i] += add[i]; 
    }
}

// 1.2: เพิ่มค่า x ในตำแหน่งที่ระบุใน pos[]
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos) {
    for(int i = 0; i < sizePos; i++) {
        int indexToChange = pos[i];
        if(indexToChange < sizeNum) { // ป้องกัน Error ถ้า index เกินขนาดอาร์เรย์
            number[indexToChange] += x;
        }
    }
}

// 1.3: เพิ่มค่าตามตำแหน่งและค่าที่ระบุใน pos[row][2]
void addthree(int number[], int pos[][2], int sizePos) {
    for(int i = 0; i < sizePos; i++) {
        int targetIndex = pos[i][0];
        int valToAdd = pos[i][1];
        number[targetIndex] += valToAdd;
    }
}