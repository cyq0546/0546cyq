/*
	�ļ����ƣ����ʹ���ϵͳ.cpp
	������ڣ�2018-06-29
	���ߣ�������
	�༶:17���
	ѧ�ţ�117583010104
*/

#include "stdio.h"	//����ͷ�ļ�
#include "conio.h"	//����getch()��getche()����
#include "string.h"	
#include "windows.h"//����Sleep()����
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

	
void read()		//���ļ�gz.dat�ж�ȡְ�����ʵ����ݵ��ṹ����zggz��
{
	FILE *file;	//�����ļ�ָ��

	if((file=fopen("gz.dat","rb"))==NULL)//�Զ����Ʒ�ʽ��ְ�����������ļ����ж��Ƿ�ʧ��
	{
		printf("\n\n\tְ�����������ļ��޷��򿪣���Ϊ��! ");
		printf("\n\n\t��������������˵�����");
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
		printf("\n\t5���Ӻ�������� \n",n);
		n--;	//�����ְ�����ݵ�����
		Sleep(5000);	//������ʱ5����
	}
}


void write()    //��ְ�����������ļ���д������
{
	FILE *file;	//�����ļ�ָ��

	if(n==-1)	//��ְ������Ϊ0ʱ
	{
		printf("�����ݿɴ�! ��������������˵���\n");
		getch();
		return;
	}
	if((file=fopen("gz.dat","wb"))!=NULL)//�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);//�����м�¼һ��д���ļ�
		fclose(file);	//�ر��ļ�ָ��
		printf("\n\n\t\t%d��ְ����¼�������! \n",n+1 );
	}
	else	//���ļ��򿪲��ɹ�ʱ
		printf("\t\t�޷���ְ�����������ļ�! \n");
		printf("\n\t\t��������������˵�����");
	getch();
}