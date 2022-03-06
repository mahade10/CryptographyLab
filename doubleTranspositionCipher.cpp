#include<bits/stdc++.h>
using namespace std;

string Encrypt(string s, int w){
    int rows,i,j;
    string cipher ="";
    //int len = s.size();
    //cout<<len;
    rows = ceil(s.size()/(double)w);
    // cout<<rows;
    int rem = s.size() % w;
    int trailingSpacesCount = w - rem;

    for(int i=0; i<trailingSpacesCount; i++)
    {
        s += ' ';
    }
    for (i=0;i<w;i++){
        for(j=i;j<s.size();j= j+w){
            cipher += s[j];
        }
    }
    return cipher;
}
string Decrypt(string s, int w){
    int rows,i,j;
    string c ="";
    //int len = s.size();
    //cout<<len;
    rows = ceil(s.size()/(double)w);
    // cout<<rows;
    for (i=0;i<rows;i++){
        for(j=i;j<s.size();j= j+rows){
            c += s[j];
        }
    }
    int spaceCount = 0;
    for(int i=c.size()-1; i>=0 ;i--)
    {
        if(c[i] == ' ') spaceCount++;
        else break;
    }
    c = c.substr(0, c.size()-spaceCount);
    return c;
}

int main(){
    string plaintext,ciphertext;
    int w;
    cout<<"enter the value of width\n";
    cin>>w;
    ifstream fin;
    fin.open("plaintextP4.txt");
    getline(fin,plaintext);
    //fin>>plaintext;
    fin.close();

    ofstream fout;
    fout.open("resultP4.txt");
    ciphertext = Encrypt( Encrypt(plaintext,w) ,w);
    plaintext = Decrypt( Decrypt(ciphertext,w) ,w);

    fout<<"Encrypted is:"<<ciphertext<<endl;

    fout<<"Decrypted is :"<<plaintext<<endl;
    fout.close();
}

