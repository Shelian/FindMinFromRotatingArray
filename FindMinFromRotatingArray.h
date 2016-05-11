#include <iostream>
using namespace std;


int InorderArray(int* array, int left, int right)
{
	int begin = array[left];
	for (int i = left + 1; i <= right; i++)
	{
		if (begin > array[i])
			return array[i];
	}

	return begin;
}

//size为数组的容量
int FindMinFromRotatingArray(int* array, int size)
{
	int left = 0;
	int right = size - 1;
	int mid = left;
	
	//当左边大于右边的时候做操作，反之最小值即为array[left]
	while (array[left] >= array[right])
	{
		//当只有两个数时，能进入循环，肯定是第2个数小
		if (right - left == 1)
		{
			mid = right;
			break;
		}

		mid = right - (right - left) / 2;
		//处理特殊情况，等序列.如 0 1 1 1 1旋转的情况可能为1 0 1 1 1或者1 1 1 0 1
		if (array[left] == array[right] && array[mid] == array[right])
		{
			return InorderArray(array, left, right);
		}

		if (array[mid] > array[left])
			left = mid;

		else if (array[mid] < array[right])
		{
			right = mid;
		}
	}
}