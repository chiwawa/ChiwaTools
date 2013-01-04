//
//  main.c
//  Test
//
//  Created by Antoine Duong on 19/07/12.
//  Copyright (c) 2012 Epitech. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "GenericList.h"

ListInit(int)

void
intDisplay(int* t) {
    printf("List : %d\n", *t);
}

void
intInc(int *t) {
    (*t)++;
}

int
main(int argc, const char * argv[]) {
    List(int)  toto = ListFunc(int, new)();

    printf("%d\n", toto->size(toto));
    toto->push_back(toto, 1);
    printf("%d\n", toto->begin->__value);
    printf("Size : %d\n", toto->size(toto));


    toto->push_front(toto, 2);
    toto->push_back(toto, 4);
    toto->remove(toto, 1);
    printf("Display ----\n");
    toto->apply(toto, &intDisplay);
    toto->apply(toto, &intInc);
    printf("Display ----\n");
    toto->apply(toto, &intDisplay);
    ListIterator(int) it = toto->begin;
    while (it) {
      printf("----%d----\n", it->value(it));
      it = it->next(it);
    }
    /*
    List(int)    myList = 0;
    
    //myList = ListFunc(int, push_back)(myList, 1);
    
    myList = list_push_back(int)(myList, 1);
    if (myList == 0) {
        printf("Memory Error\n");
        return 0;
    }
    
    myList = ListFunc(int, push_back)(myList, 2);
    if (myList == 0) {
        printf("Memory Error\n");
        return 0;
    }
    
    myList = ListFunc(int, push_back)(myList, 3);
    if (myList == 0) {
        printf("Memory Error\n");
        return 0;
    }
    
    myList = ListFunc(int, push_back)(myList, 4);
    if (myList == 0) {
        printf("Memory Error\n");
        return 0;
    }
    
    printf("size ::%d::\n", ListFunc(int, size)(myList));

    ListFunc(int, apply)(myList, &intDisplay);
    printf("----- INC -----\n");
    ListFunc(int, apply)(myList, &intInc);
    printf("----- AFTER -----\n");
    ListFunc(int, apply)(myList, &intDisplay);
 */   return 0;
}

