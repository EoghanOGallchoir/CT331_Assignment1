#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

genericListElement *createEl(void *info, size_t size, printer printFunc) {
    
    genericListElement* el = malloc(sizeof(genericListElement));
    
    //Error in malloc
    if(el == NULL) {
        return NULL;
    }
    
    void *dataPointer = malloc(size);
    
   
    if(dataPointer == NULL) {
        free(el);
        return NULL;
    }
    
    memmove(dataPointer, info, size);
    
    el->info = dataPointer;
    el->size = size;
    el->printFunc = printFunc;
    el->next = NULL;
    
    return el;
    
}
void traverse(genericListElement *beginning) {
    genericListElement *currEl = beginning;
    
    while(currEl != NULL) {
        currEl->printFunc(currEl->info);
        currEl = currEl->next;
    }
    
}

genericListElement* insertAfter(genericListElement* el, void *info, size_t size, printer printFunc) {
    
    genericListElement* newEl = createEl(info, size, printFunc);
    
    genericListElement* next = el->next;
    
    newEl->next = next;
    el->next = newEl;
    
    return newEl;
    
}

void deleteAfter(genericListElement* afterEl) {
    genericListElement* deleteEl = afterEl->next;
    genericListElement* newNextEl = deleteEl->next;
    afterEl->next = newNextEl;
    
    free(deleteEl->info);
    free(deleteEl);
}

int length(genericListElement *list) {
    
    genericListElement *currEl = list;
    int counter = 0;
    
    while(currEl != NULL) {
        counter++;
        currEl = currEl->next;
    } 
    
}

void push(genericListElement **list, void *info, size_t size, printer printFunc) {
    
    genericListElement *newEl = createEl(info, size, printFunc);
    
    newEl->next = *list;
    
    *list = newEl;
    
}

genericListElement *pop(genericListElement **list) {
    genericListElement *headEl = *list;
    
    if(headEl) {
        *list = headEl->next;
    }
    
    return headEl;
}

void enqueue(genericListElement **list, void *info, size_t size, printer printFunc) {
    genericListElement *newEl = createEl(info, size, printFunc);
    
    newEl->next = *list;
    
    *list = newEl;
}

genericListElement *dequeue(genericListElement *list) {
    genericListElement *temp = list;
    
    while((temp-> next)-> next != NULL) {
        temp = temp->next;
    }
    
    genericListElement *tailEl = temp->next;
    temp->next = NULL;
    
    return tailEl;
    
}

