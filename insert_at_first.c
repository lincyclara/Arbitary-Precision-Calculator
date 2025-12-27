#include<stdio.h>
#include<stdlib.h>
#include "head.h"

int insert_at_first(DLL **head,DLL **tail,int num)
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
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        return 0;
    }
}