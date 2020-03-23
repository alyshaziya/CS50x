#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate i through height
    for (int i = 0; i < height; i++)
    {
        // iterate j through width
        for (int j = 0; j < width; j++)
        {
            // get average of rgb
            int grey = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);

            //convert pixel rgb to greyscale
            image[i][j].rgbtBlue = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtRed = grey;
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate sepia values
            float sepiaRed = (.393 * (image[i][j].rgbtRed)) + (.769 * (image[i][j].rgbtGreen)) + (.189 * (image[i][j].rgbtBlue));
            float sepiaGreen = (.349 * (image[i][j].rgbtRed)) + (.686 * (image[i][j].rgbtGreen)) + (.168 * (image[i][j].rgbtBlue));
            float sepiaBlue = (.272 * (image[i][j].rgbtRed)) + (.534 * (image[i][j].rgbtGreen)) + (.131 * (image[i][j].rgbtBlue));
            
            // round sepia values 
            int sepRed = round(sepiaRed);
            int sepGreen = round(sepiaGreen);
            int sepBlue = round(sepiaBlue);

            if (sepRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepRed;
            }

            if (sepGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepGreen;
            }

            if (sepBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepBlue;
            }

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        int halfWidth = round((float)1 / 2 * width);

        for (int j = 0; j < width; j++)
        {
            while (j < halfWidth)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = temp;
                break;
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //make temp array
    RGBTRIPLE store[height][width];

    // assign iter image to temp array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            store[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            red = 0;
            green = 0;
            blue = 0;
            counter = 0;

            //store rgb values of middle pixel
            if (i >= 0 && j >= 0)
            {
                red += store[i][j].rgbtRed;
                green += store[i][j].rgbtGreen;
                blue += store[i][j].rgbtBlue;
                counter ++;
            }

            //store rgb values of right pixel
            if (i >= 0  &&  j + 1 >= 0 && j + 1 < width)
            {

                red += store[i][j + 1].rgbtRed;
                green += store[i][j + 1].rgbtGreen;
                blue += store[i][j + 1].rgbtBlue;
                counter ++;

            }

            //store rgb values of left pixel
            if (i >= 0 && j - 1 >= 0)
            {
                red += store[i][j - 1].rgbtRed;
                green += store[i][j - 1].rgbtGreen;
                blue += store[i][j - 1].rgbtBlue;
                counter ++;
            }

            //store rgb values of top pixel
            if (i - 1 >= 0 && i - 1 < height && j >= 0)

            {
                red += store[i - 1][j].rgbtRed;
                green += store[i - 1][j].rgbtGreen;
                blue += store[i - 1][j].rgbtBlue;
                counter ++;

            }

            //store rgb values of bottom pixel
            if (i + 1 >= 0 && i + 1 < height && j >= 0)
            {
                red += store[i + 1][j].rgbtRed;
                green += store[i + 1][j].rgbtGreen;
                blue += store[i + 1][j].rgbtBlue;
                counter ++;

            }


            //store rgb value of top left pixel (diagonal)
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += store[i - 1][j - 1].rgbtRed;
                green += store[i - 1][j - 1].rgbtGreen;
                blue += store[i - 1][j - 1].rgbtBlue;
                counter ++;
            }

            //store rgb value of top right pixel (diagonal)
            if (i - 1 >= 0 && j + 1 >= 0 && j + 1 < width)
            {
                red += store[i - 1][j + 1].rgbtRed;
                green += store[i - 1][j + 1].rgbtGreen;
                blue += store[i - 1][j + 1].rgbtBlue;
                counter ++;

            }

            //store rgb value of bottom left pixel (diagonal)
            if (i + 1 >= 0 && i + 1 < height && j - 1 >= 0)
            {
                red += store[i + 1][j - 1].rgbtRed;
                green += store[i + 1][j - 1].rgbtGreen;
                blue += store[i + 1][j - 1].rgbtBlue;
                counter ++;
            }


            //store rgb value of bottom right pixel (diagonal)
            if (i + 1 >= 0 && i + 1 < height && j + 1 >= 0 && j + 1 < width)
            {
                red += store[i + 1][j + 1].rgbtRed;
                green += store[i + 1][j + 1].rgbtGreen;
                blue += store[i + 1][j + 1].rgbtBlue;
                counter ++;

            }
            //print modified pixels 
            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }

    }

    return;
}
