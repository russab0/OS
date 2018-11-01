#include <stdio.h>
#include <unistd.h>

int main(){
    char *s = "Hello";
    char i = 0;

    while (s[i] != '\0'){
        printf("%c", s[i]);
        sleep(1);
        i += 1;
    }

    fflush(stdout);
}
