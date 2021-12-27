#include<bits/stdc++.h>

using namespace std;

int main() {
   //p,q are any prime nos.
   double p = 7;
   double q = 11;

   double n=p*q;
   double track;
   double phi= (p-1)*(q-1);           //calculate phi
   //public key
   //e stands for encrypt
   double e=7;

   while(e<phi) {
      track = __gcd((long long)e,(long long)phi);   //inbuilt function to calc gcd
      if(track==1)
         break;
      else
         e++;
   }

   //private key
   //d stands for decrypt

   double d1=1/e;
   double d=fmod(d1,phi);
   double message = 7;
   double c = pow(message,e);
   double m = pow(c,d);

   c=fmod(c,n);
   m=fmod(m,n);

   cout<<"ORIGINAL MESSAGE = "<<message;
   cout<<"\n"<<"p = "<<p<<", "<<"q = "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"ENCRYPTED MESSAGE: "<<c;
   cout<<"\n"<<"DECRYPTED MESSAGE: "<<m;
   return 0;
}

/*
OUTPUT:
spartan@spartan:~/Desktop/ICS/1$ g++ Assignment1.cpp 
spartan@spartan:~/Desktop/ICS/1$ ./a.out 
ORIGINAL MESSAGE = 7
p = 7, q = 11
n = pq = 77
phi = 60
e = 7
d = 0.142857
ENCRYPTED MESSAGE: 28
DECRYPTED MESSAGE: 7
spartan@spartan:~/Desktop/ICS/1$ 
*/