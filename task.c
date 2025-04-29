void binar_tree() {
    int n;
    struct TreeList *root = (struct TreeList*)malloc(sizeof(struct TreeList));
    root = NULL;
    do {
        puts("Please, enter the amout of the elements for Tree: ");
        if(inputN(&n) <= 0) {
            puts("You need to enter the namber > 0.\n Try again;)");
            continue;
        }
    } while(n <= 0);
    for(int i = 0; i < n; ++i) {
        int x;
        printf("Please, enter %d element: ", i + 1);
        if(inputN(&x)) {
            if(pushTreeList(&root, x) == '0') {
                i--; //?????????????????????????
            };
        } 
        else {
            printf("Invalid input, try again.\n");
            i--;
        }
    }


    char flag;
        do {
            int x;
            printf("Enter element to delete(search): ");
            inputN(&x);
            struct TreeList* node = search(root, x);
            if (node == NULL) {
                printf("The Node %d is not found!\n", x);
                freeTree(root);
                return;
            }
            printf("The dannoe Tree:\n");
            printTree(root, 0);
            printf("What you want to do with it in Tree?\n");
            printf("1. I whant to delete it;\n");
            printf("2. I want to count its amount in the Tree;\n");
            printf("3. EXIT;\n");
            printf("Your choice: ");
            char option;
            do {
                scanf(" %c", &option);
                switch(option)
                {
                    case '1':
                        deleteTreeList(root, x);
                        printf("Element %d deleted\n", x);
                        break;
                    case '2':
                        amountX(root, x);
                        break;
                    case '3':
                        break;
                    default:
                        printf("Oh! There is no this task, try again\n");
                        flag = 1;
                        continue;
                }
            } while(flag);
            printf("The new Tree:\n");
            printTree(root, 0);
            printf("Do you want to reapet manipulation with this Tree? (1 - YES, 0 - NO)\nYour choice: ");
            scanf(" %c", &flag);
        } while(flag == '1');
    freeTree(root);
}
