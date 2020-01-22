#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
//#include "db.c"
//#include "menu.c"
#define green "\033[1;32m"
#define blue  "\033[1;34m"


int main() {
    //execcQuery("insertTo students stdNo='9732531',name='negin',score=18");
//    char *query = "insertTo students stdNo='9732531',name='negin',score=18";
//    struct Table* thetable;
//    thetable = (struct Table *)malloc(sizeof(struct Table));
//    thetable = NULL;
//    insert(thetable, query);

//    int user_chose;
    printf("%s1. Create a new Table!\n", green);
    printf("%s2. Insert a property to the Table!\n", green);
    printf("%s3. Delete a property to the Table!\n", green);
    printf("%s4. Edit a property to the Table!\n", green);
    printf("%s5. Find a property to the Table!\n", green);
    printf("\n");

    printf("%sWhat you wanna do?...\n", blue);
//    scanf("%d", &user_chose);
//    //menu();
//
//
//    switch(user_chose) {
//
//        case 1 :
//            return 0;
//        case 2:
//            return 0;
//        case 3:
//            return 0;
//        case 4:
//            return 0;
//        case 5:
//            return 0;
//
//    }

    return 0;

}