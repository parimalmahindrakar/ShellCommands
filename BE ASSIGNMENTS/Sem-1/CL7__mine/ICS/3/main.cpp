#include <iostream>
#include "sha1.h"
 
using namespace std;
 
int main(int argc, char *argv[])
{
    string s;
    cout << "\nEnter a String : ";
    cin >> s;
    cout << "\nsha1('" << s << "') : " << sha1(s) << endl;
    return 0;
}

//compilation - g++ main.cpp sha1.cpp -o sha1_sample && ./sha1_sample


/*OUTPUT :

spartan@spartan:~/Desktop/ICS/3$ g++ main.cpp sha1.cpp -o sha1_sample
spartan@spartan:~/Desktop/ICS/3$ ./sha1_sample

Enter a String : parimalmahindrakar

sha1('parimalmahindrakar') : 526fa0327306faed6a63dd89695370c53b5c5010
spartan@spartan:~/Desktop/ICS/3$ 
*/