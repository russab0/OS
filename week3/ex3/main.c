#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct List{
    int x;
    struct List *next;
};


struct List* create_list(int x, struct List* next){
    struct List *l = (struct List*) malloc(sizeof(struct List));
    l->x = x;
    l->next = next;
    return l;
}


void print_list(struct List *l){ // will print out the value of each element
    printf("%i ", l->x);
    if (l->next == NULL){
        printf("\n");
        return;
    }
    print_list(l->next);
}


void insert_node(struct List *l, int pos, int val){ // will insert a new element after some existing element
    if (l->next == NULL && pos > 0){
        printf("no such element\n");
        return;
    }
    if (pos == 0){
        l->next = create_list(val, l->next);
        return;
    }
    insert_node(l->next, pos - 1, val);
}


void delete_node(struct List *l, int pos, struct List *prev){ // will delete a certain element
    if (l->next == NULL && pos > 0){
        printf("no such element\n");
        return;
    }
    if (pos == 0){
            l->x = l->next->x;
            l->next = l->next->next;
        }
        else{
            prev->next = l->next;
        }
        return;
    }
    delete_node(l->next, pos - 1, l);
}



int main()
{
    struct List *l = create_list(21, NULL);


    print_list(l);
    insert_node(l, 0, 5);
    print_list(l);
    insert_node(l, 0, 10);
    print_list(l);
    insert_node(l, 1, 15);
    print_list(l);
    insert_node(l, 3, 100);
    print_list(l);


    insert_node(l, 4, 1);
    insert_node(l, 5, 2);
    insert_node(l, 6, 3);
    insert_node(l, 7, 4);
    print_list(l);


    delete_node(l, 0, NULL);
    print_list(l);
    delete_node(l, 8, NULL);
    print_list(l);
    delete_node(l, 5, NULL);
    print_list(l);
    delete_node(l, 0, NULL);
    print_list(l);

    return 0;
}
