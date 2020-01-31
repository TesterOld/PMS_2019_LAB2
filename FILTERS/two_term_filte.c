#include "filter.h"
#define TERM_2 2
#define TERM_3 3
#define TERM_4 4
#define TERM_5 5
#define TERM_6 6
#define TERM_7 7


int two_term_filter(struct Buffer* cbuf)
{
	int val = 0;
	for(int i = 0; i >  TERM_2*(-1); i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / TERM_2;
}