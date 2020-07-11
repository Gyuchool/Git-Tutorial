#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct qNode{
	char* Data;
	struct qNode* Next;//오른쪽으로 ->
}Node;

typedef struct listQueue{
	Node* Front;//first
	Node* Rear;//last
	int size;//node counting
}listQueue;

void createQueue(listQueue** Queue){
	(*Queue) = (listQueue*)malloc(sizeof(listQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue) -> size = 0;
} 
Node* createNode(char* Data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = (char*)malloc(strlen(Data)+1);
	//data insertion
	strcpy(newNode->Data, Data);
	newNode->Next = NULL;
	
	return newNode;
}

void deleteNode(Node* removeNode){
	free(removeNode->Data);
	free(removeNode);
}

Node* Peek(listQueue* Queue){//first queue data return
	return Queue->Front;
}

void Enqueue(listQueue* Queue, Node* newNode){
	// if queue is empty
	if(Queue->size == 0){
		Queue->Front = newNode;
		Queue->Rear = newNode;
	}
	//if queue is not empty
	else{
		Queue->Rear->Next = newNode; //newNode=Queue->Rear->next;
		Queue->Rear = newNode;
	}
	Queue->size++;
}

Node* Dequeue(listQueue* Queue){
	Node* tempNode = Queue->Front;
	if(Queue->size == 0){
		printf("Don't call me");
		return 0;
	}
	else if(Queue->size == 1){
		Queue->Front = NULL;
		Queue->Rear = NULL;
		Queue->size--;
	}
	else{
		Queue->Front = Queue->Front->Next;
		Queue->size--;
	}

	return tempNode;
}

void deleteQueue(listQueue* Queue){
	int count = Queue->size;
	
	while(count-- !=0){
		Node* temp = Dequeue(Queue);
		printf("\n Dequeued node data %s\n",temp->Data);
		deleteNode(temp);
	}
	
	free(Queue);
}

int main(){
	int i;
	listQueue* Queue;
	
	createQueue(&Queue);//&Queue?

	//Insert Nodes
	Enqueue(Queue, createNode("a"));
	Enqueue(Queue, createNode("b"));
	Enqueue(Queue, createNode("c"));
	Enqueue(Queue, createNode("d"));

	//whos at peek? or Front
	Node* temp1 = Peek(Queue);
	printf("%s <-- this is at front of the queue\n",temp1->Data);
	//print current states of the queue
	printf("\n--Current Queue-- [size:%d]\n\n", Queue->size);
	printf("\nfront is : [%s]\n",Queue->Front->Data);
	printf("rear is : [%s]\n\n", Queue->Rear->Data);

	Node* horse = Queue->Front;
	
	for(int i=0; i<(Queue->size); ++i){
		printf("%s\n", horse->Data);
		horse = horse->Next;
	}
	//delete a, b 
	horse = Dequeue(Queue);
	horse = Dequeue(Queue);

	printf("\n--Current Queue--[size: %d]\n\n", Queue->size);//maybe 2
	
	horse = Queue->Front;
	
	for(int i=0; i<(Queue->size); ++i){
	printf("%s\n", horse->Data);
	horse = horse->Next;
	}
	
	horse = Dequeue(Queue);
	horse = Dequeue(Queue);

	deleteQueue(Queue);
	printf("\nQueue has been completetly freed\n");

	return 0;
}





