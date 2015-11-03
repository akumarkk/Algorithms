#include <stdio.h>
#include <stdlib.h>

typedef struct stock__
{
    int	    buy;
    int	    sell;
}stocks_t;

stocks_t profit[100];


int
maximize_profit(int *stocks, int n)
{
    int i = 0;
    int count = 0;
    int max_profit = 0;


    // Buy stock whenever it is minimum and sell whenever it reaches its next maximum
    while(i < n-1)
    {
	while(i<n-1 && (stocks[i+1] <= stocks[i]))
	    i++;

	// Though this is the minimum than the earlier one, we can not sell it as we reached 
	// out end of stocks
	if(i >= n-1)
	    break;

	profit[count].buy = i;
	i++;

	while(i < n-1 && (stocks[i+1] >= stocks[i]))
	    i++;

	profit[count].sell = i;
	count++;
	i++;
    }


    
    for(i=0; i<count; i++)
    {
	max_profit += stocks[profit[i].sell]-stocks[profit[i].buy];
	printf("buy = %d    sell = %d	    profit = %d\n", profit[i].buy, profit[i].sell, stocks[profit[i].sell]-stocks[profit[i].buy]);
    }

    return max_profit;
}

int
main()
{
    int n, stocks[] = {100, 180, 260, 310, 40, 535, 695, 500, 700};

    int max = maximize_profit(stocks, 9);
    return 0;
}

