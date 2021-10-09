#include <stdio.h> 
int check_num(int table[9][9],int row,int col,int num) //เช็คตัวเลขของแต่ละกล่องเข้าไปเลย
{
    int x;
    int box_row = (row/3) * 3;
    int box_col = (col/3) * 3;
    for (x=0;x<9;x++)
    {
        if(table[row][x] == num)
        {
            return 0;
        }
        if(table[x][col] == num)
        {
            return 0;
        }
        if(table[box_row + (x%3)][box_col + (x/3)] == num)
        {
            return 0;
        }
    }
    return 1;
}
int answer_num(int table[9][9], int row, int col)
{
    int x;
    if(row<9 && col<9) 
    {
        if(table[row][col] !=0) //คัวเลขต้องไม่เป็น 0 (ช่องว่าง)
        {
            if((col+1)<9)
            {
                return answer_num(table,row,col+1);
            }
            else if((row+1)<9)
            {
                return answer_num(table,row+1,0);
            }
            else
            {
                return 1;
            }
        }
        else
        {
            for(x=0;x<9;x++)
            {
                if(check_num(table,row,col,x+1))
                {
                    table[row][col]=x+1;
                    if((col+1)<9)
                    {
                        if(answer_num(table,row,col+1))
                        {
                            return 1;
                        }
                        else
                        {
                            table[row][col]=0;
                        }
                    }
                    else if((row+1)<9)
                    {
                        if (answer_num(table,row+1,0))
                        {
                            return 1;
                        }
                        else
                        {
                            table[row][col]=0;
                        }
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int x,y;
    int table[9][9] ={ { 9 , 1 , 0 , 7 , 0 , 0 , 0 , 0 , 0 },
                       { 0 , 3 , 2 , 6 , 0 , 9 , 0 , 8 , 0 },
                       { 0 , 0 , 7 , 0 , 8 , 0 , 9 , 0 , 0 },
                       { 0 , 8 , 6 , 0 , 3 , 0 , 1 , 7 , 0 },
                       { 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 },
                       { 0 , 5 , 1 , 0 , 2 , 0 , 8 , 4 , 0 },
                       { 0 , 0 , 9 , 0 , 5 , 0 , 3 , 0 , 0 },
                       { 0 , 2 , 0 , 3 , 0 , 1 , 4 , 9 , 0 },
                       { 0 , 0 , 0 , 0 , 0 , 2 , 0 , 6 , 1 } };
    if(answer_num(table,0,0))
    {
        for(x=1;x<10;x++) //x=row
        {
            for(y=1;y<10;y++)   //y=col
            {
                printf("%d  ",table[x-1][y-1]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Can't find the answer");
    }
    return 0;
}