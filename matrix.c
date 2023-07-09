#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void InputFile(float ***a, int *n, int* m) {
//    char filename[]="input.txt";
    char filename[30];
    printf("Nhap ten FILE: ");
    gets(filename);
    FILE *f;
    f = fopen(filename,"rt");
    if (f == NULL) {
        printf("Doc file ko thanh cong");
        return;
    }
    fscanf(f, "%d %d\n",n, m);
    *a = (float**)malloc(sizeof(float*) * (*n));
    for (int i = 0; i < *n; i++)
        (*a)[i] = (float*)malloc(sizeof(float) *(*m));

    for (int i = 0; i < *n; i++) {
        for (int j =0; j < *m; j++)
            fscanf(f, "%f", &(*a)[i][j]);
    }
    fclose(f);
}

void OutputFile(float** a, int n, int m) {
    FILE* f = fopen("xuat.txt", "w");
    fprintf(f, "%d %d", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(f, "%.1f ", a[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

void Display(float** a, int n, int m) {
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.1f\t", a[i][j]);
        }
        printf("\n");
    }
}

float Tongduoiduongcheochinh(float **a, int n, int m){
    int i,j;
    float tong = 0;
    for(i=1; i<=12; i++){
        for(j=1; j<=12; j++){
            if(j < i) tong+=a[i][j];
        }
    }
    return tong;
}

float Tongduoiduongcheophu(float **a, int n, int m){
    int i,j;
    float tong = 0;
    for(i=0;i<12;i++){
        for(j=11;j>11-i;j--){
            tong+=a[i][j];
        }
    }
    return tong;
}


int main() {
    float **a;
    int n, m;
    InputFile(&a, &n, &m);
    Display(a, n, m);
    OutputFile(a, n, m);
}