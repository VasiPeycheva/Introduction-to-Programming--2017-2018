#include <iostream>
//���� � ������ ���� ������������� �����. �� �� ������ ������� reduce,
//����� �� �������� �� ����������� �� �������� �����:
//������ �� � �� ��������� ���������� 2 ����� , ��������� ��,
//���� ����� �� ���� � ������� �� 10 � ������� ����� ������ �� ������ ���  
//���������� �����
//������: 757=> ������� 5 � 7  => 5*7=35 =>35%10=5      
//  ���� ���� ��� ����� ����� ����� ������ ���� 7 � ��� ��� ������� ��������("��������") 5 =>75
//��������� ��������: ������� 7 � 5 => 7*5=35 => 35%10=5
// ���� �������� ��� ����� => 0  �������� 5=> 5 ����
unsigned int reduceEasy(unsigned int num) 
{
	if (num<10)
	{
		return num;
	}
	unsigned short first = num % 10;
	num /= 10;
	unsigned short second = num % 10;
	num /= 10;
	return reduceEasy(num * 10 + (first*second) % 10);
}

//���� � ������ ������������� ���� ����� n.�������� �������(reduce n), ����� �� "��������" �� ����������� �� �������� ��������� :
//-������ ��� - �������� ����� � ������� � � "��������" �� ����(��� ������ �� ���� �������� �������� ��� - ������ ������ �����)
//- �������� �������������� ����� �� ���� ���������� ����� �, ��� ���������� ����� �� � �����������, ������� ����������� ������ �� ����.
//����, ��������, n = 26364. ��� - �������� ����� � 6 � ���� ���������� �� ������� ������� ���������� 2634.
//���������� 2634 * 6 = 15804, ����� ��� �� � �����������, ���� �� ������������ �� ���� �����.

unsigned short findMaxDigit(unsigned int num)
{
	unsigned short max = 0;
	while (num>0) {
		if (max<num%10) {
			max = num % 10;
		}
		num /= 10;
	}

	return max;
}

void removeMaxDigit(unsigned int& num,unsigned short max)
{
	char numStr[32];
	itoa(num,numStr,10);
	unsigned int len = strlen(numStr);
	for (int i = 0; i < len; i++)
	{
		if (numStr[i]==('0'+max))
		{
			for (int j= i+1; j <= len; j++)
			{
				numStr[j - 1] = numStr[j];
			}
			break;
		}
	}
	num = atoi(numStr);
}

unsigned int reduceHard(unsigned int num)
{
	if (num<10)
	{
		return num;
	}

	unsigned short maxDig = findMaxDigit(num);
	removeMaxDigit(num,maxDig);
	return reduceHard(num*maxDig);
}

int main()
{
	unsigned int n;
	while (1)
	{
		std::cin >> n;
		std::cout << reduceHard(n) << '\n';
	}
	return 0;
}