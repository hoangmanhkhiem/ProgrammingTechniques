#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

typedef struct{
    float x, y;
}Diem;

void DocFile( Diem* arr[], int *n) {
    char fileName[50];
    printf("Nhap ten file: ");
    scanf("%s", fileName);
    FILE* f = fopen(fileName, "rt");
    if (f == NULL) {
        printf("Doc File ko thanh cong");
        return;
    }
    fscanf(f, "%d\n", n);
    *arr = (Diem*)malloc(sizeof(Diem) * (*n));
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%f %f", &(*arr)[i].x,&(*arr)[i].y);
    }

    fclose(f);
}
void Display(Diem* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.1f %.1f \t", arr[i].x, arr[i].y);
    }
}

float Distance(Diem a, Diem b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double DgGapKhuc(Diem* arr, int n) {
    double tong = 0;
    for (int i = 1; i < n - 1; i++) {
        tong += Distance(arr[i], arr[i + 1]);
    }
    tong += Distance(arr[n - 1], arr[0]);
    return tong;
}

Diem DiemXaNhat(Diem* arr, int n) {
    if (n == 0) {
        return {0, 0};
    }
    int ans = 0; // luu vi tri diem xa nhat
    float maxD = 0; // luu kc xa nhat
    for (int i = 0; i < n; i++) {
        if (Distance({0, 0}, arr[i]) > maxD) {
            maxD = Distance({0, 0}, arr[i]);
            ans = i;
        }
    }
    return arr[ans];
}

int main() {
    Diem* arr;
    int n;
    DocFile(&arr, &n);
    if (arr == NULL) return 1;
    Display(arr, n);
    Diem ans = DiemXaNhat(arr, n);
    if (n == 0) printf("Khong co diem xa nhat");
    else
        printf("\nDiem Xa nhat : %.1f %.1f", ans.x, ans.y);
    double tong = DgGapKhuc(arr, n);
    printf("\nDo dai duong gap khuc: %.1lf\n", tong);
    return 0;
}
