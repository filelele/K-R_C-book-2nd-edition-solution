/*In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.*/

int bitcount(signed int x){
    int count = 0;
    for(;x != 0; x &= (x-1)){
        ++count;
    }
    return count;
}

int main(){
    printf("%d", bitcount(22));
}