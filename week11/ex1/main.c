#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <sys/mman.h>
#include <sys/fcntl.h>


#define filename "ex1.txt"
#define opening_mode O_RDWR


const char s[] = "This is a nice day";


int main(){
    int fd = open(filename, opening_mode);

    ftruncate(fd, sizeof(s));

    struct stat stat_s = {};
    size_t len = stat_s.st_size;

    void *ad = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    int n = sizeof(s);
    memcpy(ad, s, n);
    munmap(ad, n);
    close(fd);
}
