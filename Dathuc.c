#include <stdio.h>
#include<math.h>
#include <malloc.h>
#include <limits.h>

void DocFile_P(int **a, int *n) {
    FILE* f = fopen("../P.txt", "rt");
    if (f == NULL) {
        printf("FILE Ko ton tai\n");
        fclose(f);
        return;
    }
    fscanf(f, "%d", n);

    int* p = NULL;
    p = (int*)malloc(sizeof(int) * (*n));
    for (int i = 0; i < *n; i++) {
        int t;
        fscanf(f, "%d", &t);
        p[i] = t;
    }
    *a = p;
    fclose(f);
}

void DocFile_Q(int **b, int *m) {
    FILE* f = fopen("../Q.txt", "rt");
    if (f == NULL) {
        printf("FILE Ko ton tai\n");
        fclose(f);
        return;
    }
    fscanf(f, "%d", m);

    int* p = NULL;
    p = (int*)malloc(sizeof(int) * (*m));
    for (int i = 0; i < *m; i++) {
        int t;
        fscanf(f, "%d", &t);
        p[i] = t;
    }
    *b = p;
    fclose(f);
}

void PrintMT(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

float pow(float x,int n){
    float res = 1;
    if (n==0) return res;
    for (int i = 0; i <= n; ++i) {
        res *= x;
    }
    return res;
}

float Giatrihamso(int *x, int z, float value){
    float sum = 0;
    for (int i = 0; i <= z; ++i) {
        sum += x[i]*pow(value,i);
    }
    return sum;
}

void Value(int *a,int *b, int m, int n, float d1, float d2){
    float ans_P = Giatrihamso(a,n,d1);
    float ans_Q = Giatrihamso(b,m,d2);
    if(ans_Q==0){
        printf("Khong tinh duoc");
    }
    else{
        printf("Gia tri bang: %f\n",(float)ans_P/ans_Q);
    }
    printf("Gia tri da thuc bang: %f",2023-ans_P+ans_Q);
}

void InputTarget(float *d1, float *d2){
    float x,y;
    printf("Nhap gia tri 1: ");
    scanf("%f",&x);
    printf("Nhap gia tri 2: ");
    scanf("%f",&y);
    *d1 = x;
    *d2 = y;
}

int main() {
    int *a;
    int *b;
    int n,m;
    float d1,d2;
    DocFile_P(&a, &n);
    DocFile_Q(&b, &m);
    PrintMT(a, n);
    PrintMT(b, m);
    InputTarget(&d1,&d2);
    Value(a,b,m,n,d1,d2);
}