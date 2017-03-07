#include<cstdio>
#include<iostream>
#define MAX 25+3
using namespace std;
int rows;
int a[MAX][MAX];
int check[MAX][MAX];
int work(int i, int j, int rows)
{
	int x, y, p, k, l;
	static int b[8][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
	if(check[i][j]) return 0;
	check[i][j] = 1;
	if(!a[i][j]) return 0;
	
	for(p = 0; p < 8; p++){
		x = i+b[p][0];
		y = j+b[p][1];
		if(x>=rows||x<0||y>=rows||y<0)
			continue;
		work(x, y, rows);
	}
		
	return 1; 
}

int main()
{
	int t, i, j, k, count, change;
	
	for(t =1; scanf("%d", &rows) != EOF; t++){
		for(i = 0; i < rows; i++)
			for(j = 0; j < rows; j++)
				check[i][j] = 0;
		for(i = 0; i < rows; i++)
			for(j = 0; j < rows; j++){
				scanf("%c", &change);
				if(change == 10)
					scanf("%c", &change);
				a[i][j] = change-48;
			}

		for(i = 0, count = 0; i < rows; i++)
			for(j = 0; j < rows; j++)
				if(work(i, j, rows))
					count++;
		printf("Image number %d contains %d war eagles.\n", t, count);
	}
	return 0;
}
