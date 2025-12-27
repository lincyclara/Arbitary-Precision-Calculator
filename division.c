#include "head.h"

int division(DLL *head1,DLL *tail1,DLL *head2,DLL *tail2,DLL **div)
{
    if(!head1 || !head2 || !div){
        return e_failure;
    }

    DLL *h1 = head1;
    DLL *h2 = head2;

    long long result = 0;
    long long value1= 0,value2 = 0;
    long long sum = 0;

    while(h1){
        if(h1->data >= 0 && h1->data <= 9)
            value1 = value1 *10 + h1->data ;
        h1 = h1->next;
    }
    while(h2){
        if(h2->data >= 0 && h2->data <= 9 )
            value2 = value2 *10 + h2->data  ;
        h2 = h2->next;
    }
    if(value2 == 0){
        return e_failure;
    }
    while( sum + value2 <= value1 )
    {    
        sum = sum + value2;  
        result++;
    }
    if(result == 0){
        DLL *temp_tail = NULL;
        insert_at_last(div,&temp_tail,0);
    }
    else{
        long long temp = result;
        int digits[21];
        int count = 0;

        while(temp > 0){
            digits[count++] = temp % 10 ;
            temp /= 10;
        }
        DLL *temp_tail =  NULL;
        for(int i = count-1 ; i>= 0;i--){
            insert_at_last(div,&temp_tail,digits[i]);
            if(temp_tail == NULL){
                temp_tail = *div;
            }
            while(temp_tail && temp_tail->next){
                temp_tail = temp_tail->next;
            }
        }
    }
    
    return e_success;
}