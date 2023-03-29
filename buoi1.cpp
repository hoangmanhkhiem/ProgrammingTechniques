//----------HEADER----------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
//----------TEMPLATES----------
template<typename... T>
void in(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args << ' '), ...);}
template<typename... T>
void outl(T&&... args) { ((cout << args << ' '), ...); cout<<endl;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << '=' << a << ', '; err(++it, args...);}
//----------MACROS----------
#define skromnyy main
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define nl cout<<endl
#define E cerr<<endl
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for (int i=a; i<b; ++i)
#define FOV(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false)
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define inFOV(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define inv(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define ins(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//----------CONSTANTS----------
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll mod = 1000000007;
//----------GLOBALS----------

int lua_chon,t;
 
//----------SOLUTION----------
class Sol_1{
    int n;
    int S =0;
    public:
        void solution(){
            out("Nhap gia tri cho n: ");
            in(n);
            int a[n+1];
            a[0]=1;
            FOR(i,1,n+1)
            {
                a[i] = a[i-1]*i;
                S += a[i];
            }
            outl("Gia tri cua S =",S);
        }
};
class Sol_2{
    int n;
    int S =0;
    public:
        void solution(){
            out("Nhap vao so n: ");
            in(n);
            int a[n+1];
            a[0]=1;
            FOR(i,1,n+1)
            {
                if(i&1) a[i] = a[i-1]*i;
                else a[i] = (-1)*a[i-1]*i;
                S += a[i];
            }
            outl("Gia tri cua S =",S);
        }
};
class Sol_3{
    int n;
    ld x;
    int S;
    public:
        void setup_gt(int a[]){
            a[0]=1;
            FOR(i,1,n+1){
                a[i] = a[i-1]*i;
            }
        }
        void solution(){
            out("Nhap vao n va x: ");
            in(n,x);
            int a[n+1];
            setup_gt(a);
            FOR(i,1,n+1){
                if(i&1){
                    S += pow(x,i)/a[i];
                    if((i-1)/2==0) S *= -1;
                }
            }
            outl("Gia tri cua S =",S);
        }
};
class Sol_4{
    int ga, cho;
    int tong_con = 36;
    int tong_chan = 100;
    public:
        void solution(){
            FOR(i,1,36){
                    if(i*2+(36-i)*4==100){
                        ga = i;
                        cho = 36-i;
                        outl("So ga la: ",ga);
                        outl("So cho la: ",cho);
                        return;
                    }
            }
        }
};
class Sol_5{
    int trau_dung, trau_nam, trau_gia;
    public:
        void solution(){
            FOR(i,1,26){
                FOR(j,1,26){
                    FOR(k,1,26){
                        if(i*5+j*3+k*1.0/3==100){
                            trau_dung = i;
                            trau_nam = j;
                            trau_gia = k;
                            outl("So trau dung la: ",trau_dung);
                            outl("So trau_nam la: ",trau_nam);
                            outl("So trau_gia la: ",trau_gia);
                            return;
                        }
                    }
                }
            }
        }
};
class Sol_6{
    string s;
    int S = 0;
    public:
        void solution(){
            out("Hay nhap so: ");
            cout << "\n";
            in(s);
            FOR(i,0,s.size()){
                S += (s[i]-'0');
            }
            outl("Tong so cac chu so la: ",S);
        }
};
class Sol_7{
    int n;
    int S1= 0,S2=0;
    public:
        bool tong_so_chu_so(int n){
            S1 = n;
            while(n>0){
                int tmp =n % 10;
                S2 += pow(tmp,3);
                n /= 10;
            }
            if(S1==S2) return true;
            return false;
        }
        void solution(){
            out("Nhap vao n de kiem tra: ");
            in(n);
            if(tong_so_chu_so(n)) outl("Day la so armostrong");
            else outl("Day khong la so armostrong");
        }
};
class Sol_8{
    int S1,S2;
    public:
        bool tong_so_chu_so(int n){
            S2 =0;
            S1 = n;
            string s = to_string(n);
            FOR(i,0,3){
                S2 += pow((s[i]-'0'),3);
            }
            if(S1==S2) return true;
            else return false;
        }
        void solution(){
            outl("So la so armostrong la:");
            FOR(i,100,1000){
                if(tong_so_chu_so(i)) outl(i);
            }
        }
};
class Menu{
    int click;
    public:
        void MENU(){
            in(click);
            switch (click)
            {
            case 1:{
                Sol_1 hmk1;
                hmk1.solution();}
                break;
            case 2:{
                Sol_2 hmk2;
                hmk2.solution();}
                break;
            case 3:{
                Sol_3 hmk3;
                hmk3.solution();}
                break;
            case 4:{
                Sol_4 hmk4;
                hmk4.solution();}
                break;
            case 5:{
                Sol_5 hmk5;
                hmk5.solution();}
                break;
            case 6:{
                Sol_6 hmk6;
                hmk6.solution();}
                break;
            case 7:{
                Sol_6 hmk6;
                hmk6.solution();}
                break;
            case 8:{
                Sol_7 hmk7;
                hmk7.solution();}
                break;
            case 9:{
                Sol_8 hmk8;
                hmk8.solution();}
                break;
            default:
                outl("Cam on ban da su dung");
                break;
            }
        }
};
class Giao_dien{
    public:
        void MN(){
                outl("_______________MENU_______________");
                cout << "\n";
                Menu Danhsach;
                cout << setw(30) << "Chon mot trong cac tinh nang duoi day\n\n";
                outl("1.Tinh tong S = 1! + 2! + ... + n!");
                outl("2.Tinh tong S = 1! - 2! + ... + (-1)^n*n!");
                outl("3.Tinh tong S = x - x^3/3! + ... + (-1)^n*x^(2n+1)/(2n+1)!");
                outl("4.Giai bai toan vua ga vua cho");
                outl("5.Giai bai toan so con trau");
                outl("6.Tinh tong cac chu so co 3 chu so");
                outl("7.Tinh tong cac chu so cua mot so");
                outl("8.Kiem tra so Armstrong");
                outl("9.In cac so co 3 chu so la so Armstrong");
                out("\nNhap vao lua chon cua ban: ");
                Danhsach.MENU();
        }
};
//----------MAIN----------
signed skromnyy(){
    IOS;
    cout << "\n";
    cout << "\n";
    outl("_____________SKROMNYY_____________");
    cout << "\n";
    cout << setw(27) << "Xin chao moi nguoi\n";
    cout << setw(30) << "Tool creater by skromnyy\n";
    cout << "\n";
    outl("______________SELECT______________\n");
    outl("1. Menu\n");
    outl("2. Exit\n");
    outl("3. InfoAdmin\n");
    do{
        out("Nhap vao lua chon cua ban: ");
        in(lua_chon);
        if(lua_chon==1){
            outl("Doi mot chut.......");
            sleep(1);
            outl("Dang vao giao dien menu....");
            sleep(2);
            outl("-           10%");
            sleep(1);
            outl("--          20%");
            sleep(1);
            outl("---         30%");
            sleep(1);
            outl("----        40%");sleep(1);
            outl("-----       50%");sleep(1);
            outl("------      60%");sleep(1);
            outl("-------     70%");sleep(1);
            outl("--------    80%");sleep(1);
            outl("---------   90%");sleep(1);
            outl("----------  100%");sleep(2);
            outl("\n");
            outl("Tai hoan tat!");
            outl("\n");
            Giao_dien giaodien;
            giaodien.MN();
            do{
                sleep(1);
                outl("Lua chon:");
                sleep(1);
                outl("1.Quay ve menu");
                outl("2.Exit");
                in(t);
                if(t==1) giaodien.MN();
                else if(t==2){
                    out("Cam on ban da su dung phan mem nay");
                    return 0;
                } 
                else out("Vui long nhap lai");
            } while(t!=1||t!=2);
        }
        else if(lua_chon==2){
            sleep(1);
            outl("Cam on ban da su dung phan mem nay\n");
            return 0;
        }
        else if(lua_chon==3){
            sleep(1);
            outl("Admin Information\n");
            outl("Author: Hoang Manh Khiem");
            outl("Nickname: Skromnyy");
            outl("Class : CNTTVA1_K63");
            outl("Education : UTC");
            sleep(1);
            cout << "\n";
            outl("Nhap lua chon: ");
            outl("1.Quay ve menu");
            outl("2.Exit");
        }
        else outl("Vui long nhap lai\n");
    }
    while(lua_chon!=1||lua_chon!=2||lua_chon!=3);
}
