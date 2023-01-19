#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

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

// Вспомогательная функция для удаления переднего элемента из очереди
int Delqueue()        // удалить в начале
{
    if (front == NULL)
    {
        exit(EXIT_FAILURE);
    }

    struct Queue* temp = front;

    // продвигаемся вперед к следующему узлу
    front = front->next;

    // если список станет пустым
    if (front == NULL) {
        rear = NULL;
    }

    // освобождаем память удаленного узла и при необходимости возвращаем удаленный элемент
    int item = temp->Value;
    free(temp);
    return item;
}

// Вспомогательная функция для добавления элемента в Queue
void EndQueue(int item)        // вставка в конце
{
    // выделяем новый узел в куче
    struct Queue* node = Initialisation(item);

    // особый случай: Queue пуста
    if (front == NULL)
    {
        // инициализируем и переднюю, и заднюю часть
        front = node;
        rear = node;
    }
    else {
        // обновить заднюю часть
        rear->next = node;
        rear = node;
    }
}

// Вспомогательная функция для возврата верхнего элемента в Queue
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

// Вспомогательная функция для проверки, пуста ли Queue или нет
int IsEmpty() {
    return rear == NULL && front == NULL;
}



