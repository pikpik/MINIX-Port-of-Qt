#include <unistd.h>

int main (void) {

#ifdef read
# error 'Read is a macro.'
#endif

  return 0;

}
