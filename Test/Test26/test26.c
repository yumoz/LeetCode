//����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
//
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

#include<stdio.h>
#include<windows.h>

int removeDuplicates(int* nums, int numsSize){
	if (nums == NULL || numsSize == 0){
		return 0;
	}
	int i = 0, j = i + 1;
	while (j < numsSize){
		if (nums[i] == nums[j]){
			j++;
		}
		else{
			i++;
			nums[i] = nums[j];
			j++;
		}
	}
	return i + 1;
}

int main()
{
	int array[] = { 1, 2, 2, 3, 3, 4, 5 };//ע�����Ҫ�������Ϊ��������
	int len = sizeof(array) / sizeof(array[0]);
	int ret = removeDuplicates(array, len);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

//��ߣ�
//���������������Ļ���Ӧ����ô����