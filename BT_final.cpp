#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<conio.h>
#include<cmath>
#include<sstream>
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
   //mo file lan 1
    ifstream inData;
    int s;
    inData.open("DuLieuSP.txt");
    if(inData.is_open())
    {
        cout<<"Doc file lan 1"<<endl;
            int s;
            inData >> s;
        inData.close();

    }
    else
        cout<<"Khong mo duoc file"<<endl;
    
    SanPham*b=new SanPham[s+n]; 
    // mo file lan 2
    inData.open("DuLieuSP.txt");
    if(inData.is_open())
    {
        cout<<"Doc file lan 2"<<endl;
            while(!inData.eof())
            {
            int c;
            inData >> c;
            cout<<c<<endl;
            getch();
            for(int i=0;i<s;i++)
            {
                cout << "hahahahaa" << endl;

                inData.getline(b[i].maSP,maxS,'#');
                if(b[i].maSP == "") break;
                inData.getline(b[i].tenSP,maxS,'#');
                inData >> b[i].SL;
                inData.ignore(); 
                inData >> b[i].DG;
                inData.ignore();
                inData.getline(b[i].PL,maxS);
            }
            }
            //xuatDSSP(b,s+n);
            cout<<"Ket thuc lan 2"<<endl;
            getch();
        inData.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;

    cout<<"Sao chep"<<endl;
    int dem=0;
     n+=s;
    for(int i=s;i<n;i++)
    {
        b[i]=a[dem++];
    
    }
    delete[]a;
    a=new SanPham[n];
    for(int i=0;i<n;i++)
    {
        a[i]=b[i];
    }

    delete[]b;
    b=NULL;

   xuatDSSP(a,n);
    cout<<"Lay file thanh cong"<<endl;  
            
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

void nhap_1_SP(SanPham &a)
{
    cout<<endl;
    cout<<"Ma SP: "; cin.getline(a.maSP,maxS);
    cout<<"Ten SP: "; cin.getline(a.tenSP,maxS);
    cout<<"So luong: "; cin >> a.SL;
    cout<<"Don gia: "; cin >> a.DG;
    cin.ignore();
    cout<<"Phan Loai: "; cin.getline(a.PL,maxS);

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

int main() 
{
    SanPham *a=NULL;
    int n=0;

    nhapDSSP(a,n);
    docDSSP(a,n);
    // cout<<"============================="<<endl;
    // list_VD(a,n);
    // load_file_VD(a,n);
    
    cout<<endl;
    cout<<"=============================="<<endl;
    // long double c=tinh_T(a,n);
    // ostringstream ss;
    // ss << c;
    // string str = ss.str();
    // cout<<"Tinh tong: "<<str<<endl;
    delete[]a;
    a=NULL;
    return 0;
}