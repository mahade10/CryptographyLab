#include<bits/stdc++.h>
using namespace std;
string Encryption(string p){
    int i,t;
    string result ;
    for(i=0;i<p.size();i++){
            //cout<<p[i];
        if(p[i]>='A' && p[i]<='Z'){
             //t = p[i]-'A' ;
            result += (p[i]-'A'+3)%26+'A';
        }
        else if(p[i]>='a' && p[i]<='z'){
             //t = p[i]-'A' ;
            result += (p[i]-'a'+3)%26+'a';
        }
         else
            result += p[i];
    }

    return result;
}
string Decryption(string p){
    int i,t;
    string result ;
    for(i=0;i<p.size();i++){
            //cout<<p[i];
        if(p[i]>='A' && p[i]<='Z'){
             //t = p[i]-'A' ;
            result += (p[i]-'A'-3+26)%26+'A';
        }
        else if(p[i]>='a' && p[i]<='z'){
             //t = p[i]-'A' ;
            result += (p[i]-'a'-3+26)%26+'a';
        }
         else
            result += p[i];
    }

    return result;
}
int main(){
    ifstream fin;
    string plaintext,ciphertext;
    fin.open("p1.txt");
    getline(fin,plaintext);
    fin.close();

    ciphertext = Encryption(plaintext);
    cout<<"Encrypted is:"<<ciphertext<<endl;
    ofstream fout;
    fout.open ("example.txt");
    fout<<"Decrypted is :"<<Decryption(ciphertext);
    fout.close();


}
