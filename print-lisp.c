//#include "interface.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <tcpdump-stdinc.h>

#include <stdio.h>
#include <string.h>

#include "interface.h"
#include "addrtoname.h"
#include "extract.h"
#include "ether.h"

void
lispdata_print(register const u_char *cp, u_int length)
{
	netdissect_options ndo;
	register const struct lisp *lisp;
	ndo.ndo_snapend = cp+length;

	lisp = (struct lisp *)cp;
	printf(" %d\n",length);
	ip_print(&ndo,cp+8,length-8);
}

void
lisp_print(register const u_char *cp, u_int length, int lisp_control)
{
	if(lisp_control){
		printf("LISP Control");
	}
	else{
		printf("LISP Data");
		lispdata_print(cp,length);
	}

}
