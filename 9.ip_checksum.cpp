#include <iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int bin[8];
void binary(int n)
{
	for(int j=7;j>=0;j--)
	{
		int t=pow(2,j);
		bin[7-j]=n/t;
		n=n%t;
	}

}
int main()
{
	string sip,dip;
	int nor,ttl,id,HLEN,off,pro,tl;
	int n[4];
	int bsip[4][8],bdip[4][8],bHLEN[4],bid[8],bttl[8],bpro[8],boff[13],btl[16];
	string ver="0100";
	cout<<ver<<endl;

	cout<<"Enter header length: ";
	cin>>HLEN;

	binary(HLEN);
	for (int i = 4; i < 8; ++i)
	{
		/* code */
		bHLEN[i-4]=bin[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		cout<<bHLEN[i];
	}

	cout<<"\ntotal length: ";
	cin>>tl;
	for (int i = 15; i >=0; --i)
	{
		/* code */
		int t=pow(2,i);
		btl[15-i]=tl/t;
		tl=tl%t;
		//cout<<btl[i];
	}
	for (int i = 0; i < 16; ++i)
	{
		/* code */
		cout<<btl[i];
	}

	cout<<"\nEnter id: ";
	cin>>id;
	binary(id);
	for (int i = 0; i < 8; ++i)
	{
		/* code */
		bid[i]=bin[i];
		cout<<bid[i];
	}

	cout<<"\nEnter offset: ";
	cin>>off;
	for (int i = 12; i >=0; --i)
	{
		/* code */
		int t=pow(2,i);
		boff[12-i]=off/t;
		off=off%t;
	}
	for (int i = 0; i < 13; ++i)
	{
		/* code */
		cout<<boff[i];
	}

	cout<<"\nEnter no of hosts: ";
	cin>>nor;
	ttl=2*nor;
	binary(ttl);
	for (int i = 0; i < 8; ++i)
	{
		/* code */
		bttl[i]=bin[i];
		cout<<bttl[i];
	}

	cout<<"\nEnter protocol: ";
	cin>>pro;
	binary(pro);
	for (int i = 0; i < 8; ++i)
	{
		/* code */
		bpro[i]=bin[i];
		cout<<bpro[i];
	}

	cout<<"\nEnter Source ip: ";
	cin>>sip;
    //source ip
	int l=sip.length();
	char *y = new char[l + 1];
	strcpy(y, sip.c_str());
	sscanf(y,"%d.%d.%d.%d",&n[0],&n[1],&n[2],&n[3]);
	for(int i=0;i<4;i++)
	{
		binary(n[i]);
		for (int j = 0; j < 8; ++j)
		{
			/* code */
			bsip[i][j]=bin[j];
			cout<<bsip[i][j];
		}
		cout<<endl;
	}

	cout<<"\nEnter Destination ip: ";
	cin>>dip;
	//destination ip
	l=sip.length();
	y = new char[l + 1];
	strcpy(y, dip.c_str());
	sscanf(y,"%d.%d.%d.%d",&n[0],&n[1],&n[2],&n[3]);
	for(int i=0;i<4;i++)
	{
		binary(n[i]);
		for (int j = 0; j < 8; ++j)
		{
			/* code */
			bdip[i][j]=bin[j];
			cout<<bdip[i][j];
		}
		cout<<endl;
	}
	for(i = 7; i >= 0; i--)
	{
       	    sum[i] = numa[i]+ numb[i] + c;
            if(sum[i]>=2)
	    {
           	 c = 1;
            }
            else
            	c = 0;
                sum[i] = sum[i]%2;
       }
	return 0;
}
