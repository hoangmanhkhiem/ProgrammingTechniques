#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

typedef struct{
    float x, y;
}Diem;

void DocFile(char* fileName, Diem* arr[], int *n) {
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

int Check(Diem a, Diem b, Diem c){
    float d1 = Distance(a,b);
    float d2 = Distance(b,c);
    float d3 = Distance(a,c);
    if(d1*d1+d2*d2==d3*d3||d1*d1==d2*d2+d3*d3||d2*d2==d1*d1+d3*d3)
        return 1;
    return 0;
}

void DemDiem(Diem *arr, int n){
    int R, count =0;
    printf("Nhap R: ");
    scanf("%d",&R);
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(Distance(arr[i],arr[j])<=R) count ++;
        }
    }
    printf("So diem thuoc duong tron tam O ban kinh %d la: %d",R,count);
}

void TimTGVMax(Diem *arr, int n){
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if(Check(arr[i],arr[j],arr[k])){
                    int tmp1 = i, tmp2 =j, tmp3 = k;
                }
            }
        }
    }
}

int main() {
    char fileName[50]="input.txt";
    Diem* arr;
    int n;
    DocFile(fileName, &arr, &n);
    Display(arr, n);
    DemDiem(arr,n);
    return 0;
}