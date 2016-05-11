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

//sizeΪ���������
int FindMinFromRotatingArray(int* array, int size)
{
	int left = 0;
	int right = size - 1;
	int mid = left;
	
	//����ߴ����ұߵ�ʱ������������֮��Сֵ��Ϊarray[left]
	while (array[left] >= array[right])
	{
		//��ֻ��������ʱ���ܽ���ѭ�����϶��ǵ�2����С
		if (right - left == 1)
		{
			mid = right;
			break;
		}

		mid = right - (right - left) / 2;
		//�������������������.�� 0 1 1 1 1��ת���������Ϊ1 0 1 1 1����1 1 1 0 1
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