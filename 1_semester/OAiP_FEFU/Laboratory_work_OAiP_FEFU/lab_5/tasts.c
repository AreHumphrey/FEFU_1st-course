#include <stdio.h>
//#include "Stack.c"
#include "Queue.c"
//int main() {
//    struct stack *pt = Init(5);
//    Addhead(pt, 1);
//    Addhead(pt, 2);
//    Addhead(pt, 3);
//    printf("The top element is %d\n", GetHead(pt));
//    printf("The stack get_size %d\n", Getsize(pt));
//    DelHead(pt);
//    DelHead(pt);
//    printf("element %d\n", GetHead(pt));
//    printf("get_size%d\n", Getsize(pt));
//    DelHead(pt);
//    printf("The top element is %d\n", GetHead(pt));
//    printf("The stack get_size is %d\n", Getsize(pt));
//}
int main()
{
    EndQueue(1);
    EndQueue(2);
    EndQueue(3);
    EndQueue(4);

    printf("The front element is %d\n", Peek());

//    Delqueue();
    Delqueue();
    Delqueue();
    Delqueue();

    if (IsEmpty()) {
        printf("The Queue is empty");
    }
    else {
        printf("The Queue is not empty");
    }

    Deinitialization();

    return 0;
}
