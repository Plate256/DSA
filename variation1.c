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
L = insertPos (L,500,0);
L = insertPos (L,250,8);
L = insertPos (L,2250,5);
};
List initialize (List L){
    L.count = 0;
    return L;
};
List insertPos (List L, int data, int position){
    if (L.count > MAX || position < 0)
    {
        printf ("\ninvalid position");
        return L;
    }
    for (int i = MAX; i >= position; i--){
        L.elem[i + 1] = L.elem[i];
    }

    

    L.elem[position] = data;
L.count++;
    Display (L);
    return L;
};

void Display (List L){
    printf ("\n");
    if (L.count == 0){
        printf ("Uh oh");
    };
for (int i = 0; i < MAX; i++)
    {
        printf ("%d, ", L.elem[i]);
        if (L.count == i){
            break;
        }
    }
    printf ("[%d]", L.count); 
}
List deletePos (List L, int position){
    for (int i = MAX; i > position; i--)
{
    L.elem[i - 1] = L.elem[i];
}
    Display (L);
}