#include <bits/stdc++.h>
using namespace std;
int pr[6];
char box[2];
int tar;
bool is_ASC;
bool flag;
int main()
{
	//	char egg[3] = {256-57,256-61,'\0'};
	//	printf ("%s", egg);
	int tmp = 0;
	int sum = 0;
	int cnt = 0;
	// for unicode
	int un_1 = 0;
	int un_2 = 0;

	while ((tmp = getchar()) != EOF)
	{
		//		if (tmp != '\n' || tmp != '.')
		//		{
		//			printf ("\nRestricted input is reqired!\nNo modifiction is suggested.\n");
		//			tmp=sum=cnt=un_1=un_2=0;
		//			memset (pr, 0, sizeof(pr));
		//			memset (box, '\0', sizeof(pr));
		//			putchar ('\n');
		//
		//			continue;
		//		}
		if (tmp == '\n')
		{
			tmp = sum = cnt = un_1 = un_2 = 0;
			memset(pr, 0, sizeof(pr));
			memset(box, '\0', sizeof(pr));
			putchar('\n');
			putchar('\n');
			tmp = getchar();
			flag = true;
		}
		if (char(tmp) == '.') // ascll
		{
			is_ASC = true;
			while (char(tmp = getchar()) == '.')
				;
			box[0] = tmp;
			tmp = getchar();
			box[1] = tmp;

			if (box == string("哼"))
				pr[++tar] = 0;
			else if (box == string("嗯"))
				pr[++tar] = 1;
			else if (box == string("啊"))
				pr[++tar] = 2;

			//			printf ("%d", pr[tar]);
		}
		else // unicode
		{
			is_ASC = false;

			//			tmp = -tmp;
			box[0] = tmp;
			tmp = getchar();
			//			tmp = -tmp;
			box[1] = tmp;

			if (box == string("哼"))
				pr[++tar] = 0;
			else if (box == string("嗯"))
				pr[++tar] = 1;
			else if (box == string("啊"))
				pr[++tar] = 2;
			else
			{
				printf("\n\nUndefined value: \'%c\' & \'%c\' \nRestricted input is reqired!\nNo modifiction is suggested.\n", box[0], box[1]);
				system("pause");
				return -1;
			}
			//			printf ("%d", pr[tar]);
		}
		if (++cnt == 5)
		{
			cnt = sum = tar = 0;
			sum += pr[1] * 81;
			sum += pr[2] * 27;
			sum += pr[3] * 9;
			sum += pr[4] * 3;
			sum += pr[5] * 1;
			if (is_ASC)
			{
				//				if (flag) putchar ('\n');
				//				flag = false;
				printf("%c", char(sum));
			}
			else
			{
				if (un_1 == 0) // left uni
				{
					un_1 = sum + 128;
				}
				else // right uni
				{
					//					if (flag) putchar ('\n');
					//					flag = false;
					un_2 = sum + 128;
					char bx[3] = {un_1, un_2, '\0'};
					//					printf ("%d %d\n", un_1, un_2);

					printf("%s", bx);
					un_1 = un_2 = 0;
				}
			}
		}
	}
}
