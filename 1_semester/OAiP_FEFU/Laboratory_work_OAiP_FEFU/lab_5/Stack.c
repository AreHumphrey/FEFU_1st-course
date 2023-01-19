#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#define False 0
#define True 1
typedef int t_value;
struct stack {
    int maxsize;
    int top;
    int *items;
};

//Инициализация
struct stack *Init(int maxsize) {
    struct stack *pt = (struct stack *) malloc(sizeof(struct stack));
    pt->maxsize = maxsize;
    pt->top = -1;
    pt->items = (int *) malloc(sizeof(int) * maxsize);
    if (pt != 0)
        return pt;
    else {
        return NULL;
    }
};
//Деинициализация
int DelStruct(struct stack* pt){
    if (pt == NULL){
        return False;
    }
    for (int i = 1; i <= pt -> maxsize; i++){
        free(pt -> top + i );
    }
    free(pt);
    return True;
}
//Размер
int Getsize(struct stack *pt) {
    return pt->top + 1;
}
//Проверка на наполненность
int IsEmpty(struct stack *pt) {
    return pt->top == -1;
}
//Проверка на пустоту
int IsFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;
}
//Добавить элемент в начало
void Addhead(struct stack *pt, int x) {

    if (IsFull(pt)) {
        printf("STACK is FULL");
        exit(EXIT_FAILURE);
    }
    pt->items[++pt->top] = x;
}
//Вывести элемент
int GetHead(struct stack *pt) {
    if (!IsEmpty(pt)) {
        return pt->items[pt->top];
    } else {
        printf("NOT ELEMENT");
        exit(EXIT_FAILURE);
    }
}
//Удалить элемент
int DelHead(struct stack *pt) {
    if (IsEmpty(pt)) {
        printf("NOT ELEMENT");
        exit(EXIT_FAILURE);
    }
    return pt->items[pt->top--];
}







