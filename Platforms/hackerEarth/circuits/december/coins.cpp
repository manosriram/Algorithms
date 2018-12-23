#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int i,T;
    int k,n;
    int alice,bob;
    cin >> T;
    int sum=0,ind=0;
    while(T--) {
        cin >> n >> k;
        
        while (sum <= n) {
                
                    if (i%2==0) {
                        alice += pow(k,i);
                    }
                    else if (i%2!=0) {
                        bob += pow(k,i);
                    }
                } 
                
                    if (alice>n) {
                        cout << "Alice" << endl;
                        break;
                        }
                    else {
                        cout << "Bob" << endl;
                        break;
                        }
                
                sum += pow(k,i);

                ind++;
        }
    
}
