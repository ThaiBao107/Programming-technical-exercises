#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;



struct Lop{
 string maLop;
 string tenLop;
 string khoa;
 int SLSV;
 string a;
};

void chuan_hoa(string &a);
void nhap_1_Lop(Lop &a);
void nhapDSL(Lop *&a, int &n);
void xuat_1_Lop(Lop a);
void xuatDSL(Lop *a, int n);
void load_file_Lop(Lop a);
void load_file(Lop *a, int n) ;
void docDSL();
int tinh_CNTT(Lop *a, int n) ;
int dem_NN(Lop *a, int n);
void xoa_1_Lop(Lop *&a, int &n, int vt) ;
int delete_CB(Lop *a, int n);
int xuat_F_KT(Lop *a, int n);
void menu() ;


void chuan_hoa(string &a)
{
    // xoa khoang trang o dau chuoi
    while(a[0] == ' ') {
        a.erase(a.begin() + 0);
    }
    // xoa khoang trang o cuoi chuoi
    while(a[a.length() - 1] == ' '){
        a.erase(a.begin() + (a.length()-1));
    }
    // moi tu cach nhau mot khoang trang
    for(int i=0;i<a.length();i++)
    {
        if(a[i] == ' ' && a[i+1] == ' '){
            a.erase(a.begin() + i);
            i--; // chuoi se tu update lai SL ki tu
        }
    }
    // in hoa moi tu trong chuoi
    
    if(a[0] != ' ')
    {
        if(a[0] >= 'a' && a[0] <= 'z') a[0] -= 32;
    }

    for(int i=0;i<a.length()- 1 ;i++)
    {
        if(a[i] == ' ' && a[i+1] != ' ')
        {
            if(a[i+1] >= 'A' && a[i+1] <= 'Z')
                a[i+1] +=32;
        }
    }
}


void nhap_1_Lop(Lop &a)
{
    cout<<"Nhap ma lop hoc: "; 
    getline(cin,a.maLop);
    cout<<"Nhap ten lop: ";
    getline(cin,a.tenLop);
    cout<<"Nhap ten khoa: ";
    getline(cin,a.khoa);
    chuan_hoa(a.khoa);
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

    Lop*b=new Lop[n];

    for(int i=0;i<n;i++)
        b[i] = a[i];
    
    load_file(b,n);

    delete[]b;
    b==NULL;
}

int delete_CB(Lop *a, int n)  // can xem lai //SOS
{
    int check=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].khoa=="Co ban") 
        {
            for(int i=0;i<n-1;i++)
                a[i]=a[i+1];
            n--;
            i--; // cho nay
            check++;
        }
    }
    return check;
}




int xuat_F_KT(Lop *a, int n){   // SOS
    ofstream outF,outF1;
    int check=0;
    outF.open("BT05.txt",ios_base::app);
    if(outF.is_open())
    {

        int dem=0;
        for(int i=0;i<n;i++)
        {
        if(a[i].khoa=="Kinh te va quan ly cong") dem++;
        }

        outF << dem << endl;
         outF.close();
    }

        // Data
     outF1.open("BT05.txt",ios_base::app);
        for(int i=0;i<n;i++){
            if(a[i].khoa=="Kinh te va quan ly cong")
            {
                load_file_Lop(*(a+i));
                check++;
            }
        }
        
        outF1.close();

        return check;
}


void menu() {
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
int main(){
    Lop* sv=NULL;
    int n;
    int choose;
    do{
        menu();
        cout<<"Choose: "; 
        while(true)
        {
            cin >> choose;
            if(choose >= 1 && choose <= 10) break;
            else
                cout<<"Erorr, nhap lai: ";
        } 
        system("cls");
        switch(choose)
        {
            case 1:
            cout<<"TAO DANH SACH LOP"<<endl;
            cout<<endl;
            nhapDSL(sv,n);
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;
            
            case 2:
            if(sv==NULL)
                cout<<"Chua co danh sach SV"<<endl;
            else
            {
               load_file(sv,n);
               cout<<"Load file thanh cong"<<endl;
            }
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;
            case 3:

            if(sv==NULL)
                cout<<"Chua co danh sach SV"<<endl;
            else
            {
                xuatDSL(sv,n);
            }
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;
            case 4:
            if(sv==NULL) cout<<"Chua co danh sach lop SV";
            else
            {
                int x=tinh_CNTT(sv,n);
                if(x == 0) cout<<"Hien tai trong DS khong co lop thuoc CNTT"<<endl;
                else
                    cout<<"Tong so sinh vien cua khoa CNTT: "<<tinh_CNTT(sv,n)<<endl;
            }
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;

            case 5:
            if(sv==NULL) cout<<"Chua co danh sach"<<endl;
            else
            {
                int x=dem_NN(sv,n);
                if(x==0) cout<<"Hien tai trong DS khong co lop thuoc khoa NN"<<endl;
                else 
                {
                cout<<"DEM"<<endl;
                cout<<endl;
                cout<<"So lop cua khoa ngoai ngu la: "<<x <<endl;
                }
            }
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;

            case 6:
            int vt;
            if(sv==NULL) cout<<"Chua co danh sach"<<endl;
            else
            {
                cout<<"XOA"<<endl;
                cout<<endl;
                cout<<"Nhap vi tri can xoa: ";
                while(true)
                {
                    cin>>vt;
                    if(vt > 0 && vt <=n ) break;
                    else
                        cout<<"Erorr, nhap lai: ";
                }
                xoa_1_Lop(sv,n,vt);
                cout<<"Xoa thanh cong"<<endl;
                getch();
                system("cls");
                cout<<"Danh sach sau khi xoa: "<<endl;
                cout<<endl;
                xuatDSL(sv,n);
            }
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;

            case 7:
            if(sv == NULL) cout<<"Chua co danh sach"<<endl;
            else
            {   int n=delete_CB(sv,n);
                if(n==0) cout<<"Hien tai trong DS khong co khoa CB"<<endl;
                else
                {
                cout<<"XOA LOP CO BAN"<<endl;
                cout<<endl;
                delete_CB(sv,n);
                cout<<"Xoa thanh cong"<<endl;
                getch();
                system("cls");
                cout<<"Danh sach sau khi xoa"<<endl;
                cout<<endl;
                xuatDSL(sv,n);
                }
            }
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;

            case 8:
            if(sv==NULL) cout<<"Chua co danh sach"<<endl;
            else
            {
                int c = xuat_F_KT(sv,n);
                if(c==0) cout<<"Khong co khoa KT & QLC trong DS"<<endl;
                else
                {
                xuat_F_KT(sv,n);
                cout<<"Load file DS khoa KT & QLC"<<endl;
                }
            }
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;

            case 9:
            cout<<"Chua co lam"<<endl;
            cout<<"-> Nhan enter de tro ve menu: "<<endl;
            break;

            case 10:
            if(sv==NULL)
            {
                cout<<"EXIT"<<endl;
                return 0;
            }
            else
            {
                cout<<"EXIT"<<endl;
                delete[] sv;
                sv=NULL;
                return 0;
            }
         }
        getch();
        system("cls");
    }while(true);
    return 0;
}
