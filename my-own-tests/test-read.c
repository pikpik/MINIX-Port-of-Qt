#include <sys/types.h>
#include <unistd.h>

int main (void) {

  char buf[20];
  size_t nbytes;
  ssize_t bytes_read;
  int fd;

  fd = fopen("test.c", "r");

  nbytes = sizeof(buf);
  bytes_read = read(fd, buf, nbytes);

  fclose(fd);

  return 0;

}
