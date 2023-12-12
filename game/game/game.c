#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for ( i = 0; i < rows; i++)
	{
		int j = 0;
		for ( j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    printf("-----扫雷游戏------\n");
    int i = 0;
    for (i = 0; i <= col; i++) 
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++) 
    {
        printf("%d ", i);
        int j = 0;
        for (j = 1; j <= col; j++) 
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;

        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
    int count = 0;
    int i = 0;
    for ( i = x-1; i <= x+1; i++)
    {
        int j = 0;
        for ( j = y-1; j <= y+1; j++)
        {
            count += mine[i][j] - '0';
        }
    }
    return count;
}

//排查雷
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while ( win < (row * col - EASY_COUNT) )
    {
        printf("请输入要排查的坐标：\n");
        scanf("%d %d", &x, &y);

        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                printf("很遗憾，你踩到雷了\n");
                DisplayBoard(mine, ROW, COL);
                break;
            }
            else
            {
                int count = GetMineCount(mine, x, y);
                show[x][y] = count + '0';
                DisplayBoard(show, ROW, COL);
                win++;
            }
        }
        else
        {
            printf("输入的坐标非法\n");
        }
    }
    if (win == col*row - EASY_COUNT)
    {
        printf("恭喜你，排雷成功\n");
        DisplayBoard(mine, ROW, COL);
    }
}


