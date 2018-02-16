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
		strcpy(y, ip.c_str());
		sscanf(y,"%d.%d.%d.%d/%d",&n[0],&n[1],&n[2],&n[3],&pre_len);
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

		lg=log(nsub)/log(2);
		new_pre_len=pre_len+lg; 
		nadd_net=pow(2,32-pre_len);
		cout<<"No of addresses in network :"<<nadd_net<<endl;
		nadd_sub=pow(2,32-new_pre_len);
		cout<<"No of addresses per subnet :"<<nadd_sub<<endl;
		temp=nadd_sub;

		for(i=1;i<=nsub;i++)
		{
			nadd_sub=temp-1;
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

/*******************OUTPUT***************************
raviraj@ravi:~/Desktop/TCP$ g++ classless_sub.cpp
raviraj@ravi:~/Desktop/TCP$ ./a.out
Enter the ip address in dotted decimal:
192.1.1.0/24
enter the number of subnets
4
No of addresses in network :256
No of addresses per subnet :64
Subnet No:1---->  192.1.1.0	 to	192.1.1.63
Subnet No:2---->  192.1.1.64	 to	192.1.1.127
Subnet No:3---->  192.1.1.128	 to	192.1.1.191
Subnet No:4---->  192.1.1.192	 to	192.1.1.255
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
25.1.0.0/8
enter the number of subnets
4
No of addresses in network :16777216
No of addresses per subnet :4194304
Subnet No:1---->  25.1.0.0	 to	25.64.255.255
Subnet No:2---->  25.65.255.255	 to	25.128.255.255
Subnet No:3---->  25.129.255.255	 to	25.192.255.255
Subnet No:4---->  25.193.255.255	 to	25.255.255.255
Do you want to continue:(y/n)n
**************************************************************/
