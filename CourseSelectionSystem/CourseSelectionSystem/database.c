#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#define LEN sizeof
#define DI Sleep(50)//dynamic imitate 0.05 second
struct user {
	int id;
	int id_inside;
	char name[20];
	char passwd[20];
	struct user* next;
};
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
void SPACE_LENGTH(int a);
int create_admin()	//建管理员表
{
	FILE* fp;
	if (fopen_s(&fp, "TABLE_ADMIN", "wb+") != 0) printf("ADMIN TABLE OPENING FAILED");
	int n = 0;					//结点个数
	struct user* head = NULL;
	struct user* p1, * p2;
	struct user* temp = NULL;
	p1 = p2 = (struct user*)malloc(LEN(struct user));
	printf("请输入人员id   不为0\n"); scanf_s("%d", &p1->id);
	if (p1->id == 0) goto end;
	printf("请输入人员姓名 不含空格\n"); scanf_s("%s", &p1->name, 20);
	printf("请输入人员密码 不含空格\n"); scanf_s("%s", &p1->passwd, 20);
	while (p1->id != 0)
	{
		n++;
		if (n == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (struct user*)malloc(LEN(struct user));
		printf("请输入人员id\n"); scanf_s("%d", &p1->id);
		if (p1->id == 0) break;
		printf("请输入人员姓名 不含空格\n"); scanf_s("%s", &p1->name, 20);
		printf("请输入人员密码 不含空格\n"); scanf_s("%s", &p1->passwd, 20);
	}
	p2->next = NULL;
	int i = 0;
	while (head != NULL)
	{
		head->id_inside = ++i;
		fwrite(head, LEN(struct user), 1, fp);
		temp = head->next;
		head = temp;
	}
end:fclose(fp);
	return 0;
}
void export_admin()
{
	char temp[10] = { 0 };
	struct user* FileToChain_ADMIN(FILE * fp);
	FILE* filepointer;
	struct user* show;
	if (fopen_s(&filepointer, "TABLE_ADMIN", "rb") != 0) printf("ADMIN TABLE OPENING FAILDED");
	if (getc(filepointer) == EOF)
	{
		printf("EMPTY FILE");
		goto end;
	}
	show = FileToChain_ADMIN(filepointer);
	printf("+----------+--------------------+--------------------+\n");DI;
	printf("|管理员id  |管理员名            |登录密码            |\n");DI;
	printf("+----------+--------------------+--------------------+\n");DI;
	do
	{
		printf("|%d", show->id);
		_itoa_s(show->id, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp));
		printf("|%s", show->name); SPACE_LENGTH(20 - (int)strlen(show->name));
		printf("|%s", show->passwd); SPACE_LENGTH(20 - (int)strlen(show->passwd)); printf("|\n");DI;
		printf("+----------+--------------------+--------------------+\n");DI;
		show = show->next;
	} while (show != NULL);
end:fclose(filepointer);
}

int create_user()			//建用户表
{
	FILE* fp;
	if (fopen_s(&fp, "TABLE_USER", "wb+") != 0) printf("USER TABLE OPENING FAILED");
	int n = 0;					//结点个数
	struct user* head=NULL;
	struct user* p1, * p2;
	struct user* temp = NULL;
	p1 = p2 = (struct user*)malloc(LEN(struct user));
	printf("请输入人员id   不为0\n"); scanf_s("%d", &p1->id);
	if (p1->id == 0) goto end;
	printf("请输入人员姓名 不含空格\n"); scanf_s("%s", &p1->name,20);
	printf("请输入人员密码 不含空格\n"); scanf_s("%s", &p1->passwd,20);
	while (p1->id != 0)
	{
		n++;
		if (n == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (struct user*)malloc(LEN(struct user));
		printf("请输入人员id\n"); scanf_s("%d", &p1->id);
		if (p1->id == 0) break;
		printf("请输入人员姓名 不含空格\n"); scanf_s("%s", &p1->name,20);
		printf("请输入人员密码 不含空格\n"); scanf_s("%s", &p1->passwd,20);
	}
	p2->next = NULL;
	int i = 0;
	while (head != NULL)
	{
		head->id_inside = ++i;
		fwrite(head, LEN(struct user), 1, fp);
		temp = head->next;
		head = temp;
	}
end:fclose(fp);
	return 0;
}
void export_user()
{
	char temp[10] = { 0 };
	struct user* FileToChain_USER(FILE * fp);
	FILE* filepointer;
	struct user* show;
	if (fopen_s(&filepointer, "TABLE_USER", "rb") != 0) printf("USER TABLE OPENING FAILDED");
	if (getc(filepointer) == EOF)
	{
		printf("EMPTY FILE");
		goto end;
	}
	show = FileToChain_USER(filepointer);
	printf("+----------+--------------------+--------------------+\n");DI;
	printf("|用户id    |用户名              |登录密码            |\n");DI;
	printf("+----------+--------------------+--------------------+\n");DI;
	do
	{
		printf("|%d", show->id); 
		_itoa_s(show->id, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp));
		printf("|%s", show->name); SPACE_LENGTH(20 - (int)strlen(show->name));
		printf("|%s", show->passwd); SPACE_LENGTH(20 - (int)strlen(show->passwd)); printf("|\n");DI;
		printf("+----------+--------------------+--------------------+\n");DI;
		show = show->next;
	} while (show != NULL);
end:fclose(filepointer);
}

void add_new_course()
{
	FILE* fp;
	if (fopen_s(&fp, "TABLE_COURSE", "rb+") == 0)
	{
		struct course course_new;
		struct course* former = (struct course*)malloc(LEN(struct course));
		printf("请输入课程id\n"); scanf_s("%d", &course_new.id);
		printf("请输入课名   不含空格\n"); scanf_s("%s", &course_new.name, 20);
		printf("请输入课时   \n"); scanf_s("%d", &course_new.time);
		printf("请输入授课课时\n"); scanf_s("%d", &course_new.time_theory);
		course_new.time_practice = (course_new.time) - (course_new.time_theory);
		printf("请输入科目类别 不含空格\n"); scanf_s("%s", &course_new.class, 20);
		printf("请输入授课学期\n"); scanf_s("%d", &course_new.term);
		printf("请输入学分\n"); scanf_s("%d", &course_new.credit);
		rewind(fp);
		if (fgetc(fp) == EOF)
		{
			course_new.id_inside = 1;
		}
		else
		{
			fseek(fp, -(int)LEN(struct course), SEEK_END);
			fread(former, LEN(struct course), 1, fp);
			former->next = (struct course*)malloc(LEN(struct course));
			course_new.id_inside = former->id_inside + 1;
			fseek(fp, -(int)LEN(struct course), SEEK_END);
			fwrite(former, LEN(struct course), 1, fp);
		}
		course_new.next = NULL;
		fwrite(&course_new, LEN(struct course), 1, fp);
		printf("success\n"); DI;
		fclose(fp);
	}
	else  printf("FILE OPEN FAILD");
}
int create_course()			//建课程表
{
	FILE* fp;
	if (fopen_s(&fp, "TABLE_COURSE", "wb+") != 0) printf("COURSE TABLE OPENING FAILED");
	int n = 0;					
	struct course* head = NULL;
	struct course* p1, * p2;
	struct course* temp = NULL;
	p1 = p2 = (struct course*)malloc(LEN(struct course));
	printf("请输入课程id   (输入0表示输入结束)\n"); scanf_s("%d", &p1->id);
	if (p1->id == 0) goto end;
	printf("请输入课名   不含空格\n"); scanf_s("%s", &p1->name,20);
	printf("请输入课时   \n"); scanf_s("%d", &p1->time);
	printf("请输入授课课时\n"); scanf_s("%d", &p1->time_theory);
	p1->time_practice = (p1->time) - (p1->time_theory);
	printf("请输入科目类别 不含空格\n"); scanf_s("%s", &p1->class,20);
	printf("请输入授课学期\n"); scanf_s("%d", &p1->term);
	printf("请输入学分\n"); scanf_s("%d", &p1->credit);
	while (p1->id != 0)
	{
		n++;
		if (n == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (struct course*)malloc(LEN(struct course));
		printf("请输入课程id   不为0\n"); scanf_s("%d", &p1->id);
		if (p1->id == 0)break;
		printf("请输入课名   不含空格\n"); scanf_s("%s", &p1->name, 20);
		printf("请输入课时   \n"); scanf_s("%d", &p1->time);
		printf("请输入授课课时\n"); scanf_s("%d", &p1->time_theory);
		p1->time_practice = (p1->time) - (p1->time_theory);
		printf("请输入科目类别 不含空格\n"); scanf_s("%s", &p1->class, 20);
		printf("请输入授课学期\n"); scanf_s("%d", &p1->term);
		printf("请输入学分\n"); scanf_s("%d", &p1->credit);
	} 
	p2->next = NULL;
	int i = 0;
	while (head != NULL)
	{
		head->id_inside = ++i;
		fwrite(head, LEN(struct course), 1, fp);
		temp = head->next;
		head = temp;
	}
	rewind(fp);
end:fclose(fp);
	return 0;
}
void export_course()
{
	char temp[10] = { 0 };
	struct course* FileToChain_COURSE(FILE * fp);
	//create_course();
	FILE* filepointer;
	struct course* show;
	if (fopen_s(&filepointer, "TABLE_COURSE", "rb") != 0) printf("COURSE TABLE OPENING FAILDED");
	if (getc(filepointer) == EOF)
	{
		printf("EMPTY FILE");
		goto end;
	}
	show = FileToChain_COURSE(filepointer);
	printf("+----------+--------------------+----------+----------+----------+--------------------+----------+----------+\n"); DI;
	printf("|课程id    |课程名称            |总课时    |授课课时  |上机课时  |课程性质            |开课学期  |学分      |\n"); DI;
	printf("+----------+--------------------+----------+----------+----------+--------------------+----------+----------+\n"); DI;
	do
	{
		printf("|%d", show->id); DI;
		_itoa_s(show->id, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp));
		printf("|%s", show->name); SPACE_LENGTH(20 - (int)strlen(show->name)); DI;
		printf("|%d", show->time);
		_itoa_s(show->time, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp));
		printf("|%d", show->time_theory);
		_itoa_s(show->time_theory, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp));
		printf("|%d", show->time_practice);
		_itoa_s(show->time_practice, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp));
		printf("|%s", show->class); SPACE_LENGTH(20 - (int)strlen(show->class));
		printf("|%d", show->term);
		_itoa_s(show->term, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp));
		printf("|%d", show->credit);
		_itoa_s(show->credit, temp, 10, 10);
		SPACE_LENGTH(10 - (int)strlen(temp)); printf("|\n"); DI;
		printf("+----------+--------------------+----------+----------+----------+--------------------+----------+----------+\n"); DI;
		show = show->next;
	} while (show != NULL);
	end:fclose(filepointer);
}
errno_t delete_course(int selected)
{
	struct course* FileToChain_COURSE(FILE * fp);
	FILE* fp;
	errno_t err;
	struct course* temp_head = (struct course*)malloc(LEN(struct course));
	struct course* p1 = (struct course*)malloc(LEN(struct course)), * p2 = (struct course*)malloc(LEN(struct course));
	if (err = fopen_s(&fp, "TABLE_COURSE", "rb+") != 0) printf("err");
	if (fgetc(fp) == EOF)
	{
		printf("EMPTY COURSE TABLE\n");
		goto end;
	}
	temp_head = FileToChain_COURSE(fp);
	p1 = temp_head;
	rewind(fp);
	while ((selected != p1->id) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (selected == p1->id)
	{
		if (temp_head->id != selected)p2->next = p1->next;
		else(temp_head = temp_head->next);
	}
	else
	{
		printf("查无此课\n");
		goto end;
	}
	fclose(fp);
	if (err = fopen_s(&fp, "TABLE_COURSE", "wb") != 0) printf("faild");
	if (temp_head == NULL)
	{
		printf("success\n");
		fclose(fp);
		return 0;
	}
	else
	{
		do
		{
			fwrite(temp_head, LEN(struct course), 1, fp);
			temp_head = temp_head->next;
		} while (temp_head != NULL);
		printf("success\n");
		fclose(fp);
		return 0;
	}
end:fclose(fp);
	return 1;
}
void drop_course_admin(int selected)
{
	struct info* FileToChain_INFO(FILE * fp);
	FILE* fp;
	errno_t err;
	struct info* temp_head = (struct info*)malloc(LEN(struct info));
	struct info* p1 = (struct info*)malloc(LEN(struct info)), * p2 = (struct info*)malloc(LEN(struct info));
	if (err = fopen_s(&fp, "TABLE_INFO", "rb+") != 0) printf("err");
	if (fgetc(fp) == EOF)
	{
		printf("EMPTY COURSE TABLE\n");
		goto end;
	}
	temp_head = FileToChain_INFO(fp);
	p1 = temp_head;
	rewind(fp);
	while ((selected != p1->id) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (selected == p1->id)
	{
		if (temp_head->id != selected)p2->next = p1->next;
		else(temp_head = temp_head->next);
	}
	fclose(fp);
	if (err = fopen_s(&fp, "TABLE_INFO", "wb") != 0) printf("faild");
	if (temp_head == NULL)
	{
		printf("success");
		goto end;
	}
	else
	{
		do
		{
			fwrite(temp_head, LEN(struct info), 1, fp);
			temp_head = temp_head->next;
		} while (temp_head != NULL);
		printf("success");
	}
end:fclose(fp);
}
void drop_course(int stu_id,int selected)
{
	struct info* FileToChain_INFO(FILE * fp);
	FILE* fp;
	errno_t err;
	struct info* temp_head=(struct info*)malloc(LEN(struct info));
	struct info* p1= (struct info*)malloc(LEN(struct info)), *p2= (struct info*)malloc(LEN(struct info));
	if (err = fopen_s(&fp, "TABLE_INFO", "rb+") != 0) printf("err");
	if (fgetc(fp) == EOF)
	{
		printf("EMPTY COURSE TABLE\n");
		goto end;
	}
	temp_head = FileToChain_INFO(fp);
	p1 = temp_head;
	rewind(fp);
		while ((selected != p1->id) && (p1->next != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if ((selected == p1->id) && (stu_id == temp_head->id_stu))
		{
			if (temp_head->id != selected)p2->next = p1->next;
			else(temp_head = temp_head->next);
		}
		else
		{
			printf("查无此课");
			goto end;
		}
	fclose(fp);
	if(err = fopen_s(&fp, "TABLE_INFO", "wb")!=0) printf("faild");
	if (temp_head == NULL)
	{
		printf("success");
		goto end;
	}
	else
	{
		do
		{
			fwrite(temp_head, LEN(struct info), 1, fp);
			temp_head = temp_head->next;
		} while (temp_head != NULL);
		printf("success");
	}
end:fclose(fp);
}
void sort_credit(int credit)
{
	FILE* fp;
	char temp[10] = { 0 };
	struct course* target = NULL;
	fopen_s(&fp, "TABLE_COURSE", "rb");
	struct course* show = FileToChain_COURSE(fp);
	printf("+----------+--------------------+----------+----------+----------+--------------------+----------+----------+\n"); DI;
	printf("|课程id    |课程名称            |总课时    |授课课时  |上机课时  |课程性质            |开课学期  |学分      |\n"); DI;
	printf("+----------+--------------------+----------+----------+----------+--------------------+----------+----------+\n"); DI;
	do
	{
		if (credit == show->credit)
		{
			printf("|%d", show->id); DI;
			_itoa_s(show->id, temp, 10, 10);
			SPACE_LENGTH(10 - (int)strlen(temp));
			printf("|%s", show->name); SPACE_LENGTH(20 - (int)strlen(show->name)); DI;
			printf("|%d", show->time);
			_itoa_s(show->time, temp, 10, 10);
			SPACE_LENGTH(10 - (int)strlen(temp));
			printf("|%d", show->time_theory);
			_itoa_s(show->time_theory, temp, 10, 10);
			SPACE_LENGTH(10 - (int)strlen(temp));
			printf("|%d", show->time_practice);
			_itoa_s(show->time_practice, temp, 10, 10);
			SPACE_LENGTH(10 - (int)strlen(temp));
			printf("|%s", show->class); SPACE_LENGTH(20 - (int)strlen(show->class));
			printf("|%d", show->term);
			_itoa_s(show->term, temp, 10, 10);
			SPACE_LENGTH(10 - (int)strlen(temp));
			printf("|%d", show->credit);
			_itoa_s(show->credit, temp, 10, 10);
			SPACE_LENGTH(10 - (int)strlen(temp)); printf("|\n"); DI;
			printf("+----------+--------------------+----------+----------+----------+--------------------+----------+----------+\n"); DI;
		} 
		show = show->next;
	} while (show != NULL);
}
void export_course_selecting(int stu_id)
{
	char test[20] = { 0 };
	_itoa_s(stu_id, test, 20, 10);
	char temp[20] = { 0 };
	struct info* FileToChain_INFO(FILE * fp);
	FILE* fp;
	struct info* show;
	if(fopen_s(&fp,"TABLE_INFO","rb")!=0) printf("INFO_SELECT OPENING FAILDED");
	if (fgetc(fp) != EOF)
	{
		rewind(fp);
		show = FileToChain_INFO(fp);
	}
	else goto end;
	printf("+----------+--------------------+\n");
	printf("|序号      |课程名称            |\n");
	printf("+----------+--------------------+\n");
	do
	{
		if (show->id_stu == stu_id)
		{
			printf("|%d", show->id);
			_itoa_s(show->id, temp, 10, 10); SPACE_LENGTH(10 - (int)strlen(temp));
			printf("|%s", show->info_selected); SPACE_LENGTH(20 - (int)strlen(show->info_selected));
			printf("|\n");
			printf("+----------+--------------------+\n");
		}
		show = show->next;
	} while (show != NULL);
end:fclose(fp);
}
struct course* add_course_selected(int ID)
{
	FILE* fp;
	struct course* target = NULL;
	fopen_s(&fp, "TABLE_COURSE", "rb");
	struct course* show = FileToChain_COURSE(fp);
	do
	{
		if (ID == show->id)
		{
			show->next = NULL;
			target = show;
			break;
		}
		show = show->next;
	} while (show != NULL);
	return target;
}
void export_info()
{
	char temp[10] = { 0 };
	struct info* FileToChain_INFO(FILE * fp);
	FILE* filepointer;
	struct info* show;
	if (fopen_s(&filepointer, "TABLE_INFO", "rb") != 0) printf("COURSE TABLE OPENING FAILDED");
	if (getc(filepointer) == EOF)
	{
		printf("EMPTY FILE");
		goto end;
	}
	show = FileToChain_INFO(filepointer);
	do
	{
		printf("%d\n", show->id);
		printf("%d\n", show->id_inside);
		printf("%d\n", show->id_stu);
		printf("%s\n", show->info_selected);
		printf("+----------+--------------------+--------------------+\n"); DI;
		show = show->next;
	} while (show != NULL);
end:fclose(filepointer);
}

struct course* FileToChain_COURSE(FILE* fp)
{
	int i = 0;
	struct course* head, * temp;
	struct course* p1, * p2;
	p1 = p2 = (struct course*)malloc(LEN(struct course));
	temp = (struct course*)malloc(LEN(struct course));
	head = (struct course*)malloc(LEN(struct course));
	fread(temp, LEN(struct course), 1, fp);
	rewind(fp);
	do
	{
		i++;
		if (i == 1) fread(p1, LEN(struct course), 1, fp);
		if (fseek(fp, (i - 1) * LEN(struct course), SEEK_SET) != 0) break;
		fread(temp, LEN(struct course), 1, fp);
		if (i == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (struct course*)malloc(LEN(struct course));
		temp = (struct course*)malloc(LEN(struct course));
		p1 = temp;
	} while (p2->next != NULL);
	p2->next = NULL;
	return head;
}
struct user* FileToChain_USER(FILE* fp)
{
	int i = 0;
	struct user* head, * temp;
	struct user* p1, * p2;
	p1 = p2 = (struct user*)malloc(LEN(struct user));
	temp = (struct user*)malloc(LEN(struct user));
	head = (struct user*)malloc(LEN(struct user));
	fread(temp, LEN(struct user), 1, fp);
	rewind(fp);
	do
	{
		i++;
		if (i == 1) fread(p1, LEN(struct user), 1, fp);
		if (fseek(fp, (i - 1) * LEN(struct user), SEEK_SET) != 0) break;
		fread(temp, LEN(struct user), 1, fp);
		if (i == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (struct user*)malloc(LEN(struct user));
		temp = (struct user*)malloc(LEN(struct user));
		p1 = temp;
	} while (p2->next != NULL);
	p2->next = NULL;
	return head;
}
struct user* FileToChain_ADMIN(FILE* fp)
{
	int i = 0;
	struct user* head, * temp;
	struct user* p1, * p2;
	p1 = p2 = (struct user*)malloc(LEN(struct user));
	temp = (struct user*)malloc(LEN(struct user));
	head = (struct user*)malloc(LEN(struct user));
	fread(temp, LEN(struct user), 1, fp);
	rewind(fp);
	do
	{
		i++;
		if (i == 1) fread(p1, LEN(struct user), 1, fp);
		if (fseek(fp, (i - 1) * LEN(struct user), SEEK_SET) != 0) break;
		fread(temp, LEN(struct user), 1, fp);
		if (i == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (struct user*)malloc(LEN(struct user));
		temp = (struct user*)malloc(LEN(struct user));
		p1 = temp;
	} while (p2->next != NULL);
	p2->next = NULL;
	return head;
}
struct info* FileToChain_INFO(FILE* fp)
{
	int i = 0;
	struct info* head, * temp;
	struct info* p1, * p2;
	p1 = p2 = (struct info*)malloc(LEN(struct info));
	temp = (struct info*)malloc(LEN(struct info));
	head = (struct info*)malloc(LEN(struct info));
	fread(temp, LEN(struct info), 1, fp);
	rewind(fp);
	do
	{
		i++;
		if (i == 1) fread(p1, LEN(struct info), 1, fp);
		if (fseek(fp, (i - 1) * LEN(struct info), SEEK_SET) != 0) break;
		fread(temp, LEN(struct info), 1, fp);
		if (i == 1)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (struct info*)malloc(LEN(struct info));
		temp = (struct info*)malloc(LEN(struct info));
		p1 = temp;
	} while (p2->next != NULL);
	p2->next = NULL;
	return head;
}
void SPACE_LENGTH(int a)
{
	for (int i = 0; i < a; i++) printf(" ");
}
