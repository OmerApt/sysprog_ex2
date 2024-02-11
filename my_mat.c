#include "my_mat.h"
#include <stdio.h>
#define DEBUG 0

void copyMatrixForDis(int dest[][10], int src[][10]);
void inputHandlerMain(char input);
void matrixprint(int mat[][10]);

int main()
{

    int matrix[10][10] = {0};
    static int distmatrix[10][10] = {0};
    char c;
    int scaninfo = scanf(" %c", &c);
    while (c != 'D' || scaninfo != EOF)
    {
        if (DEBUG)
            printf("%c\n", c);
        if (c == 'A')
        {
            int curr = 0;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    scaninfo = scanf("%d", &curr);
                    if (scaninfo != EOF)
                        matrix[i][j] = curr;
                    if (DEBUG)
                    {
                        printf("%d on [%d][%d]", matrix[i][j], i, j);
                        printf("\n");
                    }
                }
            }
            createPathMat(distmatrix, matrix);
            // if(DEBUG)
                // matrixprint(distmatrix);
        }
        else if (c == 'B')
        {
            int i, j;
            scaninfo = scanf("%d", &i);
            if (scaninfo != EOF)
                scaninfo = scanf("%d", &j);
            int res = isConnected(i, j, distmatrix);
            if(DEBUG)
                printf("isconn [%d][%d] ",i,j);
            if (res)
                printf("True");
            else
                printf("False");
            printf("\n");
        }
        else if (c == 'C')
        {
            int i, j;
            scaninfo = scanf("%d", &i);
            if (scaninfo != EOF)
                scaninfo = scanf("%d", &j);

            if(DEBUG)
                printf("shortpath [%d][%d] ",i,j);
            int res = shortestPath(i, j, distmatrix);
            printf("%d",res);
            printf("\n");
        }

        scaninfo = scanf(" %c", &c);
    }

    return 0;
}


void matrixprint(int mat[][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int val = mat[i][j];
            printf("%d ",val);
        }

        printf("\n");
    }
    
}

int shortestPath(int i, int j, int dist[][10])
{
    int path = i == j ? -1 : dist[i][j];
    return path == __INT_MAX__ ? -1 : path;
}

void createPathMat(int dist[][10], int mat[][10])
{
    copyMatrixForDis(dist, mat);
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                // if (i == 0)
                //     printf("[%d][%d]=%d [%d][%d],[%d][%d]=%d\n", i, j, dist[i][j], i, k, k, j, (dist[i][k] + dist[k][j]));
                if (dist[i][k] < __INT_MAX__ && dist[k][j] < __INT_MAX__)
                {
                    if (dist[i][j] > (dist[i][k] + dist[k][j]))
                    {
                        dist[i][j] = (dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
}

int isConnected(int i, int j, int dist[][10])
{
    int path = i == j ? __INT_MAX__ : dist[i][j];
    return (path != __INT_MAX__);
}

void copyMatrixForDis(int dest[][10], int src[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i != j && (src[i][j] == 0))
            {
                dest[i][j] = __INT_MAX__;
            }
            else
                dest[i][j] = src[i][j];
            // printf("///////%d//////////%d[]",dest[i][j],src[i][j]);
        }
        // printf("\n");
    }
}

// void resetMatrix(int mat[][10]){
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             mat[i][j] = 0;
//         }

//     }

//     return;
// }
