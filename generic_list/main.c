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
   
    ListIterator(int) it = myList;

    while ((it = ListFunc(int, next)(it)) != 0) {
       printf("Test : %d\n", ListFunc(int, value)(it));
    }

    ListFunc(int, apply)(myList, &intDisplay);
    printf("----- INC -----\n");
    ListFunc(int, apply)(myList, &intInc);
    printf("----- AFTER -----\n");
    ListFunc(int, apply)(myList, &intDisplay);
    return 0;
}

