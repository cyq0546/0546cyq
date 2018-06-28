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
int n;   //员工的总数
struct emploee  //职工数据结构
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
      printf("************* 职工工资管理系统 **************\n");
      printf("*            1-----输入职工信息                     *\n");
      printf("*            2-----查询职工信息                     *\n");
      printf("*            3-----根据职工工号修改              *\n");
      printf("*            4-----根据职工工号删除              *\n");
      printf("*            5-----据工资统计并浏览              *\n");
      printf("*            6-----从文件载入信息                 *\n");
      printf("*            7-----浏览全部职工                    *\n");
      printf("*            8-----追加职工信息                    *\n");
      printf("*            9-----退出程序                           *\n");
      printf("***************************************************\n");
  printf("       输入您的选择(1-9):[ ]\b\b");
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
    case 9:printf("\n×××××××谢谢，欢迎下次光临！×××××××\n\n");
    default:exit(0);  
  }
}

void enter()
{
     FILE *fp;
     int n,i;
     if ((fp=fopen("emp.txt","wb"))==NULL)
     {
 
     printf("不能建立emp文件\n");
     exit(1);
     }
     printf("输入职工人数:");
    scanf("%d",&n);
     printf("输入格式:职工号 工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资<Enter>\n");
     for(i=0;i<n;i++)   /*  循环获取n个职工记录 */
     {
         printf("第%d个职工:",i+1);
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
         printf("不能打开emp文件\n");
         exit(1);
     }
     printf("请输入工资数:");
     scanf("%d",&num);
     printf("记录号 工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
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
         printf("不能打开emp文件\n");
         exit(1);
      }
     printf("删除前:\n");
     printf("记录号 \n");
    for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp);n++)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].sex, emp[n].age,emp[n].wage1,
             emp[n].wage2,emp[n].funds,emp[n].WATERfee,emp[n].TAXfee,emp[n].wage3);/*n为emp文件中记录数*/
     printf("要删除的职工号:");
     scanf("%s",num);
     for(i=0;(strcmp(emp[i].no,num)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\t没有%s职工号的职工\n",num);
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
     printf("删除后:\n");
     fseek(fp,0,SEEK_SET);
     printf("记录号 职工号 姓名 性别 年龄   基本工资 职务工资 公积金 水电费   税  实发工资\n");
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
         printf("不能 打开emp文件\n");
         exit(1);
     }
     printf("要修改的职工号:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
    if(!strcmp(emp[i].no,num))break;
     if(feof(fp))
     {
          printf("\t没有%s职工号的职工\n",num);
          exit(2);
     }
     printf("记录号 工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
     printf("%6d%6s%9s%4s%5d%   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].sex, emp[i].age,emp[i].wage1,
              emp[i].wage2,emp[i].funds,emp[i].WATERfee,emp[i].TAXfee,emp[i].wage3);
    printf("输入格式:职工号   工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资<Enter>\n");
    printf("第%d个记录:",i+1);
    scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,newemp.sex,&newemp.age,
               &newemp.wage1,&newemp.wage2,&newemp.funds,&newemp.WATERfee,&newemp.TAXfee);
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;
    fseek(fp,-(long)sizeof(struct emploee),SEEK_CUR);  
     fwrite(&newemp,sizeof(struct emploee),1,fp); 
     printf(" 修改后:\n");
    fseek(fp,0,SEEK_SET);        
     printf("记录号 职工号  工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
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
          printf("不能打开emp文件\n");
          exit(1);
     }
     printf("要查询的职工号:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
         if(!strcmp(emp[i].no,num)) break;
    if(feof(fp))
    {
        printf("\t查无此人\n");
        exit(2);
    }
     printf("记录号 工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
     printf("%6d%6s%9s%4s%5d  %.1f  %.1f  %.1f  %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].sex, emp[i].age,emp[i].wage1,
               emp[i].wage2,emp[i].funds,emp[i].WATERfee,emp[i].TAXfee,emp[i].wage3);
       fclose(fp);
}