#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main()
{
    FILE *fp;
    int i;
    int temp;


    //std::cout << "D:\\LuVPortableApp\\CodeBlocksPortable\\Projects\\File_Read_2\\bin\\Debug_x64\\ZKRU_FILE.TXT \n";
    //fp = fopen("D:\\LuVPortableApp\\CodeBlocksPortable\\Projects\\File_Read_2\\bin\\Debug_x64\\ZKRU_FILE.TXT", "R");
    //fp = fopen("C:\\Users\\KRU\\Desktop\\ZKRU_FILE.TXT", "R");
    fp = fopen("C:\\Users\\KRU\\Desktop\\ZKRU.TXT", "A");


    if(fp == NULL)
    {
        printf("Datei konnte NICHT geöffnet werden.\n");
    }
    else {
        for (i=0; i<10; i++) {
            fscanf(fp, "%d\n", &temp);
            printf("gelesen: %d\n", temp);
        }
        fclose(fp);
    }
    return 0;
}
