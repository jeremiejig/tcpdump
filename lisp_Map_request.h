#include "lisp.h"

struct lisp_Map_request {
	

	u_int8_t lp_Type;	/*u_int4_t	lp_type;	
				u_int1_t	lp_A;		
				u_int1_t	lp_M;	
	
				u_int1_t	lp_P;	
				u_int1_t	lp_s;	*/

	u_int16_t lp_Reserved;		/*u_int1_t	lp_p;	
				u_int1_t	lp_s;	
				u_int9_t	lp_Reserved;	
				u_int5_t	lp_IRC;	*/

	u_int8_t	lp_Record_Count;
	u_int64_t	lp_Nonce;	/* Nonce/Map-Version */
		
	u_int16_t	lp_Source_EID_afi;
	
	u_int16_t	lp_Source_EID_adr;
	u_int16_t	Itr_Rloc_afi;
	u_int16_t	Itr_Rloc_adr;
	struct lisp_rec lp_rec;

	u_int32_t	lp_Map_Reply_Recor;





} UNALIGNED;
