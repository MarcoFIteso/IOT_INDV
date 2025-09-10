#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define LEN 80
#define ELEMENTS 3

typedef struct{
	int id;
	float data;
	char name[LEN];
}sAnalogData_t;

sAnalogData_t aData[ELEMENTS] = { {0, 3.1416, "Temperature\0"},
				{1, 1.18, "Humidity\0"},
				{2, 23.5, "Pressure\0"},
};


void fwrite_test(){
        FILE * fout = fopen("AnalogData.bin", "w");
	fwrite((void *)aData, sizeof(sAnalogData_t), ELEMENTS, fout);
	fclose(fout);
}

void fread_test() {
    FILE *fin = fopen("AnalogData.bin", "rb");
    if (!fin) {
        perror("Error al abrir archivo para lectura");
        exit(EXIT_FAILURE);
    }

    sAnalogData_t buffer[ELEMENTS];
    size_t readCount = fread(buffer, sizeof(sAnalogData_t), ELEMENTS, fin);
    fclose(fin);

    // Despliegue solo de los elementos realmente leídos
    for (size_t i = 0; i < readCount; i++) {
        printf("id=%d, data=%.4f, name=%s\n",
               buffer[i].id, buffer[i].data, buffer[i].name);
    }
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
        fread_test();
}

