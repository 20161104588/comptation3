// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "iomanip"
#include "string"
#define N 20
#define M 50
float CountAthleteScore(int , float ave, int n, float s[], int m);
void Sort(float a[], int n);
float b[M];
int bh[M];
struct student
{
	int n;
	int a[100];
	char c[100];
	string s[100];
public:
	student()
	{
	}

}
void input()
	{
		for (int i = 0; i<n; i++)
		{
			printf(" 请输入学生的姓名：");
			scanf("%s", s[i]);
			printf(" 请输入学生的性别：");
			scanf("%s", c[i]);
			printf(" 请输入学生的年龄：");
			scanf("%s", a[i]);
		}
	}
void read()  /*文件读取*/
{

	FILE *fp;
	int i, j;


	fp = fopen("athlete.csv", "r");   /*定义指针 打开文件*/
	if (fp == NULL)
	{
		printf("open file error.\n");
		exit(-1);
	}
	else
	{
		printf("学生信息为:\n");
		i = 0;
		while (fscanf(fp, "%s %s %s ",s[i],c[i],a[i] ) != EOF)
		{
			printf("%s %s %s ", s[i], c[i], a[i]);

			i++;
		}
        

	}
	printf("信息保存成功！\n");
	fclose(fp);
}
int main()
{
	int i = 0, n, m, r = 0,S;
	float s[N], a[M], ave = 0.0, sum = 0.0;
	cout << "欢迎使用打分系统" << endl;
	cout << "请输入评委个数";
		cin >> n;
		cout << "请输入选手个数";
		cin >> m;
	cout << endl;
	S = input();
	for (i = 0; i < m; i++)
	{
		cout << "       选手参赛中     " << endl;
		cout <<"编号为：";
		cin >> bh[i];
		a[r++] = CountAthleteScore(bh[i], ave, n, s, m);
	}
	cout << m << "位选手的平均成绩分别是：" << endl;
	for (r = 0; r<m; r++)
		cout << a[r] << "  ";
	    cout << endl;
	Sort(a, m);
    return 0;
}
float CountAthleteScore(int, float ave, int n, float s[], int m)
{
	int j, k, r = 0;
	static int w=0;
	float t, sum = 0.0;
	ave = 0.0;
	cout << "请输入该选手成绩：" << endl;
	for (k = 0; k < n; k++)
	{
		cout <<endl;
		cout << "输入第" << k + 1 << "位评委给分";
			cin >> s[k];
		if ((s[k] > 10) || (s[k] < 0))
		{
			cout << "第" << k + 1 << "位评委输入出现错误" << endl;
			k--;
		}
	}
	for (k = 0; k < n - 1; k++)
	{
		for (j = k + 1; j < n; j++)
		 if(s[k]<s[j])
		{
			 t = s[k];
			 s[k] = s[j];
			 s[j] = t;
		}
	}
	cout << "对评委打分进行排序" << endl;
	for (k = 0; k < n; k++)
	cout << s[k] << "  ";
	cout << endl;
	cout << "去点最高分" << s[0] << "去点最低分" << s[n - 1] << "，后的结果" << endl;
	for (k = 0; k < n - 2; k++)
	{
		cout << s[k + 1] << "  ";
		sum = sum + s[k + 1];
	}
	cout <<endl;
	ave = sum / float(n - 2);
	b[w++] = ave;
	cout << "该选手的平均分" << ave << endl;
	return ave;
	cout << "*******************";
	cout << endl;
}
void Sort(float a[], int m)
{
	int j, r;
	float t;
	for (r = 0; r < m - 1; r++)
	{
		for(j=0;j<m-1;j++)
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	}
	cout << "由高到低的成绩排序为：" << endl;
	for (r = 0; r < m; r++)
		cout << a[r] << "  " << endl;
	cout << "*****************" << endl;
}
