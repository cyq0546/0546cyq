#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 1000
void enter();
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 1000
void enter();
void find();
void del();
void mod();
void list();
void count();
void load();
void add();
void menu(); 
int n;   //Ա��������
struct emploee  //ְ�����ݽṹ
 char no[5];
 char name[8];
 char sex[3];
 int age;
 float wage1;      
 float wage2;      
 float funds;      
 float WATERfee;   
 float TAXfee;    
 float wage3;      
}emp[NUM],newemp;
void main()
{
 menu();
}

void menu()
{  int n,w1;
   
   do
   { system("cls");  
      printf("************* ְ�����ʹ���ϵͳ **************\n");
      printf("*            1-----����ְ����Ϣ                     *\n");
      printf("*            2-----��ѯְ����Ϣ                     *\n");
      printf("*            3-----����ְ�������޸�              *\n");
      printf("*            4-----����ְ������ɾ��              *\n");
      printf("*            5-----�ݹ���ͳ�Ʋ����              *\n");
      printf("*            6-----���ļ�������Ϣ                 *\n");
      printf("*            7-----���ȫ��ְ��                    *\n");
      printf("*            8-----׷��ְ����Ϣ                    *\n");
      printf("*            9-----�˳�����                           *\n");
      printf("***************************************************\n");
  printf("       ��������ѡ��(1-9):[ ]\b\b");
  scanf("%d",&n);
  if(n<1||n>9)                                    
         {
            w1=1;
            printf("your choice is not between 1 and 9,Please input again:");
            getchar();
          }
         else    w1=0;
      } 
    while(w1==1);
  switch(n)
  { case 1:enter();    break;   
    case 2:find();   break;  
    case 3:mod();   break;    
    case 4:del();   break;    
    case 5:count ();    break;    
    case 6:load();    break;    
    case 7:list();    break;      
    case 8:add();    break; 
    case 9:printf("\n��������������лл����ӭ�´ι��٣���������������\n\n");
    default:exit(0);  
  }
}

void enter()
{
     FILE *fp;
     int n,i;
     if ((fp=fopen("emp.txt","wb"))==NULL)
     {
 
     printf("���ܽ���emp�ļ�\n");
     exit(1);
     }
     printf("����ְ������:");
    scanf("%d",&n);
     printf("�����ʽ:ְ���� ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������<Enter>\n");
     for(i=0;i<n;i++)   /*  ѭ����ȡn��ְ����¼ */
     {
         printf("��%d��ְ��:",i+1);
         scanf("%s%s%s%d%f%f%f%f%f",emp[i].no,emp[i].name,emp[i].sex,&emp[i].age,
           &emp[i].wage1,&emp[i].wage2,&emp[i].funds,&emp[i].WATERfee,&emp[i].TAXfee);
         emp[i].wage3=emp[i].wage1+emp[i].wage2+emp[i].funds-emp[i].WATERfee-emp[i].TAXfee;
     }
     for(i=0;i<n;i++)    
          fwrite(&emp[i],sizeof(struct emploee),1,fp);
     fclose(fp);
}

void count()
{
     FILE *fp;
     int n,num;
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
         printf("���ܴ�emp�ļ�\n");
         exit(1);
     }
     printf("�����빤����:");
     scanf("%d",&num);
     printf("��¼�� ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
     for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp)!=0;n++)
     if(emp[n].wage3>=num)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].sex, emp[n].age,emp[n].wage1,
             emp[n].wage2,emp[n].funds,emp[n].WATERfee,emp[n].TAXfee,emp[n].wage3);
     fclose(fp);
}


void del()
{
     FILE *fp;
     int i,j,n;
     char num[5];
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
         printf("���ܴ�emp�ļ�\n");
         exit(1);
      }
     printf("ɾ��ǰ:\n");
     printf("��¼�� \n");
    for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp);n++)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].sex, emp[n].age,emp[n].wage1,
             emp[n].wage2,emp[n].funds,emp[n].WATERfee,emp[n].TAXfee,emp[n].wage3);/*nΪemp�ļ��м�¼��*/
     printf("Ҫɾ����ְ����:");
     scanf("%s",num);
     for(i=0;(strcmp(emp[i].no,num)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\tû��%sְ���ŵ�ְ��\n",num);
          exit(2);
     }
     fclose(fp);
     fp=fopen("emp.dat","w+");
     if(n==1)  
     {
           fclose(fp);
           exit(3);
     }
     for(j=0;j<i;j++)
        fwrite(&emp[j],sizeof(struct emploee),1,fp);
     for(j=i+1;j<n;j++)
         fwrite(&emp[j],sizeof(struct emploee),1,fp);
     printf("ɾ����:\n");
     fseek(fp,0,SEEK_SET);
     printf("��¼�� ְ���� ���� �Ա� ����   �������� ְ���� ������ ˮ���   ˰  ʵ������\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
         printf("%6d%6s%9s%4s%5d%   %.1f    %.1f   %.1f   %.1f   %.1f   %.1f\n",i+1,.emp[i]no,emp[i].name,emp[i].sex, emp[i].age,emp[i].wage1,
                 emp[i].wage2,emp[i].funds,emp[i].WATERfee,emp[i].TAXfee,emp[i].wage3);
       fclose(fp);
}

void modi()
{
     FILE *fp;
     int i,j;
     char num[5];
     if((fp=fopen("emp.txt","rb+"))==NULL)
     {
         printf("���� ��emp�ļ�\n");
         exit(1);
     }
     printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
    if(!strcmp(emp[i].no,num))break;
     if(feof(fp))
     {
          printf("\tû��%sְ���ŵ�ְ��\n",num);
          exit(2);
     }
     printf("��¼�� ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
     printf("%6d%6s%9s%4s%5d%   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].sex, emp[i].age,emp[i].wage1,
              emp[i].wage2,emp[i].funds,emp[i].WATERfee,emp[i].TAXfee,emp[i].wage3);
    printf("�����ʽ:ְ����   ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������<Enter>\n");
    printf("��%d����¼:",i+1);
    scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,newemp.sex,&newemp.age,
               &newemp.wage1,&newemp.wage2,&newemp.funds,&newemp.WATERfee,&newemp.TAXfee);
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;
    fseek(fp,-(long)sizeof(struct emploee),SEEK_CUR);  
     fwrite(&newemp,sizeof(struct emploee),1,fp); 
     printf(" �޸ĺ�:\n");
    fseek(fp,0,SEEK_SET);        
     printf("��¼�� ְ����  ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp)!=0;i++)
         printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f  %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].sex, emp[i].age,emp[i].wage1,
                   emp[i].wage2,emp[i].funds,emp[i].WATERfee,emp[i].TAXfee,emp[i].wage3);
    fclose(fp);
}

void find()
{
     FILE *fp;
     int i; 
     char num[5];
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
          printf("���ܴ�emp�ļ�\n");
          exit(1);
     }
     printf("Ҫ��ѯ��ְ����:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
         if(!strcmp(emp[i].no,num)) break;
    if(feof(fp))
    {
        printf("\t���޴���\n");
        exit(2);
    }
     printf("��¼�� ���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
     printf("%6d%6s%9s%4s%5d  %.1f  %.1f  %.1f  %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].sex, emp[i].age,emp[i].wage1,
               emp[i].wage2,emp[i].funds,emp[i].WATERfee,emp[i].TAXfee,emp[i].wage3);
       fclose(fp);
}