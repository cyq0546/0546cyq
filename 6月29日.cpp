/*
	文件名称：工资管理系统.cpp
	完成日期：2018-06-29
	作者：陈云清
	班级:17软件
	学号：117583010104
*/

#include "stdio.h"	//包含头文件
#include "conio.h"	//包含getch()及getche()函数
#include "string.h"	
#include "windows.h"//包含Sleep()函数
#define TRUE 1

void read();			  //读取职工工资数据
void write();			  //保存职工工资数据
void find();			  //查询职工工资数据
void modify();			  //修改职工工资数据
void add();			      //增加职工工资数据
void del();			      //删除职工工资数据
float grsds(float m);	  //计算个人所得税
void list();			  //浏览职工工资数据

struct zhigong			//职工工资数据结构体
{
	char gonghao[10];	//职工工号
	char name[10];		//职工姓名
	float gwgz;		    //岗位工资
	float xjgz;		    //薪级工资
	float zwjt;		    //职务津贴
	float jxgz;		    //绩效工资
	float yfgz;		    //应发工资
	float grsds;		//个人所得税
	float sfgz;		    //实发工资
};

struct zhigong zggz[100];	//声明职工工资数据里的100个元素的结构体数组

int n=-1;		//声明统计职工人数全局变量

void main()
{
	char ch;
	read();  //读取职工工资数据
	while(TRUE)
	{
		system("cls");		//清屏命令
		printf("\n\n\t\t### 欢迎使用广西民族大学软件与信息安全学院工资管理系统 ###\n\n\n");
		printf("\t\t请选择(1-7) :\n");
		printf("\t\t==============================================\n");
		printf("\t\t\t1.查询职工工资\n");
		printf("\t\t\t2.修改职工工资\n");
		printf("\t\t\t3.添加职工工资\n");
		printf("\t\t\t4.删除职工工资\n");
		printf("\t\t\t5.保存数据到文件\n");
		printf("\t\t\t6.浏览职工记录\n");
		printf("\t\t\t7.退出工资管理系统\n");
		printf("\t\t==============================================\n");
		printf("\n\t\t你的选择是：");
		ch=getche();

		switch(ch)
		{
			   case '1':find();
				   break;	//查询
			   case '2':modify();
				   break;	//修改
			   case '3':add();
				   break;	//添加
			   case '4':del();
				   break;	//删除
			   case '5':write();
				   break;	//保存
			   case '6':list();
				   break;	//浏览
			   case '7':return;		//退出
			   default:printf("\t\t请按任意键返回重新选择（1－7）\n");
			   getch();
		}
	}
	return;
}

	
void read()		//从文件gz.dat中读取职工工资的数据到结构数组zggz中
{
	FILE *file;	//声明文件指针

	if((file=fopen("gz.dat","rb"))==NULL)//以二进制方式打开职工工资数据文件并判断是否失败
	{
		printf("\n\n\t职工工资数据文件无法打开，或为空! ");
		printf("\n\n\t按任意键进入主菜单……");
		getch();
		return;
	}
	else	//当文件打开成功时
	{
		n++;		//计算结构体数组下标
		while(fread(&zggz[n],sizeof(zggz[n]),1,file)==1)
			n++;
		fclose(file);	//关闭文件指针
		printf("\n\n\t职工工资数据读取完毕，共有%d人! \n",n);
		printf("\n\t5秒钟后继续…… \n",n);
		n--;	//计算出职工数据的总数
		Sleep(5000);	//设置延时5秒钟
	}
}


void write()    //向职工工资数据文件中写入数据
{
	FILE *file;	//声明文件指针

	if(n==-1)	//当职工人数为0时
	{
		printf("无数据可存! 按任意键返回主菜单。\n");
		getch();
		return;
	}
	if((file=fopen("gz.dat","wb"))!=NULL)//以二进制方式打开职工工资数据文件并进行判断是否失败
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);//把所有记录一次写入文件
		fclose(file);	//关闭文件指针
		printf("\n\n\t\t%d条职工记录保存完毕! \n",n+1 );
	}
	else	//当文件打开不成功时
		printf("\t\t无法打开职工工资数据文件! \n");
		printf("\n\t\t按任意键返回主菜单……");
	getch();
}