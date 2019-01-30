#include <stdio.h>
#include <iostream>
#include <string.h>
#define maxn 100000

using namespace std;
char sub[maxn], seq[maxn];
int main()
{
	
	while(scanf("%s%s", sub, seq) != EOF){

		int i = 0, j = -1;
		for(; i < strlen(sub); i++){
			j++;
			for(; j < strlen(seq); j++){
				if(sub[i] == seq[j]){	
					break;	
				}				
			}
			if(j == strlen(seq))	break;
		}
		if(i != strlen(sub))  printf("No\n");
		else  printf("Yes\n"); 
		fflush(stdin);
	} 
	return 0;
}	