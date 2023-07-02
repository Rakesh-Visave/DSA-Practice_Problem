// 771. Jewels and Stones

#include<iostream>
using namespace std;


// 1st approach  T.C = n square


    // int numJewelsInStones(string jewels, string stones) {
    //     int count = 0;
    //     for(int i = 0; i < stones.size(); i++){
    //         for(int j = 0; j < jewels.size(); j++){
    //             if(stones[i] == jewels[j])
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
        
    // }






//   2nd optimize approach  T.C = o(n) 
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        for(char c : stones)
        {
            if(jewels.find(c) != -1)
                count++;
        }
        return count;
    }

int main()
{

    string jewels = "aA";
    string stones = "aAAbbbb";

    int count = numJewelsInStones(jewels,stones);

    cout<< "the total stones which is in also jewels we have : "<<count;
}






