#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 10;

struct node{
	int key;
	int value;
	struct node* next;//<-
};

struct bucket{
	struct node* head;
	int count;
};

struct node* createNode(int key, int value){
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}
int hashFunction(int key){
	return key%SIZE;
}
void insert(int key, int value){
	int hashIndex = hashFunction(key);//at index
	struct node* newNode = createNode(key, value);//create node
	//backet is empty
	if(hashTable[hashIndex].count == 0){
		hashTable[hashIndex].count=1;
		hashTable[hashIndex].head = newNode;
	}
	//backet is already full
	else{
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;

	}
	return ;
}
void Remove(int key){
	int hashIndex = hashFunction(key);
	struct node* node;//앞
	struct node* trace;//뒤
	node = hashTable[hashIndex].head;

	if(node == NULL){
		printf("\n no key found");
		return;
	}

	while(node!=NULL){
		if(node->key == key){
			//next 포인터를 바꾸어 주는 부분
			if(node == hashTable[hashIndex].head){
				hashTable[hashIndex].head = node->next;
			}
			else{
				trace->next = node->next;
			}
			hashTable[hashIndex].count--;
			free(node);
			return;
		}

		trace = node;
		node = node->next;
	}

	printf("\n no key found");
	return ;

}

void search(int key){
	int hashIndex = hashFunction(key);
	struct node* node = hashTable[hashIndex].head;
	
	if(node == NULL){
		printf("\n no key found\n");
		return;
	}
	while(node != NULL){
		if(node->key == key){
			printf("\nkeyFound Key =[%d], value = [%d]\n",node->key, node->value); 
			return;
		}

		node = node->next;
	}
	printf("\nno key found\n");
	return;
}

void display(){
	struct node* horse;
	int i = 0;
	for(i =0; i<SIZE; ++i){
		horse=hashTable[i].head;
		printf("Bucket[%d] : ",i);

		while(horse != NULL){
			printf("(key : %d, value : %d) -> ", horse->key, horse->value);
			horse = horse->next;
		}

		printf("\n");
	}
	printf("\n-------------end of display ----------\n");
	return;
}

int main(){
	hashTable = (struct bucket*)malloc(SIZE*sizeof(struct bucket));
	insert(0,1);
	insert(1,10);
	insert(11,90);
	insert(21, 64);
	insert(31, 23);
	insert(6,25);
	insert(97, 4);
	
	search(6);
	
	display();
	
	Remove(31);
	Remove(11);
	
	search(31);

	display();

	return 0;
}
