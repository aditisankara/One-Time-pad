#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<fstream>
using namespace std ;
class decryptOps
{
protected:
string ip_key ; //key - user input
string f_key = "" ; //key - from file
string f_encrypt ; //encrypted message - from file
string op_decrypt ; //decrypted message - output
public:
void readKey()
{
//initializes values of ip_key, f_key, f_encrypt
int i;

cout << "Enter your secret key in uppercase only " ;
cin >> ip_key ;
ifstream keyFile("filename1.txt") ;
string keyNum ;
i = 0 ;
while(getline(keyFile, keyNum))
{
f_key[i] = (char) (stoi(keyNum)+64);
i++ ;
}
f_key[i] = '\0' ;
ifstream encryptFile("encrymessage.txt") ;
string encryText ;
i = 0 ;
getline(encryptFile, f_encrypt) ;
}
void compareStrings()
{
//checks if user-entered key is correct by comparing it with key from file
//exception-handling
int i ;
try
{
for(i=0; i<ip_key.length()+1; i++)
{
if(ip_key[i] != f_key[i])
{
throw 99 ;
}

}
}
catch(int x)
{
cout << "Your key is wrong!\n" ;
abort() ;
}
}
void decrypt()
{
//decryption
int i ;
op_decrypt = new char[f_key.length()+2] ;
for(i=0; i<(ip_key.length()+1); i++)
{
if(f_encrypt[i]-ip_key[i] >= 0)
{
op_decrypt[i] = (char)((int)f_encrypt[i] - (int)ip_key[i] + 64) ;
}
else
{
op_decrypt[i] = (char)((int)f_encrypt[i] - (int)ip_key[i] + 26 + 64) ;
}
if(op_decrypt[i] == '@')
{
op_decrypt[i] = (char)32 ;

}
cout << op_decrypt[i] ;
}
op_decrypt[i] = '\0' ;
}
};
int main()
{
decryptOps obj ;
obj.readKey() ;
obj.compareStrings() ;
cout << "Your message is: " ;
obj.decrypt() ;
cout << endl ;
return 0 ;
}
