#include <stdio.h>
#include <malloc.h>
#include <math.h>

void DocFile(int** a, int *n) {
//    char fileName[]="input.txt";
    char fileName[30];
    printf("Nhap ten File: ");
    gets(fileName);
    FILE* f = fopen(fileName, "rt");
    fscanf(f, "%d", n);
    *a = (int*)malloc(sizeof(int) * (*n + 1));

    for (int i = 0; i <= *n; i++) fscanf(f, "%d", *a + i);

    fclose(f);
}

int main() {
    int* a, n;
    double ans = 0, x;
    DocFile(&a, &n);
    scanf("%lf", &x);
    for (int i = 0; i <= n; i++) {
        ans += a[i] * pow(x, i);
    }
    printf("P(%lf) = %.1lf", x, ans);
    return 0;
}