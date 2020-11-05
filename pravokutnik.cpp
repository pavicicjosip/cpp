#include "pravokutnik.h"

int Pravokutnik::povrsina() { return x*y; }
int Pravokutnik::opseg() { return 2 * x + 2 * y; }
void Pravokutnik::postavi(int x, int y) { this->x = x; this->y = y; }



