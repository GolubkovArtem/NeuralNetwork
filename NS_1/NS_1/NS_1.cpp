#include "stdafx.h"
#include "Perceptron.h"
#include "ExtraFunctions.h"
#include <iostream>


int main() {
	size_t dimension = 4;
	std::vector<float> answers = 
	{ 1, 1, 0, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 1, 1, 1, 1};
	std::vector<std::pair<std::vector<float>, float>> learning_samples;
	for (size_t iterator = 0; iterator < pow(2, dimension); ++iterator) {
		learning_samples.push_back(std::make_pair(GetSample(dimension + 1, iterator), answers[iterator]));
	}

	Perceptron perceptron_1(dimension);
	perceptron_1.TrainPerceptron(learning_samples, true);

	Perceptron perceptron_2(dimension, 0.3, activation_function_1, derivative_function_1);
	perceptron_2.TrainPerceptron(learning_samples, true);

	find_minimal_number_of_samples(dimension, perceptron_1, learning_samples);
	find_minimal_number_of_samples(dimension, perceptron_2, learning_samples);
	return 0;
}