#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	string ip;
	int n[4],nsub,i,pre_len,new_pre_len,nadd_sub,nadd_net,temp;
	float lg;
	char q;
	while(1)
	{
		cout<<"Enter the ip address in dotted decimal:\n";
		cin>>ip;
		int l=ip.length();
		char *y = new char[l + 1]; 
		strcpy(y, ip.c_str());		//std:string to char*
		sscanf(y,"%d.%d.%d.%d",&n[0],&n[1],&n[2],&n[3]);  //split char*
		cout<<"enter the number of subnets\n";
		cin>>nsub;

		for ( i = 0; i < 4; ++i)
		{
			if(n[i]>255||n[i]<0)
			{
				cout<<"wrong input\n";
				exit(0);
			}
		}
		//determine class hence prefix length//
		if(n[0]>=0 && n[0]<=127)
			pre_len=8;
		else if(n[0]<=191)
			pre_len=16;
		else if(n[0]<=223)
			pre_len=24;
		else if(n[0]<= 239)
		{
			cout<<"This IP belongs to Class D\n It Is Reserved For Multicasting\n";
			continue;
		}
		else if(n[0]<=255)
		{
			cout<<"This IP belongs to Class E\n It Is Reserved For Research & Development\n";
			continue;
		}
		else
		{
			cout<<"Invalid IP Address\n";
			continue;
		}
		//**************************************//
		lg=log(nsub)/log(2);
		new_pre_len=pre_len+lg; 
		nadd_net=pow(2,32-pre_len);
		cout<<"No of addresses in network :"<<nadd_net<<endl;
		for(i=1;i<=nsub;i++)
		{
			cout<<"no of addresses per subnet:";
			cin>>nadd_sub;
			nadd_sub=pow(2,ceil(log(nadd_sub)/log(2))); //if no. of add per subnet is not power of 2
			nadd_sub=nadd_sub-1;
			cout<<"Subnet No:"<<i<<"---->  ";
			cout<<n[0]<<"."<<n[1]<<"."<<n[2]<<"."<<n[3]<<"\t to\t";
			//for last address of current subnet
			for(int j=3;j>=0;j--)
			{
				n[j]=n[j]+nadd_sub;
				if(n[j]>255)
				{
					n[j]=255;
					nadd_sub=nadd_sub/256;
				}
				else
					break;
			}
			cout<<n[0]<<"."<<n[1]<<"."<<n[2]<<"."<<n[3]<<"\n";
			//for first address of next subnet
			for(int j=3;j>=0;j--)
			{
				n[j]=n[j]+1;
				if(n[j]>255)
				{
					n[j]=255;
					nadd_sub=nadd_sub/256;
				}
				else
					break;
			}
		}
		cout<<"Do you want to continue:(y/n)";
		cin>>q;
		if(q=='n')
			break;
	}
	return 0;
}

/************************OUTPUT***********************************
raviraj@ravi:~/Desktop/TCP$ g++ classfull_var_sub.cpp
raviraj@ravi:~/Desktop/TCP$ ./a.out
Enter the ip address in dotted decimal:
192.1.2.0
enter the number of subnets
4
No of addresses in network :256
no of addresses per subnet:64
Subnet No:1---->  192.1.2.0	 to	192.1.2.63
no of addresses per subnet:63
Subnet No:2---->  192.1.2.64	 to	192.1.2.127
no of addresses per subnet:45
Subnet No:3---->  192.1.2.128	 to	192.1.2.191
no of addresses per subnet:64
Subnet No:4---->  192.1.2.192	 to	192.1.2.255
Do you want to continue:(y/n)n
******************************************************************/