#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //scans the array from pixel at height i
    for(int i = 0; i < height; i++)
    {
        //scans the array from pixel at width j
       for(int j = 0; j < width; j++)
       {
           int red = image[i][j].rgbtRed;
           int green = image[i][j].rgbtGreen;
           int blue = image[i][j].rgbtBlue;
       
       //average of three colors (colors are floats)
       float temp = round((float)red + (float)green + (float)blue);
       int avg = round((int)temp/3);
       
       //set colors to new average
       image[i][j].rgbtRed = avg;
       image[i][j].rgbtBlue = avg;
       image[i][j].rgbtGreen = avg;
       }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //scans the array from pixel at height i
    for(int i = 0; i < height; i++)
    {
        //scans the array from pixel at width j
       for(int j = 0; j < width; j++)
       {
           int red = image[i][j].rgbtRed;
           int green = image[i][j].rgbtGreen;
           int blue = image[i][j].rgbtBlue;
       
       //average of three colors (colors are floats)
        int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
        int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
        int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
       
       //set colors to new average
       if(sepiaRed > 255)
       {
           image[i][j].rgbtRed = 255;
       }
       else
       {
            image[i][j].rgbtRed = sepiaRed;
       }
       
       if(sepiaBlue > 255)
       {
            image[i][j].rgbtBlue = 255; 
       }
       else
       {
            image[i][j].rgbtBlue = sepiaBlue;
       }
       
       if(sepiaGreen > 255)
       {
           image[i][j].rgbtGreen = 255; 
       }
       else
       {
            image[i][j].rgbtGreen = sepiaGreen;
       }
       
       }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //scans the array from pixel at height i
    for(int i = 0; i < height; i++)
    {
        //scans the array from pixel at width j
       for(int j = 0; j < (width/2); j++)
       {
            RGBTRIPLE temp = image[i][j];
          
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
       }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //array for temporary image to be blurred
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue;
            int green;
            int red;
            float counter;            
            blue = 0;
            green = 0;
            red = 0;
            counter = 0;

            //***********CORNERS***********
            //corner pixel on bottom right
            if (i >= 0 && j >= 0)
            {
                red += temp[i][j].rgbtRed;
                green += temp[i][j].rgbtGreen;
                blue += temp[i][j].rgbtBlue;
                counter++;
            }
            
            //corner pixel on bottom left
            if (i >= 0 && j - 1 >= 0)
            {
                red += temp[i][j-1].rgbtRed;
                green += temp[i][j-1].rgbtGreen;
                blue += temp[i][j-1].rgbtBlue;
                counter++;
            }
            
            //corner pixel on top left
            if (i - 1 >= 0 && j >= 0)
            {
                red += temp[i-1][j].rgbtRed;
                green += temp[i-1][j].rgbtGreen;
                blue += temp[i-1][j].rgbtBlue;
                counter++;
            }
            
            //corner pixel on top right
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += temp[i-1][j-1].rgbtRed;
                green += temp[i-1][j-1].rgbtGreen;
                blue += temp[i-1][j-1].rgbtBlue;
                counter++;
            }
            
            //***********FOUR EDGES***********            
            //pixels on bottom edge
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += temp[i][j+1].rgbtRed;
                green += temp[i][j+1].rgbtGreen;
                blue += temp[i][j+1].rgbtBlue;
                counter++;
            }            
            
            //pixels on top edge
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += temp[i-1][j+1].rgbtRed;
                green += temp[i-1][j+1].rgbtGreen;
                blue += temp[i-1][j+1].rgbtBlue;
                counter++;
            }
            
            //pixels on left edge
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += temp[i+1][j].rgbtRed;
                green += temp[i+1][j].rgbtGreen;
                blue += temp[i+1][j].rgbtBlue;
                counter++;
            }
            
            //pixels on right edge
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += temp[i+1][j-1].rgbtRed;
                green += temp[i+1][j-1].rgbtGreen;
                blue += temp[i+1][j-1].rgbtBlue;
                counter++;
            }
            
            //***********MIDDLE PIXELS***********
            //Middle pixels
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += temp[i+1][j+1].rgbtRed;
                green += temp[i+1][j+1].rgbtGreen;
                blue += temp[i+1][j+1].rgbtBlue;
                counter++;
            }  
            
            //find average colour value
            image[i][j].rgbtRed = round(red / counter);
            image[i][j].rgbtGreen = round(green / counter);
            image[i][j].rgbtBlue = round(blue / counter);
        }
    }
}
