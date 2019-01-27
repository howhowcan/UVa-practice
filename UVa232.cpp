#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int r, c, num[20][20], n=1, f=0;
	char conf[20][20], buf;
	while(scanf("%d", &r) && r){
		scanf("%d", &c);
		buf = getchar();
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				scanf("%c", &conf[i][j]);
			}
			buf = getchar();
		}

		int head = 1;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(conf[i][j] != '*'){
					if(i == 0 || j == 0){
						num[i][j] = head;
						head++; 
					}else if(conf[i-1][j] == '*' || conf[i][j-1] == '*'){
						num[i][j] = head;
						head++;
					}else num[i][j] = 0;
				}else num[i][j] = -1;
			}
		}

		if(f)	printf("\n");
		f = 1;
		
		printf("puzzle #%d:\n", n++);
		printf("Across");
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(num[i][j] > 0){
					printf("\n%3d.", num[i][j]);
					for(; j < c && num[i][j] >= 0; j++){
						printf("%c", conf[i][j]);
					}   
				}
			}
		}
		printf("\nDown");
		string down[200];

		for(int i = 0; i < 200; i++)    down[i] = "0";

/*		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("%d  ", num[i][j]);
			}
			printf("\n");
		}*/

		for(int j = 0; j < c; j++){
			for(int i = 0; i < r; i++){
				if(num[i][j] > 0){
					const int k = num[i][j];
					string t(1, conf[i][j]);
					down[num[i][j]] = t;
					i++;
					for(; i < r && num[i][j] >= 0; i++){
						string t(1, conf[i][j]);
						down[k] += t;
					}   
				}
			}
		}


		for(int i = 0; i < 200; i++){
			if(down[i] != "0"){
				printf("\n%3d.", i);
				cout<<down[i];
			}
		}
		printf("\n");
		fflush(stdin);
/*		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("%d", num[i][j]);
			}
			printf("\n");
		}*/
	}	
	return 0;
}