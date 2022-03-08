#include<bits/stdc++.h>
using namespace std;
string Encrypt(string p){
    string ciphertext = "", pad ="";
    int i,j,cnt =0;
    ifstream fin;
    fin.open("padEncrypt.txt");
    fin>>pad;
    fin.close();
    for(i=0,j=0;i<p.size();i++,j++){
        if(p[i] == ' '){
            ciphertext += p[i];
            j--;
            continue;
        }
        ciphertext += ((p[i]-'A') + (pad[j] - 'A')) %26 + 'A';
        cnt++;
    }
    pad = pad.substr(cnt, pad.size()- cnt);
    ofstream fout;
    fout.open("padEncrypt.txt");
    fout<<pad;
    fout.close();
    return ciphertext;
}

string Decrypt(string p){
    string plaintext = "", pad ="";
    int i,j,cnt =0;
    ifstream fin;
    fin.open("padDecrypt.txt");
    fin>>pad;
    fin.close();
    for(i=0,j=0;i<p.size();i++,j++){
        if(p[i] == ' '){
            plaintext += p[i];
            j--;
            continue;
        }
        plaintext += ((p[i]-'A') - (pad[j] - 'A')+ 26) %26 + 'A';
        cnt++;
    }
    pad = pad.substr(cnt, pad.size()- cnt);
    ofstream fout;
    fout.open("padDecrypt.txt");
    fout<<pad;
    fout.close();
    return plaintext;
}


int main(){
    string plaintext, ciphertext;
    ifstream fin;
    fin.open("plaintextP5.txt");
    getline(fin, plaintext);
    ciphertext = Encrypt(plaintext);
    plaintext = Decrypt(ciphertext);
    ofstream fout;
    fout.open("resultP5.txt");
    fout<<"encrypted form is: "<<ciphertext<<endl;
    fout<<"decrypted form is: "<<plaintext<<endl;
}
