#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
const int maxSV=50;

struct SinhVien{
    string maSV;
    string hoten;
    string maLop;
    double dtb;
};

struct DSDV{
    SinhVien*a=NULL;
    int n;
};

void nhap_1_SV(SinhVien &a );
void nhapDSSV(DSDV &a);
void xuat_1_SV(SinhVien a);
void xuatDSSV(DSDV a);
void load_1_SV(SinhVien a);
void loadF(DSDV a);
void xuatF();
int demSV_TH73(DSDV a);
int demTB(DSDV a);
void swap(SinhVien &a, SinhVien &b);
void sort_reduce(DSDV a);
void menu_sua();
void updateSV(DSDV &a);
void delete_1_Sv(DSDV &a, int vt);
void xuatTT_Anh(DSDV a);
void loadF_Anh(DSDV a);
void add_1_SV(DSDV &a, int vt);

void nhap_1_SV(SinhVien &a )

{
    cin.ignore();
    cout<<"Ma so sinh vien: "; getline(cin,a.maSV);
    cout<<"Ho va ten: "; getline(cin,a.hoten);
    cout<<"Ma lop: "; getline(cin,a.maLop);
    cout<<"Diem trung binh: "; cin>>a.dtb;

}

void nhapDSSV(DSDV &a)
{
    cout<<"So luong sinh vien (Toi da 50 SV): ";
    while(1)
    {
        cin >> a.n;
        if(a.n > 0 && a.n <= maxSV) break;
        else
            cout<<"Nhap sai, nhap lai: ";
    }
    int sl=a.n;
    a.a=new SinhVien[sl];

    // nhap sinh vien
    for(int i=0;i<sl;i++) {
        cout<<"Thong tin sinh vien thu "<<i+1<<" :"<<endl;
        nhap_1_SV(*(a.a+i));
        cout<<endl;
    }

}

void xuat_1_SV(SinhVien a) {
    cout<<"Ma so sinh vien: "<<a.maSV<<endl;
    cout<<"Ho ten: "<<a.hoten<<endl;
    cout<<"Ma lop: "<<a.maLop<<endl;
    cout<<"Diem trung binh: "<<a.dtb<<endl;
}

void xuatDSSV(DSDV a){
    cout<<"Danh sach Sinh Vien"<<endl;
    for(int i=0;i<a.n;i++) {
        cout<<"Thong tin sinh vien "<<i+1<<" :"<<endl;
        xuat_1_SV(*(a.a+i));
        cout<<endl;
    }
}

void load_1_SV(SinhVien a) {
    ofstream outF;
    outF.open("BT04CT.txt",ios_base::app);
    if(outF.is_open()) {
        outF << a.maSV <<'#'<<a.hoten<<'#'<<a.maLop<<'#'<<a.dtb<<endl;
        outF.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;
}
void loadF(DSDV a) {
    ofstream outF;
    outF.open("BT04CT.txt",ios_base::out); // duong dan tuyet doi la \\ che do out thi no se duoc tao nhow ghi tenn file
    if(outF.is_open()) {
        int sl=a.n;
        outF <<sl<<endl;
        for(int i=0;i<sl;i++) {
            load_1_SV(*(a.a+i));
        }
        cout<<"Nhap file thanh cong"<<endl;
        outF.close();
    }
    else
        cout<<"Chua mo duoc file"<<endl;

}

void xuatF() {
    int n;
    ifstream inF;
    inF.open("BT04CT.txt");
    if(inF.is_open()) {
        inF >> n;
        while(!inF.eof())
        {   
            for(int i=0;i<n;i++) 
            {
                SinhVien sv;
                getline(inF,sv.maSV,'#');
                if(sv.maSV=="") break;
                getline(inF,sv.hoten,'#');
                getline(inF,sv.maLop,'#');
                inF >> sv.dtb;
                inF.ignore();
                cout<<"Thong tin sinh vien thu "<<i+1<<" :"<<endl;
                xuat_1_SV(sv);
                cout<<endl;
            }
        }
        inF.close();
    }
    else
        cout<<"Khong mo duoc file"<<endl;
}

int demSV_TH73(DSDV a) {
    int dem=0;
    int sl=a.n;
    for(int i=0;i<sl;i++) {
        if(a.a[i].maLop == "TH73") dem++;
    }
    return dem;
}

int demTB(DSDV a) {
    int sl=a.n;
    int dem=0;
    for(int i=0;i<sl;i++) {
        if(a.a[i].dtb >= (8*1.0)) dem++;
    }
    return dem;
 }

void swap(SinhVien &a, SinhVien &b) {
    SinhVien tam=a;
    a=b;
    b=tam;
}

void sort_reduce(DSDV a) {
    int sl=a.n;
    for(int i=0;i<sl;i++) {
        for(int j=i+1;j<=sl-1;j++) {
            if(a.a[i].dtb < a.a[j].dtb)
                swap(a.a[i],a.a[j]);
        }
    }
}

void menu_sua() {
    cout<<"=========SUA THONG TIN============"<<endl;
        cout<<"1. Ma so sinh vien"<<endl;
        cout<<"2. Ho va ten"<<endl;
        cout<<"3. Ma lop"<<endl;
        cout<<"4. Diem trung binh"<<endl;
        cout<<"5. Khong muon sua thong tin SV nay"<<endl;
}

// ham nay sua thong tin sinh vien do nguoi dungf sua
// chua dong bo duoc voi file
void updateSV(DSDV &a) {
    char choose;
    int sl=a.n;
    manhinh:
        do{
            int chon;
            cout<<"Hien tai co "<<sl<<" sinh vien"<<endl;
            cout<<"Ban muon sua sinh vien thu :";
            while(true) 
            {
                cin>>chon;
                if(chon > 0 && chon <= sl) break;
                else
                    cout<<"Nhap sai thu tu sinh vien, nhap lai: ";
            }
            system("cls");
        menu:
            menu_sua();
            cout<<"Choose: ";
            while(true) {
                cin>>choose;
                if(choose > '0' && choose <='5') break;
                else
                    cout<<"Nhap sai yeu cau, nhap lai: ";
            }
            system("cls");
            switch(choose) 
            {
                // sua ma SV
                case '1':
                 char c1;
                do{
                cin.ignore();
                cout<<"Thong tin hien tai cua MSSV: "<<a.a[chon-1].maSV<<endl;
                cout<<"Sua: "; getline(cin,a.a[chon-1].maSV);
                cout<<"Ban con muon sua nua thong: "<<endl;
                cout<<"1. CO               2.KHONG"<<endl;
                cout<<"Choose: ";
                while(true) {
                    cin>>c1;
                    if(c1 > '0' && c1<='2') break;
                    else
                        cout<<"Nhap sai, nhap lai: ";
                }
                }while(c1 == '1');
                system("cls");
                goto menu;
                // sua ho ten
                case '2':
                char c2;
                do{
                cin.ignore();
                cout<<"Thong tin hien tai cua ho ten: "<<a.a[chon-1].hoten<<endl;
                cout<<"Sua: "; getline(cin,a.a[chon-1].hoten);
                cout<<"Ban con muon sua nua thong: "<<endl;
                cout<<"1. CO               2.KHONG"<<endl;
                cout<<"Choose: ";
                while(true) {
                    cin>>c2;
                    if(c2 > '0' && c2<='2') break;
                    else
                        cout<<"Nhap sai, nhap lai: ";
                }
                }while(c2 == '1');
                system("cls");
                goto menu;
                // sua ma lop
                case '3':
                 char c3;
                do{
                cin.ignore();
                cout<<"Thong tin hien tai cua ma lop: "<<a.a[chon-1].maLop<<endl;
                cout<<"Sua: "; getline(cin,a.a[chon-1].maLop);
                cout<<"Ban con muon sua nua thong: "<<endl;
                cout<<"1. CO               2.KHONG"<<endl;
                cout<<"Choose: ";
                while(true) {
                    cin>>c3;
                    if(c3 > '0' && c3<='2') break;
                    else
                        cout<<"Nhap sai, nhap lai: ";
                }
                }while(c3 == '1');
                system("cls");
                goto menu;
                //sua DTB
                case '4':
                 char c4;
                do{
                cin.ignore();
                cout<<"Thong tin hien tai cua DTB: "<<a.a[chon-1].dtb<<endl;
                cout<<"Sua: "; cin >>a.a[chon-1].dtb;
                cout<<"Ban con muon sua nua thong: "<<endl;
                cout<<"1. CO               2.KHONG"<<endl;
                cout<<"Choose: ";
                while(true) {
                    cin>>c4;
                    if(c4 > '0' && c4<='2') break;
                    else
                        cout<<"Nhap sai, nhap lai: ";
                }
                }while(c4 == '1');
                system("cls");
                goto menu;
                default: 
                {   
                    cin.ignore();
                    char c5;
                    cout<<"Ban con muon sua thong tin cua SV nua khong? "<<endl;
                     cout<<"Ban con muon sua nua thong: "<<endl;
                    cout<<"1. CO               2.KHONG"<<endl;
                     cout<<"Choose: ";
                     while(true) {
                    cin>>c5;
                    if(c5 > '0' && c5<='2') break;
                    else
                        cout<<"Nhap sai, nhap lai: ";
                   }
                   if(c5 =='1') goto manhinh;
                   else
                        return;
                }
            }
    }while(true);
}
// chua dong bo duoc file 
void delete_1_Sv(DSDV &a, int vt) {
    int sl=a.n;
    for(int i=vt;i<sl-1;i++) {
        a.a[i]=a.a[i+1];
    }
    a.n--;
}


// chua chuan hoa duoc ho ten, xem lai
void xuatTT_Anh(DSDV a) {
    int sl=a.n;
    bool tam =false;
    for(int i=0;i<sl;i++)
    {   
        if(a.a[i].hoten=="Anh") {
            cout<<"Thong tin sinh vien thu "<<i+1<<" :"<<endl;
            xuat_1_SV(a.a[i]);
            tam=true;
        }
    }
    if(tam==false) cout<<"Khong Sinh vien nao ten Anh"<<endl;
}
// chua chuan hoa duoc ho ten, xem lai
void loadF_Anh(DSDV a) {
    int sl=a.n;
    int dem=0;
    ofstream outF;  
    outF.open("BT04CT.txt",ios_base::app);
    if(outF.is_open()) {
        for(int i=0;i<sl;i++) 
        {
            if(a.a[i].hoten=="Anh") {
                dem++;
            }
        }
        outF << dem<<endl;
        // ghi file
        for(int i=0;i<sl;i++) {
            if(a.a[i].hoten=="Anh") {
                load_1_SV(a.a[i]);
            }
        }
        outF.close();
    }
    else
        cout<<"Khong mo file duoc"<<endl;
}

void menu() {
    cout<<"==============MENU================="<<endl;
    cout<<"1. Tao danh sach sinh vien"<<endl;
    cout<<"2. Load file sinh vien"<<endl;
    cout<<"3. Xuat danh sach sinh vien"<<endl;
    cout<<"4. Dem so SV hoc lop TH73"<<endl;
    cout<<"5. Dem sinh vien co TBC tu 8.0"<<endl;
    cout<<"6. Sap xep lai danh sach sinh vien giam dan"<<endl;
    cout<<"7. Cap nhap lai danh sach sinh vien"<<endl;
    cout<<"8. Xoa 1 SV"<<endl;
    cout<<"9. Them 1 SV"<<endl;
    cout<<"10.Xuat thong tin SV co ten Anh"<<endl;
    cout<<"11.Load file TT SV co ten Anh"<<endl;
    cout<<"12.EXIT"<<endl;

}

void add_1_SV(DSDV &a, int vt) {
    int sl=a.n;
    for(int i=sl-1;i >= vt-1;i--){ 
        a.a[i+1]=a.a[i];
    }
    nhap_1_SV(a.a[vt-1]);
    a.n++;
}

int main(){ 
    DSDV a;
    int choose;
    do{
        menu();
        cout<<"Chooose: "; 
        while(true) {
            cin >> choose;
            if(choose > 0 && choose <= 12) break;
            else    
                cout<<"Nhap sai, nhap lai: ";
        }
        system("cls");
        switch(choose) {
            case 1:
            nhapDSSV(a);
            break;
            case 2:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else 
            {
                loadF(a);
                cout<<"Nhap file thanh cong"<<endl;
            }
            break;
            case 3:
            if(a.a ==NULL) cout<<"Chua co du lieu"<<endl;
            else
            {
                xuatDSSV(a);
            }
            break;
            case 4:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else 
            {
                xuatDSSV(a);
                cout<<"So SV co ma lop TH73: "<<demSV_TH73(a)<<endl;
            }
            break;
            case 5:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else
                cout<<"So dinh vien co DTB tu 8.0: "<<demTB(a)<<endl;
        
            break;
            case 6:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else
            {
                sort_reduce(a);
                cout<<"Sap xep thanh cong"<<endl;
                getch();
                system("cls");               
                xuatDSSV(a);
            }
        
            break;
            case 7:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else{
                updateSV(a);
            }
        
            break;
            case 8:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else{
                int vt;
                cout<<"Nhap vi tri can xoa: ";
                while(true) {
                    cin>>vt;
                    if(vt > 0 && vt <=a.n) break;
                    else
                        cout<<"Nhap sai, nhap lai: ";
                }
                delete_1_Sv(a,vt-1);
                cout<<"Xoa thanh cong"<<endl;
                getch();
                system("cls");
                xuatDSSV(a);
            }
    
            break;
            case 9: 
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else 
            {
                int vt;
                cout<<"Nhap ci tri can them: ";
                while(true) {
                    cin>>vt;
                    if(vt > 0 && vt <= a.n) break;
                    else
                        cout<<"Nhap sai, nhap lai: ";
                }
                add_1_SV(a,vt);
                getch();
                system("cls");
                xuatDSSV(a);
            }
        
            break;
            case 10:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else{
                xuatTT_Anh(a);
            }
        
            break;
            case 11:
            if(a.a==NULL) cout<<"Chua co du lieu"<<endl;
            else{
                loadF_Anh(a);
                cout<<"Load file thanh cong"<<endl;
            }

            break;
            default: 
            {
                if(a.a==NULL)
                {
                    cout<<"Thoat"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"Thoat"<<endl;
                    delete[]a.a;
                    a.a=NULL;
                    return 0;
                }
            }
        }
        getch();
        system("cls");
    }while(true);
    return 0;
}