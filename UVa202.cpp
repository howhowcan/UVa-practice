#include <stdio.h>
#define maxn 3000

int ans[maxn], rec[maxn];

int main()
{
	int a, b, first_num;
	char buf;
	
	while(scanf("%d%d", &a, &b) != EOF){

		buf = getchar();
		printf("%d/%d = ", a, b);

		first_num = a / b;
		rec[0] = a % b;
		a = rec[0];
		int n = -1, temp, k = -1;
		while(k == -1){
			n++;			
			temp = 10 * a;
			ans[n] = temp / b;
			rec[n+1] = temp % b;
			a = rec[n+1];

			for(int i = 0; i < n + 1; i++){
				if(rec[n+1] == rec[i]){k = i; break;}
			}
		}

		printf("%d.", first_num);
		for(int i = 0; i < k ; i++)	printf("%d", ans[i]);
		printf("(");
		

		if((n-k)+1 > 50){
			for(int i = k; i < k + 50; i++)	printf("%d", ans[i]);
			printf("...)\n   %d = number of digits in repeating cycle\n\n", (n-k)+1);
		}else{
			for(int i = k; i < n + 1; i++)	printf("%d", ans[i]);
			printf(")\n   %d = number of digits in repeating cycle\n\n", (n-k)+1);
		}	


/*		for(int i = 0; i < 40; i++){
			printf("%d", ans[i]);
		}*/


		fflush(stdin);

	}
	return 0;
}