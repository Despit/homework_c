#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#define DI Sleep(40)//dynamic imitate 0.05 second
#define dot Beep(1500, 50)
#define line Beep(1500, 150)
#define Rest Sleep(50)
#define bool int 
#define true 1
#define false 0
#define LEN sizeof
bool judge = true;
FILE* fp;
FILE* fp_admin;

void zhuce();
int xuanze();
int denglu();
extern int main(),menu_login();
extern struct user* FileToChain_USER(FILE* fp);
extern struct user* FileToChain_ADMIN(FILE* fp);
struct user {
	int id;
	int id_inside;
	char name[20];
	char passwd[20];
	struct user* next;
}pe;


int xuanze()
{
	HANDLE DENGLU;
	DENGLU = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_deng_lu = { 33,7 };                   //������

	HANDLE ZHUCE;
	ZHUCE = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_zhu_ce = { 33,9 };              //������

	HANDLE LOGIN_EXIT;
	LOGIN_EXIT = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_login_exit = { 33,11 };                //������

	extern main();
	system("CLS");
	int menu_login_select = 0;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("                              ����                      �� ¼                       ����\n"); DI;
	printf("                              ��                                                    ��\n"); DI;
	printf("                              ��                       ע ��                        ��\n"); DI;
	printf("                              ��                                                    ��\n"); DI;
	printf("                              ����                      �� ��                       ����\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("                              "); DI;
	while (1)
	{
		switch (menu_login_select)
		{
		case 1:
			SetConsoleCursorPosition(ZHUCE, pos_zhu_ce);
			printf("                     ע ��                       ");
			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
			printf("                     �� ��                      ");
			SetConsoleCursorPosition(DENGLU, pos_deng_lu);
			printf("\33[47;30m                   ��     ¼                     \33[0m");
			break;
		case 2:
			SetConsoleCursorPosition(DENGLU, pos_deng_lu);
			printf("                     �� ¼                       ");
			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
			printf("                     �� ��                       ");
			SetConsoleCursorPosition(ZHUCE, pos_zhu_ce);
			printf("\33[47;30m                   ע     ��                     \33[0m");
			break;

		case 3:
			SetConsoleCursorPosition(DENGLU, pos_deng_lu);
			printf("                     �� ¼                       ");
			SetConsoleCursorPosition(ZHUCE, pos_zhu_ce);
			printf("                     ע ��                       ");
			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
			printf("\33[47;30m                   ��     ��                     \33[0m");
			break;
		}
		_getch();Sleep(80);
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (menu_login_select == 3)menu_login_select = 3;
			else menu_login_select++;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (menu_login_select == 1)menu_login_select = 1;
			else if (menu_login_select == 0)menu_login_select = 0;
			else menu_login_select--;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (menu_login_select == 1)
			{
				system("CLS");
				denglu();
			}
			else if (menu_login_select == 2)
			{
				zhuce();
			}
			else if (menu_login_select == 3)
			{
				menu_login();
			}
		}
	}
}

int denglu()
{
	system("cls");
	extern void welcome(BOOL class, int id);
	BOOL exist = 0, Class = 0;
	int i = 0, cut=0;
	char n[20], p[20] = { 0 }, temp, put;
	struct user* user_chain = (struct user*)malloc(LEN(struct user)), * user_chain_user = (struct user*)malloc(LEN(struct user)),*user_chain_admin = (struct user*)malloc(LEN(struct user));
	printf("\n");
	printf("\n\t\t\t\t\t\t�û���¼");
	printf("\n\t\t\t\t�û���:");
	scanf_s("%s", n, 20);

	if (fopen_s(&fp, "TABLE_USER", "rb+") != 0) fopen_s(&fp, "TABLE_USER", "wb");
	if (fopen_s(&fp_admin, "TABLE_ADMIN", "rb+") != 0) fopen_s(&fp_admin, "TABLE_ADMIN", "wb");//���ļ�
	
	user_chain_user = FileToChain_USER(fp);
	user_chain_admin = FileToChain_ADMIN(fp_admin);
	do
	{
		if (user_chain_user == NULL && user_chain_admin == NULL)
		{
			exist = 0;
			break;
		}
		if (user_chain_user != NULL)
		{
			if (!strcmp(n, user_chain_user->name))
			{
				exist = 1;
				Class = false;
				user_chain = user_chain_user;
				pe.id = user_chain->id;
				strcpy_s(pe.name, LEN(user_chain->name) + 1, user_chain->name);
				strcpy_s(pe.passwd, LEN(user_chain->passwd) + 1, user_chain->passwd);
				break;
			}
		}
		if (user_chain_admin != NULL)
		{
			if (!strcmp(n, user_chain_admin->name))
			{
				exist = 1;
				Class = true;
				user_chain = user_chain_admin;
				pe.id = user_chain->id;
				strcpy_s(pe.name, LEN(user_chain->name) + 1, user_chain->name);
				strcpy_s(pe.passwd, LEN(user_chain->passwd) + 1, user_chain->passwd);
				break;
			}
		}
		if (user_chain_user != NULL) user_chain_user = user_chain_user->next;
		if (user_chain_admin != NULL) user_chain_admin = user_chain_admin->next;
	} while (user_chain_user != NULL || user_chain_admin != NULL);
	temp = '0';
	if (exist != true)                               //�ж��Ƿ��и��˺�
	{
		printf("\n\t\t\t\t�û�������,��ע��");
		printf("\n\t\t\t\t1.ע�� 2.���µ�½");
		temp = _getch();
		if (temp == '1')
		{
			fclose(fp);
			fclose(fp_admin);
			system("cls");
			zhuce();                                //ע�ắ��
		}
		else return denglu();
	}
	do
	{
		temp = '0';
		//if (judge == true);//fread(&pe, sizeof(Users), 1, fp);//��ȡ�û���Ϣ�����û���������
		printf("\n\t\t\t\t�� ��:");
		while (1)
		{
			if ((put = _getch()) != '\r')          //����������
			{
				if (put != '\b')
				{
					*(p + i++) = put;              //ͨ��ָ������鸳ֵ
					printf("*");
					fflush(stdin);
					cut++;
				}
				if (put == '\b' && cut != 0)       //Ϊ�˲�ɾ�����ּ��ж�cut�Ƿ�Ϊ0
				{
					cut--;
					i--;
					printf("\b \b");
				}
			}
			else
			{
				*(p + i) = '\0';
				fflush(stdin);
				printf("\n");
				break;
			}
		}

		if (strcmp(pe.passwd, p) != 0)            //�Ա����������Ͷ�ȡ������
		{
			printf("\n\t\t\t\t�������(1.�˳� 2.�������룩");
			temp = _getch();
			printf("\n");
			if (temp == '1')
			{
				fclose(fp);
				fclose(fp_admin);
				return main();
			}
		}
	} while (temp == '2');
	fclose(fp);
	fclose(fp_admin);
	welcome(Class, pe.id);
	return 0;
}

void zhuce()//ע��
{
	system("cls");
	void write();
	int denglu();
	extern int main();

	char temp[20];                                //�Ա���
	//�˺�ע��
	printf("\t\t\t\t\t\t�û�ע��");
	printf("\n\t\t\t\t�û�id:");
	scanf_s("%d", &pe.id);
	printf("\n\t\t\t\t�û���:");
	scanf_s("%s", pe.name, 20);
	//fopen_s(&fp,pe.name, "rb+");
  //����ע��
	printf("\n\t\t\t\t��  ��:");
	scanf_s("%s", pe.passwd, 20);
	printf("\n\t\t\t\tȷ������:");
	scanf_s("%s", temp, 20);                      //��pe.passwd�Ա�
	while (strcmp(pe.passwd, temp) != 0)
	{
		printf("\n\t\t\t\t�������벻һ��,����������");
		printf("\n\t\t\t\t��  ��:");
		scanf_s("%s", pe.passwd, 20);
		printf("\n\t\t\t\tȷ������:");
		scanf_s("%s", temp, 20);
	}

	fopen_s(&fp, "TABLE_USER", "rb+");
	if (fp == NULL)
	{
		printf("\n\t\t\t\t\tע��ʧ��\n");
		fclose(fp);
		exit(0);
	}
	else
	{
		system("cls");
		printf("\n\t\t\t\tע��ɹ�");
		write(fp);                                  //�û���Ϣд��
		judge = false;
		fclose(fp);
		denglu();                                 //��ת����¼
	}
}

void write(FILE* fp)                                      //д���û���Ϣ
{
	/*if (fwrite(&pe, sizeof(Users), 1, fp) != 1)
	{
		printf("\n\t\tд���ļ�����");
		exit(0);
	}
	fclose(fp);*/
	struct user* former = (struct user*)malloc(LEN(struct user));
	rewind(fp);
	if (fgetc(fp) == EOF)
	{
		pe.id_inside = 1;
	}
	else
	{
		fseek(fp, -(int)LEN(struct user), SEEK_END);
		fread(former, LEN(struct user), 1, fp);
		former->next = (struct user*)malloc(LEN(struct user));
		pe.id_inside = former->id_inside + 1;
		fseek(fp, -(int)LEN(struct user), SEEK_END);
		fwrite(former, LEN(struct user), 1, fp);
	}
	pe.next = NULL;
	fwrite(&pe, LEN(struct user), 1, fp);
	printf("success\n"); DI;
}


void welcome(BOOL class, int id)
{
	system("cls");
	extern int menu(stu_key), menu_admin();
	HANDLE WELCOME;
	WELCOME = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD WELCOME_PO = { 75,14 };
	printf("\t\t                     UBBX                    \n");
	printf("\t\t                   .QBJJQB.                  \n");
	printf("\t\t                  XQQ    dBd                 \n");
	printf("\t\t                 YBd      IB2                \n");
	printf("\t\t                .BB        QB.               \n");
	printf("\t\t    :r77i:      gB          BB     .:vJUYr   \n");
	printf("\t\t  BQBQBBBQBBBM7:BX          uB7YBQBBBBBBBBBQ \n");
	printf("\t\t.QBi       ijQBBQBv.      :5QBBBPv.       .BQ\n");
	printf("\t\tZB1            QBLBBBK::DBBQ7RB            rB\n");
	printf("\t\t.BB            Bu   BBBBQZ   vB:           BR\n");
	printf("\t\t :Bq          7B: dBBq.:gBB2 .BJ          qB.\n");
	printf("\t\t  EBq         IBBBB7      sBBBQb         bBZ \n");
	printf("\t\t   SBQ       uBBK.          :bBBv       BBK  \n");
	printf("\t\t    rBBi   dBBBB    iMBBgi    BBBB2   iBBr   \n");
	printf("\t\t      QBSLBBr BB   KBQBBBBX   BB 7BB7KBg     \n");
	printf("\t\t       gBBB   BB   BBQZgMBB   BB   BBBX      \n");
	printf("\t\t      BQ17BB7 BB   XBBBBBBS   BB 7BQ7qBD     \n");
	printf("\t\t    vBQ:   qBBBB    igBBZi    QBBB2   rBBr   \n");
	printf("\t\t   EBM       JBBK.          :bBB7       BBS  \n");
	printf("\t\t  QBu         2BBBB7      YBQBBb         dBd \n");
	printf("\t\t rBj          7B: bBBX.:gBB5 .BJ          bB.\n");
	printf("\t\trBR            B1   BBBBBZ   YQ.           BM\n");
	printf("\t\tBBr            BBYBBBX::DBBQ7QB            rB\n");
	printf("\t\trBQ.       ijRBBBBL.      :XBBBBP7.       .BQ\n");
	printf("\t\t  BBBBBBBBBBBR7:BX          UB7JBBBBBBBBBBBB \n");
	printf("\t\t    :7vvi:      gB.         BB     .is15Jr.  \n");
	printf("\t\t                 BB        BB.               \n");
	printf("\t\t                 vBZ      SBu                \n");
	printf("\t\t                  IBQ    ZBP                 \n");
	printf("\t\t                    DBXXBQ                   \n");
	//system("cls");
	SetConsoleCursorPosition(WELCOME, WELCOME_PO);
	//line; Rest; dot; Rest; line; Rest; dot; Rest; line; Rest; Rest; Rest;//Start
	dot; Rest; line; line; Rest; Rest; Rest;//W
	printf("W");
	dot; Rest; Rest; Rest;//E
	printf("E");
	dot; Rest; line; Rest; dot; dot; Rest; Rest; Rest;//L
	printf("L");
	line; Rest; dot; Rest; line; Rest; dot; Rest; Rest; Rest;//C
	printf("C");
	line; line; line; Rest; Rest; Rest;//O
	printf("O");
	line; line; Rest; Rest; Rest;//M
	printf("M");
	dot; Rest; Rest; Rest;//E
	printf("E"); Rest; Rest; Rest;
	//dot; dot; dot; Rest; line; Rest; dot; Rest; Rest; Rest;//End
	WELCOME_PO.X= 75, WELCOME_PO.Y = 16;
	SetConsoleCursorPosition(WELCOME, WELCOME_PO);
	if (class == 0)
	{
		printf("User   "); DI; DI; DI;
		printf("%d", id); DI; DI; DI;
	}
	else
	{
		printf("Administrator   "); DI; DI; DI;
		printf("%d", id); DI; DI; DI;
	}
	WELCOME_PO.X = 0, WELCOME_PO.Y = 29;
	SetConsoleCursorPosition(WELCOME, WELCOME_PO); Sleep(1000);
	system("cls");
	if (class == false) menu(id);
	else menu_admin();
}