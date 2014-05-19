// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int i, j;

	scanf("%d %d", &i, &j);

	if (j < i) swap(i, j);
	int count(1), max_count(0), cur_digit(j);
	int n;
	while(cur_digit >= i){
		n = cur_digit;
		count = 1;
		while(n>1) {
			if (!(n % 2))
			{
				n >>= 1;
				count++;
			}else{
				n = n *3 +1;
				n >>= 1;
				count += 2;
			}
		};
		if (count > max_count) max_count = count;
		cur_digit--;
	}

	cout << i << " " << j << " " << max_count << endl;
}

