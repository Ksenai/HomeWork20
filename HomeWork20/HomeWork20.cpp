#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//Вывод массива
template <typename T>
void showArr(T arr[], const int length);

//Первое вхождение
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin = 0);

//Последнее вхождение
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin = 0);

//Количество вхождений переданного элемента в массив
template <typename T>
int counter(T arr[], const int length, T num);

//Максимальный элемент массива
template <typename T>
int maxElement(T arr[], const int length);

//Минимальный элемент массива
template <typename T>
int minElement(T arr[], const int length);

//Среднее арифметическое всех элементов массива
template <typename T>
double meanValue(T arr[], const int length);

//Вывод элементов массива в определенном диапазоне
void range(double arr[], const int length, int begin, int end);

int main() {
	setlocale(LC_ALL, "ru");
	double n;
	const int size = 100;
	double arr[size];
	cout << "Массив случайных чисел от -100 до 100:\n";
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (size + 1 - (-size)) + (-size);
	}

	//Вывод массива
	showArr(arr, size);

	//Первое вхождения
	cout << "\nВведите число: ";
	cin >> n;
	if (searchIndex(arr, size, n) == -1)
		cout << "\nТакого числа нет в массиве.\n\n";
	else
		cout << "\nПозиция числа в массиве: " << searchIndex(arr, size, n) << "\n\n";

	//Последнее вхождение
	if (searchLastIndex(arr, size, n, size - 1) == -1)
		cout << "Такого числа нет в массиве.\n\n";
	else
		cout << "Позиция последнего числа в массиве: " << searchLastIndex(arr, size, n, size - 1) << "\n\n";
	
	//Количество вхождений переданного элемента в массив
	cout << "Количество вхождений переданного элемента в массив = " << counter(arr, size, n) << "\n\n";

	//Максимальный элемент массива
	cout << "Максимальный элемент массива = " << maxElement(arr, size) << "\n\n";

	//Минимальный элемент массива
	cout << "Минимальный элемент массива = " << minElement(arr, size) << "\n\n";

	//Среднее арифметическое всех элементов массива
	cout << "Среднее арифметическое всех элементов массива = " << meanValue(arr, size) << "\n\n";

	//Вывод массива в определенном диапазоне
	int n1, n2;
	cout << "Введите начало диапазона: ";
	cin >> n1;
	cout << "Введите конец диапазона: ";
	cin >> n2;
	cout << "Элементы массива, входящие в указанный диапазон:\n";
	range(arr, size, n1, n2);

	


	

	return 0;
}

//Вывод массива
template <typename T>
void showArr(T arr[], const int length)
{
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//Первое вхождение
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

//Последнее вхождение
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == value)
			return i;
	return -1;
}

//Количество вхождений переданного элемента в массив
template <typename T>
int counter(T arr[], const int length, T num) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] == num)
			counter++;
	}
	return counter;
}

//Максимальный элемент массива
template <typename T>
int maxElement(T arr[], const int length) {
	int max = arr[0];
	for (int i = 0; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//Минимальный элемент массива
template <typename T>
int minElement(T arr[], const int length) {
	int min = arr[0];
	for (int i = 0; i < length; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

//Среднее арифметическое всех элементов массива
template <typename T>
double meanValue(T arr[], const int length) {
	double sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return sum / length;
}

//Вывод элементов массива в определенном диапазоне
void range(double arr[], const int length, int begin, int end)
{
	cout << "[";
	for (int i = 0; i < length; i++)
		if (arr[i] > begin and arr[i] < end)
			cout << arr[i] << ", ";
	cout << "\b\b]\n";
}