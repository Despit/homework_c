#include<stdio.h>
#include<Windows.h>
#include<conio.h>

#define DI Sleep(50)//dynamic imitate 0.05 second

int main()

{
	HANDLE MAIN = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorinfo_start;
	GetConsoleCursorInfo(MAIN, &cursorinfo_start);
	cursorinfo_start.bVisible = 0;
	SetConsoleCursorInfo(MAIN, &cursorinfo_start);
	extern menu_login();
	/*system("color F0");*/
	printf("                        ╔═══╗                 ╔══╗                        ╔══╗               \n"); DI;
	printf("                        ║                     ║                           ║                  \n"); DI;
	printf("                        ║    ┌─┐┬ ┬┬─┐┌─┐┌─┐  ╚══╗┌─┐┬  ┌─┐┌─┐┌┬┐┬┌┐┌┌─┐  ╚══╗┬ ┬┌─┐┌┬┐┌─┐┌┬┐\n"); DI;
	printf("                        ║    │ ││ │├┬┘└─┐├┤      ║├┤ │  ├┤ │   │ │││││ ┬     ║└┬┘└─┐ │ ├┤ │││\n"); DI;
	printf("                        ╚═══╝└─┘└─┘┴└─└─┘└─┘  ╚══╝└─┘┴─┘└─┘└─┘ ┴ ┴┘└┘└─┘  ╚══╝ ┴ └─┘ ┴ └─┘┴ ┴\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("                                              press ENTER to into system\n");DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
enter:_getch();
	if (GetAsyncKeyState(VK_RETURN))
		menu_login();
	if (GetAsyncKeyState(VK_ESCAPE))
		exit(0);
	else if (!GetAsyncKeyState(VK_ESCAPE)&& !GetAsyncKeyState(VK_RETURN)) goto enter;
}
