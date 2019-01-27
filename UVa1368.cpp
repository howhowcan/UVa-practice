#include <stdio.h>
#define maxm 100
#define maxn 1200

char d[maxm][maxn];

int compare(int a, int c, int g, int t){

	if(a>=c && a>=g && a>=t){printf("A");return a;}	
	else if(c>=a && c>=g && c>=t){printf("C");return c;}	
	else if(g>=a && g>=c && g>=t){printf("G");return g;}	
	else	{printf("T");return t;}
	
}

int main()
{
	int count, f = 0;
	char buf;
	scanf("%d", &count);
	buf = getchar();
	while(count--){
		int m, n;
		scanf("%d%d", &m, &n);
		buf = getchar();
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)	scanf("%c", &d[i][j]);
			buf = getchar();
		}

		/*if(f)	printf("\n");
		f = 1;*/


		int num_a = 0, num_c = 0, num_g = 0, num_t = 0;
		int err = 0, most;
		for(int j = 0; j < n; j++){
			num_a = 0; num_c = 0; num_g = 0; num_t = 0;

			for(int i = 0; i < m; i++){
				switch(d[i][j]){
					case 'A':	num_a++;  break;
					case 'C':	num_c++;  break;
					case 'G':	num_g++;  break;
					case 'T':	num_t++;  break;
				}
			}

			most = compare(num_a, num_c, num_g, num_t);
			err = err + m - most;
		}
		printf("\n%d\n", err);


/*		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)	printf("%c", d[i][j]);
			printf("\n");
		}*/
	}
	return 0;
}