
//管理员登陆图书管理系统
void login_system();
void login_registered();
void login_enter(char user[], char password[]);
void output_login(LOGIN * head);
TIME * getTime();
//窗口
void account_windows();
void login_windows();
void administrator_windows();
void menu_windows();
void book_windows();
void windows();
void reader_windows(char no[]);
//找回密码
LOGIN * login_read();
void password_asked(int num);
void password_setquestion();
void password_answers(int num);
void password_change();
void reset_system();
void change_adminname();
void change_adminpassword();
//图书管理
//图书录入
void onebookLoad(BOOK * head);
void bookLoad_system(BOOK * head);
BOOK* getNode();
void book_output(BOOK* info);
void book_save(BOOK * head);
void book_read(BOOK  *head);
//图书查询
void onebook_output(BOOK * p);
void book_inquire(BOOK *head);
void inquire_no(BOOK * head);
void inquire_name(BOOK * head);
void inquire_author(BOOK * head);
void book_change(BOOK * head);
void book_delete(BOOK * head);
//图书借阅
void book_lend(char no[]);
void lend_inquire(char no[]);
TIME * count_remand();
void lend_read(LEND  *head);
void lend_save(LEND * temp);
void lend_output(char no[], LEND * head);
void lendsum_change(char no[], READ * head, int n);
void booksum_change(BOOK * head, char no[], int n);
int lend_credit(char no[], READ * head);
void reader_save(READ * head);
//图书归还
void return_book(char no[]);
void onebook_return(char no[], char bookno[]);
//读者登录
void reader_registered();
void reader_read(READ * head);
void onereader_save(READ * temp);
int reader_enter(char no[], char password[]);
void reader_login();
void reader_loginwindows();
//读者信息管理
void reader_mgm();
void add_reader();
void change_readerinfo(READ * head);
void delete_reader(READ * head);
void inquire_reader(READ * head);
void inquire_reader_no(READ * head);
void inquire_reader_name(READ * head);
void inquire_reader_all(READ * head);
void CreateFolder();
