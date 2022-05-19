#include <stdio.h>
#include <stdlib.h>



	
	
typedef char TElement;  //         ü  
	
typedef struct BinTrNode {
	TElement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
}TNode;
	
TNode* root; 
	
void init_tree() {root = NULL;}
int is_empty_tree() {return root == NULL;}
TNode* get_root() {return root;}
	
	//     Ʈ    ʱ ȭ   root   null     Ȯ   ϴ     ̴ . 
	//  Ʈ   null     Ȯ   ϸ  is_empty( 
	//create_tree(e, left, right)
	//get root()   return root; 
	
	
//	void init_tree() {root
//	}

TNode* create_tree(TElement val, TNode* l, TNode* r)
{
	TNode* n = (TNode*) malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}
	
	typedef TNode* Element; //    Ʈ          rootnode pointer 
	
	
void preorder(TNode *n) //      ȸ 
{ 
	if( n != NULL) { 
		printf("[%c]", n->data);
		preorder(n->left); //         Ʈ    湮  
		preorder(n->right); // 
	}
}
	
void inorder(TNode *n) //      ȸ 
{ 
	if( n != NULL) { 
		inorder(n->left); //         Ʈ    湮 
		printf("[%c]", n->data); //  Ʈ(x)     ó   
		inorder(n->right); // 
	}
}
	
void postorder(TNode *n) //      ȸ 
{ 
	if( n != NULL) { 
		postorder(n->left); //         Ʈ    湮  
		postorder(n->right); // 
		printf("[%c]", n->data); //  Ʈ(x)     ó  
	}
}
	

#define MAX_QUEUE_SIZE	100

typedef TNode* Element;

// ���α׷� 4.1�� 6~37�� �߰�
Element data[MAX_QUEUE_SIZE];	// ����� �迭
int	front;			// ����
int	rear;			// �Ĵ�

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}
								// ť�� �ֿ� ����: ����
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
	if (is_full())
		error("  ť ��ȭ ����");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}
Element dequeue()
{
	if (is_empty())
		error("  ť ���� ����");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element peek()
{
	if (is_empty())
		error("  ť ���� ����");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}
void levelorder(TNode *root)
{
	TNode* n;

	if (root == NULL) return;
	init_queue();
	enqueue(root);
	while (!is_empty()) {
		n = dequeue();
		if (n != NULL) {
			printf("[%c] ", n->data);
			//print_elem(n);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int count_node(TNode *n)
{
	if (n == NULL) return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode *n)
{
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 1;
	else return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n)
{
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
}

TNode* search( TNode *n, int key )
{
if (n == NULL ) return NULL;
else if (key== n->data) return n;
else if (key < n->data) return search( n->left, key );
else return search( n->right, key );
}


void serch_BST(int key)
{
	TNode* n = search(root, key);
	
	if (n != NULL)
		printf("[Ž������]: Success [%d] = 0x%x\n", n->data, n);
	else
		printf("[Ž������]: Failed : NO = %d!\n", key);
}



int insert( TNode* r, TNode* n ) //���Կ��� �˰��� 
{
	if( n->data == r->data ) return;
	else if( n->data < r->data ) {
		if( r->left == NULL ) r->left = n;
		else insert( r->left, n );
	}
	else {
		if( r->right== NULL ) r->right = n;
		else insert( r->right, n );
	}
}



void insert_BST(int key)
{
	TNode* n = create_tree(key, NULL, NULL);
	if (is_empty_ ())
		root = n;
	else if (insert(root, n) == 0)
		free(n);
}


void delete(TNode *parent, TNode *node)
{
	TNode *chile, *succ, *succp;
}


void delete_BST(int key)
{
	TNode *parent = NULL;
	TNode *node  = root;
	
	if (node == NULL) return;
	while (node != NULL && node->data != key) {
		parent = node;
		node = (key < node->datadata) ? node->left : node->right;
	}
	if (node == NULL)
		printf("Errot: key is not in the tree! \n");
	else delete (parent, node);

 } 


int maxVal(TNode* n){
	TNode* max = n;
	
	while(max->right != NULL){
		max = max -> right;
	}
	return max->data;
}

//case 1 �ܸ���� ���� 
 
if ((node->left == NULL && node->right == NULL)) {
		if (parent == NULL) root = NULL;
		else {
			if (parent->left == node)
				parent->left = NULL;
			else parent->right = NULL;
		}
}


// case 2 �ڽ��� �ϳ��� ��� ����
 
if (node->left == NULL || node->right == NULL) {
	child = (node->left != NULL) ? node->left : node->right;
		if (node == root) root = child;
			else {
				if (parent->left == node)
					parent->left = child;
				else parent->right = child;
			}
}



// case 3 �� ���� �ڽ��� ���� ��� ����

if ((node->left == NULL && node->right == NULL)) {
	case 1
}
else if ((node->left == NULL && node->right == NULL)) {
	case 2
}
else {
		succp = node;
		succ = node->right;
		while (succ->left != NULL) {
				succp = succ;
				succ = succ->left;
}
		if (succp->left == succ) {
			succp->left = succ->right;
		else succp->right = succ->right;

		node->data = succ->data;
		node = succ;

	}
}
	
void main(){

	
	printf("[���� ����] : 35 18 7 26 12 3 68 22 30 99")
	
	init_tree();
	 
	insert_BST(35); insert_BST(18);
	insert_BST(7); insert_BST(26);
	insert_BST(12); insert_BST(3);
	insert_BST(68); insert_BST(22);
	insert_BST(30); insert_BST(99); 
	
	
	printf("\n In-Order: "); inorder(root);
	printf("\n Pre-Order: "); preorder(root);
	printf("\n Post-Order: "); postorder(root);
	printf("\n Level-Order: "); levelorder(root);
	
	
	printf("\n ����� ����= %d\n"), count_node(root));
	printf("\n �ܸ��� ����= %d\n"), count_leaf(root));	
	printf("\n ����� ���� = %d\n"), count_height(root));
	
	printf("max value"), max_Val


}





