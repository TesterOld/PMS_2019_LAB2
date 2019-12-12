#include "filters.h"
#define TERM_2 2
#define TERM_3 3
#define TERM_4 4
#define TERM_5 5
#define TERM_6 6
#define TERM_7 7


int A_term_filter(struct Buffer* cbuf)
{
	int val = 0;
	for(int i = 0; i >  TERM_2*(-1); i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / TERM_2;
}

int B_term_filter(struct Buffer* cbuf)
{
	int val = 0;
	for(int i = 0; i >  TERM_3*(-1); i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / TERM_3;
}

int C_term_filter(struct Buffer* cbuf)
{
	int val = 0;
	for(int i = 0; i >  TERM_4*(-1); i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / TERM_4;
}

int D_term_filter(struct Buffer* cbuf)
{
	int val = 0;
	for(int i = 0; i >  TERM_5*(-1); i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / TERM_5;
}

int E_term_filter(struct Buffer* cbuf)
{
	int val = 0;
	for(int i = 0; i >  TERM_6*(-1); i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / TERM_6;
}

int F_term_filter(struct Buffer* cbuf)
{
	int val = 0;
	for(int i = 0; i >  TERM_7*(-1); i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / TERM_7;
}