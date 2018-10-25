#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST
 typedef void (*printer) (void *info);
 typedef struct genericListElementStruct {
    void *info;
    size_t size;
    printer printFunc;
    struct genericListElementStruct *next;
} genericListElement;

 void traverse(genericListElement *beginning);
 
 genericListElement* insertAfter(genericListElement* el, void *info, size_t size, printer);
 
 void deleteAfter(genericListElement* afterEl);
 
 genericListElement *createEl(void *info, size_t size, printer);
 
 int length(genericListElement *list);
 
 void push(genericListElement **list, void *info, size_t size, printer);
 
 genericListElement *pop(genericListElement **list);
 
 void enqueue(genericListElement **list, void *info, size_t size, printer);
 
 genericListElement *dequeue(genericListElement *list);
 

 #endif