#include "macChanger.h"

int main(int argc, char *argv[]) {

  if (argc < 3) {
    fprintf(stderr, "USAGE: program -r <NIC>", argv[0]);
    return -1;
  }

  char *interface = argv[2];

  return 0;
}
