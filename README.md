# Gen-C

__Gen-C__ is a user-friendly, type-safe generic container library for C. It provides macro-generated vectors, doubly linked lists, and forward lists.

## Dependencies

This library is stand-alone.

## Makefile instructions:

This library is meant to be used as header-only.

You can install the header by using the Makefile: `make install [PREFIX=...]` - This will place the public headers inside `PREFIX/include`. Default value is `PREFIX=/usr/local`

## Usage instructions:

Simply include the header in your project. Then use generator macros for the type you need, for example:

```
GENC_VECTOR_INLINE(int_vec, int, 2.0)

int main()
{
    struct int_vec v = {0};
    assert(!int_vec_pushb(&v, 10));
    printf("%d\n", v.data[0]);
    int_vec_deinit(&v);
}
```

You can find a more detailed example in demo.c.
