#include<stdio.h>
#include<windows.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	//end1:nums1��ĩβ
	//end2:nums2��ĩβ
	//end:�ϲ�֮�����������ĩβ
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{   //ѡ��β����Ԫ�أ���ŵ����������ĩβ
		//ÿ���һ��Ԫ�أ�β��ǰ�ƶ�һ��λ��
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	//ʣ��Ԫ��������ĩβ���
	while (end1 >= 0)
	{
		nums1[end--] = nums1[end1--];
	}

	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}
int main()
{
	int array1[] = { 7, 8, 9 };
	int len1 = sizeof(array1) / sizeof(array1[0]);
	int array2[] = { 1, 5, 6,7,8,9 };
	int len2 = sizeof(array2) / sizeof(array2[0]);

	merge(array1, len1, 3, array2, len2, 6);

	for (int i = 0; i < len1 + len2; i++){
		printf("%d ", array1[i]);
	}
	system("pause");
	return 0;
}