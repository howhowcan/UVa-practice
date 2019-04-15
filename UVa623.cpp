#include <iostream>
#include <stdio.h>
#define MAX_LEN 4000
using namespace std;

int a[1001][MAX_LEN] = {0};

void big_mul(int *num1, int i, int *num2);

int main(){
	a[0][0] = 1;
	a[1][0] = 1;
	for(int i = 2; i < 1001; ++i){
		big_mul(a[i-1], i, a[i]);		
	}
	int num;
	while(scanf("%d", &num) == 1){

		printf("%d!\n", num);

		int flag = 0;
		for(int i = MAX_LEN - 1; i >= 0; i--){
			if(!flag && a[num][i] != 0)  flag = 1;

			if(flag){
				printf("%d", a[num][i]);
			}
		}


		printf("\n");
	}
	return 0;
}


void big_mul(int *num1, int i, int *num2){
	int carry = 0;
	for(int j = 0; j < MAX_LEN; ++j){
		num2[j] = num1[j] * i + carry;
		carry = num2[j] / 10;
		num2[j] %= 10; 
	}

}