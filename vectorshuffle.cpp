#include "vectorshuffle.h"
#include <QVector>
#include <vector>
#include <algorithm>
#include <random>

VectorShuffle::VectorShuffle()
{
}

void VectorShuffle::get_random_QNumVec(QVector<int>& qvec)
{
    std::vector<int> vector(400);
    for(int i = 0; i < 400; ++i)
        vector[i] = i;
    auto engine = std::default_random_engine{};
    std::shuffle(std::begin(vector), std::end(vector), engine);
    for(int i = 0; i < 60; ++i)
        qvec[i] = vector[i];
}
