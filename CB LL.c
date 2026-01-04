#include <stdio.h>
#define MAX 10

typedef struct{
    int data;
    int next;
}node;

node VH[MAX];
int head;
int freeList;

void initialize(){
    for (int i = 0; i < MAX - 1; i++){
        VH[i].next = i + 1;
    }
    VH[MAX - 1].next = -1;
    freeList = 0;
    head = -1;
}

void deallocate (int index){
 VH[index].next = freeList;
 freeList = index;
}

int allocate (){
    if (freeList == -1){
        return -1;
    }
    int index = freeList;
    freeList = VH[freeList].next;
    return index;
}

void insert_front (int value){
    int index = allocate();
    if (index == -1){
        printf ("List is Full");
        return;
    }
    VH[index].data = value;
    VH[index].next = head;
    head = index;
}

void insert_end(int value){
    int index = allocate();
    if (index == -1){
        printf("List is Full");
        return;
    }
    VH[index].data = value;
    VH[index].next = -1;
    if (head == -1){
        head = index;
        return;
    }

    int current = head;
    while (VH[current].next != -1)
    {
        current = VH[current].next;
    }
    VH[current].next = index;
}
void delete (int value){
    if (head == -1){
        return;
    }
    if (VH[head].data == value){
        int temp = head;
        head = VH[head].next;
        deallocate(temp);
        return;
    }
    int prev = head;
    int current = VH[head].next;

    while (current != -1 && VH[current].data != value)
    {
        prev = current;
        current = VH[current].next;
    }
    if (current != -1){
        VH[prev].next = VH[current].next;
        deallocate(current);
    }
}
void traversal(){
    int current = head;
    while (current != -1)
    {
        printf("%d ", VH[current].data);
        
        current = VH[current].next;
    }
    printf ("\n");
}

int main (){
    initialize();
    insert_front(5);
    insert_front(9);
    insert_front(4);
    insert_front(2);
    traversal();
    delete(5);
    traversal();
}