#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ofstream MyFile("filename.txt"); //creating file to save the numbers of letters in the message
ofstream MyFile1("filename1.txt"); //creating file to save the numbers of letters in random key
class inputstring
{
protected:
const int MAX = 26;
char *ptrname = NULL;
string message;
8
string key = "";
string ukey;
public:
inputstring()
{
//function that does dynamic allocation of string. so user can enter desired length
of message
cout << "Enter message. Press enter to end message\n";
getline(cin, message); //to store entire string till enter is pressed. else only a
single word would get stored as message
ptrname = new char[message.length()+1]; //pointer allocated to string message
}
void toupper()
{
strcpy(ptrname, message.c_str());
//function converts each character of message to uppercase. spaces get stored as $
signs
for(int i=0; i<message.length(); i++)
{
if((int)message[i]>=97 && (int)message[i]<=122)
message[i]=message[i]-32;
else if((int)message[i]==32)
message[i]='$';
else
message[i]=message[i];
}
cout<<message<<endl;
}
string printRandomString()
{
//prints random string of characters. for loop to generate as many characters as
those present in message
char alphabet[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
'H', 'I', 'J', 'K', 'L', 'M', 'N',
9
'O', 'P', 'Q', 'R', 'S', 'T', 'U',
'V', 'W', 'X', 'Y', 'Z' };
for (int i = 0; i < message.length(); i++)
key = key + alphabet[rand() % MAX];
ukey=key;
return key;
}
};
class operations:public inputstring //inherits base class variables- message and key
{
public:
void filecreation()
{
//stores numbers of letters of message in MyFile
for(int i=0;i<message.length();i++)
{
if((int)message[i]==36)
{
MyFile<<0<<"\n"; //if symbol is $ sign writes 32(ascii for space)
in file
}
else
{
MyFile<<(int) (message[i]-'A')+1<<"\n"; //saves the number of
the letter
}
}
MyFile.close(); //closing file statement
}
void filecreation(int x)
{
//same is done for secret key in file called MyFile1
for(int i=0;i<key.length();i++)
10
{
if((int)key[i]==36)
{
MyFile1<<32<<"\n";
}
else
{
MyFile1<<(int) (key[i]-'A')+1<<"\n";
}
}
MyFile1.close();
}
string encrypt()
{
ifstream MyFile("filename.txt"); //to read from respective files
ifstream MyFile1("filename1.txt");
string mytext, mytext1="";
int arr[message.length()];//array to store the numbers which have been stored file
int arr1[ukey.length()];
int i=0;
char encrypted[message.length()];//string to store encrypted message
while (getline(MyFile, mytext)) //gets each integer from the file till end-of-file
{
arr[i]=stoi(mytext);//stoi converts string-to-int and stores into array
i++;
}
MyFile.close();
i=0;
for(i=0; i<ukey.length(); i++)
{
arr1[i]=(int)(ukey[i]-'A'+1);
}
11
int res[message.length()];//array to store sum of numbers of letters of message
and key
int j;
for(j=0;j<message.length();j++)
{
res[j]=(arr[j]+arr1[j])%MAX; // summing step %MAX
if(res[j]==26)
encrypted[j]='Z';
encrypted[j] = (char) (res[j]+64); // converts numbers of res to generate
characters as part of the encrypted message
}
encrypted[j]='\0'; //appends null character to end-of-string
return encrypted;
}
friend void load(string en);
};
void load(string en)
{
ofstream MyFile2("encrymessage.txt"); //stores the message into file named MyFile2 for
later use
MyFile2<<en<<"\n";
cout<<"Encrypted message has been passed on\n";
MyFile2.close();
}
int main()
{
string str="";
operations o;
o.toupper();
srand(time(NULL)); //to get characters to be generated
cout <<"Your secret key is:"<< o.printRandomString()<<endl;
o.filecreation(); //function overloading
str=o.encrypt();//generated encrypted string stored in str
load(str); //load encrypted string to file
12
o.filecreation(5);
return 0;
}
