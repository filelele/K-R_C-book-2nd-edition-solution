#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    int so_dong = atoi(argv[1]);
    FILE* fp = fopen(argv[3], "w");
    int so_file = atoi(argv[2]);
    for(int i = 1; i <= so_dong; ++i){
        fprintf(fp, "day la dong %d file %d\n", i, so_file);
    }
}


//in nhieu dong "day la dong x file y" ra file y

//./writetxt bao_nhieu_dong ten_file