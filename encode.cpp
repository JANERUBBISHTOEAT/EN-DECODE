#include <bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

bool cn[2000]; // if unicode or ascll
int pr[2000];
int size_A;
int size_U;

int main()
{
#ifdef _WIN32
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
#endif
	srand((unsigned)time(NULL));
	int input[2000];
	int output[2000];
	char tmp;
	int size = 0;
	int cnt = 0;
	int ch, mo;
	int ans[6] = {0}; //[5]

	for (;;)
	{
		size_U = size_A = size = cnt = ch = mo = 0;
		ans, pr, cn, input, output,
			memset(ans, 0, sizeof(ans));
		memset(pr, 0, sizeof(pr));
		memset(cn, 0, sizeof(cn));
		memset(input, 0, sizeof(input));
		memset(output, 0, sizeof(output));
		while ((tmp = getchar()) != '\n')
		{
			input[++size] = (int)(tmp);
		}
		putchar('\n');
		for (int i = 1; i <= size; i++)
		{
			ch = input[++cnt];
			if (ch < 0) // if unicode or ascll
			{
				ch = ((unsigned char)ch) - 128;
				size_U++;
			}
			else
			{
				cn[cnt] = 1; // mark ascll
				size_A++;
			}

			int ttmp = 5;
			memset(ans, 0, sizeof(ans));
			while (ch != 0)
			{
				mo = ch % 3;
				ch = (ch - mo) / 3;
				ans[ttmp--] = mo;
			}

			for (int j = 1; j <= 5; j++)
			{
				pr[(i - 1) * 5 + j] = ans[j];
			}
		}

		int tar = 0;
		for (int i = 1; i <= size * 5; i++)
		{
			if (cn[int((i - 1) / 5) + 1])
			{
				output[++tar] = 3; // print '.'
			}
			output[++tar] = pr[i]; // print '哼嗯啊'
		}

		cnt = 0;

		for (int i = 1; i <= (size_A * 2 + size_U) * 5; i++)
		{
			switch (output[i])
			{
			case 0:
				printf("哼");
				break;
			case 1:
				printf("嗯");
				break;
			case 2:
				printf("啊");
				break;
			case 3:
			{
				int dot = rand() % 3 + 2;
				for (int j = 0; j < dot; j++)
				{
					printf(".");
				}
				break;
			}
			}
		}
		putchar('\n');
		putchar('\n');
	}
	system("pause");
	return 0;
}
