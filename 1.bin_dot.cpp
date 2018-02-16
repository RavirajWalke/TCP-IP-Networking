#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	string ip[4];
	int n[4],i,j,d;
	float lg;
	int bin[8];
	cout<<"Enter the ip address in binary:\n";
	for ( i = 0; i < 4; ++i)
	{
		cin>>ip[i];
	}
	cout<<"The ip address in dotted decimal is:\n";
	int k=0;
	for(i=0;i<4;i++)
	{
		d=0;
		for(j=0;j<ip[i].length();j++);
		{
			int t=ip[i][j]-'0';
			cout<<t;
		}
		if(i<3)
			cout<<".";
	}
	cout<<"\n";
}