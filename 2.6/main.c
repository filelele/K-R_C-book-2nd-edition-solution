/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged*/
int a;
int setbits(int x, int p, int n, int y){
    x = (y >> (p-n)) & ~(~0 << n);
    return x;
}//a bit clunky :>

int main(){
    int y = 12;
    a = setbits(a,4,2,y);
    printf("%d", a);
}