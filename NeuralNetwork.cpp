#include "NeuralNetwork.hpp"

#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <vector>

#include "NeuralNetwork.hpp"

namespace DL {
NeuralNetwork::NeuralNetwork(const TopologyVector &topology,
                             const Scalar learningRate)
    : mTopology(topology),
      mLearningRate(learningRate),
      mNumLayers(topology.size())
{
    init();
}

void NeuralNetwork::init()
{
    for (uint i = 0; i < mNumLayers; ++i) {
        initNeurons(i);
        initWeights(i);
    }
}

void NeuralNetwork::initNeurons(const uint layerNum)
{
    // Add an extra bias term to all but the last layer
    const uint numNeuronsInLayer =
        (layerNum != mNumLayers ? mTopology[layerNum] + UINT_ONE
                                : mTopology[layerNum]);
    mNeuronLayers.push_back(new RowVector(mTopology[layerNum]));
}

void NeuralNetwork::initCache()
{
    mCacheLayers.
}

void NeuralNetwork::initWeights(const uint layerNum)
{
    const uint numNeuronsPrevious =
        (layerNum != mNumLayers ? mTopology[layerNum - UINT_ONE] + UINT_ONE
                                : mTopology[layerNum - UINT_ONE]);
    const uint numNeuronsCurrent = mTopology[layerNum] + UINT_ONE;
    mWeights.push_back(new Matrix(numNeuronsPrevious, numNeuronsCurrent));
    mWeights.back()->setRandom();

    if (layerNum != mNumLayers) {
        setZeroBias(layerNum);
    }
}

void NeuralNetwork::setZeroBias(const uint layerNum)
{
    mWeights.back()->col(mTopology[layerNum]).setZero();
    mWeights.back()->coeffRef(mTopology[layerNum - 1], mTopology[layerNum]) =
        1.0;
}



}  // namespace DL
