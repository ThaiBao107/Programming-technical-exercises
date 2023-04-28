#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
const int maxd = 20;

void nhapM(int *&a, int &n);
void xuatM(int *a, int n);
void loadF(int *a, int n);
void nhapM(int *&a, int &n) {
    cout<<"Nhap so luong phan tu trong mang: ";
    while(1)
    {
        cin >>n;
        if(n > 0 && n <= maxd ) break;
        else
            cout<<"Chi nhap toi da 20, nhap lai: ";
    }
    a = new int[n];

    // nhap phan tu
    cout<<"Nhap so phan tu trong mang"<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<"Phan tu a["<<i<<"]: "; 
        cin>>*(a+i);
    }
    cout<<"Nhap mang thanh cong"<<endl;
}

void xuatM(int *a, int n){
    cout<<"Mang hien tai: "<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<*(a+i)<<" ";
    }
}

void loadF(int *a, int n) {
    ofstream outF;
    outF.open("D:\\Peter\\IMG\\BT03.txt",ios_base::out);
    if(outF.is_open()) {
        for(int i=0;i<n;i++) {
            outF << *(a+i)<<endl;
        }
        outF.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;
}

void xuatF(){
    int a;
    ifstream inF;
    cout<<"Du lieu trong file"<<endl;
    inF.open("D:\\Peter\\IMG\\BT03.txt");
    if(inF.is_open()) {
        while(inF >> a) 
        {
            cout<<a<<" ";
        }
        inF.close();
    }
    else 
        cout<<"khong mo file duoc" <<endl;
}


int main() {
    int*a=NULL;
    int n=0;
    char choose;
    bool tam=false;
    do{
        cout<<"============MENU=============="<<endl;
        cout<<"1. Tao mang"<<endl;
        cout<<"2. Xuat Mang"<<endl;
        cout<<"3. Load file"<<endl;
        cout<<"4. Xuat file"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Choose: "; 
        while(1)
        {
            cin>>choose;
            if(choose > '0' && choose <= '5') break;
            else
                cout<<"Nhap sai, nhap lai: ";
        }
        system("cls");
        switch(choose){
            case '1':
             nhapM(a,n);
             getch();
             system("cls");
             break;
            case '2':
             if(a==NULL) cout<<"Chua co du lieu"<<endl;
             else 
             {
                xuatM(a,n);
             }
             getch();
            system("cls");
            break;
            case '3':
            if(a==NULL) cout<<"Chua co du lieu"<<endl;
            else
            {
                 loadF(a,n);
                 cout<<"Nhap file thanh cong"<<endl;
            }
             getch();
            system("cls");
            break;
            case '4':
            if(a==NULL) cout<<"Chua co du lieu"<<endl;
            else 
            {
                xuatF();
            }
             getch();
            system("cls");
            break;
            case '5':
            if(a==NULL)
            {
                cout<<"Thoat"<<endl;
                return 0;
            }
            else{
                cout<<"Thoat"<<endl;
                 delete []a;
                 a=NULL;
                 return 0;
            }
        }
    }while(true);
   return 0;
}