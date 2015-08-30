#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int row,col,dominoes;
	scanf("%d %d",&row,&col);
	dominoes = (row * (col/2)) + ((row/2) * (col%2));
	printf("%d",dominoes);
	return 0;
}