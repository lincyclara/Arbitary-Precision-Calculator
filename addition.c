#include "head.h"

int  addition(DLL *tail1,DLL *tail2,DLL **sum)
{
    if( !sum)
    {
        return e_failure;
    }

    int c = 0; // c= carry

    DLL *t1 = tail1;
    DLL *t2 = tail2;
    if(!tail1 && !tail2)
    {
        return e_failure;
    }

    DLL *head = NULL ;


    while( t1 != NULL || t2 != NULL || c != 0)
    {
        int a1 = t1 ? t1->data : 0;
        int a2 = t2 ? t2->data : 0;

        int s  = a1 + a2 + c;
        //c = s / 10;
        int d = s % 10;
        if( s  > 9)
        {
            c = 1;
        }
        else
        {
            c = 0 ;
        }
        DLL *new = malloc(sizeof(DLL));
        if(new == NULL)
        {
            return e_failure;
        }
        new->data = d;
        new->prev = NULL;
        new->next = head;
        
        if(head)
        {
            head->prev = new; 
        }
        head = new;
        
        if(t1 != NULL )
            t1 = t1->prev;
        if(t2 != NULL)
            t2 = t2->prev;
    }
    *sum = head;
    return 0;
}