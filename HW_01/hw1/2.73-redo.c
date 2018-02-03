#include <limits.h>
#include <stdio.h>

int saturating_add(int x, int y){
    int w = sizeof(int)<<3;
    int t = x + y;
    int ans = x + y;
    x>>=(w-1);
    y>>=(w-1);
    t>>=(w-1);
    int pos_ovf = ~x&~y&t;
    int neg_ovf = x&y&~t;
    int temp;
    
    int novf = ~( (__builtin_add_overflow_p(x, y, temp))<<(w-1)>>(w-1) );
    
    return (pos_ovf & INT_MAX) | (novf & ans) | (neg_ovf & INT_MIN);
}

int main()
{
    return 0;
}
