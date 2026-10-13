#include <iostream>
#include <array>
#include <random>
#include <vector>
#include <iomanip>


std::vector<int> createTensor(int tensor_size) {
    std::vector<int> vec;

    // set up the random number generator engine and distribution range
    // there are 2 parts to C++ RNG: the engine (math formula that produces raw bit stream) ad distribution (shapes bits into number range)
    // create hardware-based random device object rd (this requests a a unique seed value from the hardware like CPU noise or thermal variation so every time we run the program we get a diff sequence of numbers)
    std::random_device rd;
    // Mersenne Twister engine which is a math formula that outputs high quality pseudorandom numbers
    // we create an instance of this engine gen and initialize it with the hardware device on the line before
    std::mt19937 gen(rd());
    // creates a distribution mapper distr; the engine/gen outputs raw 32 bit blocks of data and here we compress/stretch/map those raw bits unifromly across the number range that we provide
    std::uniform_int_distribution<> distr(1, 100);
    // fill the vector using a loop
    for (int i = 0; i < tensor_size; i++) {
        // execute the distribution object using the gen math engine as its power source
        vec.push_back(distr(gen));
    }
    return vec;
}

// here we need to calculate the strides
int getVal(int i, int j, int k, int x, int y, int z) {

    int idx = (i * y * z) + (j * z) + k;
    return idx;
}

int main() {

    std::cout << "Let's work with 3D tensors!\n";
    std::cout << "Enter the dimensions for your desired tensor from outermost dim to innermost: ";

    int x{}, y{}, z{};
    std::cin >> x >> y >> z;
    int tensor_size = x * y * z;

    auto arr = createTensor(tensor_size);

    std::cout << "Your matrix has " << tensor_size << " elements total!\n";
    std::cout << "This is what it looks like: \n";
    for (int i = 0; i < x; i++) {
        std::cout << "[\n";
        for (int j = 0; j < y; j++) {
            std::cout << "   [";
            for (int k = 0; k < z; k++) {
                std::cout << std::setw(4) << arr[getVal(i, j, k, x, y, z)];
            }
            std::cout << "]" << "\n";
        }
        std::cout << "]" << "\n";
    }

    // enter the coords of the elem we want
    int i{}, j{}, k{};
    while (std::cout << "Enter the coordinates for the element you would like to retrieve from the tensor: "
            && std::cin >> i >> j >> k) {
        if (i >= x || j >= y || k >= z || i < 0 || j < 0 || k < 0) {
            std::cout << "Please enter valid tensor coordinates!\n";
        } else {
            // compute the index we need to retrieve in the flat array of data
            int idx = getVal(i, j, k, x, y, z);
            std::cout << "Data at index " << idx << " is " << arr[idx] << "\n";
        }
    }

    return 0;
}
