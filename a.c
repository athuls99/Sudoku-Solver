#include <stdio.h>

//function checks availability for num
int isAvailable(int sudoku[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3; //3x3 box
    int i;

    for(i=0; i<9; i++)
    {
        if(sudoku[row][i] == num) return 0; //column availability
        if(sudoku[i][col] == num) return 0; //row availability
        if(sudoku[rowStart + (i%3)][colStart + (i/3)] == num) return 0;  //box availability
    }
    return 1;
}

int Sudoku_solve(int sudoku[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(sudoku[row][col] != 0) //not empty square
        {
        if((col+1)<9) return Sudoku_solve(sudoku, row, col+1);
        else if((row+1)<9) return Sudoku_solve(sudoku, row+1, 0);
        else return 1;
        }
        else
        {
            for(i=1; i<=9; i++)
            {
                if(isAvailable(sudoku, row, col, i))
                {
                    sudoku[row][col] = i;
                    if((col+1)<9)
                    {
                        if(Sudoku_solve(sudoku, row, col +1))
                            return 1;
                        else
                            sudoku[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(Sudoku_solve(sudoku, row+1, 0)) 
                            return 1;
                        else
                            sudoku[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

void main()
{
    int i, j;
    int sudoku[9][9]={{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},                      
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},	
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    if(Sudoku_solve(sudoku, 0, 0))
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++) 
                printf("%d ", sudoku[i][j]);
            printf("\n");
        }
    else printf("NO SOLUTION");
}
