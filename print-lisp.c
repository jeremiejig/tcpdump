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
{	u_int32_t lisp_flag,lisp_N,lisp_L,lisp_E,lisp_V,lisp_I,lisp_Flag,lisp_Nonce,lisp_id;
	netdissect_options ndo;
	register const struct lisp *lisp;
	//LISP
	lisp = (struct lisp *)cp;
	lisp_flag= EXTRACT_32BITS(&lisp->lp_N);
	lisp_id= EXTRACT_32BITS(&lisp->lp_id);
	

		lisp_N=(lisp_flag&2147483648);/*2^31*/
		lisp_L=(lisp_flag&1073741824);/*2^30*/
		lisp_E=(lisp_flag&536870912);	/*2^29*/
		lisp_V=(lisp_flag&268435456);/*2^28*/
		lisp_I=(lisp_flag&134217728);/*2^27*/
		lisp_Flag=(lisp_flag&117440512);/*2^26+2^25+2^24*/
		lisp_Nonce=(lisp_flag&16777215);/*2^25+2^27+.....+2^0*/

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
		
		if(vflag){
		printf(" Flag %x ",lisp_Flag);
		printf(" Instance ID %x ",lisp_id);
		if(lisp_N) 
		printf( " NONCE %x ",lisp_Nonce);
		}
		

//IH
	ndo.ndo_snapend = cp+length;
	
	printf(" %d ",length);
	ip_print(&ndo,cp+8,length-8);
}
void
lispcontrol_print(register const u_char *cp, u_int length)
{	u_int32_t lisp_type,lisp_typedesc,	lisp_reserved,lisp_record_count,lisp_A,lisp_M,lisp_P,lisp_S,lisp_p,lisp_s,lisp_Reserved,lisp_Irc,lisp_Record;

	u_int16_t lisp_Source_Eid_AFI;
	u_int32_t lisp_Source_Eid_add;
	u_int64_t lisp_Nonce;
	netdissect_options ndo;
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
				lisp_type=EXTRACT_32BITS(&lisprequest->lp_Type);
				
				lisp_A=(lisp_type&8);
				lisp_M=(lisp_type&4);
				lisp_P=(lisp_type&2);
				lisp_S=(lisp_type&1);
				lisp_p=(lisp_type&32768);
				lisp_s=(lisp_type&16384);
				lisp_Reserved=(lisp_type&352);
				lisp_Irc=(lisp_type&31);
				lisp_Record=(lisp_type&55);

				lisp_Nonce=EXTRACT_64BITS(&lisprequest->lp_Nonce);
				lisp_Source_Eid_AFI=EXTRACT_16BITS(&lisprequest->lp_Source_EID_afi);
				lisp_Source_Eid_add=EXTRACT_32BITS(&lisprequest->lp_Source_EID_adr);
				if(vflag){
					printf(" Source_Eid %x ",lisp_Source_Eid_AFI);
					printf(" Source_Eid_add %s ",ipaddr_string(&lisprequest->lp_Source_EID_adr));
}
				

				break;

	/*map reply*/		case 536870912 :
				printf(" %s","Map_reply");
				lispreply= (struct lisp_Map_Reply *)cp;
				lisp_type= (lispreply->lp_Type);

				break;

	/*map register*/	case 805306368 :
				printf(" %s","Map_register");
				lisprequest= (struct lisp_Map_request *)cp;
				lisp_type= (lisprequest->lp_Type);
				break;
				case 1073741824 :
				printf(" %s","Map_Notify");
				break;
				case 0 :
				printf(" %s","Map_Reserved");
				break;
				case 2147483648 :
				ndo.ndo_snapend = cp+length;
				printf(" %s","Map_Encapsulated control message : ");
				ip_print(&ndo,cp+4,length-4);
				
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



