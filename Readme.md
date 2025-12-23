# MAC changer for Mac 

# Usage would be like

1. macchanger -V : Verbose
2. macchanger -r <NIC>

The members of struct ifaddr are as follows:

         ifa_addr	    (struct  sockaddr  *) The local address of the in-
    		    terface.

         ifa_dstaddr    (struct sockaddr *)	The remote address  of	point-
    		    to-point  interfaces, and the broadcast address of
    		    broadcast interfaces.  (ifa_broadaddr is  a	 macro
    		    for	ifa_dstaddr.)

         ifa_netmask    (struct sockaddr *)	The network mask for multi-ac-
    		    cess  interfaces,  and the confusion generator for
    		    point-to-point interfaces.

         ifa_ifp	    (if_t) A link back to the interface	structure.

         ifa_link	    (TAILQ_ENTRY(ifaddr)) queue(3) glue	 for  list  of
    		    addresses on each interface.

         ifa_rtrequest  See	below.

         ifa_flags	    (u_short)  Some  of	 the flags which would be used
    		    for	a route	representing this address in the route
    		    table.

         ifa_refcnt	    (short) The	reference count.

ioctl(fd, SIOCSIFLLADDR, ...)
↓
networking subsystem
↓
ifioctl()
↓
driver->if_ioctl()
↓
if_setlladdr()
↓
modify struct ifnet.lladdr

struct ifaddrs {
struct ifaddrs _ifa_next; /_ Next item in list */
char *ifa*name; /* Name of interface _/
unsigned int ifa_flags; /_ Flags from SIOCGIFFLAGS _/
struct sockaddr \_ifa_addr; /_ Address of interface */
struct sockaddr *ifa*netmask; /* Netmask of interface _/
union {
struct sockaddr \_ifu_broadaddr;
/_ Broadcast address of interface */
struct sockaddr *ifu*dstaddr;
/* Point-to-point destination address _/
} ifa_ifu;
#define ifa_broadaddr ifa_ifu.ifu_broadaddr
#define ifa_dstaddr ifa_ifu.ifu_dstaddr
void \_ifa_data; /_ Address-specific data \*/
};




# Under Development (NOT Working)
