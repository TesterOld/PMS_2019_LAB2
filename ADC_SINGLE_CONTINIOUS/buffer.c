#include "buffer.h"
#include "stdlib.h"

int *normalize(int *min, int *max, int *c)
{
    if (c >= max)
    {
        return min;
    }
    if (c < min)
    {
        return max;
    }
    return c;
}

int cbuf_read(struct Buffer *b)
{
    if (b->disposed)
    {
        return -1;
    }
    b->currentRead = normalize(b->array, b->array + b->size, b->currentRead + 1);
    return *b->currentRead;
}

void cbuf_write(struct Buffer *b, int value)
{
    if (b->disposed)
    {
        return;
    }
    *b->currentWrite = value;
    b->currentWrite = normalize(b->array,b->array + b->size, b->currentWrite + 1);
}

int cbuf_avg(struct Buffer *b)
{
    if (b->disposed)
    {
        return -1;
    }
    int result = 0;
    for (int i = 0; i < b->size; i++)
    {
        result += b->array[i];
    }

    return result / b->size;
}

void cbuf_dispose(struct Buffer *b)
{
    b->disposed = 1;
    free(b->array);
}

struct Buffer cbuf_new(int size)
{
    struct Buffer buf;
    buf.disposed = 0;
    buf.size = size;
    int *array = (int *)calloc(size, sizeof(int));
    buf.array = array;
    buf.currentRead = array;
    buf.currentWrite = array;
    return buf;
}