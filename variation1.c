#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    int elem[MAX];
    int count;
}List;
List initialize (List L);
List insertPos (List L, int data, int position);
List deletePos (List L, int position);
int Locate (List L, int data);
List insertSorted (List L, int data);
void Display (List L);
int main (){
List L;
L = initialize (L);
L = insertPos (L,1,0);
L = insertPos (L,3,1);
L = insertPos (L,2,2);
L = insertPos (L,5,3);
L = deletePos (L,1);
}
List initialize (List L){
    L.count = 0;
    return L;
};
List insertPos (List L, int data, int position){
if (position < 0 || position > L.count)
{
    printf ("Invalid Position");
    return L;
}
if (L.count == MAX){
    printf ("List is Full");
    return L;
}
for (int i = L.count - 1; i >= position; i--){//i-- is to the left
 L.elem[i + 1] = L.elem[i];//right traversal. next is going to be the current.
}

L.elem[position] = data;
L.count++;
Display(L);
return L;
};

void Display (List L){
    printf ("\n");
    if (L.count == 0){
        printf ("Uh oh");
    };
for (int i = 0; i < L.count; i++)
    {
        printf ("%d, ", L.elem[i]);
        if (L.count == i){
            break;
        }
    }
    printf ("[%d]", L.count); 
}
List deletePos (List L, int position){
    if (position < 0 || position >= L.count){ //checks if the position is invalid. As in as long as position is bigger than zero or position is bigger or equal to count.
        printf ("Invalid Position");
        return L;
    }
    for (int i = position; i < L.count - 1; i++){// i++ is traversal to the right. Starting from the given position, it will re iterate until position is going to be greater than count.
        L.elem[i] = L.elem[i + 1];// left traversal. current is going to be the next.
    }
L.count--;
    Display (L);
    return L;
}
int Locate (List L, int data);
List insertSorted (List L, int data);