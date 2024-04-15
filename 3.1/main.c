/*Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.*/

int binsearch(int x, int a[], int n){
    
    int low = 0;
    int high = n-1;
    int mid;
    while((low <= high) && (x != a[mid])){
        mid = (low+high)/2;
        if(x < a[mid]) high = mid -1;
        else low = mid + 1;
    }

    return (x == a[mid])? mid : -1;
}

int main(){
    int a[] = {0,1,2,3,4,5,6};
    int result = binsearch(6,a,7);
    printf("%d", result);
}