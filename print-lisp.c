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
#include "lisp.h"

void
lispdata_print(register const u_char *cp, u_int length)
{	u_int32_t lisp_flag,lisp_N,lisp_L,lisp_E,lisp_V,lisp_I;
	netdissect_options ndo;
	register const struct lisp *lisp;
	//LISP
	lisp = (struct lisp *)cp;
	lisp_flag= EXTRACT_32BITS(&lisp->lp_N);
	

		lisp_N=(lisp_flag&2147483648);
		lisp_L=(lisp_flag&1073741824);
		lisp_E=(lisp_flag&536870912);	
		lisp_V=(lisp_flag&268435456);
		lisp_I=(lisp_flag&134217728);
	
		if(lisp_N!=0)
		printf(" %c",'N');
		if(lisp_L!=0)
		printf(" %c",'L');
		if(lisp_E!=0)
		printf(" %c",'E');
		if(lisp_V!=0)
		printf(" %c",'V');
		if(lisp_I!=0)
		printf(" %c",'I');

//IH
	ndo.ndo_snapend = cp+length;
	
	printf(" %d\n",length);
	ip_print(&ndo,cp+8,length-8);
}
void
lispcontrol_print(register const u_char *cp, u_int length)
{	u_int32_t lisp_type,lisp_typedesc;
	register const struct lisp_Map_Register *lispregister;
	register const struct lisp_Map_Reply *lispreply;
	register const struct lisp_Map_request *lisprequest;
	
	//LISP
	lispregister = (struct lisp_Map_Register *)cp;
	lisp_type= EXTRACT_32BITS(&lispregister->lp_Type);
	lisp_typedesc=(lisp_type&4026531840);
	switch (lisp_typedesc) {

	/* map request*/	case 268435456:
				printf(" %s","Map_request");
				lisprequest= (struct lisp_Map_request *)cp;

				break;

	/*map reply*/		case 536870912 :
				printf(" %s","Map_reply");
				lispreply= (struct lisp_Map_Reply *)cp;

				break;

	/*map register*/	case 805306368 :
				printf(" %s","Map_register");
				break;
				case 1073741824 :
				printf(" %s","Map_Notify");
				break;
				case 0 :
				printf(" %s","Map_Reserved");
				break;
				case 2147483648 :
				printf(" %s","Map_Encapsulated control message");

				break;

	default: ;

	

}
	
	
	
}

void
lisp_print(register const u_char *cp, u_int length, int lisp_control)
{
	if(lisp_control){
		printf("LISP Control");
		lispcontrol_print(cp,length);
	}
	else{
		printf("LISP Data");
		lispdata_print(cp,length);
	}

}



