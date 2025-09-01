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
initialize (L);
insertPos (L, 5, 5);
};
List initialize (List L){
    printf ("Pls insert a number:");
    for (int i = 0; i < MAX; i++)
    {
        printf ("[%d], ", MAX - 1);
    L.elem[MAX] =
    }
    L.count = 0;
    return L;
};
List insertPos (List L, int data, int position){
for (int i = MAX - 1; i > 0; i--)
{
    printf ("%d ", L.elem[i]);
    if (L.elem == NULL)
    {
        break;
    }
    
}

};