#include "lisp.h"
struct lisp_Map_Reply {
	u_int32_t lp_Type;

				/*u_int4_t	lp_type;	
				u_int1_t	lp_P;		
				u_int1_t	lp_E;	
				u_int1_t	lp_S;	
	
				u_int17_t	lp_Reserved;
	
				u_int8_t	lp_Rec_Count;*/
	

	struct lisp_rec lp_rec;
	


	
} UNALIGNED;

