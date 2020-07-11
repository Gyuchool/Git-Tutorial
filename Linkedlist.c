#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
	int Data;
	struct listNode* Next;
	struct listNode* Prev;
}Node;

Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->Data=data;
	newNode->Next = NULL;
	newNode->Prev = NULL;

	return newNode;
}

void deleteNode(Node* Node){
	free(Node);
}

Node* getNodeAt(Node* head, int index){
	Node* horse = head;
	int count = 0;
	
	while(horse !=NULL){
		if(count++ == index){
			return horse;
		}

		horse = horse->Next;
	}

	return NULL;

}
int countNode(Node* head){//argument?
	int count = 0;
	Node* horse = head;
	while(horse != NULL){
		horse = horse->Next;
		count++;
	}
	return count;
}

void addNode(Node** head, Node* newNode){//for update, take **
	//no list exists
	if((*head) == NULL)
		*head = newNode;
	//list exist
	else{
		Node* horse = (*head);

		while(horse->Next != NULL){
			horse = horse->Next;
		}

		horse->Next = newNode;
		newNode->Prev = horse;
	}
}

void InsertAfter(Node* Current, Node* newNode){
	//head
	if(Current->Prev == NULL && Current ->Next == NULL){///chandgegegege
		Current->Next = newNode;
		newNode->Prev = Current;
	}
	// not head
		//if tail
		if(Current->Next == NULL){
			Current->Next = newNode;
			newNode->Prev = Current;
		}
		//in the middle of 2 nodes
		else{
			Current->Next->Prev = newNode;
			newNode->Next = Current->Next;
			newNode->Prev = Current;
			Current->Next = newNode;
		}
}

void removeNode(Node** head, Node* remove){//head에 변화가 있으므로 **
	//head
	if(*head == remove){
		*head = remove->Next;
	}
	if(remove->Next != NULL){
		remove->Next->Prev = remove->Prev;
	}
	if(remove->Prev != NULL){
		remove->Prev->Next = remove->Next;
	}
	deleteNode(remove);
}

int main(){
	int i = 0;
	int count = 0;
	
	//future head
	Node* List = NULL;
	
	//temporary Node
	Node* newNode = NULL;

	//current Node
	Node* curr = NULL;

	for(int i=0; i<5; ++i){
		newNode = createNode(i);
		addNode(&List, newNode);
	}

	count = countNode(List);
	for(int i=0; i<count; ++i){
		curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, curr->Data);
	}
	printf("-------------5 Nodes Created ---------------\n");

	newNode = createNode(99);
	curr = getNodeAt(List, 0);
	InsertAfter(curr, newNode);

	newNode = createNode(444);
	curr = getNodeAt(List, 4);
	InsertAfter(curr, newNode);

	count = countNode(List);
	for(int i=0; i<count; ++i){
		curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, curr->Data);
	}

	printf("----------------After 2 Nodes inserted -----------\n");

	newNode = getNodeAt(List, 1);
	removeNode(&List, newNode);
	
	newNode = getNodeAt(List, 0);
	removeNode(&List, newNode);

	count = countNode(List);
	for(int i=0; i<count; ++i){
		curr = getNodeAt(List, i);
		printf("List[%d] = %d\n", i, curr->Data);
	}

	printf("----------After Node with index 1 removed-------------\n");

	return 0;

}

