#include <stdio.h>
#defint SIZE 100

int GCD(int x, int y){
    int result = 1;
    
    for(int i = 1; i<= x; i++){
        if(!(x%i) && !(y%i))
            result = i;
    }
    return result;
}

int LCM(int x, int y){
    return x*y/GCD(x,y);
}

int main(){
    int num; //입력하는 수를 저장 변수
    int arr[SIZE] ;
    arr[0] = 0;
    int gcd,lcm;
    int count = 0;
    
    while(1){
           scanf(“%d”,&num);
           if(num == -1) break;
           arr[count++] = num ;
       }
    
        
    gcd = lcm = arr[0];
    
    for(int i =1; i<SIZE; i++){
        gcd = GCD(gcd, arr[i])
        lcm = LCM(lcm,arr[i]);
    }
    
    printf("%d", lcm);

    return 0;
}
