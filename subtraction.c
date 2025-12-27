#include "head.h"

int subtraction(DLL *tail1,DLL *tail2,DLL **diff)
{
    if(!tail1 || !tail2 || !diff)
    {
        return e_failure;
    }
    
    int b = 0;
    DLL *t1 = tail1;
    DLL *t2 = tail2;
    DLL *head = NULL;

    while(t1 != NULL || t2 != NULL || b != 0)
    {
        int d1 = t1 ? t1->data : 0;
        int d2 = t2 ? t2->data : 0;

        int d = d1 - d2 - b;
        if(d < 0){
            d = d + 10;
            b = 1;
        }
        else{
            b = 0;
        }

        DLL *new = malloc(sizeof(DLL));
        if(new == NULL){
            return e_failure;
        } 
        new->data = d;
        new->prev = NULL;
        new->next = head;
        if(head){
            head->prev = new;
        }
        head = new;

        if(t1 != NULL){
            t1 = t1->prev;
        }
        if(t2 != NULL){
            t2 = t2->prev;
        }   
    
    }
    *diff = head;
    return 0;
       
}
 