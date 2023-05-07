#define _CRT_SECURE_NO_WARNING
#include<iostream>
#include<cstring>
#include<fstream>
#include<conio.h>
#include<cmath>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<random>
using namespace std;
const int maxS=30;
const int maxSL=50;

struct SanPham{
    char maSP[maxS];
    char tenSP[maxS];
    int SL;
    long double DG;
    char PL[maxS];
};

void docDSSP(SanPham *&a, int &n) ;
void xuatDSSP(SanPham *a, int n);
void xuat_1_SP(SanPham a);

void list_VD(SanPham *a, int n);

void load_file_VD(SanPham *a, int n);
long double tinh_T(SanPham *a, int n);
void menu();
void nhap_1_SP(SanPham &a);
void nhapDSSP(SanPham *&a, int &n);
void randomID(SanPham &a);
void xoaKT(char *a, int vt);
void chuan_Hoa(char *a);



int docSL()
{
    int s;
    ifstream indata;
    indata.open("DuLieuSP.txt");
    if(indata.is_open())
    {
        indata >> s;
    indata.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;

    return s;
}
void docDSSP(SanPham *&a, int &n) 
{
    /*
    1. doc file -> s
    2. SanPham *b = new SanPham[s+n];
    3. 
    + 1) cho b sao chep du lieu tu 0 den s  cua file
    for(int i = 0; i < s; i++)
    {
        b[i]......
    }
    donf file
    + 2) cho b copy tu a (vi tri b bat dau la s va ket thuc la n-1)
    + 3) delete a -> a = new SanPham(s+n);
    + 4) a = b;
    delete b;
    b = nullptr
    */
   //mo file lan 1SanPham*b=new SanPham[s+n]; 
    // mo file lan 2
    ifstream inData;
    int c=docSL();
    int s;
    SanPham*b=new SanPham[c+n];
    inData.open("DuLieuSP.txt");
    if(inData.is_open())
    {
        cout<<"Doc file lan 2"<<endl;
            inData >> s;
            cout<<s<<endl;
            for(int i=0;i<c;i++)
            {
                inData.getline(b[i].maSP,maxS,'#');
                if(b[i].maSP == "") break;
                inData.getline(b[i].tenSP,maxS,'#');
                inData >> b[i].SL;
                inData.ignore(); 
                inData >> b[i].DG;
                inData.ignore();
                inData.getline(b[i].PL,maxS);
            }
        inData.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;

    // cout<<"====================================="<<endl;
    // cout<<"XUat mang thu b 1"<<endl;
    // xuatDSSP(b,c);
    // cout<<"======================================="<<endl;
    int dem=0;
    for(int i=c;i<c+n;i++)
    {
        b[i]= a[dem++]; 
    }
    
    // cout<<"=============================="<<endl;
    // cout<<"Xuat mang b thu 2" <<endl;
    // xuatDSSP(b,c+n);
    // cout<<endl<<endl<<"================================="<<endl;

    delete[]a;
    a=NULL;

    a=new SanPham[c+n];
    n+=c;

    for(int i=0;i<n;i++)
    {
        a[i]=b[i];
    }

    
    // cout<<"Sao chep"<<endl;
    // int dem=0;
    //  n+=s;
    // for(int i=s;i<n;i++)
    // {
    //     b[i]=a[dem++];
    
    // }
    // delete[]a;
    // a=new SanPham[n];
    // for(int i=0;i<n;i++)
    // {
    //     a[i]=b[i];
    // }
    delete[]b;
    b=NULL;


}

void xuatDSSP(SanPham *a, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"SP thu "<<i+1<<": "<<endl;
        cout<<endl;
        cout<<"Ma SP: "<< a[i].maSP<<endl;
        cout<<"Ten SP: "<<a[i].tenSP<<endl;
        cout<<"So luong: "<<a[i].SL<<endl;
        cout<<"Don gia: "<<a[i].DG<<endl;
        cout<<"Phan loai: "<<a[i].PL<<endl;
        cout<<endl;
    }
}

void xuat_1_SP(SanPham a)
{
        cout<<"Ma SP: "<< a.maSP<<endl;
        cout<<"Ten SP: "<<a.tenSP<<endl;
        cout<<"So luong: "<<a.SL<<endl;
        cout<<"Don gia: "<<a.DG<<endl;
        cout<<"Phan loai: "<<a.PL<<endl;
        cout<<endl;
}

void list_VD(SanPham *a, int n)
{
    char b[20] = "Vat dung";
    for(int i=0;i<n;i++)
    {
        if(strlen(a[i].PL) == strlen(b)){
            xuat_1_SP(a[i]);
        }
    }
}

void load_file_VD(SanPham *a, int n)
{
    ofstream outF;
    outF.open("BT.txt",ios_base::app);
    if(outF.is_open())
    {
        char b[20] = "Vat dung";
    for(int i=0;i<n;i++)
    {
        if(strlen(a[i].PL) == strlen(b))
        {
            outF << a[i].maSP <<'#'<<a[i].tenSP<<'#'<<a[i].SL<<'#'<<a[i].DG<<'#'<<a[i].PL<<endl;
        }
    }
    outF.close();
    }
}

long double tinh_T(SanPham *a, int n)
{
    long double tong=0;
    long double tongAll=0;
    for(int i=0;i<n;i++)
    {
        tong = a[i].DG * a[i].SL;
        tongAll+=tong;
    }
    return tongAll;
}

void menu()
{
    cout<<"                           ============================================"<<endl;
    cout<<"                           =                  MENU                    ="<<endl;
    cout<<"                           = 1. Tao danh sach cac lop sinh vien       ="<<endl;
    cout<<"                           = 2. Load file dach sach lop               ="<<endl;
    cout<<"                           = 3. Xuat danh sach lop                    ="<<endl; 
    cout<<"                           = 4. Tong so luong SV khoa CNTT            ="<<endl;
    cout<<"                           = 5. Dem lop khoa Ngoai ngu                ="<<endl;
    cout<<"                           = 6. Xoa 1 lop sinh vien                   ="<<endl;
    cout<<"                           = 7. Xoa cac lop Co ban                    ="<<endl;
    cout<<"                           = 8. Load file danh sach khoa KT & QLC     ="<<endl;
    cout<<"                           = 9. CHUA LAM                              ="<<endl;
    cout<<"                           = 10. EXIT                                 ="<<endl;
    cout<<"                           ============================================"<<endl;
}


void randomID(SanPham &a)
{
    srand(time(NULL));
    const char r[]="qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM0123456789";
    const int n=4;
    char *id=new char[n+1];
    for(int i=0;i<n;i++)
    {
        id[i]=r[rand() % strlen(r)];
    }
    id[n]='\0';
    strcpy(a.maSP,id);
    cout<<id<<endl;

    delete[]id;
    id=NULL;

}
void nhap_1_SP(SanPham &a)
{
    cout<<endl;
    cout<<"Ma SP: "; 
    randomID(a);
    cout<<"Ten SP: "; cin.getline(a.tenSP,maxS);
    chuan_Hoa(a.tenSP);
    cout<<a.tenSP<<endl;
    cout<<"So luong: "; cin >> a.SL;
    cout<<"Don gia: "; cin >> a.DG;
    cin.ignore();
    cout<<"Phan Loai: "; cin.getline(a.PL,maxS);
    chuan_Hoa(a.PL);
    cout<<a.PL<<endl;

}

void nhapDSSP(SanPham *&a, int &n)
{
    cout<<"Nhap so luong san pham: ";
    while(true)
    {
        cin >> n;
        if(n > 0 && n <= maxSL) break;
        else
            cout<<"Nhap sai, nhap lai: ";
    }
    cin.ignore();
    a=new SanPham[n];

    for(int i=0;i<n;i++)
    {
        nhap_1_SP(*(a+i));
    }
    cout<<"Nhap du lieu thanh cong"<<endl;
}


void xoaKT(char a[], int vt)
{
    int n=strlen(a);
    for(int i=vt+1;i<n;i++)
    {
        a[i-1]=a[i];
    }
    a[n-1]='\0';
}
void chuan_Hoa(char a[])
{
    while(true)
    {
        if(a[0] == ' ') xoaKT(a,0);
        else
            break;
    }
    
    while(true)
    {
        if(a[strlen(a) - 1] == ' ') xoaKT(a,a[strlen(a)]-1);
        else
            break;
    }


    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        if(a[i] == ' ' && a[i+1] == ' ')
        {
            xoaKT(a,i);
            i--;
        }
    }

    if(a[0] >= 'a' && a[0] <= 'z')
        a[0] -= 32;
}


bool an(char a,char b)
{
    if(a=='a' && b=='n')
        return true;
    else
        return false;
}

int check(SanPham *a, int n)   // can coi lai
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
    int s=strlen(a[i].tenSP);
    for(int j=0;j<s-1;j++)
    {
        if(an(a->tenSP[j],a->tenSP[j+1])==true) 
        {
            dem++;
            break;
        }
    }
    }
    return dem;
}
int main() 
{
    SanPham *a=NULL;
    int n=0;

    nhapDSSP(a,n);
    docDSSP(a,n);
    cout<<"main"<<endl;
    xuatDSSP(a,n);
    // cout<<"============================="<<endl;
    // list_VD(a,n);
    // load_file_VD(a,n);
    
    cout<<endl;
    cout<<"=============================="<<endl;

    cout<<"Ki tu an torng ten co: "<<check(a,n)<<endl;
    // long double c=tinh_T(a,n);
    // ostringstream ss;
    // ss << c;
    // string str = ss.str();
    // cout<<"Tinh tong: "<<str<<endl;
    delete[]a;
    a=NULL;
    return 0;
}