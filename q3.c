#include<stdio.h>

int main() {
    int numbers[20];
    int count = 0;

    printf("Enter 20 numbers: "); 
    for(int i = 0; i < 20; i++)
        scanf("%d", &numbers[i]);
    
    for(int i = 0; i < 20; i++) {
        if (numbers[i] % 2 == 0)
            count = count + 1; 
    }

    printf("Numbers of even numbers is %d", count);
}