#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <sys/mman.h>
#include <sys/fcntl.h>


#define SRC_FILE "ex1.txt"
#define DST_FILE "ex1.memcpy.txt"


int main(){
    int src_fd = open("ex4.txt", O_RDONLY, 0666);
    int dst_fd = open("ex4.memcpy.txt", O_RDWR | O_CREAT, 0666);

    struct stat stat_s = {};
    size_t src_len = (size_t) stat_s.st_size;
    ftruncate(dst_fd, src_len);

    void *src_ad = mmap(NULL, src_len, PROT_READ, MAP_PRIVATE, src_fd, 0);
    void *dst_ad = mmap(NULL, src_len, PROT_READ | PROT_WRITE, MAP_SHARED, dst_fd, 0);

    memcpy(dst_ad, src_ad, src_len);
    munmap(src_ad, src_len);
    munmap(dst_ad, src_len);

    close(dst_fd);
    close(src_fd);
}
