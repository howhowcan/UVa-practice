#include <iostream>
#include <algorithm>

using namespace std;

int item[25] = {0};

bool pack(int k, int space);

int main()
{
	int m;
	cin >> m;
	while(m--){
		int index = 0;
		char buf = ' ';

		while(buf != '\n'){
			cin >> item[index];
			cin.get(buf);
			index++;
		}

		sort(item, item+index);
		int sum = 0;
		
		for(int i = 0; i < index; ++i)
			sum += item[i];
		
		if(sum % 2)  {cout << "NO" << endl; continue;}

		if(pack(index-1, sum/2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
		/*
		for(int i = 0; i < index; ++i){
			cout << item[i] << " ";
		}
		cout << "sum = " << sum << endl;*/

	}
	
	return 0;
}


bool pack(int k, int space){
	if(item[k] > space)  return false;

	if(item[k] == space)  return true;

	for(int i = k-1; i >= 0; --i){
		if(pack(i, space - item[k]))  return true;
	}

	return false;
}









