#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    BYTE buffer[512];

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open the card\n");
        return 1;
    }

    FILE *img = NULL;
    int jpeg_count = 0;
    char filename[8];

    while (fread(buffer, sizeof(BYTE), 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            snprintf(filename, sizeof(filename), "%03i.jpg", jpeg_count);
            jpeg_count++;

            if (img != NULL)
            {
                fclose(img);
            }

            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(card);
                printf("Could not open the image\n");
                return 1;
            }
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
        else
        {
            if (img != NULL)
            {
                fwrite(buffer, sizeof(BYTE), 512, img);
            }

            // THIS SHOULD BE IGNORED bcuz if the data isnt from jpeg, why are we
            // writing into jpg files
            //  else
            //  {
            //      img = fopen(filename, "w");
            //      fwrite(buffer, sizeof(BYTE), 512, img);
            //  }
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
    return 0;
}
