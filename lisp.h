#ifndef lisp_h
#define lisp_h
		
#include "lisp_Map_Register.h"
#include "lisp_Map_Reply.h"
#include "lisp_Map_request.h"

struct lisp {
	

	u_int32_t lp_N; 				/*u_int1_tlp_N;	
					u_int1_t	lp_L;		
					u_int1_t	lp_E;	
	
					u_int1_t	lp_V;	
					u_int1_t	lp_I;	
					u_int3_t	lp_flags;	
					u_int24_t	lp_Nonce;*/	
	u_int32_t	lp_id;	
	
	struct in_addr	lp_sou_eeid;	/* client IP address */
	struct in_addr	lp_dest_eid;

} UNALIGNED;

/*
 * LISP port numbers, data and control.
 */
#define	LISP_DATA_PORT		4341
#define	LISP_CONTROL_PORT	4342




#endif
