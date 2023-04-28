#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
const int maxd=20;
const int maxc=20;

void loadF(int **a, int d, int c);
void taoM(int **&a, int &d, int &c);
void xuatM(int **a, int d, int c) ;
int tinhT();
void docF();


void menu() {
    cout<<"===============MENU=============="<<endl;
    cout<<"1. Khoi tao ma tran "<<endl<<"2. Xuat ma tran "<<endl<<"3. Load file "<<endl<<"4. Doc file "<<endl<<"5. De quy tim GTLN "<<endl<<"6. EXIT"<<endl;
}
void taoM(int **&a, int &d, int &c){
    cout<<"Nhap so dong: ";
    while(1){
        cin>>d;
        if(d > 0 && d < maxd ) break;
        else
            cout<<"Nhap sai, nhap lai: ";
    }
    cout<<"Nhap so cot: ";
    while(1){
        cin >>c;
        if(c>0 && c< maxc ) break;
        else
            cout<<"Nhap sai, nhap lai: ";
    }
    //tao ma tran
    a=new int*[d];
    for(int i=0;i<d;i++) {
        a[i]=new int[c];
    }

    cout<<"Nhap so phan tu trong ma tran: "<<endl;
    for(int i=0;i<d;i++) 
    {
        cout<<"Nhap phan tu cua dong thu "<<i+1<<endl;
        for(int j=0;j<c;j++)
        {
            cin>> *(*(a+i)+j);
        }
    }

}


void xuatM(int **a, int d, int c) {
    cout<<"Ma tran hien tai: "<<endl;
    for(int i=0;i<d;i++) 
    {
        for(int j=0;j<c;j++)
            cout<<*(*(a+i)+j) <<" ";
        cout<<endl;
    }
}

void loadF(int **a, int d, int c) {
    ofstream outF;
    outF.open("BT04.txt",ios_base::out);
    if(outF.is_open()) {
        for(int i=0;i<d;i++) {
            for(int j=0;j<c;j++) 
            {
                outF << *(*(a+i)+j)<<",";
            }
            outF<<endl;
        }
        outF.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;
}

int tinhT() {
    int a;
    ifstream inF;
    inF.open("BT04.txt");
    if(inF.is_open()) {
        int tong=0;
        while(inF >> a) 
        {
            tong+=a;
            inF.ignore();
        }
        inF.close();
        return tong;
    }
    else
        cout<<"Khong mo file duoc"<<endl;
        
}

void docF() {
    int a;
    ifstream inF;
    inF.open("BT04.txt");
    cout<<"Du lieu file hien tai: "<<endl;
    if(inF.is_open()) {
        while( inF >> a) 
        {
            cout<<a<<" ";
            inF.ignore(1);
        }
        inF.close();
    }
    else
        cout<<"Khong mo file duoc"<<endl;
}

// Cau so tim gai tri lon nhat chua lam


int main(){
    int d=0,c=0;
    int **a=NULL;
    char choose;
    do
    {
        menu();
        cout<<"Choose: ";
        while(true)
        {
            cin>>choose;
            if(choose > 0 && choose <= '6') break;
            else   
                cout<<"Nhap sai, nhap lai: ";
        }
        system("cls");
        switch(choose)
        {
            case '1':
            taoM(a,d,c);
            cout<<"Tao mang thanh cong"<<endl;
            getch();
            system("cls");
            break;
            case '2':
            if(a==NULL) cout<<"Chua co du lieu "<<endl;
            else
            {
                xuatM(a,d,c);
            }
            getch();
            system("cls");
            break;
            case '3':
            if(a==NULL)
                cout<<"Chua co du lieu"<<endl;
            else
            {
                loadF(a,d,c);
                cout<<"Load file thanh cong"<<endl;
            }
            getch();
            system("cls");
            break;
            case '4':
            if(a==NULL) 
                cout<<"Chua co du lieu"<<endl;
            else {
                docF();
            }
            getch();
            system("cls");
            break;
            case '5':
            cout<<"Chua lam"<<endl;
            getch();
            system("cls");
            break;
            
            case '6':
            if(a==NULL)
            {
                cout<<"Thoat"<<endl;
                return 0;
            }
            else {
                cout<<"Thoat"<<endl;
                for(int i=0;i<d;i++)
                 delete[]a[i];
            delete[]a;
             return 0;
            }
            default: 
                getch();
        }
    }while(true);
    for(int i=0;i<d;i++)
        delete[]a[i];
    delete[]a;
    return 0;
}