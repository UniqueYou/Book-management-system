# 图书管理系统
 ##### 简要说明：    
+ 完成时间：2019年暑假    
+ 内容：大一上期C语言程序设计作业，编写的图书馆里系统    
+ 运行环境：Visual C++ 6.0
+ 编码格式为GBK，如果打开中文为乱码请转换成UTF-8  
### 代码片段演示：
```C++
//图书管理系统结构体
//时间
typedef struct timeInfo{
	int year;
	int mouth;
	int day;
	int hour;
	int min;
	int sec;
}TIME;

//读者信息
typedef struct readerInfo{
	char name[30];//姓名
	char no[20];//学号
	char password[16];//密码
	int maxnum;//最大借阅额度
	struct readerInfo * next;
 }READ;

//图书信息
typedef struct book{
	char no[20];//图书编号
	char bookName[50];//图书名
	char author[20];//作者名
	char type[10];//图书类型
	char unit[30];//出版单位	
	float price;//图书单价
	int num;//库存数量
	struct book * next;
}BOOK;

//图书借阅信息
typedef struct bookLend{
	char no[20];//借书学生学号
	char bookno[20];//图书编号
	TIME * remand;//借/还日期
	char condition[10];//借阅状态
	struct bookLend * next;
}LEND;

//管理员登录信息结构体
typedef struct loginInfo{
	int times;//次数
	char username[20];//用户名
	char password[16];//密码
	TIME * logintime;//登录时间
	struct loginInfo * next;
}LOGIN;

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
```  
### 程序部分示例： 
[![YyQ7z6.png](https://s1.ax1x.com/2020/05/15/YyQ7z6.png)](https://imgchr.com/i/YyQ7z6)  
[![Yy1ZnO.png](https://s1.ax1x.com/2020/05/15/Yy1ZnO.png)](https://imgchr.com/i/Yy1ZnO)  
[![Yy1k1x.png](https://s1.ax1x.com/2020/05/15/Yy1k1x.png)](https://imgchr.com/i/Yy1k1x)  
[![Yy1CN9.png](https://s1.ax1x.com/2020/05/15/Yy1CN9.png)](https://imgchr.com/i/Yy1CN9)  
[![Yy1PhR.png](https://s1.ax1x.com/2020/05/15/Yy1PhR.png)](https://imgchr.com/i/Yy1PhR)  
[![Yy1F91.png](https://s1.ax1x.com/2020/05/15/Yy1F91.png)](https://imgchr.com/i/Yy1F91)  
[![Yy1Ac6.png](https://s1.ax1x.com/2020/05/15/Yy1Ac6.png)](https://imgchr.com/i/Yy1Ac6)  
[![Yy1EjK.png](https://s1.ax1x.com/2020/05/15/Yy1EjK.png)](https://imgchr.com/i/Yy1EjK)  
###### 下载链接：  
百度网盘：*https://pan.baidu.com/s/1Mnvyos22QJhj3bq15n8YiQ* 提取码*qvru*  
