#include "head.h"

int insert_at_last(DLL **head,DLL **tail,int num)
{
    DLL *new = malloc(sizeof(DLL));

    if(new == NULL)
    {
        return -1;
    }
    new->data = num;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
       
        *head = new;
        *tail = new;
        return 0;
    }
    else{
        new->prev = *tail;
        (*tail)->next = new;
        *tail =new;
        return 0;
    }

}