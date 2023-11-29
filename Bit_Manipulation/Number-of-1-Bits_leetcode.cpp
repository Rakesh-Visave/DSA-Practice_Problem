// LEETCODE -- 191.Number of 1 Bits
#include<iostream>
using namespace std;



    int hammingWeight(uint32_t n) {
         int count = 0;
        
        for(int i = 31; i>=0; i--) {
            if(((n >> i) & 1) == 1) {
                count++;
            }
        }
        
        return count;
    }


int main() {
    
    uint32_t input = 0b00000000000000000000000000001011; // For example, input is 11 in binary

    int result = hammingWeight(input);

    std::cout << "Number of 1 bits in the input: " << result << std::endl;

    return 0;
}
