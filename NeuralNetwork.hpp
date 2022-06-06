#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <vector>

#pragma once

namespace DL {
typedef float Scalar;
typedef Eigen::MatrixXf Matrix;
typedef Eigen::RowVectorXf RowVector;
typedef Eigen::VectorXf colVector;
typedef std::vector<uint> TopologyVector;
typedef std::vector<RowVector*> VectorList;
typedef std::vector<Matrix*> MatrixList;
const uint UINT_ONE = 1;

class NeuralNetwork {
public:
    /* Methods */
    explicit NeuralNetwork(const TopologyVector& topology,
                           const Scalar learningRate);
    ~NeuralNetwork() = default;

    void train(std::vector<RowVector*> data);

private:
    /* Methods */
    void updateWeights();
    void calculateErrors(RowVector& ouput);
    void init();
    void initNeurons(const uint layerNum);
    void initWeights(const uint layerNum);
    void initCache();
    void initDeltas();
    void setZeroBias(const uint layerNum);

    /* Member variables */
    const TopologyVector mTopology;
    const Scalar mLearningRate;
    const uint mNumLayers;
    VectorList mNeuronLayers;
    VectorList mCacheLayers;
    VectorList mDeltas;
    MatrixList mWeights;
};
}  // namespace DL
