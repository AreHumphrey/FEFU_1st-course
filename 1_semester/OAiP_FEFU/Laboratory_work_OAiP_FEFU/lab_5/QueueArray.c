#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#define True 1;
#define False 0;
struct Queue
{
    int Value;
    struct Queue* next;
}*rear = NULL, *front = NULL;

// функция для выделения нового узла Queue
struct Queue* Initialisation(int item)
{
    // выделяем новый узел в куче
    struct Queue* node = (struct Queue*)malloc(sizeof(struct Queue));

    // проверяем, заполнена ли Queue (куча). Тогда вставка элемента будет
    // привести к переполнению кучи
    if (node != NULL)
    {
        // устанавливаем данные в выделенном узле и возвращаем их
        node->Value = item;
        node->next = NULL;
        return node;
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// Функция для удаления переднего элемента из очереди
int Delqueue()        // удалить в начале
{
    if (front == NULL)
    {
        exit(EXIT_FAILURE);
    }

    struct Queue* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    int item = temp->Value;
    free(temp);
    return item;
}

//  Функция для добавления элемента в Queue (вставка в конце)
void EndQueue(int item)
{

    struct Queue* node = Initialisation(item);
    if (front == NULL)
    {
        front = node;
        rear = node;
    }
    else {
        rear->next = node;
        rear = node;
    }
}

// Функция для возврата верхнего элемента в Queue
int Peek()
{
    // проверяем наличие пустой Queue
    if (front != NULL) {
        return front->Value;
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// Функция для проверки, пуста ли Queue или нет
int IsEmpty() {
    return rear == NULL && front == NULL;
}
int Deinitialization ()
{
    if (front == NULL){
        return False;
    }
    while (front-> next != 0){
        Deinitialization(front->next -> next);
        free(front->next);
    }
    free(front->next);
    free(front);
    free(rear);
    return True;
}



