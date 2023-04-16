#include <stdio.h>
#include <stdlib.h>

//  structure to represent a Binary tree node
struct node {
    int val;
    struct node *left;
    struct node *right;
};

//  function to create a root node x
struct node *x(int val) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//  function to calculate the sum of a Binary tree
int sum(struct node *root) {
    if (root == NULL)
        return 0;
    return root->val + sum(root->left) + sum(root->right);
}

// function to print all Binary trees where the sum of the right subtree is greater than the sum of the left subtree
void printTrees(int arr[], int l, int r) {
    
    if (l > r) {
        return;
    }

   
    for (int i = l; i <= r; i++) {
        // Create a new Binary tree node with the current element as the root
        struct node *root = x(arr[i]);

        // Recursively build the left and right subtrees
        for (int j = l; j <= r; j++) {
            if (j != i) {
                if (arr[j] < arr[i]) {
                    root->left = x(arr[j]);
                } else {
                    root->right = x(arr[j]);
                }
            }
        }

        // Check if the sum of the right subtree is greater than the sum of the left subtree
        if (sum(root->left) < sum(root->right)) {
            // Print the Binary tree
            printf("%d -> ", root->val);
            if (root->left != NULL) {
                printf("%d ", root->left->val);
            } else {
                printf("NULL ");
            }
            if (root->right != NULL) {
                printf("%d\n", root->right->val);
            } else {
                printf("NULL\n");
            }
        }

        // Recursively build Binary trees with the remaining elements
        printTrees(arr, l, i - 1);
        printTrees(arr, i + 1, r);
    }
}

//  main function to get user input and call the printTrees function
int main() {
    int n; //   size of the array
    int arr[50]; //  array to hold the integers

    //  enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //  enter the integers
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the printTrees function 
    printf("Binary trees where the sum of the right subtree is greater than the sum of the left subtree:\n");
    printTrees(arr, 0, n - 1);

    return 0;
}
