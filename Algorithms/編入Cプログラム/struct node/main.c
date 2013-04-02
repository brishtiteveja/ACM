#include <stdio.h>
#include <stdlib.h>

enum node_type { OP,NUM };
enum operation { ADD,SUB,MUL,DIV };


struct node { 
	enum node_type type ;
	int val;
	enum operation op;;
	struct node *left;
	struct node *right;
};

struct node *make_node(enum node_type type ,int op,int val,struct node *left ,struct node *right ){
	struct node *p;
	p = malloc( sizeof( struct node ) ) ;
	p->type = type ;
	p->op = op;
	p->val = val;
	p->left = left;
	p->right =right;
	
	return (p);

}

#define MAKE_OP(op,l,r) make_node(OP, (op) ,0,(l),(r))
#define MAKE_NUM(n) make_node(NUM,0,(n),0,0)

void print_op( struct node *p ){
		switch ( p->op ) {
			case ADD:
				printf("+");
				break;
			case SUB:
				printf("-");
				break;
			case MUL:
				printf("*");
				break;
			case DIV:
				printf("/");
				break;
            default:
				printf("?");
				break;
		}
}

void print_tree( struct node *p){
	if ( p->type == OP ){
		printf("(");
		print_tree( p->left );
		print_op( p );
		print_tree( p->right);
		printf(")");
	
	}
	else {
		printf("%d",p->val);
	}

}

void print_tree2(struct node *p){
	if ( p->type == OP ) {
		print_tree2(p->left);
		printf(" ");
		print_tree2(p->right);
		print_op(p);
	}
	else {
		printf("%d",p->val);
	}

}

int get_height( struct node *p ){
	int h,hl,hr;
	if ( p->type == OP ) {
		h = 1;
		hl = get_height( p->left );
		hr = get_height( p->right );
		if ( hl > hr ) {
			h += hl;
		}
		else {
			h += hr;
		}
		return h;
	}
	else {
		return 1;
	}

}


int main () {
    struct node *n1 , *n2 , *n3 , *n4 , *n5 , *n6 , *n7 ;
	n1 = MAKE_NUM( 2 );
	n2 = MAKE_NUM( 10 );
	n3 = MAKE_NUM( 4 );
	n4 = MAKE_NUM( 2 );
	n5 = MAKE_OP( MUL , n3 , n4 );
	n6 = MAKE_OP( SUB , n2 , n5 );
	n7 = MAKE_OP( MUL , n1 , n6 );
	
	print_tree( n7 );
	printf("\n");
	print_tree2( n7 );
	printf("\n");
	printf("height = %d \n",get_height( n5 ));
	
    return 0;
}



























