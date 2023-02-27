#include "disk.h"
#include <stdio.h>

Disk diskCreate(int size) {
    Disk d;
    d.size = size;
    return d;
}

void diskPrint(Disk disk) {
    printf("--(_%d_)--", disk.size);
}