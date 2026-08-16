#ifndef VECTOR_H
# define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct s_vector {
	size_t capacity;
	size_t length;
	int sizing;
	void* data;
} Vector;

Vector vec_create(int sizing);
void vec_add(Vector* vec, void* item);
bool vec_issuccess(Vector* vec);
void vec_remove(Vector* vec, size_t idx, size_t delete_count);
void* get(Vector* vec, size_t idx);
void vec_destroy(Vector* vec);

#endif
