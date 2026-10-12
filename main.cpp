#include <iostream>
#include <array>
#include <random>

// int getVal() {
//     return idx
// }

int main() {
    // define a flat array of 24 elements
    // 24 ints are reserved in memory but they contain random junk data until we fill it
    std::array<int, 24> randomArray;

    // set up the random number generator engine and distribution range
    // 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);

    // fill the array using a loop
    for (int i = 0; i < randomArray.size(); i++) {
        // execute the distribution object using the gen math engine as its power source
        randomArray[i] = distr(gen);
    }

    // print out the elements in our array
    for (int i = 0; i < randomArray.size(); i++) {
        std::cout << randomArray[i] << " ";
    }

    // compute the index we need to retrieve in the flat array of data
    // int idx = getVal()

    // std::cout << "Data at index " << idx << "is";
    return 0;
}
