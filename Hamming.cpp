//============================================================================
// Name        : common.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<math.h>
using namespace std;
int main()
{

	int data[11];
	int j=0;

	for(int i=1;i<=11;i++)
	{
		data[i]=0;
	}

	cout<<"Enter 7 bit data.\n";
//data is stored and redundant bits keeps empty
	for(int i=1;i<=11;i++)
	{
		if(i== pow(2,j))
		{
			j++;
			continue;
		}
		cin>>data[i];
	}


	data[1]=data[3]^data[5]^data[7]^data[9]^data[11];
	data[2]=data[3]^data[6]^data[7]^data[10]^data[11];
	data[4]=data[5]^data[6]^data[7];
	data[8]=data[9]^data[10]^data[11];

	cout<<"\n Data to be sent is :\n\n";

	for(int i=1;i<=11;i++)
	{
		cout<<data[i]<<"\t";
	}
	int msgr[4];
	int flag=0,ans;

			for(int i=1;i<=11;i++)
			{
				data[i]=0;
			}

			cout<<"Enter received data bits ::\n";

			for(int i=1;i<=11;i++)
			{
				cin>>data[i];
			}

	msgr[0]=data[1]^data[3]^data[5]^data[7]^data[9]^data[11];
	msgr[1]=data[2]^data[3]^data[6]^data[7]^data[10]^data[11];
	msgr[2]=data[4]^data[5]^data[6]^data[7];
	msgr[3]=data[8]^data[9]^data[10]^data[11];

	ans = msgr[0]*1 + msgr[1]*2 + msgr[2]*4 + msgr[3]*8;

		if(ans==0)
		{
			cout<<"Message is Correct..";
		}
		else
		{
			cout<<"Message is Incorrect..\n Location ::"<<ans;
			if(data[ans]==0)
			{
				data[ans]=1;
			}
			else
			{
				data[ans]=0;
			}
			cout<<"Corrected data is ::\n";

			for(int i=1;i<=11;i++)
			{
				cout<<data[i];
			}
		}
	return 0;
}
/*
 * Enter 7 bit data.
1
0
0
1
1
0
1

 Data to be sent is :

0	1	1	1	0	0	1	0	1	0	1
Enter received data bits ::
0
1
1
1
0
0
1
0
1
0
1
Message is Correct..
Enter 7 bit data.
1
0
0
1
1
0
1

 Data to be sent is :

0	1	1	1	0	0	1	0	1	0	1	
Enter received data bits ::
1
1
1
1
0
0
1
0
1
0
1
Message is Incorrect..
 Location ::1Corrected data is ::
01110010101*/

