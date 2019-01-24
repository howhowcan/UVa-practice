#include <stdio.h>
#include <string.h>


int main()
{
	char s[100], ch;
	int n;
	scanf("%d", &n);
	ch = getchar();

	while(n--)
	{
		scanf("%s", s);
		int len = strlen(s), sub_len = 0, f = 1;
		for(int i = 1; i <= len; i++)
		{
			if(len % i == 0)
			{
				f = 1;
				for(int j = 0; j < len - i; j++)
				{
					if(s[j] != s[j+i])
					{
						f = 0;
						break;
					}
				}
				if(f){sub_len = i; break;}
			}
		}

		printf("%d\n", sub_len);
		if(n > 0) printf("\n");
	
	}

	

	return 0;
}