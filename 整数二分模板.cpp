// 在单调递增序列a中查找>=x的数中最小的一个（即x或x的后继）
while (low < high)
{
	int mid = (low + high) / 2;
	if (a[mid] >= x)
		high = mid;
	
	else
		low = mid + 1;
}

// 在单调递增序列a中查找<=x的数中最大的一个（即x或x的前驱）
while (low < high)
{
	int mid = (low + high + 1) / 2;
	
	if (a[mid] <= x)
		low = mid;
	
	else
		high = mid - 1;
}
