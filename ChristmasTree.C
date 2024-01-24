#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
   
void christmasTree();
char** initTree( size_t , size_t);
void printTree( char**, size_t, size_t);
void setTree( char** , size_t, size_t);


int main(){
    system("clear");
    christmasTree();
    return EXIT_SUCCESS;
}

void christmasTree(){
    size_t width = 55;
    size_t height = 25;
    char** screen = initTree( height, width);
    setTree( screen, height, width );
    printTree( screen, height, width);


    for ( int i = 0; i < height; i++ ){
        free( screen[i] );
    }
    free( screen );
}

char** initTree( size_t height, size_t width){
    char** matrix = ( char** ) malloc( height * sizeof (char*) );
    for ( int i = 0; i < height ; i++ ){
        matrix[i] =  ( char* ) malloc ( (width + 1) * sizeof ( char ));
    } 

    for ( int row = 0; row < height; row++ ){
        for ( int col = 0; col < width; col++ ){
            matrix[row][col] = col+1 != width ? ' ':'\0';

        }
    }
    return matrix;
}

void printTree( char** tree, size_t height, size_t width ){
    char* message = "Feliz Navidad :3";
    for ( int row = 0; row < height; row++ ){
        for ( int col = 0; col < width; col++ ){
            printf("\033[0;32m");
            printf("%c", tree[row][col]);
        }
        printf("\n");
    }

    printf("\033[0;34m");
    for (size_t i = 0; i < width-1; i++){
        printf("=");
    }
    printf("\n");
    int pad = ((width-1) - strlen(message))/2;
    printf("|");
    printf("\033[0;35m");
    printf("%*.*s%s", pad-1, pad-1, " ", message);
    printf("\033[0;34m");
    printf("%*.*s%s\n", pad-1, pad-1, "", "|");
    for (size_t i = 0; i < width-1; i++){
        printf("=");
    }
     printf("\n");
}

void setTree( char** tree, size_t height, size_t width ){
    int increment = 0;
    int mid = width/2;
    srand(time( NULL));
    char* chars = "~~****++ooooo=^^^^^-";
    char fill;
    for ( int row = 2; row < height-3; row++ ){
        for ( int i = -increment; i <= increment; i++ ){
            fill = row == 2 ? '*': row == (height-4) ? '=': chars[rand()%strlen(chars)];
            tree[row][mid + i] = fill;
        }
        increment++;
    }

    for ( int row = height-3; row < height ; row++ ){
        tree[row][mid-(increment/4)] = '|';
        tree[row][mid+(increment/4)] = '|';
    }
}
