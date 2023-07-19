#include <netinet/in.h> // ntohl 함수를 사용하기 위한 헤더 파일
#include <stdio.h>     // printf 함수를 사용하기 위한 헤더 파일
#include <stdlib.h>

void usage(){
    printf("syntax: add-nbo <file1> <file2>\n");
    printf("sample: add-nbo a.bin c.bin\n");
}

int main(int argc, char *argv[]) {
    if(argc != 3){
        usage();
        exit(0);
    }

    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "rb");
    if (!fp1 || !fp2) {
        perror("File Open Error!");
        exit(1);
    }

    uint32_t su1 = 0, su2 = 0, sum = 0;
    fread(&su1, sizeof(uint32_t), 1, fp1);
    fread(&su2, sizeof(uint32_t), 1, fp2);
    su1 = ntohl(su1);
    su2 = ntohl(su2);
    sum = su1 + su2;

    printf("%u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n", su1, su1, su2, su2, sum, sum);

    fclose(fp1);
    fclose(fp2);
}
