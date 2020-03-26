#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    //check if single command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    //open card.raw file and check if NULL

    FILE *file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL)
    {
        printf("Invalid file \n");
        return 1;
    }

    //declare variables & pointers
    int jpeg = 0;
    char *filename = malloc(8);
    FILE *img;



    //make a byte an unsigned int worth 8bytes
    typedef uint8_t BYTE;

    //make a buffer with 512 bytes
    BYTE buffer[512];

    //read 512 bytes until EOF
    while (fread(buffer, sizeof(BYTE), 512, file_ptr) == 512)
    {
        //if we find the header pattern of bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //close img from previous loop
            if (jpeg > 0)

            {
                fclose(img);
            }
            // add counter to jpeg file, create newfile

            sprintf(filename, "%03i.jpg", jpeg++);
            img = fopen(filename, "w");
        }

        //write bytes into new file
        if (jpeg > 0)
        {
            fwrite(&buffer, sizeof(BYTE), 512, img);
        }

    }
    free(filename);
}





