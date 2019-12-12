struct Buffer
{
    int disposed;
    int size;
    int* array;
    int* currentWrite;
    int* currentRead;
};

int cbuf_read(struct Buffer* b);
void cbuf_write(struct Buffer* b, int value);
int cbuf_avg(struct Buffer* b);
void cbuf_dispose(struct Buffer* b);
int cbuf_offset(struct Buffer* b, int offset);

struct Buffer cbuf_new(int size);
