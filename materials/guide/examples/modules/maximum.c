#include "maximum.h"

int Maximum(int left, int right) {
    if (left > right) {
        return left;
    }
    return right;
}
