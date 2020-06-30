// Using Dev-C++
#include<iostream>
#include<math.h>
#include<string.h>
#include<conio.h>
using namespace std;
#define base 255

void Rabinkarp(char pattern[], char text[], int primenum )
{
	int m = strlen(pattern);  // getting length of string
	int n = strlen(text);     // getting length of text
	int hashp = 0;
	int hasht = 0;
	int hash=1;
	int i,j;
	for (i =0; i < m-1; i++)
    hash = (hash*base)%primenum;  // calculating hash value
    
    for(i=0; i<m; i++)
    {
    	hashp= (base*hashp+pattern[i])%primenum; //calculating hash value of pattern
    	hasht = (base*hasht + text[i])%primenum;
    	
	}
	for(i=0;i<=n-m;i++)
	{
		cout<<"\niteration number:"<<i<<"\nNumber of pattern:"<<hashp<<"\nnumber of text"<<hasht<<"\n";
		if (hashp==hasht)    // comparing hash values of pattern and text
		{
			for (j=0;j<m;j++)
			{
				if(text[i+j]!=pattern[j])
				{
					cout<<"Pattern doesn't match with text but hash values do";
					break;
				}
			}
			if(j==m)
			cout<<"pattern do match at value:"<<i<<"\n";
		}
		if(i<n-m)
		{
			hasht=(base*(hasht-text[i]*hash)+text[i+m])%primenum;
			if(hasht<0)
			hasht = (hasht+primenum);
		}
	}
}
int main()
{
	char Inputtext[200];
	char Inputpattern[45];
	int primeno = 11;
	int flag =1;
	while(flag==1)
	{
		cout<<"\n Enter Text:";
		cin>>Inputtext;
		cout<<"\n Enter pattern:";
		cin>>Inputpattern;
		cout<<"\n Entered text is:"<<Inputtext<<"\n Entered pattern is:"<<Inputpattern<<"\n";
		Rabinkarp(Inputpattern,Inputtext,primeno);
		cout<<"\nEnter 1 - continue execution,0 - Exit window";
		cin>>flag;
		return 0;
	}
}
