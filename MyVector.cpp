#include <iostream>
#include <stdlib.h> 
#include <time.h>       
using namespace std;
template <typename T>
class MY_VECTOR {
	T* arr = new T[1];
	int current=0;
	int maxSize=1;

	void Swap(T* val1, T* val2) {
		T temp = *val1;
		*val1 = *val2;
		*val2 = temp;
	}

public:
	bool empty() {
		if (current == 0) return true;
		else return  false;
	}

	void push(T data)
	{
		if (current == maxSize) {
			T* temp = new T[2 * maxSize];
			for (int i = 0; i < maxSize; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			maxSize *= 2;
			arr = temp;
		}
		arr[current] = data;
		current++;
	}

	void push(T data, int index)
	{
		if (index == maxSize)
			push(data);
		else
			arr[index] = data;
	}

	void pop() { 
		current--;
	}

	int size() { 
		return current;
	}
	int getMaxSize() { 
		return maxSize; 
	}

	T at(int index)
	{
		if (index < current)
			return arr[index];
	}

	void reverse() {
		for (size_t i = 0; i < current / 2; i++)
		{
			Swap(arr + i, arr + current - i - 1);
		}
	}

	void clear() {
		maxSize = 0;
		arr = new int[maxSize];
		current = 0;
	}
	void Show()
	{
		for (int i = 0; i < current; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	MY_VECTOR(int start, int end) {
		for (start; start<=end; start++)
		{
			MY_VECTOR::push(start);
		}
	}

	MY_VECTOR() {

	}
	MY_VECTOR(int Rand_count) {
		srand(time(0));
		for (int i = 0; i < Rand_count; i++)
		{
			MY_VECTOR::push(rand()%100);
		}
	}
};

int main()
{
	MY_VECTOR <int> v = MY_VECTOR<int>();
	MY_VECTOR <char> v1 = MY_VECTOR<char>(3);
	v1.Show();
	cout<<" Is empty? "<<v.empty() << endl;
	v.push(11);
	v.push(10);
	v.push(26);
	v.push(24);
	v.reverse();
	cout << "Vector size : " << v.size() << endl;
	cout << "Vector max size : " << v.getMaxSize() << endl;
	cout << "Vector elements : ";
	v.Show();
	cout << "Vector elements after cleaning: ";
	v.clear();
	v.Show();
}
