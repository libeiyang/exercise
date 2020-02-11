写一个函数BinarySearch，在包含size个元素的、从小到大排序的int数组a里查找元素p,如果找到，则返回元素下标，如果找不到，则返回-1。要求复杂度O(log(n))

int BinarySearch(int a[], int size, int p)
{
	int L = 0;
	int R = size-1;

	while(L<=R)
	{
		int mid = (L+R)/2;

		if(p == a[mid])
			return mid;

		else if(p < a[mid])
		{
			R = mid-1;
		}
		else(p > a[mid])
			L = mid+1;
	}
	return -1;
}
写一个函数LowerBound，在包含size个元素的、从小到大排序的int数组a里查找比给定整数p小的，下标最大的元素。找到则返回其下标，找不到则返回-1

int LowerBound(int size, int a[],int p)
{
	int l = 0;
	int R = size - 1;
	while(L<=R)
	{
		int mid = (l+R)/2;

		if(a[mid] == p)
			returm (mid - 1);

		else if(a[mid] > p)
			R = mid - 1;

		else if(a[mid] < p)
			L = mid + 1;
	}
}

这样不好，吧自己写死了，这种不像上一题，一定有==的情况，所以需要有最优解

int LowerBound(int size, int a[],int p)
{
	int l = 0;
	int R = size - 1;
	int LastPos = -1;
	while(L<=R)
	{
		int mid = (l+R)/2;

		if(a[mid] >= p)
			R = mid - 1;
		//你只需要看是不是大于等于p就行

		else{
			LastPos = mid;//到目前位置的最优解
			L = mid + 1;
		}
	}//等到L>R的时候她自己就停了，就像L=R，然后R-1，R<L
	return LastPos;
}

还要注意的是， 取中点 int mid = (L+R)/2 不好，因为L+R可能会溢出
所以我们用最原始的方法，最原始的数学表达式 int mid = L+(R-L)/2

求下面方程的一个根：f(x) = x3-5x2+10x-80 = 0 若求出的根是a，则要求 |f(a)| <= 10^-6


先求导，发现此函数单调递增
于是推出 f(0)<0且 f(100)>0, 便可以二分0，100;
提示 fabs() 在math.h下可求浮点数的绝对值
10^-6意味着你要用double类型

double abs = 1e-6;
double function(int x)
{
	return x*x*x*-5*x*x+10*x-80;
}

int main(){

	int L = 0; int R = 100;int root = L+(R-L)/2;

	while (fabs(function(root)-0) > abs)
		{
			if(function(root)>0)
			{
				R = root;
			}
			else L = root;

			root = L+(R-L)/2;
		}
		 
	printf("%.8f",root);
	return 0;

}

输入n ( n<= 100,000)个整数，找出其中的两个数，它们之和等于整数m(假定肯定有解)。题中所有整数都能用 int 表示

说下思路：
先把输入的n个数排序			O(n*log(n))
然后对每个数a[i], 都二分查找m-a[i],		O(log(n)*n)
最终复杂度O(n*log(n))

也可以在排序后
i = 0; j = n-1(因为从0开始)
看a[i]+a[j];
if((a[i]+a[j])>m)
{
	j--;
}
if((a[i]+a[j])<m)
{
	i++;
}
复杂度也是O(n*log(n);