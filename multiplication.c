#include "head.h"

int multiplication(DLL *tail1,DLL *tail2,DLL **mul)
{
    if(!mul || !tail1 || !tail2)
    {
        return e_failure;
    } 

    DLL *head3 = NULL , *tail3 = NULL;    

    int m ,d ; 
    int count = 0;

    DLL *temp2 = tail2;

    while(temp2){

        DLL *head4 = NULL , *tail4 = NULL;
        DLL *temp1 = tail1;
        int carry = 0;

        while(temp1){
            m =  (temp1->data * temp2->data) + carry ;
            carry = m / 10 ;
            d = m % 10 ;

            insert_at_first(&head4, &tail4, d);
            temp1 = temp1->prev;   
        }

        if(carry > 0){
            insert_at_first(&head4,&tail4,carry);
        }

        for(int i=0;i<count;i++)
        {
            insert_at_last(&head4, &tail4, 0);
        }

        if(head3 == NULL){
            head3 = head4;
            tail3 = tail4;
        }
        else
        {
            mul_addition(&head3, &tail3, head4, tail4);
        }

        count++;
        temp2 = temp2->prev;
    }

    *mul = head3;
    return e_success;
         
}
int mul_addition(DLL **head1,DLL **tail1,DLL *head2,DLL *tail2)
{
    
    int c = 0; // c= carry

    DLL *t2 = tail2;
    DLL *t1 = *tail1;

    while( t2 != NULL  )
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
        
        if(t1 != NULL){
            t1->data = d;
            t1 = t1->prev;
        }
        else
        {
            insert_at_first(head1, tail1, d);
            t1 = NULL;
        }
        if(t2 != NULL){
            t2 = t2->prev;
        }
    
    }
    if(c){
        insert_at_first(head1, tail1, c);
    }
    return e_success;
}