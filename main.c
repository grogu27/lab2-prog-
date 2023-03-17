#include "IntVector.h"

int main()
{
    IntVector* vector = int_vector_new(5);
    char text[] = "(vector) int_vector_new(5)";
    print_vector(vector, text);

    int_vector_push_back(vector, 15);
    char text3[] = "(vector) int_vector_push_back(15)";
    print_vector(vector, text3);

    IntVector* vector2 = int_vector_copy(vector);
    char text2[] = "(vector2) int_vector_copy";
    print_vector(vector2, text2);

    for (int i = 0; i < 5; i++) 
        int_vector_push_back(vector2, i);
    char text4[] = "(vector2) int_vector_push_back(0 do 4)";
    print_vector(vector2, text4);

    int_vector_pop_back(vector2);
    char text5[] = "(vector2) int_vector_pop_back";
    print_vector(vector2, text5);

    int item = int_vector_get_item(vector2, 2);
    printf("(vector2) int_vector_get_item(2)\nitem number 2: %d\n\n", item);

    int_vector_set_item(vector2, 3, 3);
    char text6[] = "(vector2) int_vector_set_item(3, 3)\nsets element number 3 to 3";
    print_vector(vector2, text6);
    
    int size = int_vector_get_size(vector2);
    printf("(vector2) int_vector_get_size: %d\n\n", size);
    
    int capacity = int_vector_get_capacity(vector2);
    printf("(vector2) int_vector_get_capacity: %d\n\n", capacity);
    
    
    int_vector_shrink_to_fit(vector2);
    char text7[] = "(vector2) int_vector_shrink_to_fit";
    print_vector(vector2, text7);

    int_vector_resize(vector2, 20);
    char text8[] = "(vector2) int_vector_resize(20)";
    print_vector(vector2, text8);

    int_vector_reserve(vector, 20);
    char text9[] = "(vector) int_vector_reserve(20)";
    print_vector(vector, text9);
    
    int_vector_free(vector);
    int_vector_free(vector2);
    printf("free(vector)\n\nfree(vector2)\n");
    return 0;
}