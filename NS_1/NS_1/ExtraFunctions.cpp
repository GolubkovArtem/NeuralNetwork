#include "stdafx.h"
#include "ExtraFunctions.h"
#include <iostream>
#include <vector>



float activation_function_1(float network_input) {
	return pow((1 + std::exp(-network_input)), -1) >= 0.5;
}

float derivative_function_1(float network_input) {
	return std::exp(network_input) * pow((1 + std::exp(-network_input)), -2);
}

std::vector<std::vector<float>> get_combinations(float collection_size, float selected_number) {
	std::vector<std::vector<float>> result;
	std::vector<float> extra_vector(collection_size - selected_number, 0);
	for (int iterator = 0; iterator < selected_number; ++iterator) {
		extra_vector.push_back(1);
	}
	int extra_iterator = collection_size - 1;
	while (extra_iterator != 0) {
		result.push_back(extra_vector);
		extra_iterator = collection_size - 1;
		while (extra_iterator != 0) {
			if (extra_vector[extra_iterator] == 1 && extra_vector[extra_iterator - 1] == 0) {
				extra_vector[extra_iterator] = 0;
				extra_vector[extra_iterator - 1] = 1;
				int unit_counter = 0;
				for (int iterator = extra_iterator + 1; iterator < collection_size; ++iterator)
				{
					if (extra_vector[iterator]) {
						++unit_counter;
					}
					extra_vector[iterator] = 0;
				}
				for (int iterator = collection_size - 1; iterator > collection_size - 1 - unit_counter; --iterator) {
					extra_vector[iterator] = 1;
				}
				break;
			}
			--extra_iterator;
		}
	}
	return result;
}

std::vector<float> GetSample(size_t dimension, size_t sample_number) {
	std::vector<float> result;
	result.reserve(dimension);
	for (size_t iterator = dimension - 1; iterator > 0; --iterator) {
		result.push_back(sample_number % 2);
		sample_number /= 2;
	}
	result.push_back(1);
	std::reverse(result.begin(), result.end());
	return result;
}

void find_minimal_number_of_samples(size_t dimension, Perceptron & perceptron,
	const std::vector<std::pair<std::vector<float>, float>> & learning_samples) {
	std::vector<std::pair<std::vector<float>, float>> learning_samples_2;
	for (size_t iterator = 1; iterator <= pow(2, dimension); ++iterator) {
		for (auto & numbers_of_samples_used : get_combinations(pow(2, dimension), iterator)) {
			perceptron.Clear();
			for (size_t iterator_2 = 0; iterator_2 < pow(2, dimension); ++iterator_2) {
				if (numbers_of_samples_used[iterator_2] == 1) {
					learning_samples_2.push_back(std::make_pair(GetSample(dimension + 1, iterator_2),
						learning_samples[iterator_2].second));
				}
			}
			perceptron.TrainPerceptron(learning_samples_2);
			if (perceptron.VerifyPerceptron(learning_samples) == true) {
				perceptron.Clear();
				perceptron.TrainPerceptron(learning_samples_2, true);
				for (auto & iterator : learning_samples_2) {
					for (auto & j : iterator.first) {
						std::cout << j << " ";
					}
					std::cout << "\n";
				}
				std::cout << "\n";
				iterator = pow(2, dimension) + 1;
				break;
			}
			else {
				learning_samples_2.clear();
			}
		}
	}
}