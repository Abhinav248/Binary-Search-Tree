# Binary-Search-Tree
Basic Operations and Problems on Binary Search Tree


#include <stdio.h>
#include <stdlib.h>
int c;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}node;

struct list
{
	int val;
	struct list *next;
};

void treetraversal(node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
void levelorder(struct node *root);
void boundarytraversal(struct node *root);
void leftboundarytraversal(struct node *root);
void leaftraversal(struct node *root);
void rightboundarytraversal(struct node *root);
void MorrisInorderTraversal(struct node *root);
//void levelbylevelorderedprinting(struct node *root);
//void reverselevelbylevelreverseorderprinting(struct node *root);
//void spiralorderprinting(struct node *root);
node *insert(node *root, int item);
node *search(node *root, int item);
node *maximum(node *root);
node *minimum(node *root);
void topview(node *root);
int sametreecheck(struct node *root1, struct node *root2);
int height(struct node *root);
int countnode(struct node *root);
node *deletenode(node *root, int item);
int roottoleafsumcheck(struct node *root, int sum);
struct node *LCA(struct node *root, int data1, int data2);
int diameter(struct node *root);
int max(int x, int y);
struct node *Tree_clone(struct node* root);
void View_Tree(node *root);
struct list *findMinMaxTopView(node *node, struct list *head, int *min, int *max, int hd);
struct list *findMinMaxBottomView(node *node, struct list *head, int *min, int *max, int hd);
void printViews(struct list *head);

int main()
{
    printf("BINARY SEARCH TREE\n");
    node *root[10];
    int choice,item,exit=1,i,r,r1,r2,res,sum,data1,data2;
    for(i=0;i<10;i++)
        root[i]=NULL;
    while(exit)
    {
        node *temp;
        printf("\nENTER\n0 to exit/terminate\n1 for tree traversal\n2 to insert an item\n3 to search an item\n");
        printf("4 to find maximum data in BST\n5 to find minimum data in BST\n6 to print topview only\n");
        printf("7 to count no. of nodes\n8 to find the height of a tree\n9 to check if two binary tree is same or not");
        printf("\n10 to delete a node\n11 to check root to leaf sum is present or not\n12 to find LCA of two node\n");
        printf("13 to find diameter of a tree\n14 to clone a BST\n15 to print Views of tree\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit=0;
            printf("\n");
            break;
        case 1:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            treetraversal(root[r-1]);
            printf("\n");
            break;
        case 2:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nEnter item to be inserted\n");
            scanf("%d",&item);
            root[r-1]=insert(root[r-1],item);
            printf("\n");
            break;
         case 3:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nEnter item to be searched\n");
            scanf("%d",&item);
            temp=search(root[r-1],item);
            if(temp==NULL)
                printf("\nitem %d not found\n",item);
            else
                printf("\nitem %d found in tree\n",temp->data);
            printf("\n");
            break;
         case 4:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            temp=maximum(root[r-1]);
            if(temp==NULL)
                printf("\n empty tree\n");
            else
                printf("\nmaximum data in tree is %d\n",temp->data);
            printf("\n");
            break;
         case 5:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            temp=minimum(root[r-1]);
            if(temp==NULL)
                printf("\n empty tree\n");
            else
                printf("\nminimum data in tree is %d\n",temp->data);
            printf("\n");
            break;
        case 6:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nBST top view is :\n");
            topview(root[r-1]);
            printf("\n");
            break;
        case 7:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nno of nodes in the tree is : %d\n",countnode(root[r-1]));
            printf("\n");
            break;
        case 8:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nheight of tree = %d\n",height(root[r-1]));
            break;
        case 9:
            printf("\nEnter 2 root no from 1 to 10\n");
            scanf("%d%d",&r1,&r2);
            if(sametreecheck(root[r1-1],root[r2-1]))
                printf("\nboth are same tree\n");
            else
                printf("\nnot same tree\n");
            break;
         case 10:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nEnter item(node) to be deleted\n");
            scanf("%d",&item);
            root[r-1]=deletenode(root[r-1],item);
            printf("\n");
            break;
        case 11:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("enter value of root to leaf sum\n");
            scanf("%d",&sum);
            res=roottoleafsumcheck(root[r-1],sum);
            if(res)
                printf("\nroot to leaf sum path is present\n");
            else
                printf("\nroot to leaf sum path is not present\n");
            break;
        case 12:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("Enter the two nodes value\n");
            scanf("%d%d",&data1,&data2);
            temp=LCA(root[r-1],data1,data2);
            if(temp)
                printf("\nLCA is : %d\n\n",temp->data);
            else
                printf("\nNo LCA & Empty Tree\n");
            break;
        case 13:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nDiameter of tree = %d\n",diameter(root[r-1]));
            break;
        case 14:
            printf("\nEnter tree root no. to be cloned\n");
            scanf("%d",&r);
            root[9]=Tree_clone(root[r-1]);
            printf("\nlevel order traversal of new clone tree\n");
            levelorder(root[9]);
            if(sametreecheck(root[r-1],root[9]))
                printf("\ntree cloned correctly\n");
            else
                printf("\nnot cloned correctly\n");
            break;
        case 15:
            c=0;
            printf("\nEnter tree root no. for viewing\n");
            scanf("%d",&r);
            View_Tree(root[r-1]);
            printf("\n");
            break;
        default:
            printf("\nyou entered a wrong choice\n");
        }
    }
    return 0;
}

void treetraversal(struct node *root)
{
    int choice;
    printf("\nENTER\n1 for inorder traversal\n2 for preorder traversal");
    printf("\n3 for postorder traversal\n4 for level order traversal\n");
    printf("5 for boundary traversal\n6 for Morris Inorder Traversal\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("your inorder tree traversed data are :\n");
        inorder(root);
        printf("\n");
        break;
    case 2:
        printf("your preorder tree traversed data are :\n");
        preorder(root);
        printf("\n");
        break;
    case 3:
        printf("your postorder tree traversed data are :\n");
        postorder(root);
        printf("\n");
        break;
    case 4:
        printf("your levelorder tree traversed data are :\n");
        levelorder(root);
        printf("\n");
        break;
    case 5:
        boundarytraversal(root);
        printf("\n");
        break;
    case 6:
            MorrisInorderTraversal(root);
            printf("\n");
            break;
    }
}

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->lchild);
    printf("\n%d\n",root->data);
    inorder(root->rchild);
}

/*
void iterativeinorder(node *root)
{
    if(!root)
        return;
    Stack s;
    push(s,root);
    while(1)
    {
        if(root)
        {
            push(s,root);
            root=root->lchild;
        }
        else
        {
            if(isEmpty(s))
                break;
            else
            {
                root=pop(s);
                printf("%d\n",root->data);
                root=root->rchild;
            }
        }
    }
}
*/

void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("\n%d\n",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

/*
void preorder(struct node *root)
{
   if(!root)
        return;
   Stack s;
   push(s,root);
   while(!isEmpty(s))
   {
       root=pop(s);
       printf("%d\n",root->data);
       if(root->rchild)
            push(s,root->rchild);
       if(root->lchild)
            push(s,root->lchild);
   }
}
*/

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("\n%d\n",root->data);
}

/*
void postorder(struct node *root)
{
    if(!root)
        return;
    Stack s1,s2;
    push(s1,root);
    while(!isEmpty(s1))
    {
        root=pop(s1);
        push(s2,root);
        if(root->lchild)
            push(s1,root->lchild);
        if(root->rchild)
            push(s1,root->rchild);
    }
    while(!isEmpty(s2))
        printf("%d\n",(pop(s2))->data);
}
*/

void levelorder(struct node *root)
{
    if(root==NULL)
    {
        printf("\n tree is empty\n");
        return;
    }
    struct queue
    {
        struct node *qdata;
        struct queue *next;
    };
    struct queue *front=NULL;
    struct queue *qnode=(struct queue *)malloc(sizeof(struct queue));
    qnode->qdata=root;
    qnode->next=NULL;
    front=qnode;
    while(front!=NULL)
    {
        qnode=front;
        printf("%d\n",qnode->qdata->data);
        if(qnode->qdata->lchild!=NULL)
        {
            struct queue *curr=front;
            while(curr->next!=NULL)
                curr=curr->next;
            struct queue *qlast=(struct queue *)malloc(sizeof(struct queue));
            qlast->qdata=qnode->qdata->lchild;
            qlast->next=NULL;
            curr->next=qlast;
        }
        if(qnode->qdata->rchild!=NULL)
        {
            struct queue *curr=front;
            while(curr->next!=NULL)
                curr=curr->next;
            struct queue *qlast=(struct queue *)malloc(sizeof(struct queue));
            qlast->qdata=qnode->qdata->rchild;
            qlast->next=NULL;
            curr->next=qlast;
        }
        front=front->next;
    }
}


void boundarytraversal(struct node *root)
{
    if(!root)
        return;
    printf("\nboundary traversal of tree is :\n");
    printf("%d\n",root->data);
    leftboundarytraversal(root->lchild);
    leaftraversal(root);
    rightboundarytraversal(root->rchild);
}
void leftboundarytraversal(struct node *root)
{
    if(!root)
        return;
    while(root->lchild!=NULL)
    {
        printf("%d\n",root->data);
        root=root->lchild;
    }
}
void leaftraversal(struct node *root)
{
    if(!root)
        return;
    if(root->lchild==NULL && root->rchild==NULL)
        printf("%d\n",root->data);
    leaftraversal(root->lchild);
    leaftraversal(root->rchild);
}
void rightboundarytraversal(struct node *root)
{
    if(root)
    {
        struct list
        {
            int value;
            struct list *next;
        };
        struct list *start=NULL,*temp;
        while(root->rchild!=NULL)
        {
            temp=(struct list*)malloc(sizeof(struct list));
            temp->value=root->data;
            temp->next=start;
            start=temp;
            root=root->rchild;
        }
        while(start!=NULL)
        {
            printf("%d\n",start->value);
            start=start->next;
        }
    }
    return;
}

void MorrisInorderTraversal(struct node *root)
{
    struct node *curr,*predecessor;
    if(root==NULL)
    {
        printf("\nEmpty Tree\n");
        return;
    }
    printf("\nyour Morris Inorder Traversal are :\n");
    curr=root;
    while(curr!=NULL)
    {
        if(curr->lchild==NULL)
        {
            printf("%d\n",curr->data);
            curr=curr->rchild;
        }
        else
        {
            predecessor=curr->lchild;
            while(predecessor->rchild!=NULL && predecessor->rchild!=curr)
                predecessor=predecessor->rchild;
            if(predecessor->rchild==NULL)
            {
                predecessor->rchild=curr;
                curr=curr->lchild;
            }
            else
            {
                predecessor->rchild=NULL;
                printf("%d\n",curr->data);
                curr=curr->rchild;
            }
        }
    }
}

/*
//iterative level by level printing algorithm
void levelbylevelorderedprinting(struct node *root)
{
    if(root==NULL)
        return;
    Queue q; // let a queue be created and implemented using linked list
    EnQueue(root);
    EnQueue(NULL);
    struct node *curr,*prev;
    prev=NULL;
    while(!isEmpty(q))
    {
        curr=DeQueue();
        if(prev==curr)
            break;
        else if(curr==NULL)
        {
            Enqueue(curr);
            printf("\n");
        }
        else
        {
            printf("%d",curr->data);
            if(curr->lchild)
                EnQueue(curr->lchild);
            if(curr->rchild)
                EnQueue(root->rchild);
        }
        prev=curr;
    }
}
*/


/*
//right view algorithm
void rightview(struct node *root)
{
    if(root==NULL)
        return;
    Queue q; // let a queue be created and implemented using linked list
    EnQueue(root);
    EnQueue(NULL);
    struct node *curr,*prev;
    prev=NULL;
    while(!isEmpty(q))
    {
        curr=DeQueue();
        if(prev==curr)
            break;
        else if(curr==NULL)
        {
            Enqueue(curr);
            printf("\n");
        }
        else
        {
            if(front(q)==NULL)//front(q) returns front item from the queue
                printf("%d",curr->data);
            if(curr->lchild)
                EnQueue(curr->lchild);
            if(curr->rchild)
                EnQueue(root->rchild);
        }
        prev=curr;
    }
}
*/


/*
//reverse level reverse order printing algorithm
void reverselevelbylevelreverseorderprinting(struct node *root)
{
    if(root==NULL)
        return;
    Queue q; // let a queue be created and implemented using linked list
    Stack s; // let a stack s be created and implemented using linked list
    EnQueue(q,root);
    EnQueue(q,NULL);
    struct node *curr,*prev;
    prev=NULL;
    while(!isEmpty(q))
    {
        curr=DeQueue(q);
        if(prev==curr)
            break;
        else if(curr==NULL)
        {
            Enqueue(q,curr);
            push(s,curr);
        }
        else
        {
            push(s,curr);
            if(curr->lchild)
                EnQueue(q,curr->lchild);
            if(curr->rchild)
                EnQueue(q,root->rchild);
        }
        prev=curr;
    }
    pop(s);
    while(!isEmpty(s))
    {
        curr=pop(s);
        if(curr==NULL)
            printf("\n");
        else
            printf("%d ",curr->data);
    }
}
*/

/*
//spiral order printing algorithm
void spiralorderprinting(struct node *root)
{
    if(root==NULL)
        return;
    Stack s1,s2; // let 2 stacks be created
    push(s1,root);
    struct node *curr;
    while( !isEmpty(s1) || !isEmpty(s2) )
    {
        while(!isEmpty(s1))
        {
            curr=pop(s1);
            printf("%d",curr->data);
            if(curr->lchild)
                push(s2,curr->lchild);
            if(curr->rchild)
                push(s2,curr->rchild);
        }
        printf("\n");
        while(!isEmpty(s2))
        {
            curr=pop(s2);
            printf("%d",curr->data);
            if(curr->rchild)
                push(s1,curr->rchild);
            if(curr->lchild)
                push(s1,curr->lchild);
        }

    }
}
*/

/*
void levelorder(struct node* root)//recursively
{
    if(root==NULL)
    {
        printf("\nEmpty Tree\n");
        return;
    }
	int h = height(root);
	int i;
	for (i=1; i<=h; i++)
		printGivenLevel(root, i);
}
*/


/*
//Print nodes at a given level
void printGivenLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printGivenLevel(root->lchild, level-1);
		printGivenLevel(root->rchild, level-1);
	}
}
*/

node *insert(node *root, int item)
{
    if(root==NULL)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->data=item;
        temp->rchild=NULL;
        temp->lchild=NULL;
        return temp;
    }
    else if(root->data==item)
        return root;
    else if(root->data>item)
        root->lchild=insert(root->lchild,item);//this line is used when we need to return the actual root but due
    else
        root->rchild=insert(root->rchild,item);//to recursion root is changed to current root i.e some other node in subtree
    return root;
}

node *search(node *root, int item)
{
    if(root==NULL || root->data==item)
        return root;
    if(item<root->data)
        search(root->lchild,item);
    else
        search(root->rchild,item);
}

node *maximum(node *root)
{
    if(root==NULL)
        return root;
    if(root->rchild==NULL)
        return root;
    maximum(root->rchild);
}

node *minimum(node *root)
{
    if(root==NULL)
        return root;
    if(root->lchild==NULL)
        return root;
    minimum(root->lchild);
}


//this functions changes the tree and deletes some nodes
//so it must not be used for top view of any tree and thus
//level by level order can be used for left/right views
void topview(node *root)
{
    if(root)
    {
        if(root->lchild)
        {
            root->lchild->rchild=NULL;
            topview(root->lchild);
        }
        printf("%d ",root->data);
        if(root->rchild)
        {
            root->rchild->lchild=NULL;
            topview(root->rchild);
        }
    }
}

int sametreecheck(struct node *root1, struct node *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    return (((root1->data==root2->data)
            && sametreecheck(root1->lchild, root2->lchild))
            && sametreecheck(root1->rchild, root2->rchild));
}

int height(struct node *root)
{
    if(root==NULL)
        return 0;
    return (height(root->lchild)+1 > height(root->rchild)+1) ? height(root->lchild)+1 : height(root->rchild)+1;
}

int countnode(struct node *root)
{
    if(root==NULL)
        return 0;
    return 1+countnode(root->lchild)+countnode(root->rchild);
}

node *deletenode(node *root, int item)
{
    struct node *temp;
    if(!root)
        return root;
    if(root->data>item)
        root->lchild=deletenode(root->lchild,item);
    else if(root->data<item)
        root->rchild=deletenode(root->rchild,item);
    else
    {
        if(!root->lchild && !root->rchild)
        {
            free(root);
            root=NULL;
        }
        else if(!root->lchild)
            root=root->rchild;
        else if(!root->rchild)
            root=root->lchild;
        else
        {
            temp=minimum(root->rchild);
            root->data=temp->data;
            root->rchild=deletenode(root->rchild,temp->data);
        }
    }
    return root;
}

int roottoleafsumcheck(struct node *root, int sum)
{
    int left,right;
    if(root==NULL)
        return 0;
    if(root->lchild==NULL && root->rchild==NULL)
    {
        if(sum-root->data==0)
        {
            printf("%d<-",root->data);
            return 1;
        }
        else
            return 0;
    }
    left=roottoleafsumcheck(root->lchild,sum-root->data);
    right=roottoleafsumcheck(root->rchild,sum-root->data);
    if(left || right)
    {
        printf("%d<-",root->data);
        return 1;
    }
    else
        return 0;
}

struct node *LCA(struct node *root, int data1, int data2)
{
    if(root==NULL)
        return root;
    else if(root->data>(data1>data2?data1:data2))
        LCA(root->lchild,data1,data2);
    else if(root->data<(data1<data2?data1:data2))
        LCA(root->rchild,data1,data2);
    else
        return root;
}

int diameter(struct node *root)
{
    int lt,rt,ld,rd;
    if(root==NULL)
        return 0;
    lt=height(root->lchild);
    rt=height(root->rchild);
    ld=diameter(root->lchild);
    rd=diameter(root->rchild);
    return max(lt+rt+1,max(ld,rd));
}

int max(int x, int y)
{
    return (x>y)?x:y;
}


struct node *Tree_clone(struct node* root)
{
    if(!root)
        return NULL;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=root->data;
    temp->lchild=Tree_clone(root->lchild);
    temp->rchild=Tree_clone(root->rchild);
    return temp;
}


void View_Tree(node *root)
{
	int min = 0, max = 0,ch;
	struct list *head;
	printf("\nEnter \n1 for top View\n2 for bottom view\n");
	scanf("%d",&ch);
	switch(ch)
	{
    case 1:
        head=NULL;
        printf("\ntop view is : ");
        head=findMinMaxTopView(root, head, &min, &max, 0);
        printViews(head);
        printf("\n");
        break;
    case 2:
        head=NULL;
        printf("\nbottom view is : ");
        head=findMinMaxBottomView(root, head, &min, &max, 0);
        printViews(head);
        printf("\n");
        break;
    default:
        printf("\nyou entered a wrong choice\n");
	}
}
struct list *findMinMaxTopView(node *root, struct list *head, int *min, int *max, int hd)
{
    struct list* curr;
	if (root == NULL) return head;
	if(c==0)
	{
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->next=head;
	    head=temp;
	    c++;
	}
	if (hd < *min)
	{
	    *min = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->next=head;
	    head=temp;
	}
	else if (hd > *max)
	{
	    *max = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    curr=head;
	    while(curr->next!=NULL)
	        curr=curr->next;
	    curr->next=temp;
	    temp->next=NULL;
	}
	head=findMinMaxTopView(root->lchild, head, min, max, hd-1);
	head=findMinMaxTopView(root->rchild, head, min, max, hd+1);
	return head;
}

struct list *findMinMaxBottomView(node *root, struct list *head, int *min, int *max, int hd)
{
    struct list* curr;
	if (root == NULL) return head;
	if(c==0)
	{
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->next=head;
	    head=temp;
	    c++;
	}
	if (hd < *min)
	{
	    *min = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->next=head;
	    head=temp;
	}
	else if (hd > *max)
	{
	    *max = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    curr=head;
	    while(curr->next!=NULL)
	        curr=curr->next;
	    curr->next=temp;
	    temp->next=NULL;
	}
	else
    {
        curr=head;
	    int z=*min;
	    while(z!=hd)
	    {
	        z++;
	        curr=curr->next;
	    }
	    curr->val=root->data;
    }
	head=findMinMaxBottomView(root->lchild, head, min, max, hd-1);
	head=findMinMaxBottomView(root->rchild, head, min, max, hd+1);
	return head;
}

void printViews(struct list *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->val);
        head=head->next;
    }
}
