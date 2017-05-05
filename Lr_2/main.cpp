#include <algorithm>
#include <stdio.h>
#include <iostream>


using namespace std;

const int n = 6;

const int Steps [2] [8] = {
	{1,	2,	-1,	-1, 1,	-2,	2,	-2},
	{2,	1,	2,	-2, -2,	 1,	-1,	-1}
};

void emptyDesk (int x[n][n])
{
    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++)
             x[i][j] = 0;
}

bool horse (int i_ , int j_ , int level, int Desk [n][n])
{
	if (level - 1 == n*n)
   {
        bool flag = 0;
        for (int i = 0; i < 8; i++)
        {
            int i1 = i_ + Steps [0][i];
            int j1 = j_ + Steps [1][i];
            if ((Desk[i1][j1] == 1) && i1 >= 0 && i1 < n && j1 >= 0 && j1 < n)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            printf ("----------- Solution --------------\n");
            Desk[i_][j_] = level-1;
            for (int i=0; i < n; i++)
            {
                for (int j=0; j < n; j++)
                    printf ("%3d" , Desk[i][j]);
                printf ("\n");
            }
            printf ("------- End Of Solution -----------\n\n");
            return true;
        }
    }

    for (int k = 0; k < 8; k++)
    {
		 int i1 = i_ + Steps [0][k];
		 int j1 = j_ + Steps [1][k];

		 if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && Desk[i1][j1] == 0 )
		 {
            Desk [i1][j1] = level;
			horse (i1 , j1 , level + 1, Desk);
			Desk [i1][j1] = 0;
		 }
	}

}

int main ()
{
    int Desk [n][n];
    emptyDesk(Desk);

    for (int i = 0 ; i< n; i++)
        for (int j = 0; j < n; j++)
    {
        int x0 = i, y0 = j;
        Desk [x0][y0] = 1;
        horse (x0 , y0 , 2, Desk);
        emptyDesk(Desk);
    }
	return 0;
}
