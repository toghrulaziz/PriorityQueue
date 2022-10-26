#include <iostream>
#include <assert.h>

using namespace std;


// Priority Queue template
// class Student olmalidir.
// Ortalamasi en yuxari olan telebe novbeden chixir.


class Student {
	string name;
	int average;
public:

	Student() {}

	Student(string name, int average) {
		SetName(name);
		SetAvarage(average);
	}

	bool operator>(const Student& o) {
		return average > o.average;
	}

	friend ostream& operator<<(ostream& out, const Student& o) {
		out << "Name: " << o.name << endl << "Average: " << o.average << endl << endl;
		return out;
	}

	void SetName(string name) {
		this->name.assign(name);
	}

	void SetAvarage(int avarage) {
		this->average = avarage;
	}

	string GetName()const { return name; }
	int GetAverage()const { return average; }
};


template<class T>
class PriorityQueue {
	T* arr;
	int count;
	int rear;
	int capacity;

	int GetMaxAverage() {
		int maxindex = 0;
		for (int i = 0; i < count; i++) {
			if (arr[i] > arr[maxindex]) {
				maxindex = i;
			}
		}
		return maxindex;
	}

public:

	PriorityQueue(int size) {
		capacity = size;
		arr = new T[size];
		rear = 0;
		count = 0;
	}

	bool IsFull() { return count == capacity; }

	bool IsEmpty() { return count == 0; }

	void Enqueue(T value) {
		assert(!IsFull() && "Queue is Full");
		arr[rear++] = value;
		count++;
	}

	void Dequeue() {
		assert(!IsEmpty() && "Queue is Empty");
		int index = GetMaxAverage();
		for (int i = index; i < count - 1; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
		rear--;
	}

	T& Front() {
		assert(!IsEmpty() && "Queue is Empty");
		return arr[GetMaxAverage()];
	}

	void Print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~PriorityQueue() {
		delete[] arr;
	}
};


void main() {
	Student s1("Togrul", 80);
	Student s2("Hakuna", 85);
	Student s3("Kamil", 90);
	Student s4("Elon Musk", 95);
	Student s5("Bill Gates", 100);
	

	PriorityQueue<Student> pq(5);
	pq.Enqueue(s1);
	pq.Enqueue(s2);
	pq.Enqueue(s3);
	pq.Enqueue(s4);
	pq.Enqueue(s5);
	
	pq.Print();
	cout << "***************\n\n";
	pq.Dequeue();
	pq.Print();
	cout << "***************\n\n";
	pq.Dequeue();
	pq.Print();
	cout << "***************\n\n";
	pq.Dequeue();
	pq.Print();
	cout << "***************\n\n";
	pq.Dequeue();
	pq.Print();
	
}