
int inputN(int* n) {
    rewind(stdin);
    *n = 0;
    int digit, sign = 1, started = 0;
    while ((digit = getchar()) != '\n' && digit != ' ') {
        if (digit == '-') {
            sign = -1;
        } else if (digit < '0' || digit > '9') {
            printf("Sorry, but it's incorrect number. Try again\n");
            while ((digit = getchar()) != '\n' && digit != ' ');
            *n = 0;
            return -1;
        } else {
            started = 1;
            *n = *n * 10 + (digit - '0');
        }
    }
   return started ? *n * sign : 0;
}
struct TreeList* createTreeList(int x) {
    struct TreeList* newList= (struct TreeList*)malloc(sizeof(struct TreeList));
    if (newList == NULL) {
        printf("Es gibt nicht genug Platz.\n");
        exit(EXIT_FAILURE);
    }
    newList->field = x;
    newList->left = NULL;
    newList->right = NULL;
    return newList;
}
int pushTreeList(struct TreeList** root, int x) {
    if(*root != NULL) {
       if((*root)->field > x) {
        pushTreeList(&((*root)->left), x);
       }
       else if((*root)->field < x){
        pushTreeList(&((*root)->right), x);
       }
       else {
        printf("Element %d already exists in tree\n", x);
        return 0; //???????????????????????????????????
       }
    }
    else {
        *root = createTreeList(x);
    }
    return 1;
}
void printTree(struct TreeList* root, int space) {
    int count = 4;
    if (root == NULL) {
        return;
    }
    space += count;
    printTree(root->right, space);

    printf("\n");
    for (int i = count; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->field);

    printTree(root->left, space);
}

struct TreeList* search(struct TreeList* root, int x) {
    if (root == NULL || root->field == x) {
        return root;
    }
    
    if (x < root->field) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}
struct TreeList* findMinList(struct TreeList* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
struct TreeList* deleteTreeList(struct TreeList* root, int x)  {
    if (root == NULL) {
        return NULL;
    }
    
    if (x < root->field) {
        root->left = deleteTreeList(root->left, x);
    } 
    else if (x > root->field) {
        root->right = deleteTreeList(root->right, x);
    } 
    else {
        if (root->left == NULL) {
            struct TreeList* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeList* temp = root->left;
            free(root);
            return temp;
        }
        
        struct TreeList* temp = findMinList(root->right); 
        root->field = temp->field; 
        root->right = deleteTreeList(root->right, temp->field);
    }
    return root;
}
int findinTree(struct TreeList* root, int x) {
    if (root == NULL) {
        return 0;
    }
    
    int count = 0;
    if (root->field == x) {
        count = 1;
    }
    
    return count + findinTree(root->left, x) + findinTree(root->right, x);
}
void amountX(struct TreeList* root, int x) {
    printf("The amount of %d - %d\n", x, findinTree(root, x));
}
void freeTree(struct TreeList* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
