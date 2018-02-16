#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	string ip;
	int n[4],i;
	char Class,q;
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
		//determine class Hencs netid and host id//
		if(n[0]>=0 && n[0]<=127)
		{
			Class='A';
			cout<<"Net ID: "<<n[0]<<"\n";
			cout<<"Host ID: "<<n[1]<<"."<<n[2]<<"."<<n[3]<<"\n";
		}
		else if(n[0]<=191)
		{
			Class='B';
			cout<<"Net ID: "<<n[0]<<"."<<n[1]<<"\n";
			cout<<"Host ID: "<<n[2]<<"."<<n[3]<<"\n";
		}
		else if(n[0]<=223)
		{
			Class='C';
			cout<<"Net ID: "<<n[0]<<"."<<n[1]<<"."<<n[2]<<"\n";
			cout<<"Host ID: "<<n[3]<<"\n";
		}
		else if(n[0]<= 239)
		{
			Class='D';
			printf("Reserved for Multicast Addresses\n");
		}
		else if(n[0]<=255)
		{
			Class='E';
			printf("Reserved for future use\n");
		}
		else
			cout<<"Invalid IP Address\n";
		cout<<"Do you want to continue:(y/n)";
		cin>>q;
		if(q=='n')
			break;
	}
	return 0;
}

/*************OUTPUT******************************************
raviraj@ravi:~/Desktop/TCP$ g++ nethostid.cpp
raviraj@ravi:~/Desktop/TCP$ ./a.out
Enter the ip address in dotted decimal:
52.1.1.0
Net ID: 52
Host ID: 1.1.0
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
125.1.2.0
Net ID: 125
Host ID: 1.2.0
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
145.1.23.0
Net ID: 145.1
Host ID: 23.0
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
225.1.5.4
Reserved for Multicast Addresses
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
255.255.1.1
Reserved for future use
Do you want to continue:(y/n)n
***************************************************************/