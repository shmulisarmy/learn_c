#include <stdio.h>
#include <sqlite3.h>


static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}



int main(){
    sqlite3* db;
    if (sqlite3_open("main.db", &db)){
        perror("failed to open db");
        return 1;
    }

    char* errorMessage = 0;

    const char* query = "select * from users";


    if (sqlite3_exec(db, query, callback, 0, &errorMessage) != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", errorMessage);
    }

    sqlite3_close(db);

}
