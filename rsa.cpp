#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

int generatePrime(int num){
  int flag = 0;
  for(int i = 2; i <= num-1; i++){
    if(num%i == 0)
      break;
    if(i == num-1)
      return num;
  }
  return generatePrime(num+1);
}

int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

int generateSmall(int small, int large){
  small = generatePrime(small);
  while(large%small == 0){
    small = generatePrime(small+1);
  }
    return small;
}

int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

long long moduloMultiplication(long long a,
                               long long b,
                               long long mod)
{
    long long res = 0;  // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= mod;

    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;

        b >>= 1;  // b = b / 2
    }

    return res;
}

int main(){
  srand(time(0));
  string str;
  cin>>str;
  vector<int> to_encrypt;
  long long int number = 0;
  for (int i = 0; i < str.size(); i++){
    to_encrypt.push_back(str[i]-96);
    //cout<<to_encrypt[i];
  number = number*100 + to_encrypt[i];
  }
  cout<<"converted to number: "<<number<<endl;
  long long int test1 = rand()%98 + pow(10,str.size());
  long long int test2 = rand()%98 +pow(10,str.size());
  long long int test3 = rand()%6 + 2;
  long long int p1 = generatePrime(test1);
  long long int p2 = generatePrime(test2);
  cout<<"first number: "<<p1<<"\n"<<"second number: "<<p2<<endl;
  long long int a_for_public = p1*p2;
  int phi_for_private = lcm(p1-1,p2-1);
  int b_for_public = generateSmall(test3,phi_for_private);

  cout<<"a_for_public:"<<a_for_public<<"\t"<<"b_for_public:"<<b_for_public<<endl;

  int k = 2; //to generate private key
  int d_for_private = modInverse(b_for_public,phi_for_private);

  cout<<"phi_for_private:"<<phi_for_private<<"\t"<<"d_for_private:"<<d_for_private<<endl;

  long long int encrypted_data = 1;
  for(int i = 0; i < b_for_public; i++){
    encrypted_data = moduloMultiplication(encrypted_data,number,a_for_public);
    //cout<<encrypted_data<<endl;
    //encrypted_data = encrypted_data%a_for_public;
  }
  cout<<"encrypted_data: "<<encrypted_data<<endl;

  long long int decrypted_data = 1;
  long long int multiplier = encrypted_data;
  for(int i = 0; i < d_for_private; i++){
    decrypted_data = moduloMultiplication(decrypted_data,multiplier,a_for_public);
    //decrypted_data = decrypted_data%a_for_public;
    //cout<<decrypted_data<<endl;
  }
  //decrypted_data = decrypted_data*multiplier;
  cout<<"decrypted_data: "<<decrypted_data<<endl;

}
