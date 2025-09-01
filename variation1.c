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
insertPos (L,500,5);
deletePos (L,5);
};
List initialize (List L){
        int temp = 0;
    printf ("Pls insert a number:");
    for (int i = 0; i < MAX; i++)
    {
        printf ("[%d]: ", i + 1);
        scanf ("%d", &temp);
    L.elem[i] = temp;
    }
    L.count = 0;
     Display (L);
    return L;
};
List insertPos (List L, int data, int position){
    if (position > MAX || position < 0)
    {
        printf ("\ninvalid position");
        return L;
    }
    
for (int i = MAX; i >= position; i--)
{
    L.elem[i + 1] = L.elem[i];
}
L.elem[position] = data;
    Display (L);
    return L;
};


void Display (List L){
    printf ("\n");
for (int i = 0; i < MAX; i++)
    {
        printf ("%d, ", L.elem[i]);
    }
}
List deletePos (List L, int position){
    for (int i = MAX; i > position; i--)
{
    L.elem[i - 1] = L.elem[i];
}
    Display (L);
}