#include <stdio.h>
#include <malloc.h>

void DocFile(int * *a, int *n) {
    char fileName[]="../input.txt";
//    char fileName[30];
//    printf("Nhap ten File: ");
//    gets(fileName);
    FILE* f = fopen(fileName, "rt");
    if(f==NULL){
        printf("Khong mo duoc file\n");
        return;
    }
    fscanf(f, "%d", n);
    if(*n==0){
        printf("Day so khong co gia tri\n");
        return;
    }
    *a = (int*)malloc(sizeof(int) * (*n));
    for (int i = 0; i < *n; i++)
        fscanf(f, "%d", *a + i);
    fclose(f);
}

int TrungVi(int *a,int n){
    int i,j;
    for (i = 0; i < n-1; ++i) {
        for (j = i+1; j < n; ++j) {
            if(a[i]>a[j]){
                int tmp;
                tmp = a[j];
                a[j]= a[i];
                a[i] = tmp;
            }
        }
    }
    return a[n/2];
}

int main() {
    int *a, n;
    DocFile(&a, &n);
    printf("Phan tu trung vi co gia tri la %d", TrungVi(a,n));
    free(a);
}
