//
//  GenericList.h
//  Test
//
//  Created by Antoine Duong on 19/07/12.
//  Copyright (c) 2012 Epitech. All rights reserved.
//

#ifndef Test_GenericList_h
#define Test_GenericList_h

#define List(Typename)          t_list##Typename*

#define ListFunc(Typename, Name)      t_list##Typename##Name

#define ListInit(Typename) typedef struct s_node##Typename {                                                             \
                                  Typename  __value;                                                                            \
                                  Typename  (*value)(); \
                                  struct s_node##Typename* (*next)(struct s_node##Typename*);\
                                  struct s_node##Typename* (*prev)(struct s_node##Typename*); \
                                  struct s_node##Typename  *__next;                                                           \
                                  struct s_node##Typename  *__prev;                                                           \
                            } t_node##Typename;                                                                           \
                            typedef struct s_list##Typename {                                    \
                                    struct s_node##Typename*       (*push_front)(struct s_list##Typename*, Typename); \
                                    struct s_node##Typename*       (*push_back)(struct s_list##Typename*, Typename); \
                                    void                           (*remove)(struct s_list##Typename*, Typename); \
                                    void                           (*apply)(struct s_list##Typename*, void (*)(Typename*)); \
                                    size_t          (*size)(struct s_list##Typename*);         \
                                    size_t          __size;                                   \
                                    Typename        __value;                                  \
                                    t_node##Typename* begin;                                \
                                    t_node##Typename* end;                                  \
                                    struct s_list##Typename *next;                          \
                                    struct s_list##Typename *prev;                          \
                                }   t_list##Typename;                                         \
static t_node##Typename* t_node##Typename##new();\
static t_list##Typename* t_list##Typename##new(); \
static t_node##Typename* t_list##Typename##push_front(t_list##Typename* list,                   \
                                                        Typename new_value) {                   \
                    t_node##Typename* new_elem = t_node##Typename##new();                                                 \
                    new_elem = malloc(sizeof(t_node##Typename));                                \
                    if (new_elem == 0) return(0);                                               \
                    memcpy(&new_elem->__value, &new_value, sizeof(new_value));                     \
                    new_elem->__prev = 0; \
                    new_elem->__next = list->begin;                                                      \
                    list->begin->__prev = new_elem; \
                    list->begin = new_elem;                                                      \
                    list->size++;\
                    if (list->begin->__next == 0) list->end = list->begin; \
                    return new_elem;                                                            \
                }                                                                               \
                                                                                                \
static t_node##Typename* t_list##Typename##push_back(t_list##Typename* list,                           \
                                                    Typename new_value) {                             \
                    t_node##Typename* new_elem = t_node##Typename##new();                                                 \
                    if (new_elem == 0) return(0);                                               \
                    memcpy(&new_elem->__value, &new_value, sizeof(new_value));                     \
                    new_elem->__next = 0;                                                         \
                    list->end = new_elem;\
                    list->__size++;\
                    t_node##Typename* tmp = list->begin;                                               \
                    while (tmp && tmp->__next) tmp = tmp->__next;                                   \
                    if (tmp == 0) { \
                      list->begin = new_elem; \
                      list->end = new_elem;\
                      return new_elem;}                                              \
                    tmp->__next = new_elem;                                                       \
                    new_elem->__prev = tmp; \
                    return new_elem;                                                                \
                }                                                                               \
                                                                                                \
static size_t t_list##Typename##size(t_list##Typename* list) {                                            \
    return list->__size;                                                                        \
}                                                                                               \
                                                                                                \
static void t_list##Typename##apply(t_list##Typename* list, void (*func)(Typename*) ) {         \
                     t_node##Typename* t = list->begin;                                                                           \
                      while (t != 0) {                                                         \
                        func(&t->__value);                                                     \
                        t = t->__next;                                                      \
                    }                                                                           \
                }                                                                               \
                                                                                                \
static void        t_list##Typename##remove(t_list##Typename* list, Typename pattern) {       \
   t_node##Typename* tmp = list->begin; \
   if (tmp == 0) return ; \
  if (memcmp(&tmp->__value,&pattern,sizeof(pattern)) == 0) {                                                                          \
       list->__size--; \
       t_node##Typename* old_begin = list->begin;                                                         \
       list->begin = tmp->__next;                                                                       \
       free(tmp);\
       if (old_begin == list->end) list->end = list->begin;     \
       return ;                                                                             \
   }                                                                                            \
   while (tmp && memcmp(&tmp->__value, &pattern, sizeof(pattern)) != 0) {                            \
     tmp = tmp->__next;                                                                         \
   }                                                                                            \
   if (tmp != 0) {                                                                             \
     list->__size--; \
     t_node##Typename* toFree = tmp; \
     tmp->__prev->__next = tmp->__next ;                                                             \
     if (tmp->__next == 0) list->end = tmp->__prev; \
     free(tmp);                                                                                \
   }                                                                                            \
}                                                                                               \
static Typename t_node##Typename##value(t_node##Typename* this) {                               \
  return this->__value;                                                                           \
}            \
static t_node##Typename* t_node##Typename##next(t_node##Typename* this) { return this->__next; }    \
static t_node##Typename* t_node##Typename##prev(t_node##Typename* this) {return this->__prev;} \
static t_list##Typename* t_list##Typename##new() {                                              \
   t_list##Typename*   t = malloc(sizeof(t_list##Typename));                                    \
   if (t == 0) return 0;                                                                        \
   t->push_back = &t_list##Typename##push_back;                                                 \
   t->begin = 0; \
   t->push_front = &t_list##Typename##push_front;                                               \
   t->size = &t_list##Typename##size;                                                           \
   t->apply = &t_list##Typename##apply; \
   t->remove = &t_list##Typename##remove; \
   t->__size = 0;                                                                               \
  return t;                                                                                     \
}                                                                                               \
static t_node##Typename* t_node##Typename##new() { \
   t_node##Typename* t = malloc(sizeof(t_node##Typename)); \
   if (t == 0) return 0; \
   t->next = &t_node##Typename##next;\
   t->prev = &t_node##Typename##prev;\
   t->value = &t_node##Typename##value;\
   return t; \
}\

#define ListIterator(Typename) t_node##Typename*
 
#define GenerateList(Typename) typedef struct s_list##Typename {                            \
                                    Typename        value;                                  \
                                    struct s_list##Typename *next;                          \
                                }   t_list##Typename;                                       \

#define GenerateListFunction(Typename)                                                          \
t_list##Typename* t_list##Typename##push_front(t_list##Typename* list,                          \
                                                        Typename new_value) {                   \
                    t_list##Typename* new_elem;                                                 \
                    new_elem = malloc(sizeof(t_list##Typename));                                \
                    if (new_elem == 0) return(0);                                               \
                    memcpy(&new_elem->__value, &new_value, sizeof(new_elem));                     \
                    new_elem->next = list;                                                      \
                    return new_elem;                                                            \
                }                                                                               \
                                                                                                \
t_list##Typename* t_list##Typename##push_back(t_list##Typename* list,                           \
                                              Typename new_value) {                             \
                    t_list##Typename* new_elem;                                                 \
                    new_elem = malloc(sizeof(t_list##Typename));                                \
                    if (new_elem == 0) return(0);                                               \
                    memcpy(&new_elem->__value, &new_value, sizeof(new_elem));                     \
                    new_elem->next = 0;                                                         \
                    t_list##Typename* tmp = list;                                               \
                    while (tmp && tmp->next) tmp = tmp->next;                                   \
                    if (tmp == 0) return new_elem;                                              \
                    tmp->next = new_elem;                                                       \
                    return list;                                                                \
                }                                                                               \
                                                                                                \
int t_list##Typename##size(t_list##Typename* list) {                                            \
                    int count = 0;                                                              \
                    while (list != 0) {                                                         \
                        list = list->next;                                                      \
                        count++;                                                                \
                    }                                                                           \
                    return count;                                                               \
                }                                                                               \
                                                                                                \
void t_list##Typename##apply(t_list##Typename* list, void (*func)(Typename*) ) {                \
                    while (list != 0) {                                                         \
                        func(&list->__value);                                                     \
                        list = list->next;                                                      \
                    }                                                                           \
                }                                                                               \
void t_list##Typename##next(t_list##Typename* node) {                                    \
   return (node != 0 ? node->next : 0);                                                         \
}                                                                                               \
                                                                                                \
static t_list##Typename* t_list##Typename##remove(t_list##Typename* list, t_list##Typename* node) {       \
   if (list == node) {                                                                          \
       list = list->next;                                                                       \
       free(node);                                                                              \
       return list;                                                                             \
   }                                                                                            \
                                                                                                \
   while (list && list->next != node) {                                                         \
     list = list->next;                                                                         \
   }                                                                                            \
                                                                                                \
   if (list != 0) {                                                                             \
     list->next = list->next->next;                                                             \
     free(node);                                                                                \
   }                                                                                            \
   return list;                                                                                 \
}                                                                                               \
static Typename t_list##Typename##value(t_list##Typename* list) {                               \
  return list->__value;                                                                           \
}                                                                                               \



#define list_push_back(Typename) t_list##Typename##push_back
#define list_push_front(Typename) t_list##Typename##push_front
#define list_apply(Typename) t_list##Typename##apply
#define list_size(Typename) t_list##Typename##size

#endif
