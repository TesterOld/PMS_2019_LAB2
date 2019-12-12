#include "filter.h"

int n_term_filter(struct Buffer* cbuf, int n)
{
	int val = 0;
	for(int i = 0; i > n * -1; i--){
		val += cbuf_offset(cbuf,i);
	}
	return val / n;
}

int n_term_recursive_filter(struct Buffer* cbuf, int n, int y)
{
	return (int)(0.7 * n_term_filter(cbuf, n) +  0.3 * y);
}