//
// Created by negin on 20/01/20.
//

#ifndef DATABASE_DB_H
#define DATABASE_DB_H



struct TableField;
struct data;
struct Property;
struct Row;
void printProperty(struct Property *p);
struct Row* CreatATable() ;
struct Property* CreateThing();
struct Row* new_insrt(struct Row* all, char * MyFieldName, void * Mydata);
struct Row* insert(struct Row* all, char * MyFieldName, void * Mydata);
struct Row* deletee(struct Row* all, char * MyFieldName);
struct Row* selectt (struct Row* all, void * data);

char prefix(const char *pre, const char *str);

struct Table* execcQuery(char *query);

#endif //DATABASE_DB_H