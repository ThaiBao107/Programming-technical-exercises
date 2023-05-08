#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<conio.h>

using namespace std;
const int maxS=50;
const int maxTT=20;

struct NTN{
    int d;
    int m;
    int y;
};
struct Sach{
    char maS[maxS];
    char tenS[maxS];
    NTN d_m_y;
};

void randomID(Sach &a)
{
    srand(time(NULL));
    const int n=4;
    const char r[]="asdfghjklmnbvcxzqwertyuiopQWERTYUIOPLKJHGFDSAZXCVBNM0123456789";
    char *id=new char[n+1];
    for(int i=0;i<n;i++)
    {
        id[i]=r[rand() % strlen(r)];
    }
    id[n]='\0';
    strcpy(a.maS,id);
    cout<<id<<endl;
    delete[]id;
    id=NULL;
}
void nhap_1_DS(Sach &a)
{
    cout<<"Ma sach: ";
    randomID(a);
    cout<<"Ten sach: ";
    cin.getline(a.tenS,maxS);
    cout<<"Ngay: "; cin >> a.d_m_y.d;
    cout<<"Thang: "; cin>>a.d_m_y.m;
    cout<<"Nam: "; cin>>a.d_m_y.y;
    cin.ignore();
}

void nhapDS(Sach *&a, int &n)
{
    cout<<"Nhap so luong danh sach: ";
    while(true)
    {
        cin>>n;
        if(n> 0 && n<=maxTT) break;
        else
            cout<<"Nhap sai, nhap lai: ";
    }

    cin.ignore();
    a=new Sach[n];
    
    for(int i=0;i<n;i++)
    {
        cout<<"Thong tin sach thu "<<i+1<<": "<<endl;
        nhap_1_DS(*(a+i));
        cin.ignore();
        cout<<endl;
    }

    cout<<"Nhap du lieu thanh cong"<<endl;
}

int docSL()
{
    int s;
    ifstream inF;
    inF.open("DuLieuS.txt");
    if(inF.is_open())
    {
        inF >>s;
        inF.close();
        return s;
    }
    else
        cout<<"Khong mo duoc file"<<endl;
}

void docDS(Sach *&a, int &n)
{
    int s;
    // Sach* b=new Sach[s+n];
    ifstream inF;
    inF.open("DuLieuS.txt");
    if(inF.is_open())
    {   
        int y;
        inF >> y;
        cin.ignore();
        Sach* b=new Sach[y+n];
        for(int i=0;i<y;i++)
        {
            inF.get();
            inF.getline(b[i].maS,maxS,'#');
            inF.getline(b[i].tenS,maxS,'#');
            inF >> b[i].d_m_y.d;
            inF >> b[i].d_m_y.m;
            b[i].d_m_y.m *=(-1);
            inF >> b[i].d_m_y.y;
            b[i].d_m_y.y *=(-1);
            cin.ignore();
        }
        inF.close();
          int dem=0;
        for(int i=y;i<y+n;i++)
        {
            b[y] = a[dem++];
        }

        delete[]a;
        a=NULL;

        n+=y;    
        a=new Sach[n];
        for(int i=0;i<n;i++)
        {
            a[i]=b[i];
        }

        delete[]b;
        b=NULL;
    }
    else
        cout<<"Khong mo duoc file"<<endl;

        // int dem=0;
        // for(int i=s;i<s+n;i++)
        // {
        //     b[s] = a[dem++];
        // }

        // delete[]a;
        // a=NULL;

        // n+=s;    
        // a=new Sach[n];
        // for(int i=0;i<n;i++)
        // {
        //     a[i]=b[i];
        // }

        // delete[]b;
        // b=NULL;

}

void xuatDL(Sach *a, int n)
{
    cout<<"Dach sach:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Thong tin thu "<<i+1<<": "<<endl;
        cout<<"Ma Sach: "<<a[i].maS<<endl;
        cout<<"Ten sach: "<<a[i].tenS<<endl;
        cout<<"Ngay: "<<a[i].d_m_y.d<<endl;
        cout<<"Thang: "<<a[i].d_m_y.m<<endl;
        cout<<"Nam: "<<a[i].d_m_y.y<<endl;
        cout<<endl;
    }
}

void swap(Sach &a, Sach &b)
{
    Sach tam;
    tam=a;
    a=b;
    b=tam;
}

void sapxep_tang(Sach *&a, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].d_m_y.y > a[j].d_m_y.y)
                swap(a[i],a[j]);
        }
    }
}


int dem_2019(Sach *a, int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].d_m_y.y == 2019)
            dem++;
    }
    return dem;
}

void xoa_1_DS(Sach *a, int &n, char ma[])
{
   for (int i = 0; i < n; i++) {
        if (strcmp(a[i].maS, ma) == 0) {
            for (int j = i; j < n - 1; j++) {
                    a[j] =a[j+1];
            }
            n--;
            break;
        }
    }
} 

void xoaDS(Sach *a, int &n, int vitri)
{
    for(int i=vitri+1;i<n;i++)
        a[vitri -1]=a[i];
    n--;
}

void menu()
{
    cout<<"=============MENU==========="<<endl;
    cout<<"1. nhap ds                  "<<endl;
    cout<<"2. Doc DL                   "<<endl;
    cout<<"3. Xuat DS                  "<<endl;
    cout<<"4. Sap xep tang             "<<endl;
    cout<<"5. Dem 2019                 "<<endl;
    cout<<"6. Xoa DS bang ma           "<<endl;
    cout<<"7. EXIT                     "<<endl;
}
int main()
{
    Sach *a = NULL;
    int n=0;

    int choose;
    do{
        menu();
        cout<<"Choose: ";
        while(true)
        {
            cin >> choose;
            if(choose > 0 && choose <= 7) break;
            else
                cout<<"Nhap sai, nhap lai: ";
        }
        system("cls");
        switch(choose)
        {
            case 1:
            nhapDS(a,n);
            cout<<"Nhap enter de tro ve man hinh chinh: ";
            break;
            case 2:
            if(a==NULL)
                cout<<"Chua co danh sach"<<endl;
            else
            {
                docDS(a,n);
                cout<<"Doc file thanh cong"<<endl;
            }
                cout<<"Nhap enter de tro ve man hinh chinh: ";
                break;
            case 3:
                if(a==NULL) cout<<"Chua co danh sach"<<endl;
                else{
                    xuatDL(a,n);
                    cout<<endl;
                }
                cout<<"Nhap enter de tro ve man hinh chinh: ";
                break;
            case 4:
                if(a==NULL) cout<<"Chua co danh sach"<<endl;
                else
                {
                    sapxep_tang(a,n);
                    cout<<"Sap xep thanh cong"<<endl;
                    cout<<"Enter de xem KQ: "; getch();
                    system("cls");
                    cout<<"Mang sau SX"<<endl;
                    xuatDL(a,n);
                }
                cout<<"Nhap enter de tro ve man hinh chinh: ";
                break;
            case 5:
                if(a==NULL) cout<<"Chua co danh sach"<<endl;
                else{
                    cout<<"Co "<<dem_2019(a,n)<<" sach co nam 2019"<<endl;
                }
                cout<<"Nhap enter de tro ve man hinh chinh: ";
                break;
            case 6:
                if(a==NULL) cout<<"Chua co danh sach"<<endl;
                else
                {
                    cin.ignore();
                    char ma[maxS+1];
                    cout<<"Nhap ma can xoa: "; 
                    cin.getline(ma,maxS);
                    cout<<"==================================="<<endl;
                    cin.ignore();
                    cout<<"Ma: "<<ma<<endl;
                    cout<<"Ma trong struct: "<<a[2].maS<<endl;
                    int y=strcmp(a[2].maS,ma);
                    cout<< "KQ: "<<y<<endl; 

                    cout<<"==================================="<<endl;
                //   int productIndex = -1;
                //     for (int i = 0; i < n; i++) {
                        // cout<<"Ma S: "<<a[i].maS<<endl;
                        xoa_1_DS(a,n,ma);
                    //     if (strcmp(a[i].maS, ma) == 0) {
                    //         xoaDS(a,n,i);
                    //         cout<<"Da co"<<endl;
                    //     }
                    //     else
                    //         cout<<"Khong ton tai"<<endl;
                    //  }

                    //  if (productIndex == -1) {
                    //     cout << "Product not found" << endl;
                    // } 
                xuatDL(a,n);
                }
                cout<<"Nhap enter de tro ve man hinh chinh: ";
                break;
            case 7:
            if(a==NULL){
                cout<<"Thoat"<<endl;
                return 0;
            }
            else
            {
                cout<<"Thoat"<<endl;
                delete[]a;
                a=NULL;
                return 0;
            }

        }
        getch();
        system("cls");
    }while(true);

    return 0;
}