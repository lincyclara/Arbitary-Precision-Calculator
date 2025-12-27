#ifndef HEAD_H
#define HEAD_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define e_failure -1
#define e_success 0

typedef struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
}DLL;

int my_atoi(const char *);
int addition(DLL *tail1,DLL *tail2,DLL **sum);
int insert_at_last(DLL **,DLL **,int);
int insert_at_first(DLL **,DLL **,int);
int subtraction(DLL *tail1,DLL *tail2,DLL **diff);
int division(DLL *head1,DLL *tail1,DLL *head2,DLL *tail2,DLL **div);
int multiplication(DLL *tail1,DLL *tail2,DLL **mul);
int mul_addition(DLL **,DLL **,DLL *,DLL *);
void zeros(DLL **,DLL **);
int get_sign(const char *);
int abs_val(int);

#endif