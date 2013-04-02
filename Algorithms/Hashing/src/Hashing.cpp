//============================================================================
// Name        : Hashing.cpp
// Author      : Dhrubo Abdullah Khan
// Version     : 1
// Copyright   : Free to share,copy and distribute
// Description : Hash, Collision, Chain Rule
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


typedef struct _Data{				//Data of a node in a slot of the hash table
	int no;
	char name[20];
}Data;

typedef struct _Node{				//node in each slot at hash table
	Data data;						//data in the node
	struct _Node* next;				//next node
}Node;

typedef struct _Hash{
	int size;						//size of the hash table
	Node** table;					//Hash table
}Hash;


int hash(int key){
	return key % 13;
}

int initHash(Hash* h,int size){
	h->size = 0;
	if((h->table = new Node*[size]) == NULL){
		return 0;
	}
	h->size = size;
	for(int i = 0; i < size ; i++){
		h->table[i] = NULL;
	}
	return 1;

}

void setNode(Node* n, Data x, Node* next){
	n->data = x;
	n->next = next;
}

int insertNode(Hash* h,Data x){
	int key = hash(x.no);
	Node* p = h->table[key];			//finding the table slot with the hashed key

	while(p != NULL){
		if(p->data.no == x.no){				//this key already registered
			return 0;
		}
		p = p->next;
	}

	Node *tmp;
	if((tmp = new Node) == NULL){		//allocating new node
		return 0;
	}
	setNode(tmp,x,h->table[key]);					//setting new node
	h->table[key] = tmp;
	return 1;
}

int deleteNode(Hash * h, Data x){
	int key = hash(x.no);
	Node* p;
	p = h->table[key];

	if(p != NULL){
		if(p->data.no == x.no){
			h->table[key] = p->next;
			free(p);
			return 1;
		}else{
			while(p->next != NULL){
				if(p->next->data.no == x.no){
					Node* pp = p->next->next;
					free(p->next);
					p->next = pp;
					return 1;
				}
				p = p->next;
			}
		}
	}
	return 0;				//no such key
}

int deleteNodeAlt(Hash* h, Data x){
	int key = hash(x.no);
	Node * p;
	p = h->table[key];

	Node** pp = &h->table[key];

	while(p!= NULL){
		if(p->data.no == x.no){
			*pp = p->next;			//changing the pointer of previous node's next node to the current node's next node
			free(p);
			return 1;
		}
		pp = &p->next;				//address of the pointer of the next node
		p = p->next;
	}

	return 0;
}

Node* searchNode(Hash* h, Data x){
	int key = hash(x.no);
	Node* p;
	p = h->table[key];

	while(p != NULL){
		if(p->data.no == x.no){			//found
			return (p);
		}
		p = p->next;
	}

	return NULL;
}

void dumpHash(Hash* h){					//Dumping the hash
	for(int i = 0; i < h->size; i++){
		Node* p = h->table[i];
		printf("%02d",i);
		while(p!= NULL){
			printf("-> %d (%s) ",p->data.no,p->data.name);
			p = p->next;
		}
		printf("\n");
	}
}

void Printdata(Data x){
	printf("%d  %s\n",x.no,x.name);
}

int main() {
	Hash hash;
	int size = 10;
	initHash(&hash,size);			//initialize a hash with empty slot

	Data x;
	for(int i = 0;i < 5;i++){
		cin >> x.no >> x.name;
		insertNode(&hash,x);
	}
	cout << "*************************delete node*****************" << endl;

	cin >> x.no >> x.name ;
	deleteNode(&hash,x);

	dumpHash(&hash);

	cout << "************************Search Node******************" << endl;
	cin >> x.no >> x.name;
	Node* p = searchNode(&hash,x);
	cout << "data = " << p ->data.no << "name = " << p->data.name << endl;


	return 0;
}
