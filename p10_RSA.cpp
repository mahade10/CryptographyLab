#include <bits/stdc++.h>
using namespace std;

//Global Variables (Public Key)
long long e,n;

//Methods
long long IntegerLength(long long n);   // Return the number of digits of an integer
long long StringToLongLong(string s);   // Convert a string to long long
string LongLongToString(long long n);   // Convert a long long to string
bool IsPrime(long long p);              // Prime Check
long long GeneratePrime();              // Generate Prime
long long FindCoPrimeOf(long long n);   // Find Co Prime of n
long long ModInverse(long long a, long long b); // Calculate (a^(-1)) % b
long long Bigmod(long long base, long long power, long long mod); // Calculate (base^power)%mod
string Encrypt(string s);   //RSA Encryption
string Decrypt(string cipher, long long key);   //RSA Decryption

int main()
{
    srand(time(NULL)); // So that rand() can return arbitrary number each time we run the program.
    
    string msg;
    string cipher;
    long long d; // Private Key

    ifstream fin;
    fin.open("p10_in.txt");
    getline(fin, msg);
    fin.close();

    long long p,q;
    p = GeneratePrime();
    q = GeneratePrime();
    n = p*q;
    e = FindCoPrimeOf((p-1)*(q-1));
    d = ModInverse(e, (p-1)*(q-1));

    cout<<"p = "<<p<<endl;
    cout<<"q = "<<q<<endl;
    cout<<"n = "<<n<<endl;
    cout<<"e = "<<e<<endl;
    cout<<"d = "<<d<<endl;

    cipher = Encrypt(msg);
    msg = Decrypt(cipher, d);

    ofstream fout;
    fout.open("p10_out.txt");
    fout<<"Encrypted: "<<cipher<<endl;
    fout<<"Decrypted: "<<msg<<endl;
    fout.close();

    return 0;
}

long long IntegerLength(long long n)
{
    long long len = 0;
    while(n)
    {
        n/=10;
        len++;
    }
    return len;
}

long long StringToLongLong(string s)
{
    long long n = 0;
    long long d = 1;
    for(int i=s.size()-1; i>=0; i--)
    {
        n += (s[i]-'0')*d;
        d *= 10;
    }
    return n;
}

string LongLongToString(long long n)
{
    string s = "";
    if(n == 0) s = "0";
    while(n)
    {
        s += ((n%10)+'0');
        n /= 10;
    }

    reverse(s.begin(), s.end());

    return s;
}

bool IsPrime(long long p)
{
    if(p==1) return false;
    if(p==2) return true;
    if(p%2 == 0) return false;

    for(long long i=3; i<=sqrt(p)+2; i+=2)
    {
        if(p%i == 0) return false;
    }

    return true;
}

long long GeneratePrime()
{
    long long p;
    while(1)
    {
        p = 100 + (rand() % 99);
        if(IsPrime(p)) return p;
    }
}

long long FindCoPrimeOf(long long n)
{
    long long e;
    while(1)
    {
        e = rand() % n;
        if(__gcd(e,n) == 1) return e;
    }
}

long long ModInverse(long long a, long long b)
{
	long long b0 = b, t, q;
	long long x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

long long Bigmod(long long base, long long power, long long mod)
{
    long long res = 1;
    for(long long i = 1; i<=power; i++)
    {
        res *= base;
        res %= mod;
    }
    return res;
}

string Encrypt(string s)
{
    string cipher = "";
    long long blockSize = IntegerLength(n)-1;

    for(long long i=0; i<s.size(); i+=blockSize)
    {
        string block = s.substr(i, blockSize);
        cipher += LongLongToString(Bigmod(StringToLongLong(block), e, n));
        cipher += " ";
    }

    return cipher;
}

string Decrypt(string cipher, long long key)
{
    string s = "";
    string block = "";

    for(long long i=0; i<cipher.size(); i++)
    {
        if(cipher[i] == ' ')
        {
            s += LongLongToString(Bigmod(StringToLongLong(block), key, n));
            block = "";
        }
        else block += cipher[i];
    }

    return s;
}