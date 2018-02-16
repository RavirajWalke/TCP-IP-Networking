#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	string ip;
	int n[4],i,j;
	float lg;
	char q;
	int bin[8];
	while(1)
	{
		cout<<"Enter the ip address in dotted decimal:\n";
		cin>>ip;
		int l=ip.length();
		char *y = new char[l + 1];
		strcpy(y, ip.c_str());
		sscanf(y,"%d.%d.%d.%d",&n[0],&n[1],&n[2],&n[3]);
		for ( i = 0; i < 4; ++i)
		{
			if(n[i]>255||n[i]<0)
			{
				cout<<"wrong input\n";
				exit(0);
			}
		}
		cout<<"The ip address in binary is:\n";
		for(i=0;i<4;i++)
		{
			for(j=7;j>=0;j--)
			{
				int t=pow(2,j);
				bin[j]=n[i]/t;
				n[i]=n[i]%t;
				cout<<bin[j];
			}
			cout<<" ";
		}
		cout<<"\n";
		cout<<"Do you want to continue:(y/n)";
		cin>>q;
		if(q=='n')
			break;
	}	
	return 0;	
}
/************OUTPUT***********************
raviraj@ravi:~/Desktop/TCP$ g++ dot_bin.cpp
raviraj@ravi:~/Desktop/TCP$ ./a.out
Enter the ip address in dotted decimal:
192.1.12.0
The ip address in binary is:
11000000 00000001 00001100 00000000 
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
192.168.1.125
The ip address in binary is:
11000000 10101000 00000001 01111101 
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
45.2.3.1
The ip address in binary is:
00101101 00000010 00000011 00000001 
Do you want to continue:(y/n)n
*****************************************/