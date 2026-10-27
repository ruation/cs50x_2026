#include "helpers.h"
#include "math.h"
#include "stdlib.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        BYTE average;
        for(int j = 0; j < width; j++){
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen)/ (float) 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        RGBTRIPLE tmp;
        for(int j = 0; j < width/2; j++){
            tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++){
        RGBTRIPLE average;

        for(int j = 0; j < width; j++){
            int a=-1,b=-1,x=1,y=1;

            if(i == 0)a++;
            else if(i == height-1){x--;}

            if(j == 0)b++;
            else if(j == width-1){y--;}


            int pixels = (abs(a) + x +1) * (abs(b) + y + 1), blue = 0, green = 0, red = 0;

            for(int hg = a; hg <= x; hg++){
                for(int wd = b; wd <= y; wd++){
                    blue += image[i + hg][j + wd].rgbtBlue;
                    green += image[i + hg][j + wd].rgbtGreen;
                    red += image[i + hg][j + wd].rgbtRed;
                }
            }

            average.rgbtBlue = round(blue/ (float) pixels);
            average.rgbtGreen = round(green/ (float) pixels);
            average.rgbtRed = round(red/ (float) pixels);



            copy[i][j] = average;
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = copy[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for(int i = 0; i < height; i++){


        for(int j = 0; j < width; j++){
            int Gx_b=0, Gx_g=0, Gx_r=0, Gy_b=0, Gy_g=0, Gy_r=0;

            if(j != 0){
                Gx_b += image[i][j-1].rgbtBlue * (-2); Gx_g += image[i][j-1].rgbtGreen * (-2); Gx_r += image[i][j-1].rgbtRed * (-2);
                if(i != 0){
                    Gx_b += image[i-1][j-1].rgbtBlue * (-1); Gx_g += image[i-1][j-1].rgbtGreen * (-1); Gx_r += image[i-1][j-1].rgbtRed * (-1);
                }
                if(i != height-1){
                    Gx_b += image[i+1][j-1].rgbtBlue * (-1); Gx_g += image[i+1][j-1].rgbtGreen * (-1); Gx_r += image[i+1][j-1].rgbtRed * (-1);
                }
            }
            if(j != width-1){
                Gx_b += image[i][j+1].rgbtBlue * (2); Gx_g += image[i][j+1].rgbtGreen * (2); Gx_r += image[i][j+1].rgbtRed * (2);
                if(i != 0){
                    Gx_b += image[i-1][j+1].rgbtBlue * (1); Gx_g += image[i-1][j+1].rgbtGreen * (1); Gx_r += image[i-1][j+1].rgbtRed * (1);
                }
                if(i != height-1){
                    Gx_b += image[i+1][j+1].rgbtBlue * (1); Gx_g += image[i+1][j+1].rgbtGreen * (1); Gx_r += image[i+1][j+1].rgbtRed * (1);
                }
            }

            if(i != 0){
                Gy_b += image[i-1][j].rgbtBlue * (-2); Gy_g += image[i-1][j].rgbtGreen * (-2); Gy_r += image[i-1][j].rgbtRed * (-2);
                if(j != 0){
                    Gy_b += image[i-1][j-1].rgbtBlue * (-1); Gy_g += image[i-1][j-1].rgbtGreen * (-1); Gy_r += image[i-1][j-1].rgbtRed * (-1);
                }
                if(j != width-1){
                    Gy_b += image[i-1][j+1].rgbtBlue * (-1); Gy_g += image[i-1][j+1].rgbtGreen * (-1); Gy_r += image[i-1][j+1].rgbtRed * (-1);
                }
            }
            if(i != height-1){
                Gy_b += image[i+1][j].rgbtBlue * (2); Gy_g += image[i+1][j].rgbtGreen * (2); Gy_r += image[i+1][j].rgbtRed * (2);
                if(j != 0){
                    Gy_b += image[i+1][j-1].rgbtBlue * (1); Gy_g += image[i+1][j-1].rgbtGreen * (1); Gy_r += image[i+1][j-1].rgbtRed * (1);
                }
                if(j != width - 1){
                    Gy_b += image[i+1][j+1].rgbtBlue * (1); Gy_g += image[i+1][j+1].rgbtGreen * (1); Gy_r += image[i+1][j+1].rgbtRed * (1);
                }
            }

            copy[i][j].rgbtBlue = round(sqrt( (Gy_b * Gy_b) + (Gx_b * Gx_b) )) > 255 ? 255 : round(sqrt( (Gy_b * Gy_b) + (Gx_b * Gx_b) ));
            copy[i][j].rgbtGreen = round(sqrt( (Gy_g * Gy_g) + (Gx_g * Gx_g) )) > 255 ? 255 : round(sqrt( (Gy_g * Gy_g) + (Gx_g * Gx_g) ));
            copy[i][j].rgbtRed = round(sqrt( (Gy_r * Gy_r) + (Gx_r * Gx_r) )) > 255 ? 255 : round(sqrt( (Gy_r * Gy_r) + (Gx_r * Gx_r) ));

        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = copy[i][j];
        }
    }

    return;
}
