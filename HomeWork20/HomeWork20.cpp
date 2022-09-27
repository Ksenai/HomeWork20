#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//����� �������
template <typename T>
void showArr(T arr[], const int length);

//������ ���������
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin = 0);

//��������� ���������
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin = 0);

//���������� ��������� ����������� �������� � ������
template <typename T>
int counter(T arr[], const int length, T num);

//������������ ������� �������
template <typename T>
int maxElement(T arr[], const int length);

//����������� ������� �������
template <typename T>
int minElement(T arr[], const int length);

//������� �������������� ���� ��������� �������
template <typename T>
double meanValue(T arr[], const int length);

//����� ��������� ������� � ������������ ���������
void range(double arr[], const int length, int begin, int end);

int main() {
	setlocale(LC_ALL, "ru");
	double n;
	const int size = 100;
	double arr[size];
	cout << "������ ��������� ����� �� -100 �� 100:\n";
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (size + 1 - (-size)) + (-size);
	}

	//����� �������
	showArr(arr, size);

	//������ ���������
	cout << "\n������� �����: ";
	cin >> n;
	if (searchIndex(arr, size, n) == -1)
		cout << "\n������ ����� ��� � �������.\n\n";
	else
		cout << "\n������� ����� � �������: " << searchIndex(arr, size, n) << "\n\n";

	//��������� ���������
	if (searchLastIndex(arr, size, n, size - 1) == -1)
		cout << "������ ����� ��� � �������.\n\n";
	else
		cout << "������� ���������� ����� � �������: " << searchLastIndex(arr, size, n, size - 1) << "\n\n";
	
	//���������� ��������� ����������� �������� � ������
	cout << "���������� ��������� ����������� �������� � ������ = " << counter(arr, size, n) << "\n\n";

	//������������ ������� �������
	cout << "������������ ������� ������� = " << maxElement(arr, size) << "\n\n";

	//����������� ������� �������
	cout << "����������� ������� ������� = " << minElement(arr, size) << "\n\n";

	//������� �������������� ���� ��������� �������
	cout << "������� �������������� ���� ��������� ������� = " << meanValue(arr, size) << "\n\n";

	//����� ������� � ������������ ���������
	int n1, n2;
	cout << "������� ������ ���������: ";
	cin >> n1;
	cout << "������� ����� ���������: ";
	cin >> n2;
	cout << "�������� �������, �������� � ��������� ��������:\n";
	range(arr, size, n1, n2);

	


	

	return 0;
}

//����� �������
template <typename T>
void showArr(T arr[], const int length)
{
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//������ ���������
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

//��������� ���������
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == value)
			return i;
	return -1;
}

//���������� ��������� ����������� �������� � ������
template <typename T>
int counter(T arr[], const int length, T num) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] == num)
			counter++;
	}
	return counter;
}

//������������ ������� �������
template <typename T>
int maxElement(T arr[], const int length) {
	int max = arr[0];
	for (int i = 0; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//����������� ������� �������
template <typename T>
int minElement(T arr[], const int length) {
	int min = arr[0];
	for (int i = 0; i < length; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

//������� �������������� ���� ��������� �������
template <typename T>
double meanValue(T arr[], const int length) {
	double sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return sum / length;
}

//����� ��������� ������� � ������������ ���������
void range(double arr[], const int length, int begin, int end)
{
	cout << "[";
	for (int i = 0; i < length; i++)
		if (arr[i] > begin and arr[i] < end)
			cout << arr[i] << ", ";
	cout << "\b\b]\n";
}