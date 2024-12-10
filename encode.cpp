#include <bits/stdc++.h>
using namespace std;
//char map[3]{'哼','嗯','啊'};
bool cn[2000];//if unicode or ascll
int pr[2000];
int size_A;
int size_U; 

int main ()
{
	srand((unsigned)time(NULL));
	int input[2000];
	int output[2000];
	char tmp;
	int size = 0;
	int cnt = 0;
	int ch, mo;
	int ans[6] = {0};//[5] 
	
	for(;;)
	{
		size_U = size_A = size = cnt = ch = mo = 0;
		ans,pr,cn,input,output,
		memset (ans, 0, sizeof(ans));
		memset (pr, 0, sizeof(pr));
		memset (cn, 0, sizeof(cn));
		memset (input, 0, sizeof(input));
		memset (output, 0, sizeof(output));
		while ((tmp=getchar()) != '\n')
		{
			input[++size] = (int)(tmp);
		}
		putchar ('\n');
		for (int i = 1; i <= size; i++)
		{
			ch = input[++cnt];
			if (ch < 0)//if unicode or ascll
			{
				ch = ((unsigned char)ch) - 128;
				size_U++;
			}
			else
			{
				cn[cnt] = 1;//mark ascll 
				size_A++;
			}
//			printf ("%d = ", ch);
			
			int ttmp = 5;
			memset (ans, 0, sizeof(ans));
			while (ch != 0)
			{
				mo = ch % 3;
				ch = (ch - mo) / 3;
				ans[ttmp--] = mo;
			}
			
			for (int j = 1; j <= 5; j++)
			{
//				printf ("%d ", ans[j]);
				pr[(i-1)*5+j] = ans[j];
			}
//			if (cn[i])//log
//			{
//				printf ("ASC\n");
//			}
//			else printf ("UNI\n");
//			putchar('\n');
		}
	//	for (int i = 1; i <= size * 5; i++)
	//	{
	//		printf ("%d ", pr[i]);
	//	}
	//	putchar('\n');
		
		int tar = 0;
		for (int i = 1; i <= size*5; i++)
		{
			//printf ("%d ", pr[i]);
			if (cn[int((i-1)/5)+1])
			{
				output[++tar] = 3;//print '.'
//				printf ("%d ", output[tar]);
			}
	//		switch (pr[i])
	//		{
	//			case 0: output[++tar] = "哼"; break;
	//			case 1: output[++tar] = "嗯"; break;
	//			case 2: output[++tar] = "啊"; break;
	//		}
			//output[++tar] = map[pr[i]];
			output[++tar] = pr[i];//print '哼嗯啊'
//			printf ("%d ", output[tar]);
		}
//		putchar ('\n');
//		putchar ('\n');
		
		cnt = 0;
//		while (input[++cnt] != 0)//log
//		{
//			printf ("%d ", char(input[cnt]));
//		}
//		putchar ('\n');
//		putchar ('\n');
			
		for (int i = 1; i <= (size_A*2+size_U)*5; i++)
		{
			//printf ("\n%d\n", (size_A*2+size_U)*5);
			switch (output[i])
			{
				case 0: printf ("哼"); break; 
				case 1: printf ("嗯"); break; 
				case 2: printf ("啊"); break;
				case 3:
				{
					int dot = rand() % 3 + 2;
					for (int j = 0; j < dot; j++)
					{
						printf (".");
					}
					break;
				}
			}
		}
		
		
		//printf ("%d", input);
		putchar ('\n');
		putchar ('\n');
	}
	system ("pause");
	return 0;
} 
