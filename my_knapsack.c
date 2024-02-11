#include <stdio.h>
#include "my_knapsack.h"
#define MAXWEIGHT 20
#define MAXLENGTH 5
#define DEBUG 1
int max(int v1, int v2);
void printResult(char names[], int selected_bool[], int res);

int main()
{
    char items_name[MAXLENGTH] = {0};
    int items_weight[MAXLENGTH] = {0};
    int items_value[MAXLENGTH] = {0};
    int selected_items[MAXLENGTH] = {0};

    char name;
    int num, index = 0;

    int scan;
    if (DEBUG)
        printf("start\n");
    do
    {
        scan = scanf(" %c", &name);
        if (scan < 0)
        {
            if (DEBUG)
                printf("%d\n", scan);
            break;
        }
        items_name[index] = name;
        scan = scanf("%d", &num);
        if (scan < 0)
        {
            break;
        }
        items_value[index] = num;
        scan = scanf("%d", &num);

        if (scan < 0)
        {
            break;
        }
        items_weight[index] = num;
        index++;

    } while ((scan > 0 || scan != EOF) && index < MAXLENGTH);

    if (DEBUG)
    {
        printf("scan weight\n");
        for (int i = 0; i < MAXLENGTH; i++)
        {
            printf("%c ", items_name[i]);
            printf("%d ", items_value[i]);
            printf("%d", items_weight[i]);
            printf("\n");
        }
        printf("\n\n");
    }

    int sum = knapSack(items_weight, items_value, selected_items);

    printResult(items_name, selected_items, sum);

    return 0;
}

void printResult(char names[], int selected_bool[], int res)
{
    printf("Maximum profit: ");
    printf("%d", res);
    printf("\n");
    printf("Selected items: ");
    for (int i = 0; i < MAXLENGTH + 1; i++)
    {
        if (selected_bool[i])
            printf("%c ", names[i]);
    }
}

int knapSack(int weights[], int values[], int selected_bool[])
{
    int ksmat[MAXLENGTH + 1][MAXWEIGHT + 1] = {{0}};
    for (int i = 1; i < MAXLENGTH + 1; i++)
    {
        int val = values[i - 1];
        int wt = weights[i - 1];
        if (DEBUG)
        {
            printf("i = %d val = %d wt= %d", i, val, wt);
            printf("\n");
        }
        for (int w = 1; w <= MAXWEIGHT; w++)
        {
            if (wt > w)
            {
                ksmat[i][w] = ksmat[i - 1][w];
            }
            else
            {
                ksmat[i][w] = max(ksmat[i - 1][w], (ksmat[i - 1][w - wt] + val));
            }
        }
    }

    if (DEBUG)
    {
        for (int i = 0; i < MAXLENGTH + 1; i++)
        {
            for (int j = 0; j < MAXWEIGHT; j++)
            {
                printf("%d ", ksmat[i][j]);
            }
            printf("\n");
        }
    }

    int sum = 0;
    int w = MAXWEIGHT;
    for (int i = MAXLENGTH; i >= 1; i--)
    {
        if (ksmat[i - 1][w] != ksmat[i][w])
        {
            selected_bool[i - 1] = 1;
            sum += values[i - 1];
            w -= weights[i - 1];
        }
    }

    return sum;
}

int max(int v1, int v2)
{
    if (v1 > v2)
    {
        return v1;
    }
    else
    {
        return v2;
    }
}
