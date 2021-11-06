#include<cs50.h>
#include<stdio.h>

int main(void)
{
    //declaring variables
    int height;
    int spaces;
    int hashes;
    //do while loop to prompt user for height, range 1:8
    do
    {
        height = get_int("%s", "Input positive integer: ");
    }
    while (height <= 0 || height >= 9);

    for (int i = 1; i <= height; i++) //iterate 1 to height
    {
        //loop around the spaces per row
        for (spaces = height - i; spaces > 0; spaces--)
        {
            printf(" ");
        }
        //loop around the spaces per row
        for (hashes = 2; hashes <= i + 1; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}