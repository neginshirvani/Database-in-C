//
// Created by negin on 18/01/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"


struct TableField {
    char field_name[10];
    char field_type;
};




struct Property {  /** indivisuals */
    struct TableField * table_field;
    void * data;
    struct Property* next;
};

struct Row { /** the whole database */
    struct Property* properties;
    struct Row* next;
};

struct Table {
    char table_name[20];
    struct Row* the_rows;
};


char prefix(const char *pre, const char *str) {
    return strncmp(pre, str, strlen(pre)) == 0;
}


void printProperty(struct Property *p) {
    if(p->table_field->field_type == 0) {
        printf("%s %d\n", p->table_field->field_name, *(int *) (p->data));

    } else if(p->table_field->field_type == 1) {

        printf("%s %s\n", p->table_field->field_name, *(char **) (p->data));

    }
}


struct Table* CreatATable() {
    struct Table *new_table = malloc(sizeof(struct Table));

    new_table->the_rows = (struct Row*)malloc(sizeof(struct Row));
    new_table->the_rows->properties = (struct Property*)malloc(sizeof(struct Property));

    new_table->the_rows->properties->next = NULL;

    return new_table;

};

struct Property* CreateThing() {
  struct Property* new_property = malloc(sizeof(struct Property));

  new_property->table_field = (struct TableField*)malloc(sizeof(struct TableField));
  new_property->next = NULL;

  return new_property;
};





struct Table* insert(struct Table* the_table, char *query) {
    //struct Table * execcQuery();
    struct Table* NewTable;
    NewTable = execcQuery(query);

    if(the_table->the_rows->next == NULL)
        return NewTable;

    while (the_table->the_rows->next != NULL)
        the_table->the_rows = the_table->the_rows->next;

    NewTable->the_rows->next = the_table->the_rows->next;
    the_table->the_rows->next = (struct Row *) NewTable;
    printf("the table successfully added");

    return the_table;

}



struct Table* Deletee(struct Table* the_table, void *query) {

    if(the_table == NULL)
        return NULL;

    while(the_table->the_rows->next != NULL) {
        if(strcmp(the_table->the_rows->properties->data, query) == 0) {
            struct Row* tmp;
            tmp = the_table->the_rows->next->next;
            free(the_table->the_rows->next);
            the_table->the_rows->next = tmp;
        }
    }

    return the_table;
}



struct Row* selectt (struct Table* the_table, void * query) {

    if(the_table == NULL)
        return NULL;
    while(the_table->the_rows->properties->next != NULL && strcmp(the_table->the_rows->properties->data, query) == 0) {
        printProperty(the_table->the_rows->properties->data);
        the_table->the_rows->properties = the_table->the_rows->properties->next;
    }

};

//char prefix(const char *pre, const char *str);

char *p1, *p2;

struct Table* execcQuery(char *query){
  
    struct Table *the_table = NULL;

    char temp[100];

    if(prefix("insertTo", query)){
        p2 = p1 = query + 9;
        while(*p2 != ' ') p2++;
        char *table_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
        strncpy(table_name, p1, p2 - p1);

        strcpy(the_table->table_name, table_name);


        //printf(table_name);

        p2 = p1 = p2+1;
        while(*p2){
            while(*p2 != '=') p2++;
            char *field_name;
            //for(int i = 0 ; i < p2; i++) {
            field_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
            strncpy(field_name, p1, p2 - p1);
            strcpy(the_table->the_rows->properties->table_field->field_name, field_name);
            the_table->the_rows = (struct Row *) the_table->the_rows->properties->next;



            p2 = p1 = p2+1;
            while(*p2 && *p2 != ',') p2++;
            char *data;

            data = (char *) malloc((p2 - p1 + 1) * sizeof(char));
            strncpy(data, p1, p2 - p1);
            strcpy(the_table->the_rows->properties->data, data);
            the_table->the_rows = (struct Row *) the_table->the_rows->properties->next;
            //printf(data);
            if(*p2)
                p2 = p1 = p2+1;
            }

    }
    the_table->the_rows->next = NULL;
    return the_table;

}


struct Table* delexeccQuery(struct Table * the_table, char *query){

    if (the_table == NULL)
        return NULL;

    char temp[100];

    if(prefix("deleteFrom", query)){
        p2 = p1 = query + 9;
        while(*p2 != ' ') p2++;
        char *table_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
        strncpy(table_name, p1, p2 - p1);


        if (strcmp(the_table->table_name, table_name) == 0) {

            //printf(table_name);

            p2 = p1 = p2 + 1;
            while (*p2) {
                while (*p2 != '=') p2++;
                char *field_name;
                //for(int i = 0 ; i < p2; i++) {
                field_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
                strncpy(field_name, p1, p2 - p1);
                p2 = p1 = p2 + 1;

                if (strcmp(the_table->the_rows->properties->table_field->field_name, field_name) == 0) {


                    while (*p2 && *p2 != ',') p2++;
                    char *data;

                    data = (char *) malloc((p2 - p1 + 1) * sizeof(char));
                    strncpy(data, p1, p2 - p1);
                    while (the_table->the_rows->next != NULL) {
                        if (strcmp(the_table->the_rows->properties->data, data) == 0) {
                            struct Row* tmp;
                            tmp = the_table->the_rows->next->next;
                            free(the_table->the_rows->next);
                            the_table->the_rows->next = tmp;
                        }
                    }
                    if (*p2)
                        p2 = p1 = p2 + 1;
                }
            }
        }

    }

    return the_table;

}




struct Table* FindexeccQuery(struct Table *the_table ,char *query){

    if (the_table == NULL) return NULL;


    char temp[100];

    if(prefix("FindIn", query)) {
        p2 = p1 = query + 9;
        while (*p2 != ' ') p2++;
        char *table_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
        strncpy(table_name, p1, p2 - p1);

        if (strcmp(the_table->table_name, table_name) == 0) {


            //printf(table_name);

            p2 = p1 = p2 + 1;
            while (*p2) {
                while (*p2 != '=') p2++;
                char *field_name;
                //for(int i = 0 ; i < p2; i++) {
                field_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
                strncpy(field_name, p1, p2 - p1);
                p2 = p1 = p2 + 1;

                if (strcmp(the_table->the_rows->properties->table_field->field_name, field_name) == 0) {


                    while (*p2 && *p2 != ',') p2++;
                    char *data;

                    data = (char *) malloc((p2 - p1 + 1) * sizeof(char));
                    strncpy(data, p1, p2 - p1);

                    while (the_table->the_rows->properties->next != NULL && strcmp(the_table->the_rows->properties->data, data) == 0) {
                        printProperty(the_table->the_rows->properties->data);
                        the_table->the_rows->properties = the_table->the_rows->properties->next;
                    }

                    if (*p2)
                        p2 = p1 = p2 + 1;
                }
            }

        }
    }

    return the_table;

}