#include <errno.h>
#include <ifaddrs.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/sockio.h>
#include <time.h>

#define unsigned char u_char

#if 0
  *struct sockaddr_dl {
    u_char  sdl_len;        /* total length */
    u_char  sdl_family;     /* AF_LINK */
    u_short sdl_index;      /* interface index */
    u_char  sdl_type;       /* interface type */
    u_char  sdl_nlen;       /* interface name length */
    u_char  sdl_alen;       /* link-layer address length */
    u_char  sdl_slen;       /* link-layer selector length */
    char    sdl_data[120];  /* link-layer address & name */
};
#endif
