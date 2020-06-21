#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define DI Sleep(50)//dynamic imitate 0.05 second


int menu_login()
{
	extern void xuanze(), menu_guest();
	HANDLE LOGIN_IN;
	LOGIN_IN = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_login_in = {33,7};						//定位光标
	//CONSOLE_CURSOR_INFO cursorinfo;
	//GetConsoleCursorInfo(LOGIN_IN, &cursorinfo);
	//cursorinfo.bVisible = FALSE;						//隐藏光标
	HANDLE LOGIN_GUEST;
	LOGIN_GUEST = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_login_guest = { 33,9 };					//定位光标
	//GetConsoleCursorInfo(LOGIN_GUEST, &cursorinfo);
	//cursorinfo.bVisible = FALSE;						//隐藏光标
	HANDLE LOGIN_EXIT;
	LOGIN_EXIT = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_login_exit = { 33,11 };					//定位光标
	//GetConsoleCursorInfo(LOGIN_EXIT, &cursorinfo);
	//cursorinfo.bVisible = FALSE;						//隐藏光标
	extern login_user(), login_guest(), main();
	system("CLS");
	int menu_login_select = 0;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("                              ┌─                     Login in                     ─┐\n"); DI;
	printf("                              │                                                    │\n"); DI;
	printf("                              │                   Login as guest                   │\n"); DI;
	printf("                              │                                                    │\n"); DI;
	printf("                              └─                    Quit system                   ─┘\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	while (1)
	{
		switch (menu_login_select)
		{
		case 2:
			/*system("CLS");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                              ┌─ \33[47;30m                    Login in                    \33[0m─┐\n");
			printf("                              │                                                    │\n");
			printf("                              │                   Login as guest                   │\n");
			printf("                              │                                                    │\n");
			printf("                              └─                    Quit system                   ─┘\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                              登入系统"); DI; */
			SetConsoleCursorPosition(LOGIN_GUEST, pos_login_guest);
			printf("                 Login as guest                   ");
			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
			printf("                   Quit system                   ");
			/*SetConsoleCursorInfo(LOGIN_IN, &cursorinfo);*/
			SetConsoleCursorPosition(LOGIN_IN, pos_login_in);
			printf("\33[47;30m                    Login in                     \33[0m");
			break;
		case 4:
			/*system("CLS");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                              ┌─                     Login in                     ─┐\n");
			printf("                              │                                                    │\n");
			printf("                              │  \33[47;30m                 Login as guest                  \33[0m │\n");;
			printf("                              │                                                    │\n");
			printf("                              └─                    Quit system                   ─┘\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                              以访客身份登入"); DI;*/
			SetConsoleCursorPosition(LOGIN_IN, pos_login_in);
			printf("                    Login in                     ");
			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
			printf("                   Quit system                   ");
			SetConsoleCursorPosition(LOGIN_GUEST, pos_login_guest);
			//SetConsoleCursorInfo(LOGIN_GUEST, &cursorinfo);
			printf("\33[47;30m                 Login as guest                  \33[0m");
			break;
		case 6:
			//system("CLS");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("                              ┌─                     Login in                     ─┐\n");
			//printf("                              │                                                    │\n");
			//printf("                              │                   Login as guest                   │\n");
			//printf("                              │                                                    │\n");
			//printf("                              └─ \33[47;30m                   Quit system                   \33[0m─┘\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("\n");
			//printf("                              离开系统"); DI;
			SetConsoleCursorPosition(LOGIN_IN, pos_login_in);
			printf("                    Login in                     ");
			SetConsoleCursorPosition(LOGIN_GUEST, pos_login_guest);
			printf("                 Login as guest                   ");
			SetConsoleCursorPosition(LOGIN_EXIT, pos_login_exit);
			//SetConsoleCursorInfo(LOGIN_EXIT, &cursorinfo);
			printf("\33[47;30m                   Quit system                   \33[0m");
			break;
		}
		_getch();
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (menu_login_select == 6)menu_login_select = 6;
			else menu_login_select++;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (menu_login_select == 2)menu_login_select = 2;
			else if (menu_login_select == 0)menu_login_select =0;
			else menu_login_select--;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (menu_login_select == 2)
			{
				xuanze();
			}
			else if (menu_login_select == 4)
			{
				menu_guest();
			}
			else if (menu_login_select == 6)
			{
				exit(0);
			}
		}
	}
}