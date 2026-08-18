#include "genc.h"

GENC_VECTOR_GENERATE(int_vec, int, 2.0)
GENC_VECTOR_GENERATE(intptr_vec, int*, 2.0)
GENC_LIST_GENERATE(int_list, int)
GENC_FWD_LIST_GENERATE(int_fwd_list, int)

#include <assert.h>
#include <stdio.h>

int main()
{
    struct intptr_vec v = {0};

    int status;
     
    status = intptr_vec_prealloc(&v, 5);
    assert(!status);

    int vals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 10 };
    int* ptrs[10];

    size_t i;
    for(i = 0; i < 10; i++)
    {
        ptrs[i] = &vals[i];
        status = intptr_vec_pushb(&v, ptrs[i]);
        assert(!status);
    }

    for(i = 0; i < intptr_vec_size(&v); i++)
    {
        printf("%p ", intptr_vec_data(&v)[i]);
    }
    printf("\n");

    struct int_list list = {0};

    assert(!status);

    status = int_list_pushb(&list, 10);
    assert(!status);
    status = int_list_pushb(&list, 1);
    assert(!status);
    status = int_list_pushf(&list, 5);
    assert(!status);

    struct int_list_node* it_node = int_list_head(&list);
    while(it_node)
    {
        printf("%d ", *int_list_node_data(it_node));

        it_node = int_list_node_next(it_node);
    }

    printf("\n");

    status = int_list_deinit(&list);
    assert(!status);

    return 0;
}
