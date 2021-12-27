#include<bits/stdc++.h>

using namespace std;

int main() {

    double p = 7;
    double q = 11;

    double n = p * q;
    double track;
    double phi = (p - 1) * (q - 1);
    double e = 7;


    while (e < phi) {
        track = __gcd((long long)e, (long long)phi);
        if(track == 1) {
            break;
        } else {
            e++;
        }
    }

    double d1 = 1 / e;
    double d = fmod(d1, phi);
    double message = 7;
    double c = pow(message, e);
    double m = pow(c, d);

    c = fmod(c, n);
    m = fmod(m, n);

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
