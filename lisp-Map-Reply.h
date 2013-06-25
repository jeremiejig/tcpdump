
		


#include "lisp.h"

struct lisp-Map-Reply {
	u_int32_t Type;

				/*u_int4_t	lp_type;	
				u_int1_t	lp_P;		
				u_int1_t	lp_E;	
				u_int1_t	lp_S;	
	
				u_int17_t	lp_Reserved;
	
				u_int8_t	lp_Rec_Count;*/
	

	struct lisp_rec lp_rec;
	


	
} UNALIGNED;
struct lisp_rec {
u_int32_t	lp_Rec_TTL;
u_int8_t	lp_Loca_count;
u_int8_t	lp_EID_mask_len;
u_int16_t	lp_Act;				/*u_int3_t	lp_ACT;
						u_int1_t	lp_A;
						u_int12_t	lp_Reserved;*/
		

u_int16_t 	lp_Rsvd;			/*u_int4_t	lp_Rsvd;
						u_int12_t	lp_Map_version_number;*/
u_int16_t	lp_EID_Pref_AFI;
u_int32_t	lp_EID_Pref;

struct lisp_loc lp_loc;

}UNALIGNED;


struct lisp_loc {
u_int8_t	lp_Prio;
u_int8_t	lp_Weight;
u_int8_t	lp_M_Prio;
u_int8_t	lp_M_Weight;

u_int16_t	lp_Unused_Flag;				/*u_int13_t	lp_Unused_Flag;
							u_int1_t	lp_L;
							u_int1_t	lp_p;
							u_int1_t	lp_R;*/
u_int16_t	lp_Loc_AFI;
u_int32_t	lp_Locator;

}UNALIGNED;



/*
 * LISP port numbers, data and control.
 */
#define	LISP_DATA_PORT		4341
#define	LISP_CONTROL_PORT	4342









