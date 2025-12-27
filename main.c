/*
Name : Lincy K
Date : 12/10/2025
Description :  The Arbitrary Precision Calculator (APC) is a Data Structures and Algorithms project 
               implemented in C that performs arithmetic operations on extremely large numbers beyond 
               the capacity of standard data types. Using doubly linked lists where each node stores a 
               single digit, the calculator can handle numbers of virtually unlimited length. The project 
               implements all four basic arithmetic operations—addition, subtraction, multiplication, and 
               division—using digit-by-digit processing algorithms that mimic manual calculation methods 
               with proper carry, borrow, and intermediate result handling. This implementation demonstrates 
               core DSA concepts including linked list manipulation, dynamic memory management, pointer operations,
               and algorithmic problem-solving, providing a practical solution for applications requiring high-precision
               calculations such as cryptography, scientific computing, and large-scale financial computations where 
               conventional integer types fall short.

*/

#include<stdio.h>
#include <string.h>
#include "head.h"

int abs_val(int num){
    return num < 0 ? -num : num;
}

int main(int argc , char *argv[])
{
    DLL *head1 = NULL, *tail1 = NULL; //Head and tail of 1st Linked list
    DLL *head2 = NULL, *tail2 = NULL; //Head and tail of 2nd Linked list

    int r;
    int a = 0;
    // checking whether the arguements found or not
    if(argc < 4)
    {
        printf("Use arguements : ./a.out <num1> operator <num2>\n");
        return e_failure;
    }

    char str[100]; // copy array
    strcpy(str,argv[1]); // copying....
    
    if(str[0] == '-' || str[0] == '+')
        a = 1;
    //Inserting elements into Linked list(1st num)
    for(int i=a; str[i]!='\0'; i++)
    {
        r =insert_at_last(&head1,&tail1,(str[i]-'0')) ;
        
    }
    int out1 =  my_atoi(str); // coverting char array to integer(num1)
    
    char  str1[100]; // copy array
    strcpy(str1,argv[3]);// copying....

    a = 0;
    if(str1[0] == '-' || str1[0] == '+')
        a = 1;
    //Inserting elements into Linked list(2nd num)
    for(int i=a; str1[i]!= '\0' ;i++)
    {
        r = insert_at_last(&head2,&tail2,(str1[i]-'0'));
        
    }
    int out2 =  my_atoi(str1); // coverting char array to integer(num2)

    char operator = argv[2][0];
    DLL *res = NULL, *res_tail = NULL;

    int sign1 = get_sign(argv[1]);
    int sign2 = get_sign(argv[3]);

    int res_i;
    int res_sign = 1;
    
    switch(operator)
    {
        case '+':
        if(sign1 == sign2)
        {
            res_i = addition(tail1,tail2,&res);
            res_sign = sign1;
        }
        else
        {  
            if(abs_val(out1) >= abs_val(out2)){
                res_i = subtraction(tail1,tail2,&res);
                res_sign = sign1;
            }
            else{
                res_i = subtraction(tail2,tail1,&res);
                res_sign = sign2;
            }
        }

        if(res_i == e_failure)
        {
            printf("Error!\n");
        }
        else
        {
            zeros(&res,&res_tail);
            if(res_sign == -1 && !(res->data == 0 && res->next == NULL)){
                printf("-");
            }
            DLL *temp = res;
            while(temp)
            {
                printf("%d",temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        break;

        case '-':
        if(sign1 == sign2){
            if(abs_val(out1) >= abs_val(out2)){
                res_i = subtraction(tail1,tail2,&res);
                res_sign = sign1;
            }
            else{
                res_i = subtraction(tail2, tail1, &res);
                res_sign = -sign1;
            }
        }
        
        else{
                res_i = addition(tail1, tail2, &res);
                res_sign = sign1;
        }
        
        //res_i = subtraction(tail1, tail2, &res);
        if(res_i == e_failure)
        {
            printf("Error!\n");
        }
        else
        {
            //printf("Difference : ");
            zeros(&res,&res_tail);
            if(res_sign == -1 && !(res->data == 0 && res->next == NULL)){
                printf("-");
            }
            DLL *temp = res;
            while(temp)
            {
                printf("%d",temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        break;
        
        case 'x':
        res_i = multiplication(tail1, tail2, &res);
        res_sign = (sign1 *sign2 == -1) ? -1 : 1;

        if(res_i == e_failure)
        {
            printf("Error!\n");
        }
        else
        {
           
            zeros(&res,&res_tail);
            if(res_sign == -1 && !(res->data == 0 && res->next == NULL)){
                printf("-");
            }
            DLL *temp = res;
            while(temp)
            {
                printf("%d",temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        break;
        
        case '/':
        res_i = division(head1, tail1, head2, tail2,&res);
        res_sign = (sign1 *sign2 == -1) ? -1 : 1;
        if(res_i == e_failure)
        {
            printf("Error!\n");
        }
        else
        {
            zeros(&res,&res_tail);
            if(res_sign == -1 && !(res->data == 0 && res->next == NULL)){
                printf("-");
            }
            DLL *temp = res;
            while(temp)
            {
                printf("%d",temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        break;


        default:
        printf("Invalid option!!!\n");
        return e_failure;
    }
    
    while(head1){
        DLL *temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while(head2){
        DLL *temp = head2;
        head2 = head2->next;
        free(temp);
    }
    while(res){
        DLL *temp = res;
        res = res->next;
        free(temp);
    }
    return e_success;
}


int my_atoi(const char * str)
{
    int sign = 1;
    int result = 0;
    int i=0;

    while(str[i] == ' ' )
    {
        i++;
    }
    if(str[i] == '-')
    {
        sign =-1;
        i++;
    }
    else if(str[i] == '+')
    {
        i++;
    }
    while(str[i] >= '0' && str[i]<='9')
    {
        result = result*10 + (str[i] - '0');
        i++;
    }
    return sign*result;
}

void zeros(DLL **head,DLL **tail)
{
    if(*head == NULL)
    {
        return;
    }
    while((*head)->data == 0 && (*head)->next != NULL)
    {
        DLL *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);

    }
}

int get_sign(const char *str){
    if(str[0] == '-')
    {
        return -1;
    }
    return 1;
}
