#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<cctype>
using namespace std;
const int maxS=20;


struct Lop{
 string maLop;
 string tenLop;
 string khoa;
 int SLSV;
 string a;
};


void nhap_1_Lop(Lop &a)
{
    cout<<"Nhap ma lop hoc: "; 
    getline(cin,a.maLop);
    cout<<"Nhap ten lop: ";
    getline(cin,a.tenLop);
    cout<<"Nhap ten khoa: ";
    getline(cin,a.khoa);
    cout<<"Nhap so luong SV: ";
    cin >> a.SLSV;
    cin.ignore();
    cout<<"Nhap ngay thang nam khai giang: ";
    getline(cin,a.a);
}

void nhapDSL(Lop *&a, int &n) 
{
    cout<<"Nhap so luong lop: ";
    cin>> n;
    cin.ignore();
    // tao nhieu lop
    a=new Lop[n];

    cout<<"=====NHAP DANH SACH SINH VIEN====="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap lop thu "<<i+1<<": "<<endl;
        nhap_1_Lop(a[i]);
        cout<<endl;
    }

}


void xuat_1_Lop(Lop a)
{
    cout<<"Ma lop hoc: "<<a.maLop<<endl;
    cout<<"Ten lop: "<<a.tenLop<<endl;
    cout<<"Ten khoa: "<<a.khoa<<endl;
    cout<<"So luong sinh vien: "<<a.SLSV<<endl;
    cout<<"Ngay/thang/nam: "<<a.a<<endl;
}

void xuatDSL(Lop *a, int n)
{
    cout<<"=======DANH SACH CAC LOP======="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Lop sinh vien thu "<<i+1<<": "<<endl;
        xuat_1_Lop(a[i]);
        cout<<endl;
    }
}

void load_file_Lop(Lop a)
{
    ofstream outF;
    outF.open("BT05.txt",ios_base::app);
    if(outF.is_open())
    {
    outF << a.maLop <<'#'<<a.tenLop<<'#'<<a.khoa<<'#'<<a.SLSV<<'#'<<a.a<<endl;
    }
    else
        cout<<"Khong mo file duoc"<<endl;
}


void load_file(Lop *a, int n) 
{
    ofstream outF;
    outF.open("BT05.txt");
    if(outF.is_open()) 
    {
        outF << n<<endl;
        for(int i=0;i<n;i++)
        {
            load_file_Lop(*(a+i));
        }
    }
    else 
        cout<<"Khong mo duoc file"<<endl;
}

 

 void docDSL()
 {
    int b;
    ifstream inData;
    inData.open("BT05.txt");
    if(inData.is_open())
    {
       inData >> b;
       for(int i=0;i<b;i++)
       {
        cout<<"Thong tin lop thu "<<": "<<endl;
        Lop sv;
        getline(inData,sv.maLop,'#');
        if(sv.maLop == "") break;
        getline(inData,sv.tenLop,'#');
        getline(inData,sv.khoa,'#');
        inData >> sv.SLSV;
        cin.ignore();
        getline(inData,sv.a);
        // xuat Lop
        xuat_1_Lop(sv);
        cout<<endl;
       }
       inData.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;
 }

 
int tinh_CNTT(Lop *a, int n) 
{
    int tong=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].khoa =="Cong nghe thong tin")
        {
            tong+=a[i].SLSV;
        }
    }
    return tong;
}

int dem_NN(Lop *a, int n)
{
    int count =0;
    for(int i=0;i<n;i++){
        if(a[i].khoa=="Ngoai ngu")
            count++;
    }
    return count;
}

void xoa_1_Lop(Lop *&a, int &n, int vt) 
{
    for(int i=vt-1;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n--;
}

void delete_CB(Lop *a, int n)  // can xem lai
{
    for(int i=0;i<n;i++)
    {
        if(a[i].khoa=="Co ban") 
        {
            for(int i=0;i<n-1;i++)
                a[i]=a[i+1];
            n--;
            i--; // cho nay
        }
    }
}




void xuat_F_KT(Lop *a, int n){
    ofstream outF;
    outF.open("BT05.txt",ios_base::app);
    if(outF.is_open())
    {
        int dem=0;
        for(int i=0;i<n;i++)
        {
        if(a[i].khoa=="Kinh te va quan ly cong") dem++;
        }
        outF << dem<<endl;
        // Data

        for(int i=0;i<n;i++){
            if(a[i].khoa=="Kinh te va quan ly cong")
            {
                load_file_Lop(*(a+i));
            }
        }
        
        outF.close();
    }
    else 
        cout<<"Khong mo duoc file"<<endl;
}

