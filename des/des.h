#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<queue>
using namespace std;
const int len1=8;
const int wid1=8;
const int round=16;
int code[wid1][len1];
int code48[wid1][len1/2+2];
int code32[wid1][len1/2];
int miyao56[wid1][len1-1];
int miyao48[wid1][len1-2];
int circle[round];
char she[16][15]=
{"S1.txt","S2.txt",
"S3.txt","S4.txt",
"S5.txt","S6.txt",
"S7.txt","S8.txt",
"ini_exchange.txt","uncryptograph.txt",
"cipher.txt","exchange1.txt",
"exchange2.txt","exchange_p.txt",
"left_loop_shift.txt","extend.txt"
};
void chushizh(FILE* fp1,FILE*fp2)
{
	int zhihuan[wid1][len1];
	int temp[wid1][len1];
	for ( int i=0;i!=wid1;++i)
		for(int j=0;j!=len1;++j)
		{
			fscanf(fp1,"%d",&temp[i][j]);
			fscanf(fp2,"%d",&zhihuan[i][j]);
		}
		
		
			for ( i=0;i!=wid1;++i)
			for(int j=0;j!=len1;++j)
		{
			int t;
			t=zhihuan[i][j];
			code[i][j]=temp[(t-1)/len1][(t-1)%len1];
		}
}
void nichushizh(FILE*fp)
{
	int i,j,zhihuan[wid1][len1],temp[wid1][len1];
	for ( i=0;i!=wid1;++i)
	for( j=0;j!=len1;++j)
			fscanf(fp,"%d",&zhihuan[i][j]);
	for ( i=0;i!=wid1;++i)
		for( j=0;j!=len1;++j)
			{
				int t;
				t=zhihuan[i][j];
				temp[(t-1)/len1][(t-1)%len1]=code[i][j];
			}
	for ( i=0;i!=wid1;++i)
		for( j=0;j!=len1;++j)
				code[i][j]=temp[i][j];
				
}
void zhihuan1(FILE*fp1,FILE*fp2)
{
	int temp[wid1][len1];
	int zhihuan[wid1][len1-1];
	
	for ( int i=0;i!=wid1;++i)
		for(int j=0;j!=len1;++j)
		{
			fscanf(fp1,"%d",&temp[i][j]);
			if(j!=len1-1)
			fscanf(fp2,"%d",&zhihuan[i][j]);
		}
	for ( i=0;i!=wid1;++i)
		for(int j=0;j!=len1-1;++j)
		{
			int t;
			t=zhihuan[i][j];
			miyao56[i][j]=temp[(t-1)/len1][(t-1)%len1];
		}

}
void yiwei1(queue<int>&temp,int i)
{
	int j;
	for(j=0;j!=circle[i];++j)
	{
		temp.push(temp.front());
		
		temp.pop();
	}
}
void yiwei2(int a,int b,int i)
{
	int j,k;
	queue<int> temp;
	for(j=a;j!=b;++j)
		for(k=0;k!=len1-1;++k)
		temp.push(miyao56[j][k]);
	yiwei1(temp,i);
	for(j=a;j!=b;++j)
		for(k=0;k!=len1-1;++k)
		{
			miyao56[j][k]=temp.front();
		
			temp.pop();
		}
}
void zyiwei(int i)
{	
	yiwei2(0,wid1/2,i);
	yiwei2(wid1/2,wid1,i);
}
void zhihuan2(FILE*fp1)
{
	int zhihuan[wid1][len1-2];
	for ( int i=0;i!=wid1;++i)
		for(int j=0;j!=len1-2;++j)
		fscanf(fp1,"%d",&zhihuan[i][j]);
	for ( i=0;i!=wid1;++i)
		for(int j=0;j!=len1-2;++j)
		{
			int t;
			t=zhihuan[i][j];
			miyao48[i][j]=miyao56[(t-1)/(len1-1)][(t-1)%(len1-1)];
		}
		
}
void kuozhan(FILE*fp)
{
	int i,j,t;
	int zhihuan[wid1][len1/2+2];
	for(i=0;i!=wid1;++i)
	for(j=0;j!=len1/2+2;++j)
		fscanf(fp,"%d",&zhihuan[i][j]);
	
	for(i=0;i!=wid1;++i)
	for(j=0;j!=len1/2+2;++j)
	{
		t=zhihuan[i][j];
		code48[i][j]=code[(t-1)/len1+wid1/2][(t-1)%len1];
	}
	
	
}
void xor1()
{
	int i,j;
	for(i=0;i!=wid1;++i)
		for(j=0;j!=len1-2;++j)
			code48[i][j]=(code48[i][j]+miyao48[i][j])%2;
}
void daihuan(FILE*fp,int t)
{
	int j,x,y=0,n=1,p;
	x=code48[t][len1/2+1]+code48[t][0]*2;
	for(j=len1/2;j!=0;--j)
	{
		y+=code48[t][j]*n;
		n*=2;
	}
    for(j=-1;j!=x*16+y;++j)
	
		//fseek(fp,(x*16+y)*sizeof(char),SEEK_SET);
	fscanf(fp,"%d",&p);
		for(j=len1/2-1;j!=-1;--j)
		{
			code32[t][j]=p%2;
			p/=2;
		}
}
void zhihuanP(FILE*fp)
{
	int zhihuan[wid1][len1/2],temp[wid1][len1/2];
	int i,j;
	for (  i=0;i!=wid1;++i)
		for( j=0;j!=len1/2;++j)
		fscanf(fp,"%d",&zhihuan[i][j]);
	for ( i=0;i!=wid1;++i)
		for( j=0;j!=len1/2;++j)
		{
			int t;
			t=zhihuan[i][j];
			temp[i][j]=code32[(t-1)/(len1/2)][(t-1)%(len1/2)];
		}
			
	for ( i=0;i!=wid1;++i)
		for( j=0;j!=len1/2;++j)
		{
			code32[i][j]=temp[i][j];
		}
}
void xor2(int temp[])
{
	int i,j;
	for(i=0;i!=wid1/2;++i)
		for(j=0;j!=len1;++j)
			code[i+wid1/2][j]=(temp[i*len1+j]+code[i][j])%2;
}
void swap()
{
	int i,j,temp[wid1*len1/2],temp1[wid1/2][len1];
	for(i=0;i!=wid1;++i)
		for(j=0;j!=len1/2;++j)
			temp[i*len1/2+j]=code32[i][j];
	for(i=0;i!=wid1/2;++i)
		for(j=0;j!=len1;++j)
			temp1[i][j]=code[i+wid1/2][j];
		xor2(temp);
		for(i=0;i!=wid1/2;++i)
		for(j=0;j!=len1;++j)
			code[i][j]=temp1[i][j];
		
}
void wenjian(FILE * fp)
{
	if(fp==NULL)
	{
		printf("cannot open this file\n");
		getchar();
		exit(1);
	}
}

