#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h>

typedef struct sNode{
	char* data;
	struct sNode* next;//이전 stack 가리킴 <-
}Node;

typedef struct listStack{
	Node* peek;// last node
	int size;
}listStack;

void createStack(listStack** stack){
	(*stack)=(listStack*)malloc(sizeof(listStack));
	(*stack)->peek = NULL;
	(*stack)->size = 0;
}

Node* createNode(char* newChar){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(newChar)+1);

	strcpy(newNode->data, newChar);
	newNode->next = NULL;
}
void deleteNode(Node* removeNode){
	free(removeNode->data);
	free(removeNode);
}

void Push(listStack* stack, Node* newNode){
	
	//when stack is empty
	if(stack->size==0){
		stack->peek = newNode;
	}
	//when stack is not empty
	else{
		newNode->next=stack->peek;
		stack->peek = newNode;
	}
	stack->size++;
}

Node* pop(listStack* stack){
	Node* tempNode;

	//when stack is empty
	if(stack->size == 0){
		printf("hey!!! stack is empty");
		tempNode==NULL;
	}
	//when stack is not empty
	else{
		tempNode = stack->peek;
		stack->peek = stack->peek->next;
		stack->size--;
	}
	return tempNode;	
}

void deleteStack(listStack* stack){
	int count = stack->size;
	int i;
	Node* tempNode;
	for(int i=0; i<count; i++){
		tempNode = pop(stack);
		deleteNode(tempNode);
	}

	free(stack);

}


int main(){
	int i;
	listStack* Stack;
	createStack(&Stack);

	Push(Stack, createNode("a"));
	Push(Stack, createNode("b"));
	Push(Stack, createNode("c"));
	Push(Stack, createNode("d"));

	printf("abcd pushed\n");
	printf("\n--Current Stack--[size:%d]\n\n", Stack->size);

	Node* horse = Stack->peek;
	for(int i=0; i<(Stack->size); ++i){
		printf("%s\n", horse->data);
		horse = horse->next;
	}

	horse = pop(Stack);
	horse = pop(Stack);
	
	printf("\n--Current Stack--[size:%d]\n\n", Stack->size);

	horse = Stack->peek;
	for(int i=0; i<(Stack->size); ++i){
		printf("%s\n", horse->data);
		horse = horse->next;
	}

	deleteStack(Stack);
	printf("\nStack has been completely freed\n");

}
