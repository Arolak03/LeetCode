#define mod 1000000007
typedef long long ll;

class Solution {
public:
    ll power(ll a , ll b)
    {
        ll res = 1;
        while(b)
        {
            if(b%2==1) // odd b&1==1
             res = (res%mod * a%mod)%mod;
            a = (a%mod * a%mod)%mod;
            b=b/2; // b = b>>1 
        }
        return res;
    }
   

   /*
   based on the fact that (a*b)>=(a+b-1)*1 ; and say if p = 3 , we have total of 
   8 values [ 0-7] out of which we are interested only in [1-7]; and we know that
   iun binary representation 2; 
   **** 0 and 7 complimentary ***
   1 and 6 complimentary
   2 and 5 complimentary
   3 and 4 complimentary

   so we can use this and. onvery all the above 3 except the first one into
   1*6 and then can multiply 7;
   6*6*6*7 will be our answer.
   */
    int minNonZeroProduct(int p) 
    {
        ll mx  = (1LL<<p) - 1; // 2^p - 1
        /* 

        can't use the above power funtion bcz 2^p can be greater than mod
        and then we will get the value wrong which need to be multiplied and 
        whose power need to be taken of.

        and we have used 1LL bcz p>32 normally if p is less than 32 , we can 
        simply use (1<<p) bcz by default represented in 32 bits

        */

        ll base = (mx-1+mod)%mod;
        ll exponent = mx/2;

        return (power(base,exponent)%mod * (mx%mod) )%mod;
        //return (power( (mx-1+mod)%mod,mx/2)%mod *(mx%mod))%mod;

    }
};