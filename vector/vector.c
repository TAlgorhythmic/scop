#include "vector.h"
#include <stdlib.h>
#include <string.h>

static inline size_t max(size_t n1, size_t n2) {
	return n1 > n2 ? n1 : n2;
}

static inline size_t min(size_t n1, size_t n2) {
	return n1 < n2 ? n1 : n2;
}

static void ensure_capacity(Vector* vec, size_t elements) {
	if (vec->length + elements > vec->capacity) {
		size_t new_capacity = max(vec->capacity * 2, vec->capacity + elements);
		vec->data = realloc(vec->data, new_capacity * vec->sizing);
	}
}

Vector vec_create(int sizing) {
	return (Vector){
		.sizing = sizing,
		.capacity = 8,
		.data = malloc(sizing * 8),
		.length = 0,
	};
}

void vec_add(Vector* vec, void* item) {
	ensure_capacity(vec, 1);
	memcpy(item, vec->data + vec->length, vec->sizing);
	++(vec->length);
}

bool vec_issuccess(Vector* vec) {
	return vec->data != NULL;
}

void vec_remove(Vector* vec, size_t idx, size_t delete_count) {
	if (idx >= vec->length || delete_count == 0) return;
	unsigned char* data = vec->data;

	size_t end = min(idx + delete_count, vec->length);
	size_t amount = vec->length - end;
	memmove(data + (idx * vec->sizing), data + (end * vec->sizing), amount * vec->sizing);

	vec->length -= (end - idx);
}

void* get(Vector* vec, size_t idx) {
	return ((unsigned char*)vec->data) + (idx * vec->sizing);
}

void vec_destroy(Vector* vec) {
	free(vec->data);
	vec->sizing = 0;
	vec->length = 0;
	vec->capacity = 0;
}
