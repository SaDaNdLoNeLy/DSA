#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    double math, physics;
}student;


typedef struct dllist
{
    student data;
    struct dllist *next;
    struct dllist *prev;
}duo_list;

duo_list *head, *tail;
