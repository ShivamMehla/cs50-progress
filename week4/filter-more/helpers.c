#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int greyscale = round((double)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);

            image[i][j].rgbtRed = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtBlue = greyscale;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int opposite = width - 1 - j;

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][opposite];
            image[i][opposite] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            int count = 0;

            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        red += copy[x][y].rgbtRed;
                        green += copy[x][y].rgbtGreen;
                        blue += copy[x][y].rgbtBlue;
                        count++;
                    }
                }
            }
            int averageRed = round((double) red / count);
            int averageGreen = round((double) green / count);
            int averageBlue = round((double) blue / count);

            image[i][j].rgbtRed = averageRed;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtBlue = averageBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Gxred = 0;
            int Gxgreen = 0;
            int Gxblue = 0;
            int Gyred = 0;
            int Gygreen = 0;
            int Gyblue = 0;

            int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        int kernelRow = x - (i - 1);
                        int kernelCol = y - (j - 1);

                        Gxred += copy[x][y].rgbtRed * Gx[kernelRow][kernelCol];
                        Gxgreen += copy[x][y].rgbtGreen * Gx[kernelRow][kernelCol];
                        Gxblue += copy[x][y].rgbtBlue * Gx[kernelRow][kernelCol];

                        Gyred += copy[x][y].rgbtRed * Gy[kernelRow][kernelCol];
                        Gygreen += copy[x][y].rgbtGreen * Gy[kernelRow][kernelCol];
                        Gyblue += copy[x][y].rgbtBlue * Gy[kernelRow][kernelCol];
                    }
                }
            }

            int edgeRed = round(sqrt(Gxred * Gxred + Gyred * Gyred));
            int edgeGreen = round(sqrt(Gxgreen * Gxgreen + Gygreen * Gygreen));
            int edgeBlue = round(sqrt(Gxblue * Gxblue + Gyblue * Gyblue));
            
            if (edgeRed > 255)
            {
                edgeRed = 255;
            }
            if (edgeGreen > 255)
            {
                edgeGreen = 255;
            }
            if (edgeBlue > 255)
            {
                edgeBlue = 255;
            }

            image[i][j].rgbtRed = edgeRed;
            image[i][j].rgbtGreen = edgeGreen;
            image[i][j].rgbtBlue = edgeBlue;
        }
    }
    return;
}
