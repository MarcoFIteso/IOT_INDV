#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define LEN 80

void stream_char_test(){
	FILE * fout, * fin;
	char line[LEN+1];
	int c;
	fout = fopen("test_file_char.txt","wa");
	printf("File descriptor of test_file.txt is %d\n", fileno(fout));
	fin = fdopen(0,"r");
	if ( fout == (FILE *)NULL)
		exit(-1);
	do{
		c = fgetc(fin);
		fputc(c, fout);
	}while(c != EOF);
	fclose(fout);
}

void stream_string_test(){
        FILE * fout, * fin;
        char line[LEN+1];
        int c;
        fout = fopen("test_file_char.txt","wa");
        printf("File descriptor of test_file.txt is %d\n", fileno(fout));
        fin = fdopen(0,"r");
        if ( fout == (FILE *)NULL)
                exit(-1);
	// read line by line
   	 while (fgets(line, sizeof(line), fin) != NULL) {
        	// write the line into the file
        	fputs(line, fout);
    	}
        fclose(fout);
}

int main(int argc, char * argv[]){
	stream_string_test();
}
