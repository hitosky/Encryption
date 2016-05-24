#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"des.h"
#include<queue>
using namespace std;

void jiami()
{
	int i,j;
	char *f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[9]);
	FILE *fp1=fopen(f1,"rb");
	wenjian(fp1);
	free(f1);
	f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[8]);
	FILE *fp2=fopen(f1,"rb");
	wenjian(fp2);
	free(f1);
	f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[14]);
	FILE *fp3=fopen(f1,"rb");
	wenjian(fp3);
	free(f1);
	f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[13]);
	FILE*fp4=fopen(f1,"rb");
	free(f1);
	chushizh(fp1,fp2);
	fclose(fp1);
	fclose(fp2);
	f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[10]);
	fp1=fopen(f1,"rb");
	free(f1);
	wenjian(fp1);
	f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[11]);
	fp2=fopen(f1,"rb");
	wenjian(fp2);
	free(f1);
	zhihuan1(fp1,fp2);
	fclose(fp1);
	fclose(fp2);
	f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[12]);
	fp1=fopen(f1,"rb");
	wenjian(fp1);
	free(f1);
	FILE *fp5;
	f1=(char*)malloc(sizeof(char)*15);
	strcpy(f1,she[15]);
	fp5=fopen(f1,"r");
	wenjian(fp5);
	free(f1);

	for(i=0;i!=round;++i)
	{
		fscanf(fp3,"%d",&circle[i]);
		zyiwei(i);
		zhihuan2(fp1);
		kuozhan(fp5);
		xor1();
		for(j=0;j!=8;++j)
		{
			char *f=(char*)malloc(sizeof(char)*15);
			strcpy(f,she[j]);
			fp2=fopen(f,"rb");
			wenjian(fp2);
			
			daihuan(fp2,j);
			fclose(fp2);
		}
		
		zhihuanP(fp4);
	
		if(i!=15)swap();

		rewind(fp1);
		rewind(fp4);
		rewind(fp5);
	}
	fclose(fp1);
	fclose(fp3);
	fclose(fp4);
	fp1=fopen("ini_exchange.txt","rb");
	wenjian(fp1);


	nichushizh(fp1);
}
int main()
{
	int i,j;
	double start=GetTickCount();
	jiami();
	for ( i=0;i!=wid1;++i)
	{
		for( j=0;j!=len1;++j)
			printf("%d ",code[i][j]);
		printf("\n");
	}
	printf("加密所花时间为%4.3fs\n",(GetTickCount()-start)/1000);
	return 0;
}