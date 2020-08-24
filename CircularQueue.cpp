#include <iostream>
#define INF 987654321
#define SIZE 6
using namespace std;

struct CircularQueue {

	int arr[SIZE];
	int front, rear;
	
	CircularQueue() {
	
		front = 0;
		rear = 0;
		
	}


	
	bool isEmpty() {
		return rear == front;
	}
	
	bool isFull() {
		return ((rear + 1) % SIZE) == front;
	}


	
	void enqueue(int data) {
	
		if (isFull()) {
			cout << "Q is full" << endl;
			return;
			
		}
		rear = (rear + 1) % SIZE;
		arr[rear] = data;
		
	}
	
	int dequeue() {
	
		if (isEmpty()) {
			cout << "Q is empty" << endl;
			return INF;
			
		}
		
		front = (front + 1) % SIZE;
		return arr[front];
	}
};


int main() {
	
	CircularQueue cq;
	
	for (int i = 1; i <= 6; i++)
		cq.enqueue(i);
		
	cq.enqueue(10);
	
	while (!cq.isEmpty())
		cout << cq.dequeue() << endl;
		
	cout << cq.isEmpty() << endl;
	cout << cq.isFull() << endl;

	return 0;
}

