/*
	�ļ����ƣ����ʹ���ϵͳ.cpp
	������ڣ�2018-07-03
	���ߣ�������
	�༶:17���
	ѧ�ţ�117583010104
*/

#include "stdio.h"	  //����ͷ�ļ�
#include "conio.h"	  //����getch()��getche()����
#include "string.h"	  //�����ַ�����غ���
#include "windows.h"  //����Sleep()����
#define TRUE 1

void read();			  //��ȡְ����������
void write();			  //����ְ����������
void find();			  //��ѯְ����������
void modify();			  //�޸�ְ����������
void add();			      //����ְ����������
void del();			      //ɾ��ְ����������
float grsds(float m);	  //�����������˰
void list();			  //���ְ����������

struct zhigong			//ְ���������ݽṹ��
{
	char gonghao[10];	//ְ������
	char name[10];		//ְ������
	float gwgz;		    //��λ����
	float xjgz;		    //н������
	float zwjt;		    //ְ�����
	float jxgz;		    //��Ч����
	float yfgz;		    //Ӧ������
	float grsds;		//��������˰
	float sfgz;		    //ʵ������
};

struct zhigong zggz[100];	//����ְ�������������100��Ԫ�صĽṹ������

int n=-1;		//����ͳ��ְ������ȫ�ֱ���

void main()
{
	char ch;
	read();  //��ȡְ����������
	while(TRUE)
	{
		system("cls");		//��������
		printf("\n\n\t\t### ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺ���ʹ���ϵͳ ###\n\n\n");
		printf("\t\t��ѡ��(1-7) :\n");
		printf("\t\t==============================================\n");
		printf("\t\t\t1.��ѯְ������\n");
		printf("\t\t\t2.�޸�ְ������\n");
		printf("\t\t\t3.���ְ������\n");
		printf("\t\t\t4.ɾ��ְ������\n");
		printf("\t\t\t5.�������ݵ��ļ�\n");
		printf("\t\t\t6.���ְ����¼\n");
		printf("\t\t\t7.�˳����ʹ���ϵͳ\n");
		printf("\t\t==============================================\n");
		printf("\n\t\t���ѡ���ǣ�");
		ch=getche();

		switch(ch)
		{
			   case '1':find();
				   break;	//��ѯ
			   case '2':modify();
				   break;	//�޸�
			   case '3':add();
				   break;	//���
			   case '4':del();
				   break;	//ɾ��
			   case '5':write();
				   break;	//����
			   case '6':list();
				   break;	//���
			   case '7':return;		//�˳�
			   default:printf("\t\t�밴�������������ѡ��1��7��\n");
			   getch();
		}
	}
	return;
}

//��ȡְ����������
	
void read()		//���ļ�gz.dat�ж�ȡְ�����ʵ����ݵ�����zggz��
{
	FILE *file;	//�����ļ�ָ��

	if((file=fopen("gz.dat","rb"))==NULL)   //�Զ����Ʒ�ʽ��ְ�����������ļ����ж��Ƿ�ʧ��
	{
		printf("\n\n\tְ�����������ļ�Ϊ��! ");
		printf("\n\n\t�밴������������˵�����");
		getch();
		return;
	}
	else	//���ļ��򿪳ɹ�ʱ
	{
		n++;		//����ṹ�������±�
		while(fread(&zggz[n],sizeof(zggz[n]),1,file)==1)
			n++;
		fclose(file);	//�ر��ļ�ָ��
		printf("\n\n\tְ���������ݶ�ȡ��ϣ�����%d��! \n",n);
		printf("\n\t3���Ӻ�������� \n",n);
		n--;	//�����ְ�����ݵ�����
		Sleep(3000);	//������ʱ3����
	}
}

//����ְ����������

void write()      //��ְ�����������ļ���д������
{
	FILE *file;	  //�����ļ�ָ��

	if(n==-1)  	  //��ְ������Ϊ0ʱ
	{
		printf("�����ݿɴ�! ��������������˵���\n");
		getch();
		return;
	}
	if((file=fopen("gz.dat","wb"))!=NULL)    //�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);    //�����м�¼һ��д���ļ�
		fclose(file);	 //�ر��ļ�ָ��
		printf("\n\n\t\t%d��ְ����¼�������! \n",n+1 );
	}
	else	//���ļ��򿪲��ɹ�ʱ
		printf("\t\t�޷���ְ�����������ļ�! \n");
		printf("\n\t\t��������������˵�����");
	getch();
}

//��ѯְ����������

void find()
{
	char gonghao[10];    //����ְ�������ַ�����
	int i;	

	if(n==-1)   //����Ϊ0˵�����ʼ�¼��δ���
	{
		printf("\n\n\t\t��ǰ��û��ְ�����ʼ�¼����������������˵�����");
		getch();
		return;
	}

	printf("\t������ְ�����ţ�");    //��ʾ��Ϣ
	gets(gonghao);        //�Ӽ��̶�ȡ�ַ���

	for(i=0;i<=n;i++)    //��ְ��������Χ��ѭ������
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)   //�Ƚϲ��ҵ�
		{
			printf("\n  ��ְ������������£�");
			printf("\n  ===================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","����˰","ʵ������");

			printf("%-6s%-6s%8.2f",zggz[i].gonghao,zggz[i].name,zggz[i].gwgz);
			printf("%9.2f%9.2f",zggz[i].xjgz,zggz[i].zwjt);
			printf("%9.2f%9.2f",zggz[i].jxgz,zggz[i].yfgz);
			printf("%9.2f%9.2f\n",zggz[i].grsds,zggz[i].sfgz);
			printf("\n ��������������˵�����");
			getch();
			break;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t���������ְ����������򲻴���! ");
		printf("��������������˵�����");
		getch();
		return;
	}
}

//���ְ����������

void list()
{
	int i;
	system("cls");
	printf("\n\n\t\t\t ȫ��ְ�������������\n");
	printf("\t\t\t======================\n\n");

	printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
	printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","����˰","ʵ������");

	for(i=0;i<=n;i++)
	{
		printf("%-6s%-6s%8.2f",zggz[i].gonghao,zggz[i].name,zggz[i].gwgz);
		printf("%9.2f%9.2f",zggz[i].xjgz,zggz[i].zwjt);
		printf("%9.2f%9.2f",zggz[i].jxgz,zggz[i].yfgz);
		printf("%9.2f%9.2f\n",zggz[i].grsds,zggz[i].sfgz);

	}
	printf("  ��������������˵�����");
	getch();
	return;
}

//�޸�ְ����������

void modify()
{
	char gonghao[10];    //����ְ�������ַ�����
	
	int i;	   //ѭ������

	if(n==-1)    //������Ϊ0˵�����ʼ�¼δ���
	{
		printf("\n\n\t\t��ǰ��û��ְ�����ʼ�¼����������������˵�����");
		getch();
		return;
	}

	printf("\t������ְ�����ţ�");    //��ʾ��Ϣ
	gets(gonghao);      //�Ӽ��̶�ȡ�ַ���

	for(i=0;i<=n;i++)   //��ְ��������Χ��ѭ������
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)   //�Ƚϲ��ҵ�
		{
			//��ʾ����ְ���������
			printf("\n\t\t\t  ��ְ������������£�");
			printf("\n\t\t\t  ===================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","����˰","ʵ������");
			printf("%-6s%-6s%8.2f",zggz[i].gonghao,zggz[i].name,zggz[i].gwgz);
			printf("%9.2f%9.2f",zggz[i].xjgz,zggz[i].zwjt);
			printf("%9.2f%9.2f",zggz[i].jxgz,zggz[i].yfgz);
			printf("%9.2f%9.2f\n",zggz[i].grsds,zggz[i].sfgz);

			//���ո�ְ���µĹ�������
			printf("\n\t\t�������ְ���µĸ�λ���ʣ�");
			scanf("%f",&zggz[i].gwgz);
			printf("\t\t�������ְ���µ�н�����ʣ�");
			scanf("%f",&zggz[i].xjgz);
			printf("\t\t�������ְ���µ�ְ�������");
			scanf("%f",&zggz[i].zwjt);
			printf("\t\t�������ְ���µļ�Ч���ʣ�");
			scanf("%f",&zggz[i].jxgz);

			//����Ӧ�����ʡ���������˰��ʵ������
			zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;
			zggz[i].grsds=grsds(zggz[i].yfgz);
			zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds;
			//ͬ����ʾ������
			printf("\n\t\t��ְ����Ӧ�����ʶ��ǣ�%f",zggz[i].yfgz);
			printf("\n\t\t��ְ���ĸ�������˰�ǣ�%f",zggz[i].grsds);
			printf("\n\t\t��ְ����ʵ�����ʶ��ǣ�%f",zggz[i].sfgz);

			printf("\n\n\t\t��ְ�����������޸ĳɹ�����������������˵�����");
			getch();
			return;
		}
	}
	printf("\n\t\t���������ְ����������򲻴���! ");
	printf("��������������˵�����");
	getch();
	return;
}

//��ְ�����������ļ������Ӽ�¼

void add()
{
	printf("\t������ְ�����ţ�");
	fflush(stdin);  	//������̻�����
	gets(zggz[++n].gonghao);
	printf("\t\t\t\t������ְ��������");
	gets(zggz[n].name);
	printf("\n\t\t\t\t�������ְ���µĸ�λ���ʣ�");
	scanf("%f",&zggz[n].gwgz);
	printf("\t\t\t\t�������ְ���µ�н�����ʣ�");
	scanf("%f",&zggz[n].xjgz);
	printf("\t\t\t\t�������ְ���µ�ְ�������");
	scanf("%f",&zggz[n].zwjt);
	printf("\t\t\t\t�������ְ���µļ�Ч���ʣ�");
	scanf("%f",&zggz[n].jxgz);

	//����Ӧ�����ʡ���������˰��ʵ������
	zggz[n].yfgz=zggz[n].gwgz+zggz[n].xjgz+zggz[n].zwjt+zggz[n].jxgz;


	                                 
        zggz[n].grsds=grsds(zggz[n].yfgz);           //�����������˰



	zggz[n].sfgz=zggz[n].yfgz-zggz[n].grsds;
	//������ϼ�������
	printf("\n\t\t\t\t��ְ����Ӧ�����ʶ��ǣ�%f",zggz[n].yfgz);
	printf("\n\t\t\t\t��ְ���ĸ�������˰�ǣ�%f",zggz[n].grsds);
	printf("\n\t\t\t\t��ְ����ʵ�����ʶ��ǣ�%f",zggz[n].sfgz);

	printf("\n\n\t\t\t\t����������ء���");
	getch();
}

//��ְ�����������ļ���ɾ����¼

void del()
{
	char gonghao[10];    //����ְ�������ַ�����
	int i,j;	
	char d;		         //����ȷ��ɾ���ַ���y/n

	printf("\t�������ɾ��ְ�����ţ�");
	gets(gonghao);
	for(i=0;i<=n;i++)    //��ְ��������Χ��ѭ������
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)     //�Ƚϲ��ҵ�
		{
			printf("\n\t\t��ȷ��Ҫɾ��%s��ְ��������Ϣ��(y/n)��",zggz[i].gonghao);
			d=getche();
			if(d=='y'||d=='Y')    //ȷ��ɾ��
			{
				if(i==n)       //��������һ����¼
					n--;
				else	       //����������һ����¼
				{
					for(j=i;j<=n;j++)    //�Ӹü�¼��ʼ��������ǰһ����¼
					{
						strcpy(zggz[j].gonghao,zggz[j+1].gonghao);
						strcpy(zggz[j].name,zggz[j+1].name);
						zggz[j].gwgz=zggz[j+1].gwgz;
						zggz[j].xjgz=zggz[j+1].xjgz;
						zggz[j].zwjt=zggz[j+1].zwjt;
						zggz[j].jxgz=zggz[j+1].jxgz;
						zggz[j].yfgz=zggz[j+1].yfgz;
						zggz[j].grsds=zggz[j+1].grsds;
						zggz[j].sfgz=zggz[j+1].sfgz;
					}
					n--;
				}
				printf("\n\n\t\t��ְ����¼�ɹ�ɾ������������������˵�����");
				getch();
				break;
			}
			else	//��ɾ���ü�¼
			{
				printf("\n\n\t\t��ѡ���˲�ɾ����ְ����¼����������������˵�����");
				getch();
				return;
			}
		}
	}
	if(i==n+1)	//δ�ҵ���Ӧ����
	{
		printf("\n\t\t����λ�޴˹��ţ���������������˵�����");
		getch();
	}
}


//�����������˰

float grsds(float m)
{
	float x;    	//����Ӧ��˰���ö�
	float y=0;	    //����Ӧ��˰��
	int n;

	x=m-2000;

	if(x>0)
		if(x<500)n=1;
		else if(x<2000)n=2;
		else if(x<5000)n=3;
		else if(x<20000)n=4;
		else if(x<40000)n=5;
		else if(x<60000)n=6;
		else if(x<80000)n=7;
		else if(x<100000)n=8;
		else n=9;
		
	switch(n)	
	{
		case 9:y=(x-100000)*0.45;x=100000;
		case 8:y+=(x-80000)*0.40;x=80000;
		case 7:y+=(x-60000)*0.35;x=60000;
		case 6:y+=(x-40000)*0.30;x=40000;
		case 5:y+=(x-20000)*0.25;x=20000;
		case 4:y+=(x-5000)*0.20;x=5000;
		case 3:y+=(x-2000)*0.15;x=2000;
		case 2:y+=(x-500)*0.10;x=500;
		case 1:y+=x*0.05;
	}
	return y;

}