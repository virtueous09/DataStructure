/*
	Name : Fakhra Najm
	Email : fnajm09@gmail.com
	code for creating Binary-tree with the help of queue.
*/

#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

struct Node *root = NULL;

void createTree(){
	struct Node *holder, *node;
	int value;
	struct Queue q;
	createQ(&q);
	printf("Enter root value : ");
	scanf("%d", &value);
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = value;
	root->left_child = root->right_child = NULL;
	enqueue(&q, root);

	while(! isEmpty(q)){
		holder = dequeue(&q);
		printf("Enter left child of %d : ", holder->data);
		scanf("%d", &value); 
		if( value != -1){
			node = (struct Node *)malloc(sizeof(struct Node));
			node->data = value;
			node->left_child = node->right_child = NULL;
			holder->left_child = node;
			enqueue(&q, node);
		}
		printf("Enter right child of %d : ", holder->data);
		scanf("%d", &value); 
		if( value != -1){
			node = (struct Node *)malloc(sizeof(struct Node));
			node->data = value;
			node->left_child = node->right_child = NULL;
			holder->right_child = node;
			enqueue(&q, node);
		}
	}
}

void preorder(struct Node *holder){
	if(holder){
		printf("%d ", holder->data);
		preorder(holder->left_child);
		preorder(holder->right_child);
	}
}

int main(){
	createTree();
	printf("Preorder tree\n");
	preorder(root);
}