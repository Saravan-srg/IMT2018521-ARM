#include<stdio.h>

int main() {
    int numbers[20];
    int temp;
    printf("Enter 20 numbers: ");
    for(int i = 0; i < 20; i++)
        scanf("%d", &numbers[i]);
    
    for(int i = 0; i < 20; i++) {
        for(int j = i+1; j < 20; j++) {
            if(numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }        
    }

    for(int i = 0; i < 20; i++)
        printf("%d ", numbers[i]);
    
}