/*
	文件名称：工资管理系统.cpp
	完成日期：2018-07-03
	作者：陈云清
	班级:17软件
	学号：117583010104
*/

#include "stdio.h"	  //包含头文件
#include "conio.h"	  //包含getch()及getche()函数
#include "string.h"	  //包含字符串相关函数
#include "windows.h"  //包含Sleep()函数
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

//读取职工工资数据
	
void read()		//从文件gz.dat中读取职工工资的数据到数组zggz中
{
	FILE *file;	//声明文件指针

	if((file=fopen("gz.dat","rb"))==NULL)   //以二进制方式打开职工工资数据文件并判断是否失败
	{
		printf("\n\n\t职工工资数据文件为空! ");
		printf("\n\n\t请按任意键进入主菜单……");
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
		printf("\n\t3秒钟后继续…… \n",n);
		n--;	//计算出职工数据的总数
		Sleep(3000);	//设置延时3秒钟
	}
}

//保存职工工资数据

void write()      //向职工工资数据文件中写入数据
{
	FILE *file;	  //声明文件指针

	if(n==-1)  	  //当职工人数为0时
	{
		printf("无数据可存! 按任意键返回主菜单。\n");
		getch();
		return;
	}
	if((file=fopen("gz.dat","wb"))!=NULL)    //以二进制方式打开职工工资数据文件并进行判断是否失败
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,file);    //把所有记录一次写入文件
		fclose(file);	 //关闭文件指针
		printf("\n\n\t\t%d条职工记录保存完毕! \n",n+1 );
	}
	else	//当文件打开不成功时
		printf("\t\t无法打开职工工资数据文件! \n");
		printf("\n\t\t按任意键返回主菜单……");
	getch();
}

//查询职工工资数据

void find()
{
	char gonghao[10];    //接收职工工号字符数组
	int i;	

	if(n==-1)   //人数为0说明工资记录尚未添加
	{
		printf("\n\n\t\t当前还没有职工工资记录，按任意键返回主菜单……");
		getch();
		return;
	}

	printf("\t请输入职工工号：");    //提示信息
	gets(gonghao);        //从键盘读取字符串

	for(i=0;i<=n;i++)    //在职工总数范围内循环查找
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)   //比较并找到
		{
			printf("\n  该职工工资情况如下：");
			printf("\n  ===================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","工号","姓名","岗位工资","薪级工资","职务津贴");
			printf("%-9s%-9s%8s%9s\n","绩效工资","应发工资","所得税","实发工资");

			printf("%-6s%-6s%8.2f",zggz[i].gonghao,zggz[i].name,zggz[i].gwgz);
			printf("%9.2f%9.2f",zggz[i].xjgz,zggz[i].zwjt);
			printf("%9.2f%9.2f",zggz[i].jxgz,zggz[i].yfgz);
			printf("%9.2f%9.2f\n",zggz[i].grsds,zggz[i].sfgz);
			printf("\n 按任意键返回主菜单……");
			getch();
			break;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t您所输入的职工工号有误或不存在! ");
		printf("按任意键返回主菜单……");
		getch();
		return;
	}
}

//浏览职工工资数据

void list()
{
	int i;
	system("cls");
	printf("\n\n\t\t\t 全体职工工资情况如下\n");
	printf("\t\t\t======================\n\n");

	printf("%-6s%-6s%-9s%-9s%-9s","工号","姓名","岗位工资","薪级工资","职务津贴");
	printf("%-9s%-9s%8s%9s\n","绩效工资","应发工资","所得税","实发工资");

	for(i=0;i<=n;i++)
	{
		printf("%-6s%-6s%8.2f",zggz[i].gonghao,zggz[i].name,zggz[i].gwgz);
		printf("%9.2f%9.2f",zggz[i].xjgz,zggz[i].zwjt);
		printf("%9.2f%9.2f",zggz[i].jxgz,zggz[i].yfgz);
		printf("%9.2f%9.2f\n",zggz[i].grsds,zggz[i].sfgz);

	}
	printf("  按任意键返回主菜单……");
	getch();
	return;
}

//修改职工工资数据

void modify()
{
	char gonghao[10];    //接收职工工号字符数组
	
	int i;	   //循环变量

	if(n==-1)    //当人数为0说明工资记录未添加
	{
		printf("\n\n\t\t当前还没有职工工资记录，按任意键返回主菜单……");
		getch();
		return;
	}

	printf("\t请输入职工工号：");    //提示信息
	gets(gonghao);      //从键盘读取字符串

	for(i=0;i<=n;i++)   //在职工总数范围内循环查找
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)   //比较并找到
		{
			//显示出该职工工资情况
			printf("\n\t\t\t  该职工工资情况如下：");
			printf("\n\t\t\t  ===================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","工号","姓名","岗位工资","薪级工资","职务津贴");
			printf("%-9s%-9s%8s%9s\n","绩效工资","应发工资","所得税","实发工资");
			printf("%-6s%-6s%8.2f",zggz[i].gonghao,zggz[i].name,zggz[i].gwgz);
			printf("%9.2f%9.2f",zggz[i].xjgz,zggz[i].zwjt);
			printf("%9.2f%9.2f",zggz[i].jxgz,zggz[i].yfgz);
			printf("%9.2f%9.2f\n",zggz[i].grsds,zggz[i].sfgz);

			//接收该职工新的工资数据
			printf("\n\t\t请输入该职工新的岗位工资：");
			scanf("%f",&zggz[i].gwgz);
			printf("\t\t请输入该职工新的薪级工资：");
			scanf("%f",&zggz[i].xjgz);
			printf("\t\t请输入该职工新的职务津贴：");
			scanf("%f",&zggz[i].zwjt);
			printf("\t\t请输入该职工新的绩效工资：");
			scanf("%f",&zggz[i].jxgz);

			//计算应发工资、个人所得税、实发工资
			zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz;
			zggz[i].grsds=grsds(zggz[i].yfgz);
			zggz[i].sfgz=zggz[i].yfgz-zggz[i].grsds;
			//同屏显示计算结果
			printf("\n\t\t该职工的应发工资额是：%f",zggz[i].yfgz);
			printf("\n\t\t该职工的个人所得税是：%f",zggz[i].grsds);
			printf("\n\t\t该职工的实发工资额是：%f",zggz[i].sfgz);

			printf("\n\n\t\t该职工工资数据修改成功！按任意键返回主菜单……");
			getch();
			return;
		}
	}
	printf("\n\t\t您所输入的职工工号有误或不存在! ");
	printf("按任意键返回主菜单……");
	getch();
	return;
}

//从职工工资数据文件中增加记录

void add()
{
	printf("\t请输入职工工号：");
	fflush(stdin);  	//清除键盘缓冲区
	gets(zggz[++n].gonghao);
	printf("\t\t\t\t请输入职工姓名：");
	gets(zggz[n].name);
	printf("\n\t\t\t\t请输入该职工新的岗位工资：");
	scanf("%f",&zggz[n].gwgz);
	printf("\t\t\t\t请输入该职工新的薪级工资：");
	scanf("%f",&zggz[n].xjgz);
	printf("\t\t\t\t请输入该职工新的职务津贴：");
	scanf("%f",&zggz[n].zwjt);
	printf("\t\t\t\t请输入该职工新的绩效工资：");
	scanf("%f",&zggz[n].jxgz);

	//计算应发工资、个人所得税、实发工资
	zggz[n].yfgz=zggz[n].gwgz+zggz[n].xjgz+zggz[n].zwjt+zggz[n].jxgz;


	                                 
        zggz[n].grsds=grsds(zggz[n].yfgz);           //计算个人所得税



	zggz[n].sfgz=zggz[n].yfgz-zggz[n].grsds;
	//输出以上计算内容
	printf("\n\t\t\t\t该职工的应发工资额是：%f",zggz[n].yfgz);
	printf("\n\t\t\t\t该职工的个人所得税是：%f",zggz[n].grsds);
	printf("\n\t\t\t\t该职工的实发工资额是：%f",zggz[n].sfgz);

	printf("\n\n\t\t\t\t按任意键返回……");
	getch();
}

//从职工工资数据文件中删除记录

void del()
{
	char gonghao[10];    //接收职工工号字符数组
	int i,j;	
	char d;		         //接收确认删除字符：y/n

	printf("\t请输入待删除职工工号：");
	gets(gonghao);
	for(i=0;i<=n;i++)    //在职工总数范围内循环查找
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)     //比较并找到
		{
			printf("\n\t\t你确认要删除%s号职工工资信息吗(y/n)？",zggz[i].gonghao);
			d=getche();
			if(d=='y'||d=='Y')    //确认删除
			{
				if(i==n)       //如果是最后一条记录
					n--;
				else	       //如果不是最后一条记录
				{
					for(j=i;j<=n;j++)    //从该记录开始后续更新前一条记录
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
				printf("\n\n\t\t该职工记录成功删除，按任意键返回主菜单……");
				getch();
				break;
			}
			else	//不删除该记录
			{
				printf("\n\n\t\t你选择了不删除该职工记录，按任意键返回主菜单……");
				getch();
				return;
			}
		}
	}
	if(i==n+1)	//未找到对应工号
	{
		printf("\n\t\t本单位无此工号，按任意键返回主菜单……");
		getch();
	}
}


//计算个人所得税

float grsds(float m)
{
	float x;    	//当月应纳税所得额
	float y=0;	    //当月应纳税额
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