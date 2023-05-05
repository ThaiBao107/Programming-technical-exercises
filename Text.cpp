#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int t_Tong(string a)
{
    int s=a.length();
    int tong=0;
    for(int i=0;i<s;i++) 
    {
        if(a[i] >= '0' && a[i]<='9')
        {
            tong += int(a[i]);
        }
    }
    return tong;
}

void xoa_KT_D_C(string &a)
{
    while(a[0] == ' '){
        a.erase(a.begin() + 0);
    }
    while(a[a.length() - 1] == ' '){
        a.erase(a.begin() + (a.length() - 1));
    }
}


int c_length(char *a) {
    int i= 0;
    while(true) {
        if(a[i] == '\0') return i;
        i++;
    }
}

// sao chep chuoi


int main(){
    // string a;
    // cout<<"\n nhap chuoi: "; getline(cin,a);
    char a[20];
    cout<<"Nhap chuoi: ";
    cin.getline(a,20);
    cout<<strlen(a)<<endl;
      cout<<" after :"<<a<<endl;
    // char *p =a;
    // cout<<a<<endl;
    // cout << a.length()<<endl;
    // cout<<"==========================="<<endl;
    // xoa_KT_D_C(a);
    // cout<<a<<endl;
    // cout <<a.length()<<endl;
    // cout<<"TT "<<t_Tong(a)<<endl;

    // p=NULL;
    // delete []p;
    return 0;
}