/*
	内容:图书管理系统
	作者:王淞
	Email:415582152@qq.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <io.h>//判断文件是否存在
#include <direct.h>
#include "struct.h"
#include "main.h"
#define BUFFER_WIDTH  60//缓冲区宽度
#define BUFFER_LENGTH 2000//缓冲区高度
FILE *fp1=NULL,*fp2=NULL;
int main()
{
	system("color F1");//颜色
	system("mode con cols=60 lines=30");//窗口大小
	system("title 图书管理系统");
	CreateFolder();//创建文件夹储存信息
	menu_windows();
	return 0;
}
//界面
void windows()
{
	HANDLE handle_out;//定义一个句柄
	handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄
	CONSOLE_SCREEN_BUFFER_INFO scbi;    //定义一个窗口缓冲区信息结构体
	COORD size = { BUFFER_WIDTH, BUFFER_LENGTH };
	GetConsoleScreenBufferInfo(handle_out, &scbi);    //获得窗口缓冲区信息	
	SetConsoleScreenBufferSize(handle_out, size);//缓存区的大小设置	
}
//图书管理系统所有的窗口
//系统菜单 
void menu_windows()
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("***********************[图书管理系统]***********************\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n                      [1.管理员入口]                      \n");
	printf("\n                      [2.读者入口]                        \n");
	printf("\n                      [3.退出系统]                        \n\n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:login_windows(); break;
	case 2:reader_loginwindows(); break;
	case 3:exit(0); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		menu_windows();
		break;
	}
}
//管理员界面设置
void administrator_windows()
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("********************[欢迎来到管理员界面]********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.账号信息管理]                      \n");
	printf("                                                            \n");
	printf("                      [2.图书信息管理]                      \n");
	printf("                                                            \n");
	printf("                      [3.读者信息管理]                      \n");
	printf("                                                            \n");
	printf("                      [4.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1: account_windows(); break;
	case 2:book_windows(); break;
	case 3:reader_mgm(); break;
	case 4:login_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		administrator_windows();
		break;
	}
}

//账户信息管理
void account_windows()
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("***********************[账户信息管理]***********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.修改用户名]                        \n");
	printf("                                                            \n");
	printf("                      [2.修改密码]                          \n");
	printf("                                                            \n");
	printf("                      [3.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:change_adminname(); break;
	case 2:change_adminpassword(); break;
	case 3:administrator_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		account_windows();
		break;
	}
}

//管理员登录窗口
void login_windows()
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[管理员登录]************************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.登录账号]                          \n");
	printf("                                                            \n");
	printf("                      [2.忘记密码]                          \n");
	printf("                                                            \n");
	printf("                      [3.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:login_system(); break;
	case 2:password_change(); break;
	case 3:menu_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		login_windows();
		break;
	}
}

//图书管理界面
void book_windows()
{
	BOOK * head = getNode();
	int n;
	book_read(head);
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("***********************[图书信息管理]***********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.图书信息添加]                      \n");
	printf("                                                            \n");
	printf("                      [2.图书信息查询]                      \n");
	printf("                                                            \n");
	printf("                      [3.图书信息修改]                      \n");
	printf("                                                            \n");
	printf("                      [4.图书信息删除]                      \n");
	printf("                                                            \n");
	printf("                      [5.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1: bookLoad_system(head); break;
	case 2: book_inquire(head); break;
	case 3: book_change(head); break;
	case 4: book_delete(head); break;
	case 5:administrator_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		book_windows();
		break;
	}
}

//图书信息查询
void book_inquire(BOOK *head)
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[图书信息查询]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.图书编号查询]                      \n");
	printf("                                                            \n");
	printf("                      [2.图书名查询]                        \n");
	printf("                                                            \n");
	printf("                      [3.图书作者查询]                      \n");
	printf("                                                            \n");
	printf("                      [4.查看所有图书]                      \n");
	printf("                                                            \n");
	printf("                      [5.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:inquire_no(head); book_inquire(head); break;
	case 2:inquire_name(head); book_inquire(head); break;
	case 3:inquire_author(head); book_inquire(head); break;
	case 4:book_output(head);
		system("mode con cols=60 lines=30");//窗口大小
		book_inquire(head); break;
	case 5:book_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		book_inquire(head);
		break;
	}
}

//读者窗口
void reader_windows(char no[])
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*********************[欢迎来到读者界面]*********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                          \n");
	printf("                     [1.借阅查询]                         \n");
	printf("                                                          \n");
	printf("                     [2.图书借阅]                         \n");
	printf("                                                          \n");
	printf("                     [3.图书归还]                         \n");
	printf("                                                          \n");
	printf("                     [4.返回上级菜单]                     \n");
	printf("                                                          \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:lend_inquire(no); break;
	case 2:book_lend(no); break;
	case 3:return_book(no); break;
	case 4:menu_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		reader_windows(no);
		break;
	}
}

//读者登录窗口
void reader_loginwindows()
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*************************[读者登录]*************************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.登录账号]                          \n");
	printf("                                                            \n");
	printf("                      [2.注册账号]                          \n");
	printf("                                                            \n");
	printf("                      [3.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:reader_login(); break;
	case 2:reader_registered(); break;
	case 3:menu_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		reader_loginwindows();
		break;
	}
}

//读者信息管理
void reader_mgm()
{
	int n;
	READ * head = (READ *)malloc(sizeof(READ));
	memset(head, 0, sizeof(READ));
	reader_read(head);
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("**********************[读者信息管理]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.添加读者信息]                      \n");
	printf("                                                            \n");
	printf("                      [2.删除读者信息]                      \n");
	printf("                                                            \n");
	printf("                      [3.修改读者信息]                      \n");
	printf("                                                            \n");
	printf("                      [4.查询读者信息]                      \n");
	printf("                                                            \n");
	printf("                      [5.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:add_reader(); break;
	case 2:delete_reader(head); break;
	case 3:change_readerinfo(head); break;
	case 4:inquire_reader(head); break;
	case 5:administrator_windows(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		reader_mgm();
		break;
	}
}

//查询读者信息
void inquire_reader(READ * head)
{
	int n;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("**********************[查询读者管理]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("                                                            \n");
	printf("                      [1.编号查询]                          \n");
	printf("                                                            \n");
	printf("                      [2.姓名查询]                          \n");
	printf("                                                            \n");
	printf("                      [3.浏览读者信息]                      \n");
	printf("                                                            \n");
	printf("                      [4.返回上级菜单]                      \n");
	printf("                                                            \n");
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	printf("\n\t[请选择]\t·");
	scanf("%d", &n);
	switch (n)
	{
	case 1:inquire_reader_no(head); break;
	case 2:inquire_reader_name(head); break;
	case 3:inquire_reader_all(head); break;
	case 4:reader_mgm(); break;
	default:printf("\t\t输入有误!\n");
		Sleep(1000);
		inquire_reader(head);
		break;
	}
}

//功能实现
//图书管理员登录系统
void login_system()
{
	LOGIN * ch=(LOGIN *)malloc(sizeof(LOGIN));
	memset(ch, 0, sizeof(LOGIN));
	//读入管理员缓存
	ch=login_read();
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*********************[欢迎来到登录界面]*********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	if (ch->times == 0)
	{
		login_registered();
		ch = login_read();
	}
		login_enter(ch->username,ch->password);
		fclose(fp1);
}
//管理员注册
void login_registered()
{	
	system("cls");
	LOGIN * temp = (LOGIN *)malloc(sizeof(LOGIN));
	char temp1[16], temp2[16];//密码输入缓存区
	char username[20];
	memset(temp, 0, sizeof(LOGIN));
	temp->logintime = getTime();
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("***********************[账号注册界面]***********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\n[请设置用户名(长度不大于10位)]\n");
	printf("\n\t\t用户名:\t·");
	while(1)
	{
		fflush(stdin);
		scanf("%s",username);
	if (strlen(username)<20)
	{
		strcpy(temp->username,username);
		break;
	}
	else
	printf("用户名设置有误！请重新输入！\n");
	}
	//设置密码
	printf("[设置密码]\n");
	printf("\t密码格式:\n\t1.长度不大于16个字符;\n\t2.不能使用中文、空格;\n\t3.不能含有非法字符。\n");
	while (1)
	{ 
	printf("\n\t\t密码:\t·");
	scanf("%s",temp1);
	fflush(stdin);
	printf("\t再次输入密码:\t·");
	scanf("%s", temp2);
	if (strcmp(temp1, temp2) == 0)
	{
		printf("------------------------[设置成功]--------------------------\n");
		strcpy(temp->password, temp1);	
		temp->times++;
		Sleep(1000);
		password_setquestion();
		Sleep(1000);
		output_login(temp);
		system("cls");	
		login_system();
		break;
	}
	else
		printf("-------------------[两次输入密码不相等]---------------------\n");
		
	}
}
//管理员登录
void login_enter(char username[],char password[])
{
	int times = 3;
	char temp[16];
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*********************[欢迎来到登录界面]*********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\n\n                        [用户名]:%s\n\n",username);
	printf("\n                        [ 密码 ]:");
	while (times > 0)
	{		
		fflush(stdin);
		scanf("%s",temp);
		if (strcmp(temp,password) == 0)
		{
			printf("\n\n------------------------[登录成功]--------------------------\n");
			printf("\n\n             正在跳转请稍后······\n");
			Sleep(1000);
			administrator_windows();
			break;
		}
		times--;
		if (times == 0)
		{
			printf("\n------------------------[登录失败]--------------------------\n");
			printf("\n\n             正在跳转请稍后······\n");
			Sleep(1000);
			login_windows();
			continue;
		}
		printf("\n-------------------[密码错误,还有%d次机会]-------------------\n", times);
		printf("\n                        [ 密码 ]:");
	}
}


//设置密保问题
void password_setquestion()
{
	LOGIN ch;
	int i;
	memset(&ch, 0, sizeof(LOGIN));
	system("cls");
	printf("\n请选择密保问题(用于找回密码)\n");
	printf("1、您目前的姓名是？\n");
	printf("2、您配偶的生日是？\n");
	printf("3、您的学号（或工号）是?\n");
	printf("4、您母亲的生日是？\n");
	printf("5、您高中班主任的名字是？\n");
	printf("6、您父亲的姓名是？\n");
	printf("7、您小学班主任的名字是？\n");
	printf("8、您父亲的生日是？\n");
	printf("9、您配偶的姓名是？\n");
	printf("10、您初中班主任的名字是？\n");
	printf("11、您最熟悉的童年好友名字是？\n");
	printf("12、您最熟悉的学校宿舍舍友名字是？\n");
	printf("13、对您影响最大的人名字是？\n");
	for (i = 1; i <= 3; i++)
	{
		password_asked(i);
		password_answers(i);
	}
	printf("-------------------------[设置完成]-------------------------\n");
}

//选择密保问题
void password_asked(int num)
{
	int n;
	if (num == 1)
		fp1 = fopen("Data\\FindPassword_Qusetion.txt", "w");
	else
		fp1 = fopen("Data\\FindPassword_Qusetion.txt", "a");
	printf("\n请选择第%d个密保问题:>>\t", num);
	scanf("%d", &n);
	while (n<0||n>13)
	{
		printf("选择有误!请重新输入\n");
		scanf("%d", &n);
	}
	switch (n)
	{
	case 1:fprintf(fp1, "%s", "您目前的姓名是？\t"); break;
	case 2:fprintf(fp1, "%s", "您配偶的生日是？\t"); break;
	case 3:fprintf(fp1, "%s", "您的学号（或工号）是\t"); break;
	case 4:fprintf(fp1, "%s", "您母亲的生日是？\t"); break;
	case 5:fprintf(fp1, "%s", "您高中班主任的名字是？\t"); break;
	case 6:fprintf(fp1, "%s", "您父亲的姓名是？\t"); break;
	case 7:fprintf(fp1, "%s", "您小学班主任的名字是？\t"); break;
	case 8:fprintf(fp1, "%s", "您父亲的生日是？\t"); break;
	case 9:fprintf(fp1, "%s", "您配偶的姓名是？\t"); break;
	case 10:fprintf(fp1, "%s", "您初中班主任的名字是？\t"); break;
	case 11:fprintf(fp1, "%s", "您最熟悉的童年好友名字是？\t"); break;
	case 12:fprintf(fp1, "%s", "您最熟悉的学校宿舍舍友名字是？\t"); break;
	case 13:fprintf(fp1, "%s", "对您影响最大的人名字是？\t"); break;
	}
	fclose(fp1);
}

//密保问题答案
void password_answers(int num)
{
	char str[30];
	memset(str, 0, sizeof(str));
	if (num == 1)
		fp1 = fopen("Data\\FindPassword_Answers.txt", "w");
	else
		fp1 = fopen("Data\\FindPassword_Answers.txt", "a");
	fflush(stdin);
	printf("请设置密保答案:\t>>");
	gets(str);
	fprintf(fp1, "%s\t",str);
	fclose(fp1);
}
//忘记密码通过密保问题修改密码
void password_change()
{
	int times = 0,i;
	char answer[3][30],qustion[3][30],temp[30];
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("*************************[找回密码]*************************\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	if (!access("Data\\FindPassword_Qusetion.txt", 0))//如果文件存在)
	{
		fp1 = fopen("Data\\FindPassword_Qusetion.txt", "r");
		fp2 = fopen("Data\\FindPassword_Answers.txt", "r");
		for (i = 0; i < 3; i++)
		{
			fscanf(fp1, "%s", answer[i]);
			fscanf(fp2, "%s", qustion[i]);
			printf("\n%d、%s\n", i + 1, answer[i]);
			printf("\n\t输入答案:\t·");
			scanf("%s", temp);
			if (strcmp(temp, qustion[i]) == 0)
				times++;
		}
		if (times == 3)
		{
			printf("\n-------------------------[验证成功]-------------------------\n");
			Sleep(1000);
			//修改密码
			login_registered();
		}
		else
		{
			printf("\n-------------------------[验证失败]-------------------------\n");
			Sleep(1000);
			login_windows();
		}
		fclose(fp1);
		fclose(fp2);
	}
	else
	{
		printf("\n---------------------[请先创建一个账号]---------------------\n");
		Sleep(1500);
		login_registered();
	}
}

//缓存管理员登录信息
//(输出管理员的登录信息到文件中)
void output_login(LOGIN * info)
{
	fp1 = fopen("Data\\LoginInfo_Administrator.txt", "w");
	fprintf(fp1, "%d\t%s\t%s\t", info->times, info->username, info->password);
	fprintf(fp1, "%d\t%d\t%d\t", info->logintime->year, info->logintime->mouth, info->logintime->day);
	fprintf(fp1, "%d\t%d\t%d\t\n", info->logintime->hour, info->logintime->min, info->logintime->sec);
	fclose(fp1);
}

//读取管理员的登录信息
LOGIN * login_read()
{
	LOGIN * temp=(LOGIN *)malloc(sizeof(LOGIN));
	memset(temp,0,sizeof(temp));
	if(!access("Data\\LoginInfo_Administrator.txt",0))//如果文件存在
	{
		fp1 = fopen("Data\\LoginInfo_Administrator.txt", "r");
		fscanf(fp1, "%d%s%s", &temp->times, temp->username, temp->password);
	}
	else	fp1=fopen("Data\\LoginInfo_Administrator.txt", "w");		
	return temp;
}

//修改管理员用户名
void change_adminname()
{
	LOGIN * temp = login_read();
	temp->logintime = getTime();
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*************************[用户名修改]***********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("[请输入修改后的用户名]\n");
	printf("\n\t\t用户名:\t·");
	scanf("%s", temp->username);
	printf("\n-------------------------[修改成功]-------------------------\n");
	Sleep(1000);
	output_login(temp);
	account_windows();
}
//修改管理员密码
void change_adminpassword()
{
	LOGIN * temp = login_read();
	temp->logintime = getTime();
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("**************************[密码修改]************************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("[请输入修改后的密码]\n");
	printf("\n\t\t密码:\t·");
	scanf("%s", temp->password);
	printf("\n-------------------------[修改成功]-------------------------\n");
	Sleep(1000);
	output_login(temp);
	account_windows();	
}
//获取系统的时间
TIME * getTime()
{
	TIME * nowtime = (TIME *)malloc(sizeof(TIME));
	time_t timep;
	struct tm * p;
	memset(nowtime, 0, sizeof(TIME));	
	time(&timep);
	p = gmtime(&timep);
	nowtime->year = p->tm_year+1900;//年
	nowtime->mouth = p->tm_mon+1;//月
	nowtime->day = p->tm_mday;//日
	nowtime->hour = p->tm_hour+8;//时
	nowtime->min = p->tm_min;//分
	nowtime->sec = p->tm_sec;//秒
	return nowtime;
}

//有序录入图书
void onebookLoad(BOOK * head)
{
	BOOK * p = head;
	BOOK * newbook = getNode();
	system("cls");
	printf("\n请输入图书信息\n");
	printf("[图书编号]·");
	scanf("%s", newbook->no);
	printf("[图书类型]·");
	scanf("%s", newbook->type);
	printf("[图书名]  ·");
	scanf("%s", newbook->bookName);
	printf("[作者名]  ·");
	scanf("%s", newbook->author);
	printf("[出版单位]·");
	scanf("%s", newbook->unit);
	printf("[图书单价]·");
	scanf("%f", &newbook->price);
	printf("[库存数量]·");
	scanf("%d", &newbook->num);
	while (p->next != NULL&&strcmp(p->next->no, newbook->no)<0)
		p = p->next;
	newbook->next = p->next;
	p->next =newbook;
	printf("图书录入成功!");
}

//图书录入系统
void bookLoad_system(BOOK * head)
{
	char temp;
	while (1)
	{
		onebookLoad(head);
		fflush(stdin);
		printf("\n是否继续录入图书\nY、是\tN、否  \n");
		scanf("%c", &temp);
		if (temp == 'n' || temp == 'N')
			break;
	}
	book_save(head);
	book_windows();
}

//创建一个节点
BOOK* getNode()
{
	BOOK * p = (BOOK *)malloc(sizeof(BOOK));
	memset(p, 0, sizeof(BOOK));
	return p;
}

//输出所有的图书信息
void book_output(BOOK* head)
{
	BOOK* p = head->next;
	system("cls");
	windows();
	printf("\n[图书信息如下]\n");	
	while (p != NULL)
	{
		onebook_output(p);
		p = p->next;
	}
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	book_inquire(head);
}
//保存图书信息
void book_save(BOOK * head)
{
	BOOK * p =head->next;
	fp1 = fopen("Data\\BookInfo.txt", "w");
	while (p != NULL)
	{
		fprintf(fp1,"%s %s %s %s %s %.1f %d\n", p->no, p->type, p->bookName, p->author, p->unit, p->price, p->num);
		p = p->next;
	}
	fclose(fp1);
}
//读取文件缓存
void book_read(BOOK  *head)
{
	BOOK  *p = NULL;
	BOOK  *tail = head;
	if (!access("Data\\BookInfo.txt", 0))//如果文件存在
	{
		fp1 = fopen("Data\\BookInfo.txt", "r");
		while (!feof(fp1))
		{
			p = getNode();
			if ((fscanf(fp1, "%s%s%s%s%s%f%d\n", p->no, p->type, p->bookName, p->author, p->unit, &p->price, &p->num)) != 0)
			{
				tail->next = p;
				tail = p;		
			}
			else
				free(p);
		}
		tail->next = NULL;
		fclose(fp1);
	}	
}
//输出一本图书的信息(管理员查看详细信息)
void onebook_output(BOOK * p)
{
	printf("\n[图书编号] ");
	printf("%s\n", p->no);
	printf("[图书类型] ");
	printf("%s\n", p->type);
	printf("[图书名]   ");
	printf("%s\n", p->bookName);
	printf("[作者名]   ");
	printf("%s\n", p->author);
	printf("[出版单位] ");
	printf("%s\n", p->unit);
	printf("[图书单价] ");
	printf("%.1f（元）\n", p->price);
	printf("[库存数量] ");
	printf("%d\n\n", p->num);
}

//查询图书
//图书编号查询
void inquire_no(BOOK * head)
{
	BOOK * p=head->next;
	char no[20];
	int flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[图书编号查询]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("[输入查询的编号]·");
	scanf("%s", no);
	for (;p!=NULL; p = p->next)
	{
		if ((strcmp(no, p->no)) == 0)
		{		
			onebook_output(p);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
}
//图书名查询
void inquire_name(BOOK * head)
{
	BOOK * p = head->next;
	char name[50];
	int flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*************************[图书名查询]***********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("[输入查询的图书名]·");
	scanf("%s", name);
	for (; p != NULL; p = p->next)
	{
		if ((strcmp(name, p->bookName)) == 0)
		{
			flag = 1;
			onebook_output(p);
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
}

//图书作者查询
void inquire_author(BOOK * head)
{
	BOOK * p = head->next;
	char author[20];
	int flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[图书作者查询]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("[输入查询的作者名]·");
	scanf("%s", author);
	for (; p != NULL; p = p->next)
	{
		if ((strcmp(author, p->author)) == 0)
		{
			onebook_output(p);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
}

//图书信息修改
void book_change(BOOK * head)
{
	BOOK * p = head->next;
	char no[20];
	int flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[图书信息修改]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("\n[输入修改图书的编号]·");
	scanf("%s", no);
	for (; p != NULL; p = p->next)
	{
		if ((strcmp(no, p->no)) == 0)
		{
			printf("\n请输入修改后的图书信息\n");
			printf("\n[图书编号]·");
			scanf("%s", p->no);
			printf("[图书类型]·");
			scanf("%s", p->type);
			printf("[图书名]  ·");
			scanf("%s", p->bookName);
			printf("[作者名]  · ");
			scanf("%s", p->author);
			printf("[出版单位]·");
			scanf("%s", p->unit);
			printf("[图书单价]·");
			scanf("%f", &p->price);
			printf("[库存数量]·");
			scanf("%d", &p->num);
			book_save(head);
			printf("\n-------------------------[修改成功]-------------------------\n");
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
}

//图书信息删除
void book_delete(BOOK * head)
{
	BOOK * p = head;
	BOOK * temp = NULL;
	char no[20],ch;
	int flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[图书信息删除]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("\n[输入删除图书的编号]·");
	scanf("%s", no);
	while (p->next != NULL)
	{
		if ((strcmp(no, p->next->no)) == 0)
		{
			fflush(stdin);
			onebook_output(p->next);
			printf("确定删除该图书\nY、确认\tN、取消\n");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				temp = p->next;
				p->next = temp->next;
				free(temp);
				printf("\n-------------------------[删除成功]-------------------------\n");
				book_save(head);
				flag++;
			}
			else
			{
					printf("\n按回车键返回···\n");
					fflush(stdin);
					getchar();
					book_inquire(head);
			}

		}
		else
			p = p->next;
	}
	if (flag == 0)
		printf("\n-------------------------[没有找到]-------------------------\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	book_inquire(head);
}
//读者功能管理


//图书借阅
void book_lend(char no[])
{
	int flag = 0;
	BOOK * head = getNode(), *p = NULL;
	READ * newhead = (READ *)malloc(sizeof(READ));
	LEND * temp =(LEND *)malloc(sizeof(LEND));	
	memset(newhead, 0, sizeof(READ));
	reader_read(newhead);//读取读者信息
	book_read(head);//读取图书信息
	strcpy(temp->no, no);
	strcpy(temp->condition, "未归还");
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*************************[图书借阅]***********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("[输入图书的编号]·");
	scanf("%s", temp->bookno);
	temp->remand = count_remand();//计算还书日期
	for (p=head->next; p != NULL; p = p->next)
	{
		if ((strcmp(temp->bookno, p->no)) == 0 && p->num>0)
		{
			flag = 1;
			if (lend_credit(no, newhead))
			{
				onebook_output(p);
				booksum_change(head, temp->bookno, 1);//减少图书库存
				lendsum_change(no,newhead,1);//减少用户额度
				lend_save(temp);//保存图书借阅信息
				printf("图书借阅成功！");
			}
			else
			{
				printf("\n\n抱歉,你的借阅额度不足了,每个人做多只能借10本哟`-`\n");
				continue;
			}	
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_windows(no);
}


//修改读者最大借阅额度
void lendsum_change(char no[], READ * head,int n)
{
	READ * p = head->next;
	for (; p != NULL; p = p->next)
	{
		if (strcmp(p->no, no) == 0)
		{
			switch (n){
			case 1:p->maxnum--; break;
			case 2:p->maxnum++; break;
			}			
		}
	}
	reader_save(head);
}

//修改图书库存
void booksum_change(BOOK * head,char no[],int n)
{
	BOOK * p = head;
	for (; p != NULL; p = p->next)
	{
		if (strcmp(p->no, no) == 0)
		{
			switch (n){
			case 1:p->num--; break;
			case 2:p->num++; break;
			}
		}
	}
	book_save(head);
}

//保存读者信息
void reader_save(READ * head)
{
	READ * p = head->next;
	fp1 = fopen("Data\\ReaderInfo.txt", "w");
	while (p != NULL)
	{
		fprintf(fp1, "%s\t%s\t%s\t%d\n",p->name,p->no,p->password,p->maxnum);
		p = p->next;
	}
	fclose(fp1);
}
//检查信用额度
int lend_credit(char no[],READ * head)
{
	READ * p = head->next;
	for (; p != NULL; p = p->next)
	{
		if (strcmp(no, p->no) == 0 && p->maxnum > 0)
			return 1;
	}
	return 0;
}


//计算还书日期，还书期限为一个月
TIME * count_remand()
{
	TIME * p = getTime();
	switch (p->mouth)//计算日
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (p->day != 1)
			p->day--;break;	
	case 2:p->day++; break;
	}
	if (p->mouth == 12)//计算年份
		p->year++;
	p->mouth = (p->mouth++) % 12;//计算月份
	if (p->year % 4 == 0 && p->year % 100 != 0 || p->year % 400 == 0)//如果是闰年
		if (p->mouth == 3)
			p->day++;
	return p;
}

//保存图书借阅信息
void lend_save(LEND * temp)
{
	if (!access("Data\\LendInfo.txt", 0))//如果文件存在
		fp1 = fopen("Data\\LendInfo.txt", "a");
	else
		fp1 = fopen("Data\\LendInfo.txt", "w");
	fprintf(fp1,"%s %s %d %d %d %s\n", temp->no, temp->bookno, temp->remand->year, temp->remand->mouth, temp->remand->day, temp->condition);
	fclose(fp1);
}

//学生在借图书查询
void lend_inquire(char no[])
{
	LEND * head = (LEND *)malloc(sizeof(LEND));
	memset(head, 0, sizeof(LEND));
	lend_read(head);
	lend_output(no, head);
}
//图书借阅文件读取
void lend_read(LEND  *head)
{
	LEND * tail = head;
	LEND *p = NULL;
	if (!access("Data\\LendInfo.txt", 0))//如果文件存在
	{
		fp1 = fopen("Data\\LendInfo.txt", "r");
		while (!feof(fp1))
		{
			p = (LEND *)malloc(sizeof(LEND));
			memset(p, 0, sizeof(LEND));
			p->remand = (TIME *)malloc(sizeof(TIME));
			if ((fscanf(fp1, "%s%s%d%d%d%s\n", p->no,p->bookno,&p->remand->year,&p->remand->mouth,&p->remand->day,p->condition)) != 0)
			{
				tail->next = p;
				tail = p;
			}
			else
				free(p);
		}
		tail->next = NULL;
		fclose(fp1);
	}
}

//输出借阅信息
void lend_output(char no[],LEND * head)
{
	LEND * p = head->next;
	int flag = 0,times=0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[在借图书查询]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("欢迎%s^-^\n\n", no);
	printf("[您的图书借阅情况如下]\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("图书编号\t还书日期\t借阅状态\n");
	for (; p != NULL; p = p->next)
	{
		if ((strcmp(no, p->no)) == 0 && strcmp(p->condition,"未归还")==0)
		{
			printf("%s\t\t%d-%d-%d\t%s\n",p->bookno, p->remand->year, p->remand->mouth, p->remand->day, p->condition);
			flag = 1;
			if (strcmp("未归还",p->condition)==0)
			times++;
		}
	}
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\t\t\t\t\t共%d本未归还\n\n", times);
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_windows(no);
}

//读者登录
void reader_login()
{
	char no[20], password[16];
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*********************[欢迎来到登录界面]*********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("\n\n                        [ 学号 ]:");
	scanf("%s",no);
	printf("\n                        [ 密码 ]:");
	scanf("%s", password);
	if (reader_enter(no, password))
	{
		printf("\n\n------------------------[登录成功]--------------------------\n");
		printf("\n\n             正在跳转请稍后······\n");
		Sleep(1000);
		reader_windows(no);
	}
	else
	{
		printf("\n\n             正在跳转请稍后······\n");
		Sleep(1000);
		menu_windows();
	}
}
//检查登录信息是否正确
int reader_enter(char no[],char password[])
{
	READ * head = (READ *)malloc(sizeof(READ));
	READ * p = NULL;
	memset(head, 0, sizeof(READ));
	p = head;
	reader_read(head);	
	for (; p != NULL; p = p->next)
	{
		if ((strcmp(no, p->no)) == 0 && strcmp(password, p->password) == 0)
		{
			return 1;
		}
	}
	printf("\n\n--------------------[用户名或密码错误]----------------------\n\n");
	return 0;
}

//读者注册
void reader_registered()
{
	READ * newhead = (READ  *)malloc(sizeof(READ));
	READ * head = (READ *)malloc(sizeof(READ));
	READ * p = head;
	memset(head, 0, sizeof(READ));
	reader_read(head);
	memset(newhead, 0, sizeof(READ));
	newhead->maxnum = 10;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*************************[读者注册]*************************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("[请填写以下信息]\n\n");
	printf("[姓名]:");
	scanf("%s", newhead->name);
	printf("[学号]:");
	scanf("%s", newhead->no);
	printf("[密码(少于16位)]:");
	scanf("%s", newhead->password);
	for (; p != NULL; p = p->next)
	{
		if ((strcmp(newhead->no, p->no)) == 0 )
		{
			printf("\n\n----------------------[该用户已存在]------------------------\n");
			Sleep(1000);
			reader_registered();
		}
	}
	onereader_save(newhead);
	reader_login();
}


//保存个人读者信息
void onereader_save(READ * temp)
{
	temp->maxnum = 10;
	if (!access("Data\\ReaderInfo.txt", 0))//如果文件存在
		fp1 = fopen("Data\\ReaderInfo.txt", "a");
	else
		fp1 = fopen("Data\\ReaderInfo.txt", "w");
	fprintf(fp1, "%s\t%s\t%s\t%d\n",temp->name,temp->no,temp->password,temp->maxnum);
	fclose(fp1);
}


//读取读者信息
void reader_read(READ * head)
{
	READ * tail=head;
	READ *p = NULL;
	if (!access("Data\\ReaderInfo.txt", 0))//如果文件存在
	{
		fp1 = fopen("Data\\ReaderInfo.txt", "r");
		while (!feof(fp1))
		{
			p = (READ *)malloc(sizeof(READ));
			memset(p, 0, sizeof(READ));
			if ((fscanf(fp1, "%s%s%s%d\n",p->name,p->no,p->password,&p->maxnum)) != 0)
			{
				tail->next = p;
				tail = p;
			}
			else
				free(p);
		}
		tail->next = NULL;
		fclose(fp1);
	}
}

//图书归还
void return_book(char no[])
{
	BOOK * head = getNode(), *p = NULL;
	READ * newhead = (READ *)malloc(sizeof(READ));
	char bookno[20];
	int flag = 0;
	memset(newhead, 0, sizeof(READ));
	reader_read(newhead);//读取读者信息
	book_read(head);//读取图书信息
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("*************************[图书借阅]***********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("[输入图书的编号]·");
	scanf("%s",bookno);
	for (p = head->next; p != NULL; p = p->next)
	{
		if ((strcmp(bookno, p->no)) == 0 && flag!=1)
		{
				flag = 1;
				onebook_output(p);
				booksum_change(head,bookno, 2);//增加图书库存
				lendsum_change(no, newhead, 2);//增加用户额度
				onebook_return(no, bookno);
				printf("图书归还成功！");
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_windows(no);
}
//图书归还后清除借书记录
void onebook_return(char no[], char bookno[])
{
	LEND * head = (LEND *)malloc(sizeof(LEND));
	LEND * p = head, *temp = NULL;
	memset(head, 0, sizeof(LEND));
	lend_read(head);
	fp1 = fopen("Data\\LendInfo.txt","w");
	while (p->next != NULL)
	{
		if (strcmp(p->next->bookno, bookno) == 0 && strcmp(p->next->no, no) == 0)
		{
			temp = p->next;
			p->next = temp->next;
			free(temp);
			break;
		}
		else
			p = p->next;
	}
	fclose(fp1);
	for (p = head->next; p != NULL; p = p->next)
		lend_save(p);
}

//管理员修改读者信息
void change_readerinfo(READ * head)
{
	READ * p = head;
	int flag = 0;
	char no[20];
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("**********************[修改读者信息]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("请输入想要修改的学生编号\n");
	scanf("%s", no);
	for (; p != NULL; p = p->next)
	{
		if (strcmp(p->no, no) == 0)
		{
			printf("已经找到该学生\n");
			printf("[姓名]:%s\n", p->name);
			printf("[学号]:%s\n", p->no);
			printf("[密码]:%s\n", p->password);
			printf("[最大借阅额度]:%d\n\n", p->maxnum);
			printf("请输入修改后的信息\n");
			printf("[姓名]:");
			fflush(stdin);
			scanf("%s", p->name);
			printf("[学号]:");
			fflush(stdin);
			scanf("%s", p->no);
			printf("[密码]:");
			scanf("%s", p->password);
			printf("[最大借阅额度]");
			scanf("%d", &p->maxnum);
			flag = 1;
			reader_save(head);
		}
	}
	if (flag == 1)
		printf("修改成功!\n");
	else
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_mgm();
}

//增加读者信息
void add_reader()
{
	READ * newhead = (READ  *)malloc(sizeof(READ));
	READ * head = (READ *)malloc(sizeof(READ));
	READ * p = head;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("**********************[增加读者信息]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	memset(head, 0, sizeof(READ));
	reader_read(head);
	memset(newhead, 0, sizeof(READ));
	newhead->maxnum = 10;
	printf("[请填写以下信息]\n\n");
	printf("[姓名]:");
	scanf("%s", newhead->name);
	printf("[学号]:");
	scanf("%s", newhead->no);
	printf("[密码(少于16位)]:");
	scanf("%s", newhead->password);
	for (; p != NULL; p = p->next)
	{
		if ((strcmp(newhead->no, p->no)) == 0)
		{
			printf("\n\n----------------------[该用户已存在]------------------------\n");
			Sleep(1000);
			add_reader();
		}
	}
	onereader_save(newhead);
	printf("\n\n----------------------[读者添加成功]------------------------\n");
	Sleep(1000);
	reader_mgm();
}
//删除读者信息
void delete_reader(READ * head)
{
	READ * p = head;
	READ * temp = NULL;
	char no[20], ch;
	int flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[删除读者信息]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("\n[输入删除读者的编号]·");
	scanf("%s", no);
	while (p->next != NULL)
	{
		if ((strcmp(no, p->next->no)) == 0)
		{
			fflush(stdin);
			printf("[姓名]:%s\n", p->next->name);
			printf("[学号]:%s\n", p->next->no);
			printf("[密码]:%s\n", p->next->password);  
			printf("[最大借阅额度]:%d\n\n", p->maxnum);
			printf("确定删除该读者\nY、确认\tN、取消\n");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				temp = p->next;
				p->next = temp->next;
				free(temp);
				printf("\n-------------------------[删除成功]-------------------------\n");
				reader_save(head);
				flag++;
			}
		}
		else
			p = p->next;
	}
	if (flag == 0)
		printf("\n-------------------------[没有找到]-------------------------\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_mgm();
}
//编号查询
void inquire_reader_no(READ * head)
{
	READ * p = head->next;
	char no[20];
	int	flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[编号查询]************************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("请输入想要查询的学生编号\n");
	scanf("%s", no);
	for (; p != NULL; p = p->next)
	{
		if (strcmp(no, p->no) == 0)
		{
			flag = 1;
			printf("[姓名]:%s\n", p->name);
			printf("[学号]:%s\n", p->no);
			printf("[密码]:%s\n", p->password);
			printf("[最大借阅额度]:%d\n\n", p->maxnum);
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_mgm();  
}
//姓名查询
void inquire_reader_name(READ * head)
{
	READ * p = head->next;
	char name[30];
	int	flag = 0;
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("************************[姓名查询]************************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	printf("请输入想要查询的学生姓名\n");
	scanf("%s", name);
	for (; p != NULL; p = p->next)
	{
		if (strcmp(name, p->name) == 0)
		{
			flag = 1;
			printf("[姓名]:%s\n", p->name);
			printf("[学号]:%s\n", p->no);
			printf("[密码]:%s\n", p->password);
			printf("[最大借阅额度]:%d\n\n", p->maxnum);
		}
	}
	if (flag == 0)
		printf("没有找到!\n");
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_mgm();
}
//查看所有读者
void inquire_reader_all(READ * head)
{
	READ * p = head->next;
	windows();
	system("cls");
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	printf("**********************[浏览图书信息]**********************");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n\n");
	for (; p != NULL; p = p->next)
	{
		printf("[姓名]:%s\n", p->name);
		printf("[学号]:%s\n", p->no);
		printf("[密码]:%s\n", p->password);
		printf("[最大借阅额度]:%d\n\n", p->maxnum);
		printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	}
	printf("\n按回车键返回···\n");
	fflush(stdin);
	getchar();
	reader_mgm();
}

//创建文件夹
void CreateFolder()
{
	//文件夹名称
	char folderName[] = "Data";
	// 文件夹不存在则创建文件夹
	if (_access(folderName, 0) == -1)
	{
		_mkdir(folderName);
	}
}
