#include <stdio.h>
#include <stdlib.h>

// Structure for AVL tree node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to calculate the height of a node
int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to calculate the balance factor of a node
int balanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to create a new node with a given key
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf level
    return node;
}

// Function to rotate a subtree rooted with y to the right
struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x; // New root
}

// Function to rotate a subtree rooted with x to the left
struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y; // New root
}

// Function to balance the AVL tree
struct Node* balance(struct Node* node) {
    // Get balance factor of the node
    int balance = balanceFactor(node);

    // Left heavy
    if (balance > 1) {
        if (balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    // Right heavy
    if (balance < -1) {
        if (balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node; // No need for balancing
}

// Function to insert a key into the AVL tree
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else { // Duplicate keys are not allowed
        return root;
    }

    // Update height of current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Balance the node
    return balance(root);
}

// Function to find the node with the minimum key value
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a key from the AVL tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) { // No child
                temp = root;
                root = NULL;
            } else { // One child
                *root = *temp; // Copy the contents of the non-empty child
            }
            free(temp);
        } else { // Node with two children, get the inorder successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Balance the node
    return balance(root);
}

// Function to search for a key in the AVL tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to print the inorder traversal of the AVL tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of AVL tree: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 30);

    printf("Inorder traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    struct Node* found = search(root, 40);
    if (found) {
        printf("Element 40 found in the AVL tree.\n");
    } else {
        printf("Element 40 not found in the AVL tree.\n");
    }

    return 0;
}

