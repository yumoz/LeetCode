#include<stdio.h>

#include<windows.h>

/*
����˼·����������һ������������ʽ + һ�������� ���غ͵�������ʽ��
ģ��ӷ�������λ��ӣ� �ӵ�λ���λ��ӣ�����������ã��õ����ս��
1. ÿһλ��ֵ = ��Ӧλֵ�ĺ� + ǰһλ�Ľ�λ
2. ÿһλ��ֵ�������֮����Ҫ����Ƿ���Ҫ��λ
3. ���λ����֮����Ҫ�����Ƿ���Ҫ���Ͻ�λ
*/
void reverse(int* nums, int begin, int end)
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;

		++begin;
		--end;
	}
}

// ������Ҫ�ر�ע���[9,9,9,7] + 5�ĵ���������Ĵ���
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int* addRet = (int*)malloc(10001 * sizeof(int));
	//reti: ��iλ�Ľ��
	int reti = 0;
	//�ӵ�λ��ʼ���
	int ai = ASize - 1;
	int next = 0; // ��λֵ
	while (ai >= 0 || K > 0)
	{

		int x1 = 0;
		//���aiû��Խ�磬����δ��ӵ�λ��ȡ��һλ����x1
		if (ai >= 0)
		{
			x1 = A[ai];
			--ai;
		}

		int x2 = 0;
		//���k����0����ȡk�ĵ�iλ
		if (K > 0)
		{
			x2 = K % 10;
			K /= 10;
		}
		//��iλ�Ľ����ÿһλ��ֵ + ��λ
		int ret = x1 + x2 + next;
		//����������9����Ҫ��λ
		if (ret > 9)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}
		//�����iλ�Ľ����������
		addRet[reti++] = ret;
	}
	//������λ�н�λ����Ҫ�ڴ���1
	if (next == 1)
	{
		addRet[reti++] = 1;
	}
	//���ý��
	reverse(addRet, 0, reti - 1);
	*returnSize = reti;

	return addRet;
}



int main()
{
	int array[] = { 1, 2, 0, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	int key = 34;
	int ret = { 0 };
	int *res = addToArrayForm(array, len, key, ret);
	for (int i = 0; i < sizeof(ret); i++){
		printf("%d ", res[i]);
	}
	printf("%d\n", res);
	system("pause");
	return 0;
}