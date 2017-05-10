#include <stdlib.h>
#include <stdio.h>

#include "test.h"
#include "../vector.h"

void test_make_vector(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    Vector *vec = make_vector();
    expecti(0, vec_len(vec));
    free(vec);
}

void test_make_vector_with(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp = 666;
    Vector *vec = make_vector_with(&temp);
    expecti(1, vec_len(vec));
    expecti(temp, *(int *)vec_get(vec, 0));
    free(vec);
}

void test_make_vector_copy(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp = 666;
    Vector *vec1 = make_vector_with(&temp);
    Vector *vec2 = make_vector_copy(vec1);
    expecti(1, vec_len(vec2));
    expecti(temp, *(int *)vec_get(vec2, 0));
    free(vec1);
    free(vec2);
}

void test_vec_push(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp1 = 666;
    int temp2 = 777;
    Vector *vec = make_vector();
    expecti(0, vec_len(vec));
    vec_push(vec,&temp1);
    expecti(1, vec_len(vec));
    expecti(temp1, *(int *)vec_get(vec, 0));
    vec_push(vec,&temp2);
    expecti(2, vec_len(vec));
    expecti(temp1, *(int *)vec_get(vec, 0));
    expecti(temp2, *(int *)vec_get(vec, 1));
    free(vec);
}

void test_vec_pop(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp1 = 666;
    int temp2 = 777;
    Vector *vec = make_vector();
    vec_push(vec, &temp1);
    vec_push(vec, &temp2);
    expecti(temp2, *(int *)vec_pop(vec));
    expecti(1, vec_len(vec));
    expecti(temp1, *(int *)vec_get(vec, 0));
    free(vec);
}

void test_vec_append(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp1 = 666;
    int temp2 = 777;
    Vector *vec1 = make_vector_with(&temp1);
    Vector *vec2 = make_vector_with(&temp2);
    vec_append(vec1, vec2);
    expecti(2, vec_len(vec1));
    expecti(temp1, *(int *)vec_get(vec1, 0));
    expecti(temp2, *(int *)vec_get(vec1, 1));

    expecti(1, vec_len(vec2));
    expecti(temp2, *(int *)vec_get(vec2, 0));

    free(vec1);
    free(vec2);
}

void test_vec_get(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp = 666;
    Vector *vec = make_vector_with(&temp);
    expecti(temp, *(int *)vec_get(vec, 0));

    expecti(1, vec_len(vec));
    expecti(temp, *(int *)vec_pop(vec));

    free(vec);
}

void test_vec_set(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp1 = 666;
    int temp2 = 777;
    Vector *vec = make_vector_with(&temp1);
    vec_set(vec, 0, &temp2);

    expecti(1, vec_len(vec));
    expecti(temp2, *(int *)vec_get(vec, 0));

    free(vec);
}

void test_vec_head(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp1 = 666;
    int temp2 = 777;
    int temp3= 888;
    Vector *vec = make_vector();
    vec_push(vec,&temp1);
    vec_push(vec,&temp2);
    vec_push(vec,&temp3);

    expecti(temp1, *(int *)vec_head(vec));

    expecti(3, vec_len(vec));
    expecti(temp1, *(int *)vec_get(vec, 0));
    expecti(temp2, *(int *)vec_get(vec, 1));
    expecti(temp3, *(int *)vec_get(vec, 2));
    free(vec);
}

void test_vec_tail(){
    printf("\n\nCurrent Function : %s\n\n", __FUNCTION__);
    int temp1 = 666;
    int temp2 = 777;
    int temp3= 888;
    Vector *vec = make_vector();
    vec_push(vec,&temp1);
    vec_push(vec,&temp2);
    vec_push(vec,&temp3);

    expecti(temp3, *(int *)vec_tail(vec));

    expecti(3, vec_len(vec));
    expecti(temp1, *(int *)vec_get(vec, 0));
    expecti(temp2, *(int *)vec_get(vec, 1));
    expecti(temp3, *(int *)vec_get(vec, 2));
    free(vec);
}

void test(){
    test_make_vector();
    test_make_vector_with();
    test_make_vector_copy();
    test_vec_push();
    test_vec_pop();
    test_vec_append();
    test_vec_get();
    test_vec_set();
    test_vec_head();
    test_vec_tail();
}
