#include "genc.h"

GENC_VECTOR_INLINE(int_vec, int, 2.0)
GENC_VECTOR_INLINE(intptr_vec, int*, 2.0)
GENC_LIST_INLINE(int_list, int)
GENC_FWD_LIST_INLINE(int_fwd_list, int)

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

    for(i = 0; i < v.size; i++)
    {
        printf("%p ", v.data[i]);
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

    struct int_list_node* it_node = list.head;
    while(it_node)
    {
        printf("%d ", it_node->data);

        it_node = it_node->next;
    }

    printf("\n");

    status = int_list_deinit(&list);
    assert(!status);

    return 0;
}
