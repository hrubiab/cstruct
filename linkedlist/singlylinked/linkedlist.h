/**
 * CStruct  https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct {
    int value;
} Info;

typedef struct tnode {
    struct tnode *next;
    Info *info;
} Node;

typedef struct {
    int size;
    Node *first;
} List;

// function prototypes
List *createlst();

void destroylst(List *lst);

int isemptylst(List *lst);

int positionlst(List *lst, Info *info);

int isinlst(List *lst, Info *info);

Info *findlst(List *lst, Info *info);

int lenlst(List *lst);

void printlst(List *lst);

Node *createnode();

Info *createinfo(int i);

int insertfirstlst(List *lst, Info *info);

int insertlastlst(List *lst, Info *info);

Info *delfirstlst(List *lst);

Info *delinfolst(List *lst, Info *info);

Info *delpositionlst(List *lst, int pos);

void reverselst(List *lst);

void sortlst(List *lst);

Info *dellastlst(List *lst);

#endif