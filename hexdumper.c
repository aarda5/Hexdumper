#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

void flush_row(size_t offset, uint8_t *row, size_t count){

    printf("%08zx: ", offset); 
    
    for(size_t l = 0; l < count; l++){
        printf("%02x", row[l]);
        if(l % 2 == 1) printf(" ");

    }
    if(count < 16){
        for (size_t padding = count; padding < 16; padding++){
        
            printf("  ");
            if(padding % 2 == 1) printf(" ");
        }
    }

    for(size_t m = 0; m < count; m++){
        if(isprint((unsigned char)row[m])){
            printf("%c", row[m]);
        }
        else printf(".");
    }
    printf("\n");

}


int main(int argc, char **argv){

    FILE *fp = argc > 1 ? fopen(argv[1], "rb") : stdin;

    if (fp == NULL){
        perror("fopen");
        return 1; 
    } 
    size_t buffer_size = 4096;
    uint8_t *buffer = malloc(buffer_size);

    if(buffer == NULL){
        fprintf(stderr, "malloc failed. please restart.\n");
        return 1;
    }

    size_t byte_count;
    size_t running_total = 0;
    uint8_t row[16];

    while((byte_count = fread(buffer, 1, buffer_size, fp)) > 0){

        for( size_t i = 0; i < byte_count; i++){
            row[running_total % 16] = buffer[i];
            running_total++;
            
            if(running_total % 16 == 0){
                flush_row(running_total - 16, row, 16);    
            }
                


            }
        }

    if(running_total % 16 != 0){
        flush_row(running_total - (running_total % 16), row, running_total % 16);
    }
    
    if(ferror(fp)){
        fprintf(stderr, "An error has been occured. Please restart.");
        free(buffer);
        fclose(fp);
        return 1;
    }
    
    free(buffer);
    
    if(fp != stdin){
    fclose(fp);
    }

    return 0;
    
    
}




