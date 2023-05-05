#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
const int maxS=30;

struct SanPham{
    char maSP[maxS];
    char tenSP[maxS];
    int SL;
    double DG;
    char PL[maxS];
};



void docDSSP(SanPham *&a, int &n) 
{
    ifstream inData;
    inData.open("DuLieuSP.txt");
    if(inData.is_open())
    {
        while(!inData.eof())
        {
            inData >> n;
            cout<<n<<endl;
            a = new SanPham[n];

            for(int i=0;i<n;i++)
            {
                inData.getline(a[i].maSP,maxS,'#');
                if(a[i].maSP == "") break;
                inData.getline(a[i].tenSP,maxS,'#');
                inData >> a[i].SL;
                inData.ignore(); 
                inData >> a[i].DG;
                inData.ignore();
                inData.getline(a[i].PL,maxS);
            }
            
        }
        inData.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;
}

void xuatDSSP(SanPham *a, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"SP thu "<<i+1<<": "<<endl;
        cout<<"Ma SP: "<< a[i].maSP<<endl;
        cout<<"Ten SP: "<<a[i].tenSP<<endl;
        cout<<"So luong: "<<a[i].SL<<endl;
        cout<<"Don gia: "<<a[i].DG<<endl;
        cout<<"Phan loai: "<<a[i].PL<<endl;
        cout<<endl;
    }
}
int main() 
{
    SanPham *a=NULL;
    int n;
    docDSSP(a,n);
    xuatDSSP(a,n);
    
    delete[]a;
    a=NULL;
}