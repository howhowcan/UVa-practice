#include <stdio.h>
#include <iostream>
//#include <time.h>
#define maxn 1000

using namespace std;

struct piece
{
	int r, c;
	char type;	
};

piece army[maxn], john;
int num;
int checkmate(piece a, piece john2);



int eat(int r, int c){		//其中一個棋子可吃return 1
	piece john2;
	john2.r = john.r;
	john2.c = john.c;
	john2.r += r;
	john2.c += c;
//	printf("eat(%d, %d): john2.r = %d john2.c = %d\n", r, c, john2.r, john2.c);
	for(int i = 0; i < num; i++){
		if(checkmate(army[i], john2))
			return 1;
	}	
	return 0;
}



int checkmate(piece a, piece john2){	//這顆棋子可吃return 1

	switch(a.type){
		case 'G':

			if(a.c == john2.c){
				for(int i = 0; i < num; i++)
					if(army[i].c == a.c && army[i].r < a.r && army[i].r > john2.r){return 0; break;}
				return 1;
			}else return 0;		
			break;

		case 'R':
			if(a.c == john2.c && a.r == john2.r)	return 0;
			else if(a.c == john2.c){
				int big, small;
				if(a.r > john2.r){big = a.r; small = john2.r;}
				else	{big = john2.r; small = a.r;}
				for(int i = 0; i < num; i++)
					if(army[i].c == a.c && army[i].r < big && army[i].r > small){return 0; break;}
				return 1;				
			}else if(a.r == john2.r){
				int big, small;
				if(a.c > john2.c){big = a.c; small = john2.c;}
				else	{big = john2.c; small = a.c;}
				for(int i = 0; i < num; i++)
					if(army[i].r == a.r && army[i].c < big && army[i].c > small){return 0; break;}
				return 1;
			}else	return 0;
			break;

		case 'C':
			if(a.c == john2.c && a.r == john2.r)	return 0;
			else if(a.c == john2.c){
				int big, small;
				if(a.r > john2.r){big = a.r; small = john2.r;}
				else	{big = john2.r; small = a.r;}
				int count = 0;
				for(int i = 0; i < num; i++)
					if(army[i].c == a.c && army[i].r < big && army[i].r > small){count++;}
				if(count == 1)	{/*printf("kill_by_C\n");*/ return 1;}
				else	return 0;
			}else if(a.r == john2.r){
				int big, small;
				if(a.c > john2.c){big = a.c; small = john2.c;}
				else	{big = john2.c; small = a.c;}
				int count = 0;
				for(int i = 0; i < num; i++)
					if(army[i].r == a.r && army[i].c < big && army[i].c > small){count++;}
				if(count == 1)	return 1;
				else	return 0;
			}else	return 0;
			break;

		case 'H':
			int big_r, big_c, small_r, small_c;
			if(a.c > john2.c){big_c = a.c; small_c = john2.c;}
			else	{big_c = john2.c; small_c = a.c;}
			if(a.r > john2.r){big_r = a.r; small_r = john2.r;}
			else	{big_r = john2.r; small_r = a.r;}
	
			if(a.c == john2.c && a.r == john2.r){
				return 0;
			}	
			else if(big_r - small_r == 2 && big_c - small_c == 1){
				int count = (john2.r - a.r) / 2;
				for(int i = 0; i < num; i++)
					if(army[i].c == a.c && army[i].r == a.r + count){return 0; break;}
				//printf("kill_by_H\n");
				return 1;
			}else if(big_c - small_c == 2 && big_r - small_r == 1){
				int count = (john2.c - a.c) / 2;
				for(int i = 0; i < num; i++)
					if(army[i].r == a.r && army[i].c == a.c + count){return 0; break;}
				return 1;
			}else	return 0;
	}
	return 0;
}

int main()
{
	while(cin>>num>>john.r>>john.c){
		if(num == 0 && john.r == 0 && john.c == 0)	break;
		
		for(int i = 0; i < num; i++){
			cin>>army[i].type>>army[i].r>>army[i].c;
		}
		int ckmt = 1;
		int j = 0;
		for(int i = 0; i < num; i++){
			if(army[i].type == 'G' && army[i].c == john.c){
				for(j = 0; j < num; j++){
					if(army[j].c == john.c && army[j].r < army[i].r && army[j].r > john.r)	break;
				}
				if(j == num)  ckmt = 0;
			}
		}
		if(john.c == 4){
			if(!eat(0, 1))	ckmt = 0;
		}
		else if(john.c == 5){
			if(!eat(0, 1))	ckmt = 0;
			else if(!eat(0, -1)) ckmt = 0;
		}
		else if(!eat(0, -1))	ckmt = 0;

		if(john.r == 1){
			if(!eat(1, 0))	ckmt = 0;
		}
		else if(john.r == 2){
			if(!eat(1, 0))	ckmt = 0;
			else if(!eat(-1, 0))	ckmt = 0;
		}
		else if(!eat(-1, 0))	ckmt = 0;
	
		
		if(ckmt)	printf("YES\n");
		else	printf("NO\n");

/*		for(int i = 0; i < num; i++){
			printf("%c %d %d\n", army[i].type, army[i].r, army[i].c);
		}*/

	}
//	printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}


