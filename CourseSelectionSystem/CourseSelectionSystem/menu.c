#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#define DI Sleep(50)
int menu(int stu_key)
{
	extern void export_course(), sort_credit(int credit);
	int navigator_add(int stu_primary_key), navigation_drop(int stu_primary_key);
	extern int menu_login();
	
	BOOL check_key(int ascii_key);
	int menu_select = 0;// stu_key = login();
	int credit = 0;
	HANDLE cursor;
	cursor = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_cursor_browse = { 40,7 };
	COORD pos_cursor_add = { 40,9 };
	COORD pos_cursor_drop = { 40,11 };
	COORD pos_cursor_sort = { 40,13 };
	COORD pos_cursor_logout = { 40,15 };
start:while (1)
	{
		switch (menu_select)
		{
		case 0:
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("                                     ©°©¤                 Browse Courses               ©¤©´\n"); DI;
			printf("                                     ©¦                                                ©¦\n"); DI;
			printf("                                     ©¦                  Add Courses                   ©¦\n"); DI;
			printf("                                     ©¦                                                ©¦\n"); DI;
			printf("                                     ©¦                  Drop Courses                  ©¦\n"); DI;
			printf("                                     ©¦                                                ©¦\n"); DI;
			printf("                                     ©¦                  Sort by Credit                ©¦\n"); DI;
			printf("                                     ©¦                                                ©¦\n"); DI;
			printf("                                     ©¸©¤                 Log Out                      ©¤©¼\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			printf("\n"); DI;
			break;
		case 2:
			SetConsoleCursorPosition(cursor, pos_cursor_browse);
			printf("\33[47;30m                Browse Courses               \33[0m");
			SetConsoleCursorPosition(cursor, pos_cursor_add);
			printf("                Add Courses                  ");
			SetConsoleCursorPosition(cursor, pos_cursor_drop);
			printf("                Drop Courses                 ");
			SetConsoleCursorPosition(cursor, pos_cursor_sort);
			printf("                Sort by Credit               ");
			SetConsoleCursorPosition(cursor, pos_cursor_logout);
			printf("                Log Out                      ");
			break;
		case 4:
			SetConsoleCursorPosition(cursor, pos_cursor_browse);
			printf("                Browse Courses               ");
			SetConsoleCursorPosition(cursor, pos_cursor_add);
			printf("\33[47;30m                Add Courses                  \33[0m");
			SetConsoleCursorPosition(cursor, pos_cursor_drop);
			printf("                Drop Courses                 ");
			SetConsoleCursorPosition(cursor, pos_cursor_sort);
			printf("                Sort by Credit               ");
			SetConsoleCursorPosition(cursor, pos_cursor_logout);
			printf("                Log Out                      ");
			break;
		case 6:
			SetConsoleCursorPosition(cursor, pos_cursor_browse);
			printf("                Browse Courses               ");
			SetConsoleCursorPosition(cursor, pos_cursor_add);
			printf("                Add Courses                  ");
			SetConsoleCursorPosition(cursor, pos_cursor_drop);
			printf("\33[47;30m                Drop Courses                 \33[0m");
			SetConsoleCursorPosition(cursor, pos_cursor_sort);
			printf("                Sort by Credit               ");
			SetConsoleCursorPosition(cursor, pos_cursor_logout);
			printf("                Log Out                      ");
			break;
		case 8:
			SetConsoleCursorPosition(cursor, pos_cursor_browse);
			printf("                Browse Courses               ");
			SetConsoleCursorPosition(cursor, pos_cursor_add);
			printf("                Add Courses                  ");
			SetConsoleCursorPosition(cursor, pos_cursor_drop);
			printf("                Drop Courses                 ");
			SetConsoleCursorPosition(cursor, pos_cursor_sort);
			printf("\33[47;30m                Sort by Credit               \33[0m");
			SetConsoleCursorPosition(cursor, pos_cursor_logout);
			printf("                Log Out                      ");
			break;
		case 10:
			SetConsoleCursorPosition(cursor, pos_cursor_browse);
			printf("                Browse Courses               ");
			SetConsoleCursorPosition(cursor, pos_cursor_add);
			printf("                Add Courses                  ");
			SetConsoleCursorPosition(cursor, pos_cursor_drop);
			printf("                Drop Courses                 ");
			SetConsoleCursorPosition(cursor, pos_cursor_sort);
			printf("                Sort by Credit               ");
			SetConsoleCursorPosition(cursor, pos_cursor_logout);
			printf("\33[47;30m                Log Out                      \33[0m");
			break;
		}
	reinput:_getch();
		if (check_key(13))//VK_ENTER
		{
			switch (menu_select)
			{
			case 2:
				system("cls");
				export_course();
				printf("press any key to continue");
				_getch();
				fflush(stdin);
				system("cls");
				goto start;
				break;
			case 4:
				navigator_add(stu_key);
				printf("press any key to continue");
				_getch();
				fflush(stdin);
				system("cls");
				goto start;
				break;
			case 6:
				navigation_drop(stu_key);
				printf("press any key to continue");
				_getch();
				fflush(stdin);
				system("cls");
				goto start;
				break;
			case 8:
				system("cls");
				printf("Input Credit You Want to Query\n");
				scanf_s("%d", &credit);
				sort_credit(credit);
				printf("press any key to continue");
				_getch();
				fflush(stdin);
				system("cls");
				goto start;
				break;
			case 10:
				menu_login();
				break;
			}
		}
		if (check_key(40))	//VK_DOWN
		{
			if (menu_select == 10)menu_select = 10;
			else menu_select++;
		}
		else if (check_key(38))	//VK_UP
		{
			if (menu_select == 2)menu_select = 2;
			else if (menu_select == 0)menu_select = 0;
			else menu_select--;
		}
		else goto reinput;
	}
}
int menu_admin()
{
	void export_course();
	extern int menu_login(), create_course();
	extern errno_t delete_course(int selected);
	extern void drop_course_admin(int selected), add_new_course();
	BOOL check_key(int ascii_key);
	HANDLE cursor;
	int menu_select;
	cursor = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_cursor_browse = { 40,7 };
	COORD pos_cursor_add = { 40,9 };
	COORD pos_cursor_add_single = { 40,11 };
	COORD pos_cursor_drop = { 40,13 };
	COORD pos_cursor_logout = { 40,15 };
start:menu_select = 0;
	while (1)
{
	switch (menu_select)
	{
	case 0:
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("                                     ©°©¤                 Browse Courses               ©¤©´\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¦               Establish New Courses            ©¦\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¦                    Add Course                  ©¦\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¦                 Delete Courses                 ©¦\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¸©¤                   Log Out                    ©¤©¼\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		break;
	case 2:
		SetConsoleCursorPosition(cursor, pos_cursor_browse);
		printf("\33[47;30m               Browse Courses                \33[0m");
		SetConsoleCursorPosition(cursor, pos_cursor_add);
		printf("             Establish New Courses            ");
		SetConsoleCursorPosition(cursor, pos_cursor_add_single);
		printf("                  Add Course                  ");
		SetConsoleCursorPosition(cursor, pos_cursor_drop);
		printf("               Delete Courses                 ");
		SetConsoleCursorPosition(cursor, pos_cursor_logout);
		printf("                  Log Out                    ");
		break;
	case 4:
		SetConsoleCursorPosition(cursor, pos_cursor_browse);
		printf("               Browse Courses                ");
		SetConsoleCursorPosition(cursor, pos_cursor_add);
		printf("\33[47;30m             Establish New Courses           \33[0m");
		SetConsoleCursorPosition(cursor, pos_cursor_add_single);
		printf("                  Add Course                  ");
		SetConsoleCursorPosition(cursor, pos_cursor_drop);
		printf("               Delete Courses                 ");
		SetConsoleCursorPosition(cursor, pos_cursor_logout);
		printf("                  Log Out                    ");
		break;
	case 6:
		SetConsoleCursorPosition(cursor, pos_cursor_browse);
		printf("               Browse Courses                ");
		SetConsoleCursorPosition(cursor, pos_cursor_add);
		printf("             Establish New Courses           ");
		SetConsoleCursorPosition(cursor, pos_cursor_add_single);
		printf("\33[47;30m                  Add Course                  \33[0m");
		SetConsoleCursorPosition(cursor, pos_cursor_drop);
		printf("               Delete Courses                 ");
		SetConsoleCursorPosition(cursor, pos_cursor_logout);
		printf("                  Log Out                    ");
		break;
	case 8:
		SetConsoleCursorPosition(cursor, pos_cursor_browse);
		printf("               Browse Courses                ");
		SetConsoleCursorPosition(cursor, pos_cursor_add);
		printf("             Establish New Courses            ");
		SetConsoleCursorPosition(cursor, pos_cursor_add_single);
		printf("                  Add Course                  ");
		SetConsoleCursorPosition(cursor, pos_cursor_drop);
		printf("\33[47;30m               Delete Courses                \33[0m");
		SetConsoleCursorPosition(cursor, pos_cursor_logout);
		printf("                  Log Out                    ");
		break;
	case 10:
		SetConsoleCursorPosition(cursor, pos_cursor_browse);
		printf("               Browse Courses                ");
		SetConsoleCursorPosition(cursor, pos_cursor_add);
		printf("             Establish New Courses            ");
		SetConsoleCursorPosition(cursor, pos_cursor_add_single);
		printf("                  Add Course                  ");
		SetConsoleCursorPosition(cursor, pos_cursor_drop);
		printf("               Delete Courses                 ");
		SetConsoleCursorPosition(cursor, pos_cursor_logout);
		printf("\33[47;30m                  Log Out                    \33[0m");
		break;
	}
reinput:_getch();
	if (check_key(13))//VK_ENTER
	{
		switch (menu_select)
		{
		case 2:
			system("cls");
			export_course();
			printf("press any key to continue");
			_getch();
			fflush(stdin);
			system("cls");
			goto start;
			break;
		case 4:
			system("cls");
			printf("    \t\tWARNING\n"); DI;
			printf("    \t\tTHIS ACTION WILL DELETE THE ORIGINAL COURSES AND CAN NOT UNDO\n"); DI;
			printf("\t\tPRESS 'Y' TO COMFIRM\n"); DI;
			if (_getch() == 'Y' ) create_course();
			printf("press any key to continue");
			_getch();
			fflush(stdin);
			system("cls");
			goto start;
			break;
		case 6:
			system("cls");
			add_new_course();
			printf("press any key to continue");
			_getch();
			fflush(stdin);
			system("cls");
			goto start;
		case 8:
			system("cls");
			export_course();
			printf("\n\n\n\n\n\n\n\n\nInput Course ID You Want to Delete\n");
			int selected_id = 0;
			scanf_s("%d", &selected_id);
			if (delete_course(selected_id) == 0) drop_course_admin(selected_id);
			printf("press any key to continue");
			_getch();
			fflush(stdin);
			system("cls");
			goto start;
			break;
		case 10:
			menu_login();
			break;
		}
	}
	if (check_key(40))	//VK_DOWN
	{
		if (menu_select == 10)menu_select = 10;
		else menu_select++;
	}
	else if (check_key(38))	//VK_UP
	{
		if (menu_select == 2)menu_select = 2;
		else if (menu_select == 0)menu_select = 0;
		else menu_select--;
	}
	else goto reinput;
}
}
void menu_guest()
{
	system("cls");
	void export_course();
	extern int menu_login();
	int menu_select = 0;// stu_key = login();
	HANDLE cursor;
	cursor = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_cursor_browse = { 40,7 };
	COORD pos_cursor_logout = { 40,13 };
start:while (1)
{
	switch (menu_select)
	{
	case 0:
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("                                     ©°©¤                 Browse Courses               ©¤©´\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¦                                                ©¦\n"); DI;
		printf("                                     ©¸©¤                 Log Out                      ©¤©¼\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		break;
	case 2:
		SetConsoleCursorPosition(cursor, pos_cursor_browse);
		printf("\33[47;30m                Browse Courses               \33[0m");
		SetConsoleCursorPosition(cursor, pos_cursor_logout);
		printf("                Log Out                      ");
		break;
	case 4:
		SetConsoleCursorPosition(cursor, pos_cursor_browse);
		printf("                Browse Courses               ");
		SetConsoleCursorPosition(cursor, pos_cursor_logout);
		printf("\33[47;30m                Log Out                      \33[0m");
		break;
	}
reinput:_getch();
	if (check_key(13))//VK_ENTER
	{
		switch (menu_select)
		{
		case 2:
			system("cls");
			export_course();
			printf("press any key to continue");
			_getch();
			fflush(stdin);
			system("cls");
			goto start;
			break;
		case 4:
			menu_login();
			break;
		}
	}
	if (check_key(40))	//VK_DOWN
	{
		if (menu_select == 4)menu_select = 4;
		else menu_select++;
	}
	else if (check_key(38))	//VK_UP
	{
		if (menu_select == 2)menu_select = 2;
		else if (menu_select == 0)menu_select = 0;
		else menu_select--;
	}
	else goto reinput;
}
}
BOOL check_key(int ascii_key)
{
	if (GetKeyState(ascii_key) < 0)return 1;
	else return 0;
}
int login()
{
	int id = 20015;
	return id;
}