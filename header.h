#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct TreeList {
    int field;
    struct TreeList *left, *right;
};
int inputN(int*);
struct TreeList* createTreeList(int);
int pushTreeList(struct TreeList**, int);
void printTree(struct TreeList*, int);
struct TreeList* search(struct TreeList*, int);
struct TreeList* findMinList(struct TreeList*);
struct TreeList* deleteTreeList(struct TreeList*, int);
int findinTree(struct TreeList*, int);
void freeTree(struct TreeList*); 

#endif
