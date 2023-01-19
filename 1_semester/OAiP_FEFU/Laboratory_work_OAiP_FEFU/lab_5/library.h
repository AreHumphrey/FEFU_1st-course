#ifndef STRUCTARRAY_LIBRARY_H
#define STRUCTARRAY_LIBRARY_H

struct stack *Init(int maxsize);
int DelStruct(struct stack* pt);
int Getsize(struct stack *pt);
int IsEmpty(struct stack *pt);
int IsFull(struct stack *pt);
void Addhead(struct stack *pt, int x);
int GetHead(struct stack *pt);
int DelHead(struct stack *pt);
#endif //STRUCTARRAY_LIBRARY_H
