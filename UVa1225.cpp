#include <stdio.h>
#include <string.h>

int main()
{
	int n, ch;

	scanf("%d", &n);
	ch = getchar();
	while(n--)
	{
		int num, a, b, c, d, s[20] = {0};
		scanf("%d", &num);
		a = num / 1000;
		b = (num / 100) % 10;
		c = (num / 10) % 10;
		d = num % 10;

		if(a)
		{
			for(int i = 1; i < a; i++)  //千位
			{
				s[i] += 1000;
			}
			s[a] = s[a] + ((num % 1000) + 1);
		}
		else
		{

		}

		
		if(b)
		{
			for(int i = 1; i <= 9; i++)  //百位
			{
				if(i < b)  s[i] = s[i] + (a+1) * 100;
				else       s[i] = s[i] + a * 100;
			}
			s[b] = s[b] + (num % 100) + 1;
			if(a != 0)  s[0] = s[0] + a * 100;

		}
		else
		{
			for(int i = 1; i <= 9; i++)  //百位
			{
				if(i < b)  s[i] = s[i] + (a+1) * 100;
				else       s[i] = s[i] + a * 100;
			}
			if(a != 0)  s[0] = s[0] + (a-1) * 100 + (num % 100) + 1;
		}


		if(c)
		{
			for(int i = 1; i <= 9; i++)  //十位
			{
				if(i < c)  s[i] = s[i] + ((num/100)+1) * 10;
				else       s[i] = s[i] + (num/100) * 10;
			}
			s[c] = s[c] + (num % 10) + 1;
			if(a || b)  s[0] = s[0] + (num/100) * 10;

		}
		else
		{
			for(int i = 1; i <= 9; i++)  //十位
			{
				if(i < c)  s[i] = s[i] + ((num/100)+1) * 10;
				else       s[i] = s[i] + (num/100) * 10;
			}
			if(a || b)  s[0] = s[0] + ((num/100)-1) * 10 + (num % 10) + 1;
		}
		
	

		if(d)
		{
			for(int i = 1; i <= 9; i++)  //個位
			{
				if(i <= d)  s[i] = s[i] + (num/10) + 1;
				else       s[i] = s[i] + (num/10);
			}

			if(a || b || c)  s[0] = s[0] + (num/10);
		}
		else
		{
			for(int i = 1; i <= 9; i++)  //個位
			{
				if(i <= d)  s[i] = s[i] + (num/10) + 1;
				else       s[i] = s[i] + (num/10);
			}

			if(a || b || c)  s[0] = s[0] + (num/10);
		}

		

		for(int i = 0; i < 9; i++)
			printf("%d ", s[i]);
		printf("%d\n", s[9]);
	}
	return 0;
}