#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

void DocFile(Point** arr, int* n) {
    char fName[50];
    printf("Nhap ten tep: ");
    fgets(fName);
    f* f = fopen(fName, "r");
    if (f == NULL) {
        printf("Khong the mo file.\n");
        return NULL;
    }
    fscanf(f, "%d", n);
    *arr = (Point*)malloc(*n * sizeof(Point));
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%lf %lf", &(*arr)[i].x, &(*arr)[i].y);
    }
    fclose(f);
}


void display(Point *arr, int n){
    printf("\nDanh sach toa do:\n");
    for (int i = 0; i < n; i++) {
        printf("(%lf, %lf)\n", arr[i].x, arr[i].y);
    }
}
float Distance(Point a){
    return sqrt(pow(a.x,2)+pow(a.y,2));
}

int TimDoanthuocTRON(Point* arr, int n) {
    double R;
    printf("\nNhap ban kinh duong tron: ");
    scanf("%lf", &R);
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = sqrt(pow(arr[j].x - arr[i].x, 2) +  pow(arr[j].y - arr[i].y, 2));
            if (distance <= 2 * R && Distance(arr[i])<= R && Distance(arr[j])<= R) {
                count++;
            }
        }
    }
    printf("\nSo doan thang nam trong duong tron: %d\n", count);
}

void TimkiemTamgiacVuong_Smax(Point* arr, int n) {
    double maxS = 0;
    Point A, B, C;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double d1 = pow(arr[j].x - arr[i].x, 2) + pow(arr[j].y - arr[i].y, 2);
                double d2 = pow(arr[k].x - arr[i].x, 2) + pow(arr[k].y - arr[i].y, 2);
                double d3 = pow(arr[k].x - arr[j].x, 2) + pow(arr[k].y - arr[j].y, 2);

                if (d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1) {
                    double S = fabs((arr[i].x * (arr[j].y - arr[k].y) +
                                        arr[j].x * (arr[k].y - arr[i].y) +
                                        arr[k].x * (arr[i].y - arr[j].y)) / 2.0);

                    if (S > maxS) {
                        maxS = S;
                        A = arr[i];
                        B = arr[j];
                        C = arr[k];
                    }
                }
            }
        }
    }

    if (maxS == 0) {
        printf("Khong co tam giac vuong.\n");
    } else {
        printf("Tam giac vuong co dien tich lon nhat:\n");
        printf("Dinh A: (%lf, %lf)\n", A.x, A.y);
        printf("Dinh B: (%lf, %lf)\n", B.x, B.y);
        printf("Dinh C: (%lf, %lf)\n", C.x, C.y);
        printf("Dien tich: %lf\n", maxS);
    }
}

int main() {
    int n;
    Point *arr;
    DocFile(&arr, &n);
    display(arr,n);
    TimkiemTamgiacVuong_Smax(arr, n);
    return 0;
}

