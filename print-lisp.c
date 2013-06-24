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
lisp_print(register const u_char *cp, u_int length, int lisp_control)
{
	if(lisp_control){
		printf("LISP Control");
	}
	else{
		printf("LISP Data");
	}

}
