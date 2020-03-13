//图书管理系统结构体
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

