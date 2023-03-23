#include<stdio.h>

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}


void solve(int a[], int low, int high,int &max1,int &max2)
{
	if (low == high)
	{
		max1 = a[low];
		max2 = 0;
	}
	else if (low == high - 1)
	{
		max1 = max(a[low], a[high]);
		max2 = min(a[low], a[high]);
	}
	else
	{
		int mid = (low + high) / 2;
		int lmax1, lmax2;
		solve(a, low, mid, lmax1, lmax2);
		int rmax1, rmax2;
		solve(a, mid + 1, high, rmax1, rmax2);
		if (lmax1 > rmax1)
		{
			max1 = lmax1;
			max2 = max(lmax2, rmax1);
		}
		else
		{
			max1 = rmax1;
			max2 = max(lmax1, rmax2);
		}
	}
}


void main()
{
	int max1, max2;
	int a[] = { 1,5,7,9,6,2,4,3 ,8};
	solve(a, 0, 8,max1,max2);
	printf("最大值：%d\n次大值：%d", max1, max2);
}