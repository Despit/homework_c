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
////typedef struct//����˺ź�����
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
//	COORD pos_login_in = { 33,7 };                   //������
//
//	HANDLE LOGIN_GUEST;
//	LOGIN_GUEST = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos_login_guest = { 33,9 };              //������  
//
//	HANDLE LOGIN_EXIT;
//	LOGIN_EXIT = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos_login_exit = { 33,11 };                //������
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
//	printf("                              ����                     Login in                     ����\n"); DI;
//	printf("                              ��                                                    ��\n"); DI;
//	printf("                              ��                   Login as guest                   ��\n"); DI;
//	printf("                              ��                                                    ��\n"); DI;
//	printf("                              ����                    Quit system                   ����\n"); DI;
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
//				printf("\\t�ο�");//login_guest();
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
//	printf("\n\t\t1.�û���¼");
//	printf("\n\t\t\t\t\t2.�û�ע��");
//	printf("\n\t\t\t(������ 1 �� 2 ѡ���¼��ע��)");
//	printf("\n\t\t������:");
//	scanf_s("%d", &n);
//	getchar();
//
//	while (n != 1 && n != 2)
//	{
//		printf("\n\t\t�����������������:");
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
//	printf("\n\t\t\t\t�û���¼");
//	printf("\n\t\t�û���:");
//	scanf_s("%s", n, 20);
//
//	if (fopen_s(&fp, "TABLE_USER", "rb+") != 0) fopen_s(&fp, "TABLE_USER", "wb");  
//	if (fopen_s(&fp_admin, "TABLE_ADMIN", "rb+") != 0) fopen_s(&fp_admin, "TABLE_ADMIN", "wb");//���ļ�
//	if (getc(fp) != EOF) Class = false;
//	else if(getc(fp_admin) != EOF) Class = true;
//	else if (getc(fp) == EOF && getc(fp_admin == EOF))
//	{
//		printf("���κ��û���Ϣ����ע��\n");
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
//	if (exist!=true)                               //�ж��Ƿ��и��˺�
//	{
//		printf("\n\t\t�û�������,��ע��");
//		printf("\n\t\t1.ע�� 2.���µ�½");
//		temp = _getch();
//		if (temp == '1')
//		{
//			system("cls");
//			zhuce();                              //ע�ắ��
//		}
//		else return denglu();
//	}
//	do
//	{
//		temp = '0';
//		//if (judge == true);//fread(&pe, sizeof(Users), 1, fp);//��ȡ�û���Ϣ�����û���������
//		printf("\t\t�� ��:");
//		for (i = 0;i <= 20;i++)                   //����***
//		{
//			p[i] = _getch();
//			if (p[i] == '\r')
//				break;
//			printf("*");
//		}
//		p[i] = '\0';
//
//		if (strcmp(pe.passwd, p) != 0)            //�Ա����������Ͷ�ȡ������
//		{
//			printf("\n\t\t�������(1.�˳� 2.�������룩");
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
//void zhuce()//ע��
//{
//	void write();
//	int denglu();
//	extern int main();
//
//	char temp[20];                                //�Ա���
//	//�˺�ע��
//	printf("\t\t\t\t�û�ע��");
//	printf("\n\t\t�û���:");
//	scanf_s("%s", pe.name, 20);
//	//fopen_s(&fp,pe.name, "rb+");
//  //����ע��
//	printf("\n\t\t��  ��:");
//	scanf_s("%s", pe.passwd, 20);
//	printf("\n\t\tȷ������:");
//	scanf_s("%s", temp, 20);                      //��pe.passwd�Ա�
//	if (strcmp(pe.passwd, temp) != 0)             //��pe.passwd�Ա�
//		printf("\n\t\t�������벻һ��,����������");
//
//	fopen_s(&fp, "TABLE_USER", "rb+");
//	if (fp == NULL)
//	{
//		printf("\n\tע��ʧ��\n");
//		fclose(fp);
//		exit(0);
//	}
//	else
//	{
//		system("cls");
//		printf("\n\tע��ɹ�");
//		write(fp);                                  //�û���Ϣд��
//		judge = false;
//		fclose(fp);
//		denglu();                                 //��ת����¼
//	}
//}
//
//void write(FILE *fp)                                      //д���û���Ϣ
//{
//	/*if (fwrite(&pe, sizeof(Users), 1, fp) != 1)
//	{
//		printf("\n\t\tд���ļ�����");
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
