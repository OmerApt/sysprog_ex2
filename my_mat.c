#include "my_mat.h"
#include <stdio.h>
#define DEBUG 0
void copyMatrixForDis(int dest[][10], int src[][10]);


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
