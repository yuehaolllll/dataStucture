#include "Queue.h"

void TestQueue(){

    Queue q;
    QueueInit(&q);

    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    QueuePush(&q, 5);

    while(!QueueEmpty(&q)){
        QDataType Front = QueueFront(&q);
        printf("%d ", Front);
        QueuePop(&q);
    }

    QueueDestroy(&q);

}

int main(){

    TestQueue();
    return 0;

}

