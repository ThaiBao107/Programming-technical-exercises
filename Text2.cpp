#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct NTN{
    int d;
    int m;
    int y;
};
struct Sach{
    char maS[50];
    char tenS[50];
    NTN d_m_y;
};

int main()
{
    int c;
    Sach* b=new Sach[10];
    ifstream inF;
    inF.open("DuLieuS.txt");
    if(inF.is_open())
    {
        inF >> c;
        for(int i=0;i<c;i++)
        {
            inF.get();
            inF.getline(b[i].maS,50,'#');
            inF.getline(b[i].tenS,50,'#');
            inF >> b[i].d_m_y.d;
            inF >> b[i].d_m_y.m;
            b[i].d_m_y.m *=(-1);
            inF >> b[i].d_m_y.y;
            b[i].d_m_y.y *=(-1);
            cin.ignore();
        }
        inF.close();

    }
    else    
        cout<<"Khong mo duoc file"<<endl;
    
    cout<<"Dach sach:"<<endl;
    for(int i=0;i<c;i++)
    {

        cout<<"Thong tin thu "<<i+1<<": "<<endl;
        cout<<"Ma Sach: "<<b[i].maS<<endl;
        cout<<"Ten sach: "<<b[i].tenS<<endl;
        cout<<"Ngay: "<<b[i].d_m_y.d<<endl;
        cout<<"Thang: "<<b[i].d_m_y.m<<endl;
        cout<<"Nam: "<<b[i].d_m_y.y<<endl;
        cout<<endl;
    }
    delete[]b;
    b=NULL;
    return 0;
}