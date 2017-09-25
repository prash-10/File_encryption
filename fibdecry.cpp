#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int fib[100005];

void fibonacci(){
 fib[0]=1;
 fib[1]=1;
 for(int i=2;i<100005;i++){
  fib[i]=fib[i-1]+fib[i-2];
 }
}


int main()
{
 ofstream outputFile ;
 outputFile.open("final.txt");
 fibonacci();
 int n,i,len;
 char small[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 char large[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 string s,password,data;
 s = "new.txt";
 password = "password";
 int plen=password.size();
 ifstream file;
 file.open(s.c_str());

  while(2){
   file>>data;
   len=data.size();
   for(i=0;i<plen;i++)
    {
    for(int j=0;j<len;j++)
    {
     if(data[j]>=97 && data[j]<=122)
     {
      if(j%2!=0)
      data[j]=small[((data[j]-'a')+fib[i]%26)];
      else
      data[j]=small[((data[j]-'a')+26-fib[i]%26)];
     }
     else if(data[j]>=65 && data[j]<=90)
     {
      if(j%2!=0)
      data[j]=large[((data[j]-'A')+fib[i]%26)];
      else
      data[j]=large[((data[j]-'A')+26-fib[i]%26)];
     }
    }
   }

   reverse(data.begin(),data.end());
   string x=data.substr(0,plen);
   reverse(x.begin(),x.end());
   for(i=0;i<plen;i++){
    if(x[i]!=password[i]){
     //printf("Wrong Password\n");
     return 0;
    }
   }
   cout<<data.substr(plen,len-plen)<<endl;
   outputFile<<data.substr(plen,len-plen);
   outputFile.close();
  }

 return 0;
}
