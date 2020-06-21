//#include<stdio.h>
//#include<windows.h>
//#include<conio.h>
//#define DI Sleep(50)//0.05 second
//#define bool int 
//#define true 1
//#define false 0
//#define LEN sizeof
//bool judge = true;
//FILE* fp;
//FILE* fp_admin;
//
//void zhuce();
//void xuanze();
//int denglu();
//extern struct user* FileToChain_USER(FILE* fp);
//extern struct user* FileToChain_ADMIN(FILE* fp);
//struct user {
//	int id;
//	int id_inside;
//	char name[20];
//	char passwd[20];
//	struct user* next;
//}pe;
////typedef struct//存放账号和密码
////{
////	int id;
////	int id_inside;
////	char name[20];
////	char passwd[20];
////}Users;
////Users pe;
//
//int login_menu()
//{
//	HANDLE LOGIN_IN;
//	LOGIN_IN = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos_login_in = { 33,7 };                   //定义光标
//
//	HANDLE LOGIN_GUEST;
//	LOGIN_GUEST = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos_login_guest = { 33,9 };              //定义光标  
//
//	HANDLE LOGIN_EXIT;
//	LOGIN_EXIT = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos_login_exit = { 33,11 };                //定义光标
//
//	extern login_user(), login_guest(), main();
//	system("CLS");
//	int menu_login_select = 0;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("                              ┌─                     Login in                     ─┐\n"); DI;
//	printf("                              │                                                    │\n"); DI;
//	printf("                              │                   Login as guest                   │\n"); DI;
//	printf("                              │                                                    │\n"); DI;
//	printf("                              └─                    Quit system                   ─┘\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("\n"); DI;
//	printf("                              "); DI;
//
//	while (1)
//	{
//		switch (menu_login_select)
//		{
//		case 1:
//			SetConsoleCursorPosition(LOGIN_GUEST, pos_login_guest);
//			printf("                 Login as guest                   ");
//			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
//			printf("                   Quit system                   ");
//			SetConsoleCursorPosition(LOGIN_IN, pos_login_in);
//			printf("\33[47;30m                    Login in                     \33[0m");
//			break;
//
//		case 2:
//			SetConsoleCursorPosition(LOGIN_IN, pos_login_in);
//			printf("                    Login in                     ");
//			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
//			printf("                   Quit system                   ");
//			SetConsoleCursorPosition(LOGIN_GUEST, pos_login_guest);
//			printf("\33[47;30m                 Login as guest                \33[0m");
//			break;
//
//		case 3:
//			SetConsoleCursorPosition(LOGIN_IN, pos_login_in);
//			printf("                    Login in                     ");
//			SetConsoleCursorPosition(LOGIN_GUEST, pos_login_guest);
//			printf("                 Login as guest                   ");
//			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
//			break;
//		}
//		_getch(); Sleep(80);
//		if (GetAsyncKeyState(VK_DOWN))
//		{
//			if (menu_login_select == 3)menu_login_select = 3;
//			else menu_login_select++;
//		}
//		if (GetAsyncKeyState(VK_UP))
//		{
//			if (menu_login_select == 1)menu_login_select = 1;
//			else if (menu_login_select == 0)menu_login_select = 0;
//			else menu_login_select--;
//		}
//		if (GetAsyncKeyState(VK_RETURN))
//		{
//			if (menu_login_select == 1)
//			{
//				system("CLS");
//				xuanze();
//			}
//			else if (menu_login_select == 2)
//			{
//				printf("\\t游客");//login_guest();
//			}
//			else if (menu_login_select == 3)
//			{
//				exit(0);
//			}
//		}
//	}
//}
//
//
//void xuanze()
//{
//	int n;
//	printf("\n\t\t1.用户登录");
//	printf("\n\t\t\t\t\t2.用户注册");
//	printf("\n\t\t\t(请输入 1 或 2 选择登录或注册)");
//	printf("\n\t\t请输入:");
//	scanf_s("%d", &n);
//	getchar();
//
//	while (n != 1 && n != 2)
//	{
//		printf("\n\t\t输入错误，请重新输入:");
//		scanf_s("%d", &n);
//		getchar();
//	}
//	if (n == 1)
//		denglu();
//	else
//		zhuce();
//}
//
// int denglu()
//{
//	BOOL exist = 0, Class = 0;
//	int i;
//	char n[20], p[20], temp;
//	struct user* user_chain = (struct user*)malloc(LEN(struct user));
//	printf("\n\t\t\t\t用户登录");
//	printf("\n\t\t用户名:");
//	scanf_s("%s", n, 20);
//
//	if (fopen_s(&fp, "TABLE_USER", "rb+") != 0) fopen_s(&fp, "TABLE_USER", "wb");  
//	if (fopen_s(&fp_admin, "TABLE_ADMIN", "rb+") != 0) fopen_s(&fp_admin, "TABLE_ADMIN", "wb");//读文件
//	if (getc(fp) != EOF) Class = false;
//	else if(getc(fp_admin) != EOF) Class = true;
//	else if (getc(fp) == EOF && getc(fp_admin == EOF))
//	{
//		printf("无任何用户信息，请注册\n");
//		_getch();
//		fflush(stdin);
//		system("cls");
//		fclose(fp);
//		zhuce();
//	}
//	if (Class = false)user_chain = FileToChain_USER(fp);
//	if (Class = true)user_chain = FileToChain_ADMIN(fp_admin);
//	do
//	{
//		if (!strcmp(n,user_chain->name))
//		{
//			exist = 1;
//			strcpy_s(pe.name, LEN(user_chain->name) + 1, user_chain->name);
//			strcpy_s(pe.passwd, LEN(user_chain->passwd) + 1, user_chain->passwd);
//			break;
//		}
//		user_chain = user_chain->next;
//	} while (user_chain != NULL);
//	temp = '0';
//	if (exist!=true)                               //判断是否有该账号
//	{
//		printf("\n\t\t用户不存在,请注册");
//		printf("\n\t\t1.注册 2.重新登陆");
//		temp = _getch();
//		if (temp == '1')
//		{
//			system("cls");
//			zhuce();                              //注册函数
//		}
//		else return denglu();
//	}
//	do
//	{
//		temp = '0';
//		//if (judge == true);//fread(&pe, sizeof(Users), 1, fp);//读取用户信息，即用户名和密码
//		printf("\t\t密 码:");
//		for (i = 0;i <= 20;i++)                   //密码***
//		{
//			p[i] = _getch();
//			if (p[i] == '\r')
//				break;
//			printf("*");
//		}
//		p[i] = '\0';
//
//		if (strcmp(pe.passwd, p) != 0)            //对比输入的密码和读取的密码
//		{
//			printf("\n\t\t密码错误(1.退出 2.重新输入）");
//			temp = _getch();
//			printf("\n");
//			if (temp == '1')
//			{
//				fclose(fp);
//				return main();
//			}
//		}
//	} while (temp == '2');
//	return 0;
//}
//
//void zhuce()//注册
//{
//	void write();
//	int denglu();
//	extern int main();
//
//	char temp[20];                                //对比用
//	//账号注册
//	printf("\t\t\t\t用户注册");
//	printf("\n\t\t用户名:");
//	scanf_s("%s", pe.name, 20);
//	//fopen_s(&fp,pe.name, "rb+");
//  //密码注册
//	printf("\n\t\t密  码:");
//	scanf_s("%s", pe.passwd, 20);
//	printf("\n\t\t确认密码:");
//	scanf_s("%s", temp, 20);                      //与pe.passwd对比
//	if (strcmp(pe.passwd, temp) != 0)             //与pe.passwd对比
//		printf("\n\t\t两次密码不一致,请重新输入");
//
//	fopen_s(&fp, "TABLE_USER", "rb+");
//	if (fp == NULL)
//	{
//		printf("\n\t注册失败\n");
//		fclose(fp);
//		exit(0);
//	}
//	else
//	{
//		system("cls");
//		printf("\n\t注册成功");
//		write(fp);                                  //用户信息写入
//		judge = false;
//		fclose(fp);
//		denglu();                                 //跳转到登录
//	}
//}
//
//void write(FILE *fp)                                      //写入用户信息
//{
//	/*if (fwrite(&pe, sizeof(Users), 1, fp) != 1)
//	{
//		printf("\n\t\t写入文件错误");
//		exit(0);
//	}
//	fclose(fp);*/
//	struct user* former = (struct user*)malloc(LEN(struct user));
//	rewind(fp);
//	if (fgetc(fp) == EOF)
//	{
//		pe.id_inside = 1;
//	}
//	else
//	{
//		fseek(fp, -(int)LEN(struct user), SEEK_END);
//		fread(former, LEN(struct user), 1, fp);
//		former->next = (struct user*)malloc(LEN(struct user));
//		pe.id_inside = former->id_inside + 1;
//		fseek(fp, -(int)LEN(struct user), SEEK_END);
//		fwrite(former, LEN(struct user), 1, fp);
//	}
//	pe.next = NULL;
//	fwrite(&pe, LEN(struct user), 1, fp);
//	printf("success\n"); DI;
//}
//
