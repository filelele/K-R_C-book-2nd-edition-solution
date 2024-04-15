/*Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)*/

#define swap(t,x,y) t temp = x; \ 
x = y;\ 
y = temp;

#define print2floats(x,y) printf(#x " is %g " #y " is %g", x, y);

int main(){
    float test1 = 10e-5;
    float test2 = 20e-6;
    swap(float,test1,test2);
    print2floats(test1,test2);
}