#include<bits/stdc++.h>
using namespace std;
map <string, string> hashMap;
map <string, string> revHashmap;

void hashFile(){
    ifstream fin;
    string key, value;
    fin.open("hashFile.txt");
    while(!fin.eof()){
        fin>>key>>value;
        hashMap[key] = value;
        revHashmap[value] = key;
    }
}

string Encrypt(string p){
    string cipher="";
    for(int i=0;i<p.size();i = i+3){
        string res ="";
        res += p[i];
        res += p[i+1];
        res += p[i+2];

        cipher += hashMap[res];
    }
    return cipher;
}
string Decrypt(string p){
    string plain="";
    for(int i=0;i<p.size();i = i+3){
        string res ="";
        res += p[i];
        res += p[i+1];
        res += p[i+2];

        plain += revHashmap[res];
    }
    return plain;
}
int main(){
    string plaintext,ciphertext;
    ifstream fin;
    fin.open("plaintextP2.txt");
    fin>>plaintext;
    fin.close();
    hashFile();
    ciphertext = Encrypt(plaintext);
    plaintext = Decrypt(ciphertext);

    ofstream fout;
    fout.open("resultP2.txt");
    fout<<"Encrypted form is:"<<ciphertext<<endl;
    fout<<"Decrypted form is:"<<plaintext<<endl;
    fout.close();
    return 0;
}
