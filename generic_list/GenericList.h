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

#define ListInit(Typename) typedef struct s_list##Typename {                                    \
                                    Typename        value;                                  \
                                    struct s_list##Typename *next;                          \
                                    struct s_list##Typename *prev;                          \
                                }   t_list##Typename;                                       \
static t_list##Typename* t_list##Typename##push_front(t_list##Typename* list,                   \
                                                        Typename new_value) {                   \
                    t_list##Typename* new_elem;                                                 \
                    new_elem = malloc(sizeof(t_list##Typename));                                \
                    if (new_elem == 0) return(0);                                               \
                    memcpy(&new_elem->value, &new_value, sizeof(new_elem));                     \
                    new_elem->next = list;                                                      \
                    return new_elem;                                                            \
                }                                                                               \
                                                                                                \
static t_list##Typename* t_list##Typename##push_back(t_list##Typename* list,                           \
                                              Typename new_value) {                             \
                    t_list##Typename* new_elem;                                                 \
                    new_elem = malloc(sizeof(t_list##Typename));                                \
                    if (new_elem == 0) return(0);                                               \
                    memcpy(&new_elem->value, &new_value, sizeof(new_elem));                     \
                    new_elem->next = 0;                                                         \
                    t_list##Typename* tmp = list;                                               \
                    while (tmp && tmp->next) tmp = tmp->next;                                   \
                    if (tmp == 0) return new_elem;                                              \
                    tmp->next = new_elem;                                                       \
                    return list;                                                                \
                }                                                                               \
                                                                                                \
static int t_list##Typename##size(t_list##Typename* list) {                                            \
                    int count = 0;                                                              \
                    while (list != 0) {                                                         \
                        list = list->next;                                                      \
                        count++;                                                                \
                    }                                                                           \
                    return count;                                                               \
                }                                                                               \
                                                                                                \
static void t_list##Typename##apply(t_list##Typename* list, void (*func)(Typename*) ) {                \
                    while (list != 0) {                                                         \
                        func(&list->value);                                                     \
                        list = list->next;                                                      \
                    }                                                                           \
                }                                                                               \
                                                                                                \
static t_list##Typename* t_list##Typename##next(t_list##Typename* node) {                                    \
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
  return list->value;                                                                           \
}                                                                                               \

#define ListIterator(Typename) t_list##Typename*
 
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
                    memcpy(&new_elem->value, &new_value, sizeof(new_elem));                     \
                    new_elem->next = list;                                                      \
                    return new_elem;                                                            \
                }                                                                               \
                                                                                                \
t_list##Typename* t_list##Typename##push_back(t_list##Typename* list,                           \
                                              Typename new_value) {                             \
                    t_list##Typename* new_elem;                                                 \
                    new_elem = malloc(sizeof(t_list##Typename));                                \
                    if (new_elem == 0) return(0);                                               \
                    memcpy(&new_elem->value, &new_value, sizeof(new_elem));                     \
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
                        func(&list->value);                                                     \
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
  return list->value;                                                                           \
}                                                                                               \



#define list_push_back(Typename) t_list##Typename##push_back
#define list_push_front(Typename) t_list##Typename##push_front
#define list_apply(Typename) t_list##Typename##apply
#define list_size(Typename) t_list##Typename##size

#endif
