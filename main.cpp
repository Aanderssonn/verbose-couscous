#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <string>
#include <vector>

#include "NeuralNetwork.hpp"
using namespace DL;

int main()
{
    const TopologyVector topology({2, 2, 2});
    const Scalar learningRate = 0.05;
    NeuralNetwork nn(topology, learningRate);
    return 0;
}
