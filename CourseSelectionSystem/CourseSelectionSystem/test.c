//#include<stdio.h>
//#include<Windows.h>
//#define LEN sizeof
//struct user {
//	int id;
//	char name[20];
//	char passwd[20];
//	struct user* next;
//};
//struct course {
//	int id;
//	char name[20];
//	int time;
//	int time_theory;
//	int time_practice;
//	char class[20];
//	int term;
//	int credit;
//	struct course* next;
//};
//
//int main()
//{
//	int i = 0;
//	FILE* fp;
//	fopen_s(&fp, "TABLE_COURSE", "rb");
//	struct course* show = (struct course*)malloc(LEN(struct course));
//	do
//	{
//		i++;
//		if (i == 1)
//		{
//			fread(show, LEN(struct course), 1, fp);
//			printf("%d %s %d %d %d %s %d %d \n", show->id, show->name, show->time, show->time_theory, show->time_practice, show->class, show->term, show->credit);
//		}
//		else
//		{
//			fseek(fp, (i-1)*LEN(struct course), SEEK_SET);
//			fread(show, LEN(struct course), 1, fp);
//			printf("%d %s %d %d %d %s %d %d \n", show->id, show->name, show->time, show->time_theory, show->time_practice, show->class, show->term, show->credit);
//		}
//	} while (show->next != NULL);
//}
//int main()
//{
//	extern struct course* create_course();
//	create_course();
//	return 0;
//}
//#include<stdio.h>
//#include<windows.h>
//int main()
//{
//    HANDLE hOut;
//    COORD pos = { 15,5 };
//    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleCursorPosition(hOut, pos);
//    printf("HelloWorld!\n");
//    return 0;
//}
//#include<Windows.h>
//#include<conio.h>
//#include<stdio.h>
//void main()
//{
//	/*extern int menu();
//	menu();
//	int a;
//	while (1)
//	{
//		_getch(); _getch();
//		a = GetAsyncKeyState(VK_UP);
//		printf("%d", a);
//	}*/
//
//
//	//void drop_course(int stu_id, int selected), export_course();
//	//extern void export_course(), export_course_selecting(int stu_id);
//	//int id_selected;
//	//int stu = 4123;//2003//5610//4123
//	//export_course();
//	//export_course_selecting(stu);
//	//scanf_s("%d", &id_selected);
//	//drop_course(stu,id_selected);
//
//	/*void export_info();
//		export_info();*/
//	void welcome(BOOL class, int id);
//	BOOL a = 0;
//	int id = 20130624;
//	welcome(a, id);
//}
//int main()
//{
//	extern int create_admin();
//	create_admin();
//	return 0;
//}


















//#include <stdio.h>
//#include <string.h>
//#include <conio.h>
//#include <stdlib.h>
//#define bool int 
//#define true 1
//#define false 0
//bool judge = true;
//FILE *fp;
//
//typedef struct//存放账号和密码
//{
//	char name[20];
//	char passwd[20];
//}Users;
//Users pe;
//
//int main()
//{
//	void zhuce();
//	//int denglu();
//	zhuce();
//	//denglu();
//	printf("sucess");
//	return 0;
//}
//void zhuce()//注册
//{
//	void write();
//	int denglu();
//	extern int main();
//	char temp[20];
//	//账号
//	printf("\t\t\t\t用户注册");
//	printf("\n\t\t用户名:");
//	scanf_s("%s", pe.name,20);
//	//fopen_s(&fp,pe.name, "rb+");
//	////密码
//	printf("\n\t\t密  码:");
//	scanf_s("%s", pe.passwd,20);
//	printf("\n\t\t确认密码:");
//	scanf_s("%s", temp,20);//与pe.passwd对比
//	if (strcmp(pe.passwd, temp) != 0)//与pe.passwd对比
//		printf("\n\t\t两次密码不一致,请重新输入");
//
//	fopen_s(&fp,pe.name, "wb");
//	if (fp == NULL)
//	{
//		printf("\n\t注册失败\n");
//		exit(0);
//	}
//	else
//	{
//		system("cls");
//		printf("\n\t注册成功");
//		write();//用户信息写入函数，在后面又
//		judge = false;
//		denglu();//跳转到登录
//	}
//}
//void write()//写入用户信息
//{
//	if (fwrite(&pe, sizeof(Users), 1, fp) != 1)
//	{
//		printf("\n\t\t写入文件错误");
//		exit(0);
//	}
//	fclose(fp);
//}
//int denglu()
//{
//	char n[20], p[20], temp;
//	printf("\n\t\t\t\t用户登录");
//	printf("\n\t\t用户名:");
//	scanf_s("%s", n,20);
//
//	fopen_s(&fp, n, "rb");
//	temp = '0';
//	if (fp == NULL)
//	{
//		printf("\n\t\t用户不存在,请注册");
//		printf("\n\t\t1.注册 2.重新登陆");
//		temp = _getch();
//		if (temp == '1')
//		{
//			system("cls");
//			zhuce();
//		}
//		else return denglu();
//	}
//	do 
//	{
//		temp = '0';
//		if (judge == true)fread(&pe, sizeof(Users), 1, fp);//读取用户信息，即用户名和密码
//		printf("\t\t密 码:");
//		scanf_s("%s", p,20);
//		if (strcmp(pe.passwd, p) != 0)//对比输入的密码和读取的密码
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
//}
//#include<stdlib.h>
//int main()
//{
//		void course_select(int stu_id);
//		extern void export_course_selecting(int stu_id);
//		int stu_primary_key = 1000;
//		course_select(stu_primary_key);
//		export_course_selecting(stu_primary_key);
//		return 0;
//}