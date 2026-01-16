#include "genc.h"

GENC_VECTOR_GENERATE(test_int_vec, int, 2.0, NULL);
GENC_VECTOR_GENERATE(test_intptr_vec, int*, 2.0, NULL);
GENC_LIST_GENERATE(test_int_list, int, NULL);

#include <assert.h>
#include <stdio.h>

int main()
{
//    struct test_intptr_vec v;
//    int _status;
//    test_intptr_vec_init(&v, 5, &_status);
//    assert(_status == 0);
//
//    int vals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 10 };
//    int* ptrs[10];
//
//    size_t i;
//    for(i = 0; i < 10; i++)
//    {
//        ptrs[i] = &vals[i];
//        test_intptr_vec_pushb(&v, ptrs[i], &_status);
//        assert(_status == 0);
//    }
//
//    for(i = 0; i < v.size; i++)
//    {
//        printf("%d ", v.data[i]);
//    }
//    printf("\n");
//
//    struct test_intptr_vec_view view = (struct test_intptr_vec_view) {
//        .data = (const int**)v.data,
//        .size = v.size
//    };
//
//    for(i = 0; i < view.size; i++)
//    {
//        printf("%d ", view.data[i]);
//    }

    struct test_int_list list;
    int _status;

    test_int_list_init(&list, &_status);
    assert(_status == 0);

    test_int_list_pushb(&list, 10, &_status);
    assert(_status == 0);
    test_int_list_pushb(&list, 1, &_status);
    assert(_status == 0);
    test_int_list_pushf(&list, 5, &_status);
    assert(_status == 0);

    size_t i;
    for(i = 0; i < list.size; i++)
    {
        printf("%d ", *(test_int_list_at(&list, i))->data);
    }
    printf("\n");

    test_int_list_deinit(&list, &_status);
    assert(_status == 0);

    return 0;
}
