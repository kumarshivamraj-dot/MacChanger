#include "macChanger.h"

void generateMac(u_char (*Macaddr)[6]) {
  (*Macaddr)[0] = 0x02; // Locally administered, unicast MAC

  for (int i = 1; i < 6; i++)
    (*Macaddr)[i] = rand() & 0xFF; // each byte is 0–255
}

int main(int argc, char **argv) {

  srand(time(NULL));

  u_char mac[6];
  // struct ifaddr ifaddr;
  if (argc < 3) {
    fprintf(stderr, "Usage: macchanger -r <NIC>");
    return -1;
  }

  struct sockaddr_dl HardwareAdder;
  char *interface = argv[2];
  size_t sizeName = strlen(interface);
  printf("%zu\n", sizeName);
  // The struct ifreq accepts a chat[]
  char interface_name[sizeName + 1];
  memcpy(&interface_name, interface, sizeName + 1);
  printf("The interface name is %s\n", interface_name);

  // Filling the mac address with new mac address
  generateMac(&mac);
  struct ifreq ifreq;

  memset(&ifreq, 0, sizeof(ifreq));
  strncpy(ifreq.ifr_name, interface, IFNAMSIZ);

  struct sockaddr_dl *sdl =
      (struct sockaddr_dl *)&ifreq.ifr_addr; // sockaddr_dl struct
  sdl->sdl_len = sizeof(struct sockaddr_dl); // uchar !!!!!
  sdl->sdl_family = AF_LINK;
  sdl->sdl_index = if_nametoindex(interface);
  sdl->sdl_type = IFT_ETHER;
  sdl->sdl_nlen = strlen(interface);
  sdl->sdl_alen = 6;
  sdl->sdl_slen = 0;

  memcpy(sdl->sdl_data, interface, sdl->sdl_nlen);
  memcpy(LLADDR(sdl), mac, 6);

  int fd = socket(AF_INET, SOCK_DGRAM, 0);

  // Calling a kernal sys call with struct ifreq
  int res = ioctl(fd, SIOCSIFLLADDR, &ifreq);
  if (res < 0) {
    perror("ioctl");
  }

  return 0;
}
