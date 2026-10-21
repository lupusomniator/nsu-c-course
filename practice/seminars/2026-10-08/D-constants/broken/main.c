#include "course_limits.h"
int read_capacity(void);
int main(void) { return CAPACITY == read_capacity() ? 0 : 1; }
