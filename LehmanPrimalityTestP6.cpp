#include<bits/stdc++.h>
#include<math.h>
using namespace std;

long long int Bigmod(long long int a, long long int temp, long long int n){
    long long int res =1;
    for(long long int i =1;i<= temp;i++){
        res = res * a;
        res = res%n;
    }

    return res;
}
int main()
{
    long long int n, a,test,x,d,e,flag =0;

    cout<<"enter the value of n & test\n";
    cin>>n>>test;
    if(n==2 || n == 3){
        cout<<"prime\n";
        }
    else if(n%2 ==0){
        cout<< "composite\n";

        }
    else{

        while(test--){

            a =  2+ rand() % (n-3);
            x = Bigmod(a,(n-1)/2,n);
            if(x !=1 && x!= -1 && x != (n-1)){
                cout<<"Definitely not prime\n";
                flag =1;
                break;
            }
        }
        if(flag != 1)
            cout<<"may be prime\n";
    }
    return 0;
}
