#pragma once

typedef struct disk {
    int size;
} Disk;

/**
 * @brief Creates a disk.
 * 
 * @param size size of the disk, e.g. 1, 2, ...
 * @return a disk. 
 */
Disk diskCreate(int size);

/**
 * @brief Prints a representation of a disk.
 * 
 * @param disk disk to print.
 */
void diskPrint(Disk disk);