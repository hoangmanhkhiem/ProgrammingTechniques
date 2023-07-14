#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int ms;
    char ten[50];
    char tg[50];
    int nam;
    int gia;
} TV;

void FileInput(TV** arr, int *n) {
    char fileName[]="input.txt";
//    char fileName[30];
//    printf("Nhap ten File: ");
//    gets(fileName);
    FILE* f = fopen(fileName, "rt");
    if (f == NULL) {
        printf("Doc File ko thanh cong\n");
        return;
    }

    fscanf(f, "%d\n", n);
    *arr = (TV*)malloc(sizeof(TV) * (*n));

    for (int i = 0; i < *n; i++) {
        fscanf(f,"%d\n",&(*arr)[i].ms);
        fgets((*arr)[i].ten, sizeof((*arr)[i].ten), f);
        (*arr)[i].ten[strcspn((*arr)[i].ten, "\n")] = '\0';
        fgets((*arr)[i].tg, sizeof((*arr)[i].tg), f);
        (*arr)[i].tg[strcspn((*arr)[i].tg, "\n")] = '\0';
        fscanf(f, "%d\n", &(*arr)[i].nam);
        fscanf(f, "%d\n", &(*arr)[i].gia);
    }
    fclose(f);
}

void Display(FILE *f,TV* arr, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(f,"|%-5d|%-5d|%-50s|%-50s|%-5d|%-5d|\n",i, arr[i].ms,arr[i].ten,arr[i].tg, arr[i].nam, arr[i].gia);
    }
}

void Timsach(TV *arr, int n){
    char ten[50];
    int maso;
    printf("Nhap ten sach: ");
    gets(ten);
    printf("Nhap gia tien: ");
    scanf("%d",&maso);
    for (int i = 0; i < n; ++i) {
        if(strcmp(ten,arr[i].ten)==0 && maso == arr[i].gia){
            printf("|%-5d|%-50s|%-50s|%-5d|%-5d|\n", arr[i].ms,arr[i].ten,arr[i].tg, arr[i].nam, arr[i].gia);
            return;
        }
    }
    printf("\n Khong tim thay \n");
}

void DSgiamdan(FILE *f,TV **arr, int n){
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if((*arr)[i].nam<(*arr)[j].nam){
                TV tmp;
                tmp = (*arr)[j];
                (*arr)[j] = (*arr)[i];
                (*arr)[i]= tmp;
            }
        }
    }
    fprintf(f,"Danh sach ten sach co nam xuat ban giam dan\n");
    for (int i = 0; i < n; i++) {
        fprintf(f,"|%-5d|%-5d|%-50s|%-50s|%-5d|%-5d|\n",i, (*arr)[i].ms,(*arr)[i].ten,(*arr)[i].tg, (*arr)[i].nam, (*arr)[i].gia);
    }
}

int main() {
    TV* arr;
    int n;
    FileInput(&arr, &n);
    FILE *f;
    f = fopen("output.txt","wt");
    Display(f,arr, n);
    Timsach(arr,n);
    DSgiamdan(f,&arr,n);
}
