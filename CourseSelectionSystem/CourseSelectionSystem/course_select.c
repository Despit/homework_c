#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#define DI Sleep(50)  //dynamic imitate 0.05 second
#define LEN sizeof
struct course {
	int id;
	int id_inside;
	char name[20];
	int time;
	int time_theory;
	int time_practice;
	char class[20];
	int term;
	int credit;
	struct course* next;
};
struct info {
	int id;
	int id_inside;
	int id_stu;
	char info_selected[20];
	struct info* next;
};

int navigator_add(int stu_primary_key)
{
	system("cls");
	extern BOOL check_key(int ascii_key);
	extern void export_course_selecting(int stu_id);
	extern void export_course();
	int course_select(int stu_id, int id_selected);
	int id_select = 0;
		int continue_count = 0;
		int check = 0;
	reselect:system("cls");
		printf("学校已开设课程：\n"); DI;
		export_course();
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("\n"); DI;
		printf("welcome,user %d \n", stu_primary_key); DI;
		printf("输入想选的科目代号：");
		scanf_s("%d", &id_select);
		check=course_select(stu_primary_key,id_select);
		if (check != 0) return 0;
		_getch();
		system("cls");
		export_course_selecting(stu_primary_key);
		printf("Press 'Y' to Continue\n");
		if (_getch() == 'Y') goto reselect;
		system("cls");
		return 0;
}
int navigation_drop(int stu_primary_key)
{
	extern void drop_course(int stu_id, int selected), export_course_selecting(int stu_id);
	int id_select = 0;
	int check = 0;
	int continue_count = 0;
	reselect:system("cls");
	printf("你选的课程：\n"); DI;
	export_course_selecting(stu_primary_key);
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("\n"); DI;
	printf("welcome,user %d \n", stu_primary_key); DI;
	printf("输入想退的科目代号：");
	scanf_s("%d", &id_select);
	drop_course(stu_primary_key, id_select);
	_getch();
	system("cls");
	printf("continue?\n");
	printf("Press 'Y' to Continue\n");
	if (_getch() == 'Y') goto reselect;
	system("cls");
	return 0;
}

int course_select(int stu_id, int id_selected)
{
	extern struct course* add_course_selected(int ID);
	extern struct info* FileToChain_INFO(FILE * fp);
	FILE* fp;
	errno_t err;
	int course_cursor=0;
	err = fopen_s(&fp, "TABLE_INFO", "rb+");
	if (err != 0)
	{
		printf("INFO_SELECT OPENING FAILDED, CREATING NOW...\n");
		fopen_s(&fp, "TABLE_INFO", "wb+");
	}
	system("cls");
		if (add_course_selected(id_selected) != NULL)
		{
			struct course* temp;
			struct info* selected = (struct info*)malloc(LEN(struct info)), * former = (struct info*)malloc(LEN(struct info)), * check = (struct info*)malloc(LEN(struct info));
			rewind(fp);
			if (fgetc(fp) != EOF)
			{
				check = FileToChain_INFO(fp);
				for (; check != NULL; check = check->next)
				{
					if ((id_selected == check->id)&&(check->id_stu==stu_id))
					{
						printf("已选中，不能复选\n"); DI;
						_getch();
						fclose(fp);
						return 1;
					}
				}
			}
			temp = add_course_selected(id_selected);
			selected->id = temp->id;
			strcpy_s(selected->info_selected, LEN(temp->name) + 1, temp->name);
			rewind(fp);
			if (fgetc(fp) == EOF)
			{
				selected->id_inside = 1;
			}
			else
			{
				fseek(fp, -(int)LEN(struct info), SEEK_END);
				fread(former, LEN(struct info), 1, fp);
				former->next = (struct info*)malloc(LEN(struct info));
				selected->id_inside = former->id_inside + 1;
				fseek(fp, -(int)LEN(struct info), SEEK_END);
				fwrite(former, LEN(struct info), 1, fp);
			}
			selected->id_stu = stu_id;
			selected->next = NULL;
			fwrite(selected, LEN(struct info), 1, fp);
			printf("success\n"); DI;
		}
		else
		{
			printf("查无此课\n"); DI;
			_getch();
			fclose(fp);
			return 1;
		}
	fclose(fp);
		return 0;
}