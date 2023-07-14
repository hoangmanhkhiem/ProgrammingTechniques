#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include<limits.h>

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

float Manhattan(Diem a, Diem b){
	return fabs(a.x-b.x)+fabs(a.y-b.y);
}

void Doan_Ngan_Nhat(Diem *arr,int n ){
	float dis[n][n];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			dis[i][j] = Manhattan(arr[i],arr[j]);
		}
	}
	float maxx = INT_MAX;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(dis[i][j]<maxx){
				maxx = dis[i][j];
			}
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(dis[i][j]== maxx){
				printf("%f",)
			}
		}
	}
}

Diem ChanLe_GanNhat(Diem *arr, int n){
    if(n==0)
        return {0,0};
    int ans = 0;
    float minD = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (Distance({0, 0}, arr[i]) < minD && (arr[i].x+arr[i].y)%(double)(2.0)!=0) {
            minD = Distance({0, 0}, arr[i]);
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
    Diem ans = ChanLe_GanNhat(arr, n);
    if (n == 0) printf("Khong co diem gan nhat");
    else
        printf("\nDiem le gan nhat : %.1f %.1f", ans.x, ans.y);
    double tong = DgGapKhuc(arr, n);
    printf("\nDo dai duong gap khuc: %.1lf\n", tong);
    return 0;
}
