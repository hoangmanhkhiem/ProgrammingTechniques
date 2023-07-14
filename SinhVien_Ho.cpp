#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

typedef struct{
    char Ht[50];
    char dh;
    float diem;
} SV;

void FileInput(SV** arr, int *n) {
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
    *arr = (SV*)malloc(sizeof(SV) * (*n));

    for (int i = 0; i < *n; i++) {
        fgets((*arr)[i].Ht, sizeof((*arr)[i].Ht), f);
        (*arr)[i].Ht[strcspn((*arr)[i].Ht, "\n")] = '\0';
        fscanf(f, "%f\n", &(*arr)[i].diem);
        fscanf(f, "%c\n", &(*arr)[i].dh);
    }
    fclose(f);
}

void TinhTongDiem(SV* arr, int n) {
    double Tong[3]={};
    for (int i = 0; i < n; i++) {
        Tong[arr[i].dh - 'A'] += arr[i].diem;
        // A - A = 0
        // B - A = 1
        // C - A = 2
    }
    printf("\nDanh sach tong diem cac truong");
    printf("\n|Truong A| %-5.1lf|", Tong[0]);
    printf("\n|Truong B| %-5.1lf|", Tong[1]);
    printf("\n|Truong C| %-5.1lf|", Tong[2]);

    int ans = 0; double t = Tong[0];
    if (t > Tong[1]) {
        ans = 1;
        t = Tong[1];
    }
    if (t > Tong[2]) ans = 2;
    printf("\nTruong thap nhat : %c", char(ans + 'A'));
}

void Display(SV* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("|%-5d|%-25s|%-8.2f|%-5c|\n",i, arr[i].Ht, arr[i].diem, arr[i].dh);
    }
}

void SvCaoNhat(SV* arr, int n) {
    FILE *f;
    f = fopen("caonhat.txt","wt");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].diem < arr[j].diem) {
                SV t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    float maxx = arr[0].diem;
    fprintf(f,"\nCac Sv diem cao nhat: \n");
    for (int i = 0; i < n; ++i) {
        if(maxx == arr[i].diem)
            fprintf(f,"|%-25s|%-8.2f|%-5c|\n", arr[i].Ht, arr[i].diem, arr[i].dh);
    }
}

void Timkiem(SV *arr, int n){
    char tenn[50];
    printf("Nhap ho cua sinh vien: ");
    gets(tenn);
    int len = strlen(tenn);
    for (int i = 0; i < n; ++i) {
        if(strncmp(tenn,arr[i].Ht,len)==0)
            printf("|%-25s|%-8.2f|%-5c|\n", arr[i].Ht, arr[i].diem, arr[i].dh);
    }
}


int main() {
    SV* arr;
    int n;
    FileInput(&arr, &n);
    Display(arr, n);
    TinhTongDiem(arr, n);
    SvCaoNhat(arr, n);
    Timkiem(arr,n);
    return 0;
}
