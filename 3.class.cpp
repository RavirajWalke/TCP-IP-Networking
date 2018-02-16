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
		//determine class //
		if(n[0]>=0 && n[0]<=127)
			Class='A';
		else if(n[0]<=191)
			Class='B';
		else if(n[0]<=223)
			Class='C';
		else if(n[0]<= 239)
			Class='D';
		else if(n[0]<=255)
			Class='E';
		else
			cout<<"Invalid IP Address\n";
		cout<<"IP belongs to Class :"<<Class<<"\n";
		
		cout<<"Do you want to continue:(y/n)";
		cin>>q;
		if(q=='n')
			break;
	}
	return 0;
}

/*************OUTPUT***********************
raviraj@ravi:~/Desktop/TCP$ g++ class.cpp
raviraj@ravi:~/Desktop/TCP$ ./a.out
Enter the ip address in dotted decimal:
25.1.1.0
IP belongs to Class :A
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
142.2.3.1
IP belongs to Class :B
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
229.54.10.2 
IP belongs to Class :D
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
192.1.4.3
IP belongs to Class :C
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
255.3.1.2
IP belongs to Class :E
Do you want to continue:(y/n)n
*****************************************/