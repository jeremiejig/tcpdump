

struct lisp-Map-request {
	

	u_int8_t lp_Type	/*u_int4_t	lp_type;	
				u_int1_t	lp_A;		
				u_int1_t	lp_M;	
	
				u_int1_t	lp_P;	
				u_int1_t	lp_s;	*/

	u_int16_t lp_Reserved		/*u_int1_t	lp_p;	
				u_int1_t	lp_s;	
				u_int9_t	lp_Reserved;	
				u_int5_t	lp_IRC;	*/

	u_int8_t	lp_Record_Count;
	u_int32_t	lp_Nonce;	/* Nonce/Map-Version */
	u_int32_t	lp_Nonce;
		
	u_int16_t	lp_Source_EID_afi;
	
	u_int16_t	lp_Source_EID_adr;
	u_int16_t	Itr_Rloc_afi;
	u_int16_t	Itr_Rloc_adr;
	struct lisp_rec lp_rec;

	u_int32_t	lp_Map_Reply_Recor;





} UNALIGNED;
struct lisp_rec {
u_int8_t	lp_Reserved;
u_int8_t	lp_EID_mask_leng;
u_int16_t	lp_EID_Pref_Afi;
u_int32_t	lp_EID_Pref;

}UNALIGNED;

/*
 * LISP port numbers, data and control.
 */
#define	LISP_DATA_PORT		4341
#define	LISP_CONTROL_PORT	4342



/
