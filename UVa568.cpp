#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	long long least[10005];
	least[0] = least[1] = 1;	

	for (int i = 2; i <= 10000; ++i){
		least[i] = least[i-1] * i;
		while(least[i] % 10 == 0){
			least[i] /= 10;
		}
		if(least[i] > 100000)  least[i] %= 100000;
	}

	while(scanf("%d", &n) == 1){
		printf("%5d -> %d\n", n, (least[n]%10));
	}

	return 0;
}