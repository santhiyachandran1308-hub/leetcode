#include <stdlib.h>
#include <math.h>

// Structure for hash table entries
struct HashTable {
    int key;
    int value;
};

// Simple linear probing hash map search
int find(struct HashTable* map, int size, int key) {
    int hash = abs(key) % size;
    while (map[hash].value != -1) {
        if (map[hash].key == key) {
            return map[hash].value; // Return the index of the found complement
        }
        hash = (hash + 1) % size;
    }
    return -1; // Not found
}

// Simple linear probing hash map insert
void insert(struct HashTable* map, int size, int key, int value) {
    int hash = abs(key) % size;
    while (map[hash].value != -1) {
        hash = (hash + 1) % size;
    }
    map[hash].key = key;
    map[hash].value = value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
     int mapSize = numsSize * 2;
    struct HashTable* map = (struct HashTable*)malloc(mapSize * sizeof(struct HashTable));
    
      for (int i = 0; i < mapSize; i++) {
        map[i].value = -1;
    }
      for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = find(map, mapSize, complement);
         if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            free(map); // Free hash map memory before returning
            return result;
        }
        insert(map, mapSize, nums[i], i);
    } free(map);
    return NULL; 
}
