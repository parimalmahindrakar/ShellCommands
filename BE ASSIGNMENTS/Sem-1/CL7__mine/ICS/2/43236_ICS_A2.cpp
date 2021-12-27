#include <bits/stdc++.h>

using namespace std;
/*
x=3mod5
x=1mod7
x=6mod8
*/

//Inverse calculation
int inv(int a, int m){
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)return 0;
    while(a>1){
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}


int main(){

    int n[]={5,7,8};
    int b[]={3,1,6};
    int N=n[0]*n[1]*n[2];

    //cout<<N<<endl;

    int Ni[]={N/n[0],N/n[1],N/n[2]};

    int invr[]={inv(Ni[0],n[0]),inv(Ni[1],n[1]),inv(Ni[2],n[2])};

    int x=0;

    for(int i=0;i<3;i++){
        x=(x+b[i]*Ni[i]*(invr[i]))%N;
    }

    x%=N;

    cout<<"Given xi's"<<endl;
    for(int i=0;i<3;i++){
        cout<<invr[i]<<" ";
    }cout<<endl;cout<<endl;

    cout<<"Given bi's"<<endl;
    for(int i=0;i<3;i++){
        cout<<b[i]<<" ";
    }cout<<endl;cout<<endl;

    cout<<"Given n's"<<endl;
    for(int i=0;i<3;i++){
        cout<<n[i]<<" ";
    }cout<<endl;cout<<endl;

    cout<<"x = "<<x<<endl;
}

/*
spartan@spartan:~/Desktop/ICS/2$ g++ Assignment2.cpp 
spartan@spartan:~/Desktop/ICS/2$ ./a.out 
Given xi's
1 3 3 

Given bi's
3 1 6 

Given n's
5 7 8 

x = 78
spartan@spartan:~/Desktop/ICS/2$ 
*/