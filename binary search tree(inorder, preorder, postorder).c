#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node *root, int item)
{
    if (root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root -> left = root -> right = NULL;
        root -> data = item;
        return root;
    }
    else
    {
        if(item < root -> data)
        {
            root -> left = create(root -> left, item);
        }
        else if(item > root -> data)
        {
            root -> right = create(root -> right, item);
        }
        else
        {
            printf("Duplicate element\n");
        }
        return(root);
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root ->right);
    }
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root ->right);
    }
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        preorder(root -> left);
        preorder(root ->right);
        printf("%d ", root -> data);
    }
}

int main()
{
    struct node *root = NULL;
    int ch, item, n;
    
    while(1)
    {
        printf("\n- - - BINARY SEARCH TREE - - -\n");
        printf("1. CREATE\n");
        printf("2. INORDER\n");
        printf("3. PREORDER\n");
        printf("4. POSTORDER\n");
        printf("5. EXIT\n");
        
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            root = NULL;
            printf("Enter the no.of nodes: ");
            scanf("%d", &n);
            
            for(int i = 1; i <= n; ++i)
            {
                printf("Enter data of node %d: ", i);
                scanf("%d", &item);
                root = create(root, item);
            }
            printf("\nBinary search tree created with %d nodes\n",n);
            break;
            
            case 2:
            printf("INORDER: \n");
            inorder(root);
            break;
            
            case 3:
            printf("PREORDER: \n");
            preorder(root);
            break;
            
            case 4:
            printf("POSTORDER: \n");
            postorder(root);
            break;
            
            case 5:
            exit(0);
            break;
            
            default:
            printf("Invalid input\n");
            break;
        }
    }
    getch();
}
