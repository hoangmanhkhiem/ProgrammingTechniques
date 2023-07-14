#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char Ht[50];
    char dc[50];
    int stt;
    int sd;
} GD;

void FileInput(GD** arr, int* n) {
    char fileName[] = "input.txt";
    //    char fileName[30];
    //    printf("Nhap ten File: ");
    //    gets(fileName);
    FILE* f = fopen(fileName, "rt");
    if (f == NULL) {
        printf("Doc File ko thanh cong\n");
        return;
    }

    fscanf(f, "%d\n", n);
    *arr = (GD*)malloc(sizeof(GD) * (*n));

    for (int i = 0; i < *n; i++) {
        fgets((*arr)[i].Ht, sizeof((*arr)[i].Ht), f);
        (*arr)[i].Ht[strcspn((*arr)[i].Ht, "\n")] = '\0';

        fgets((*arr)[i].dc, sizeof((*arr)[i].dc), f);
        (*arr)[i].dc[strcspn((*arr)[i].dc, "\n")] = '\0';

        fscanf(f, "%d\n", &(*arr)[i].stt);
        fscanf(f, "%d\n", &(*arr)[i].sd);
    }
}

void Display(GD* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("|%-5d|%-50s|%-50s|%-15d|%-15d|\n", i, arr[i].Ht, arr[i].dc, arr[i].stt, arr[i].sd);
    }
}

void Tinhtiennuoc(GD* arr, int** Money, int n) {
    *Money = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        if (0 <= arr[i].sd && arr[i].sd <= 10)
            (*Money)[i] = arr[i].sd * 5000;
        if (10 < arr[i].sd && arr[i].sd <= 20)
            (*Money)[i] = 50000 + (arr[i].sd - 10) * 6200;
        if (20 < arr[i].sd && arr[i].sd <= 30)
            (*Money)[i] = 50000 + 62000 + (arr[i].sd - 20) * 9000;
        if (30 < arr[i].sd)
            (*Money)[i] = 50000 + 62000 + 90000 + (arr[i].sd - 30) * 16000;
    }
}

void Timkiemtiendien(GD* arr, int* Money, int n) {
    int tmp;
    printf("Nhap ma so cong to: ");
    scanf("%d", &tmp);
    for (int i = 0; i < n; ++i) {
        if (tmp == arr[i].stt) {
            printf("%-25s|%-25s|%-5d|%-15d|%15d|\n", arr[i].Ht, arr[i].dc, arr[i].stt, arr[i].sd, Money[i]);
            return;
        }
    }
    printf("\nKhong tim thay\n");
}

int main() {
    GD* arr;
    int n;
    int* Money;
    FileInput(&arr, &n);
    Display(arr, n);
    Tinhtiennuoc(arr, &Money, n);
    Timkiemtiendien(arr, Money, n);
    return 0;
}

