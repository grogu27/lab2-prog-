#include "IntVector.h"

IntVector* int_vector_new(size_t initial_capacity)
{
    IntVector* v = malloc(sizeof(IntVector));
    if (!v) {
        return NULL;
    }
    v->data = malloc(sizeof(int) * initial_capacity);
    if (!v->data) {
        free(v);
        return NULL;
    }
    v->capacity = initial_capacity;
    v->size = 0;
    return v;
}

IntVector* int_vector_copy(const IntVector* v)
{
    if (!v)
        return NULL;
    IntVector* v2 = int_vector_new(v->capacity);
    if (!v2)
        return NULL;
    for (int i = 0; i < v->size; i++)
    {
        v2->data[i] = v->data[i];
        v2->size++;
    }
    return v2;
}


void int_vector_free(IntVector *v)
{
    if (v)
    {
        free(v->data);
        free(v);
    }
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    if (!v)
        return 0;
    if (index < v->size)
        return v->data[index];
    return 0;
    
    
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
    if (index < v->size)
        v->data[index] = item;
}

size_t int_vector_get_size(const IntVector* v)
{
    if (!v)
        return 0;
    return v->size;
}

size_t int_vector_get_capacity(const IntVector* v)
{
    if (!v)
        return 0;
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
    if (!v)
        return -1;
    if (v->size == v->capacity)
    {
        int *new_data = realloc(v->data, v->capacity * sizeof(int) * 2);
        if (!new_data)
            return -1;
        v->data = new_data;
        v->capacity *= 2; 
    }
    v->data[v->size] = item;
    v->size++;
    return 0;
}

void int_vector_pop_back(IntVector *v)
{
    if (v->size > 0)
        v->size--;
}

int int_vector_shrink_to_fit(IntVector *v)
{
    if (!v)
        return -1;
    if (v->capacity == v->size)
        return 0;
    int *new_data = realloc(v->data, sizeof(int) * v->size);
    if (!new_data)
        return -1;
    v->data = new_data;
    v->capacity = v->size;
    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
    if (!v)
        return -1;
    if (new_size > v->capacity)
    {
        if (int_vector_reserve(v, new_size))
            return -1;
        for (int i = v->size; i < new_size; i++)
            v->data[i] = 0;
    }
    
    v->size = new_size;
    return 0;
}

int int_vector_reserve(IntVector* v, size_t new_capacity)
{
    if (!v)
        return -1;
    if (new_capacity <= v->capacity)
        return 0;
    int* new_data = realloc(v->data, new_capacity * sizeof(int));
    if (!new_data)
        return -1;
    v->data = new_data;
    v->capacity = new_capacity;
    return 0;
}

void print_vector(IntVector *v, char* text) {
    
    printf("%s: size: %ld, capacity: %ld\n", text, v->size, v->capacity);
    printf("{");
    for (int i = 0; i < v->size; i++) 
        printf("%d ", int_vector_get_item(v, i));
    printf("}");
    printf("\n\n");
}