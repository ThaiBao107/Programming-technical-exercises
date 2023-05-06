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

void them(int *a, int &n)
{
    int s=3;
    int*b=new int[s+n];
    n+=s;
    cout<<n<<endl;

    for(int i=0;i<n;i++)
        b[i]=a[i];
    
    cout<<endl<<endl;

    for(int i=0;i<s;i++)
        cout<<b[i]<<" ";
    cout<<b<<endl;

    cout<<endl<<endl;

    delete[]a;
    a=NULL;


    
    cout<<"DC: "<<a<<endl;
    
    a=b;
    a[s]=4;
    a[s+1]=5;
    a[s+2]=6;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";


    cout<<"S: "<<n<<endl;
    cout<<"=============="<<endl;
}


int main(){
    // string a;
    // cout<<"\n nhap chuoi: "; getline(cin,a);
    // char a[20];
    // cout<<"Nhap chuoi: ";
    // cin.getline(a,20);
    // cout<<strlen(a)<<endl;
    //   cout<<" after :"<<a<<endl;

    int *a;
    int n=3;
    cout<<"Nhap"<<endl;
    for(int i=0;i<n;i++)
        cin>> a[i];

    them(a,n);
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
    delete[]a;
    a=NULL;
    return 0;
}