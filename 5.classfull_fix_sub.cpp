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
		sscanf(y,"%d.%d.%d.%d",&n[0],&n[1],&n[2],&n[3]);
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
		nadd_sub=pow(2,32-new_pre_len);
		cout<<"No of addresses per subnet :"<<nadd_sub<<endl;
		temp=nadd_sub;
		//for last address of current subnet
		for(i=1;i<=nsub;i++)
		{
			nadd_sub=temp-1;
			cout<<"Subnet No:"<<i<<"---->  ";
			cout<<n[0]<<"."<<n[1]<<"."<<n[2]<<"."<<n[3]<<"\t to\t";
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

/************OUTPUT***********************************
raviraj@ravi:~/Desktop/TCP$ g++ classfull_fix_sub.cpp
raviraj@ravi:~/Desktop/TCP$ ./a.out
Enter the ip address in dotted decimal:
25.1.0.0
enter the number of subnets
64
No of addresses in network :16777216
No of addresses per subnet :262144
Subnet No:1---->  25.1.0.0	 to	25.4.255.255
Subnet No:2---->  25.5.255.255	 to	25.8.255.255
Subnet No:3---->  25.9.255.255	 to	25.12.255.255
Subnet No:4---->  25.13.255.255	 to	25.16.255.255
Subnet No:5---->  25.17.255.255	 to	25.20.255.255
Subnet No:6---->  25.21.255.255	 to	25.24.255.255
Subnet No:7---->  25.25.255.255	 to	25.28.255.255
Subnet No:8---->  25.29.255.255	 to	25.32.255.255
Subnet No:9---->  25.33.255.255	 to	25.36.255.255
Subnet No:10---->  25.37.255.255	 to	25.40.255.255
Subnet No:11---->  25.41.255.255	 to	25.44.255.255
Subnet No:12---->  25.45.255.255	 to	25.48.255.255
Subnet No:13---->  25.49.255.255	 to	25.52.255.255
Subnet No:14---->  25.53.255.255	 to	25.56.255.255
Subnet No:15---->  25.57.255.255	 to	25.60.255.255
Subnet No:16---->  25.61.255.255	 to	25.64.255.255
Subnet No:17---->  25.65.255.255	 to	25.68.255.255
Subnet No:18---->  25.69.255.255	 to	25.72.255.255
Subnet No:19---->  25.73.255.255	 to	25.76.255.255
Subnet No:20---->  25.77.255.255	 to	25.80.255.255
Subnet No:21---->  25.81.255.255	 to	25.84.255.255
Subnet No:22---->  25.85.255.255	 to	25.88.255.255
Subnet No:23---->  25.89.255.255	 to	25.92.255.255
Subnet No:24---->  25.93.255.255	 to	25.96.255.255
Subnet No:25---->  25.97.255.255	 to	25.100.255.255
Subnet No:26---->  25.101.255.255	 to	25.104.255.255
Subnet No:27---->  25.105.255.255	 to	25.108.255.255
Subnet No:28---->  25.109.255.255	 to	25.112.255.255
Subnet No:29---->  25.113.255.255	 to	25.116.255.255
Subnet No:30---->  25.117.255.255	 to	25.120.255.255
Subnet No:31---->  25.121.255.255	 to	25.124.255.255
Subnet No:32---->  25.125.255.255	 to	25.128.255.255
Subnet No:33---->  25.129.255.255	 to	25.132.255.255
Subnet No:34---->  25.133.255.255	 to	25.136.255.255
Subnet No:35---->  25.137.255.255	 to	25.140.255.255
Subnet No:36---->  25.141.255.255	 to	25.144.255.255
Subnet No:37---->  25.145.255.255	 to	25.148.255.255
Subnet No:38---->  25.149.255.255	 to	25.152.255.255
Subnet No:39---->  25.153.255.255	 to	25.156.255.255
Subnet No:40---->  25.157.255.255	 to	25.160.255.255
Subnet No:41---->  25.161.255.255	 to	25.164.255.255
Subnet No:42---->  25.165.255.255	 to	25.168.255.255
Subnet No:43---->  25.169.255.255	 to	25.172.255.255
Subnet No:44---->  25.173.255.255	 to	25.176.255.255
Subnet No:45---->  25.177.255.255	 to	25.180.255.255
Subnet No:46---->  25.181.255.255	 to	25.184.255.255
Subnet No:47---->  25.185.255.255	 to	25.188.255.255
Subnet No:48---->  25.189.255.255	 to	25.192.255.255
Subnet No:49---->  25.193.255.255	 to	25.196.255.255
Subnet No:50---->  25.197.255.255	 to	25.200.255.255
Subnet No:51---->  25.201.255.255	 to	25.204.255.255
Subnet No:52---->  25.205.255.255	 to	25.208.255.255
Subnet No:53---->  25.209.255.255	 to	25.212.255.255
Subnet No:54---->  25.213.255.255	 to	25.216.255.255
Subnet No:55---->  25.217.255.255	 to	25.220.255.255
Subnet No:56---->  25.221.255.255	 to	25.224.255.255
Subnet No:57---->  25.225.255.255	 to	25.228.255.255
Subnet No:58---->  25.229.255.255	 to	25.232.255.255
Subnet No:59---->  25.233.255.255	 to	25.236.255.255
Subnet No:60---->  25.237.255.255	 to	25.240.255.255
Subnet No:61---->  25.241.255.255	 to	25.244.255.255
Subnet No:62---->  25.245.255.255	 to	25.248.255.255
Subnet No:63---->  25.249.255.255	 to	25.252.255.255
Subnet No:64---->  25.253.255.255	 to	25.255.255.255
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
128.2.1.0
enter the number of subnets
4
No of addresses in network :65536
No of addresses per subnet :16384
Subnet No:1---->  128.2.1.0	 to	128.2.64.255
Subnet No:2---->  128.2.65.255	 to	128.2.128.255
Subnet No:3---->  128.2.129.255	 to	128.2.192.255
Subnet No:4---->  128.2.193.255	 to	128.2.255.255
Do you want to continue:(y/n)y 
Enter the ip address in dotted decimal:
192.2.1.0
enter the number of subnets
4
No of addresses in network :256
No of addresses per subnet :64
Subnet No:1---->  192.2.1.0	 to	192.2.1.63
Subnet No:2---->  192.2.1.64	 to	192.2.1.127
Subnet No:3---->  192.2.1.128	 to	192.2.1.191
Subnet No:4---->  192.2.1.192	 to	192.2.1.255
Do you want to continue:(y/n)y
Enter the ip address in dotted decimal:
225.1.1.1
enter the number of subnets
4
This IP belongs to Class D
It Is Reserved For Multicasting
Do you want to continue:(y/n)n
**********************************************************/