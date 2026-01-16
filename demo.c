#include "genc.h"

GENC_VECTOR_GENERATE(test_int_vec, int, 2.0, NULL);
GENC_VECTOR_GENERATE(test_intptr_vec, int*, 2.0, NULL);
GENC_LIST_GENERATE(test_int_list, int, NULL);
GENC_SIMPLE_LIST_GENERATE(test_int_slist, int);

struct emilija
{
    int x, y, z;
};
GENC_VECTOR_GENERATE(my_vec, struct emilija, 2.0, NULL);

#include <assert.h>
#include <stdio.h>

int main()
{
    struct my_vec mv;
    my_vec_init(&mv, 10, NULL);

    struct emilija a = {
        .x = 1,
        .y = 2,
        .z = 3
    };

    my_vec_pushb(&mv, a, NULL);

    printf("%d\n", mv.data[0].x);

   // struct test_intptr_vec v;
   // int _status;
   // test_intptr_vec_init(&v, 5, &_status);
   // assert(_status == 0);

   // int vals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 10 };
   // int* ptrs[10];

   // size_t i;
   // for(i = 0; i < 10; i++)
   // {
   //     ptrs[i] = &vals[i];
   //     test_intptr_vec_pushb(&v, ptrs[i], &_status);
   //     assert(_status == 0);
   // }

   // for(i = 0; i < v.size; i++)
   // {
   //     printf("%d ", v.data[i]);
   // }
   // printf("\n");

   //  struct test_int_list list;
   //  int _status;

   //  test_int_list_init(&list, &_status);
   //  assert(_status == 0);

   //  test_int_list_pushb(&list, 10, &_status);
   //  assert(_status == 0);
   //  test_int_list_pushb(&list, 1, &_status);
   //  assert(_status == 0);
   //  test_int_list_pushf(&list, 5, &_status);
   //  assert(_status == 0);

   //  size_t i;
   //  for(i = 0; i < list.size; i++)
   //  {
   //      printf("%d ", *(test_int_list_at(&list, i, NULL))->data);
   //  }
   //  printf("\n");

   //  test_int_list_deinit(&list, &_status);
   //  assert(_status == 0);

    return 0;
}
