#include <stdio.h>
#define MAX 1025
int k;
int x, y;
int board[MAX][MAX];
int tile = 1;
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)return;
	int t = tile++;
	int s = size / 2;
	//左上
	if (dr<tr+s&&dc<tc+s)
	{
		ChessBoard(tr, tc, dr, dc, s);
	}
	else
	{
		board[tr + s - 1][tc + s - 1] = t;
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	//右上
	if (dr < tr + s && dc >= tc + s)
	{
		ChessBoard(tr, tc+s, dr, dc, s);
	}
	else
	{
		board[tr + s - 1][tc + s] = t;
		ChessBoard(tr, tc+s, tr + s - 1, tc + s , s);
	}
	//左下
	if (dr >= tr + s && dc < tc + s)
	{
		ChessBoard(tr+s, tc, dr, dc, s);
	}
	else
	{
		board[tr + s][tc + s - 1] = t;
		ChessBoard(tr+s, tc, tr + s, tc + s - 1, s);
	}
	//右下
	if (dr >= tr + s && dc >= tc + s)
	{
		ChessBoard(tr+s, tc + s, dr, dc, s);
	}
	else
	{
		board[tr + s][tc + s] = t;
		ChessBoard(tr+s, tc + s, tr + s, tc + s, s);
	}
}

void main()
{
	k = 3;
	x = 1, y = 2;
	int size = 1 << k;
	ChessBoard(0, 0, x, y, size);;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%4d", board[i][j]);
		printf("\n");
	}
}