#include <stdio.h>


int main(){
    FILE* f = fopen("file.txt", "a");
    if (f == NULL){
        perror("file open err\n");
    }

    fputs("\nthis is some new fuck", f);

    char buffer[255];
    while (fgets(buffer, 255, f)){
        printf("%s", buffer);
    }


    fclose(f);


}
