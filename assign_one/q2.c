#include<stdio.h>

int main() {
    int numbers[15];
    int max;
    
    printf("Enter 15 numbers: ");
    for(int i = 0; i < 15; i++)
        scanf("%d", &numbers[i]);
    
    max = numbers[0];
    for(int i = 1; i < 15; i++) {
        if (numbers[i] > max)
            max = numbers[i];
    }

    printf("Largest number is %d", max);
}