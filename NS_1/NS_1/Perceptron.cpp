#include "stdafx.h"
#include "Perceptron.h"
#include <iostream>


float activation_function(float network_input) {
	return network_input >= 0;
}

float derivative_function(float network_input) {
	return 1;
}

Perceptron::Perceptron(size_t output_number,
	float learning_rate,
	float(*activation_function)(float),
	float(*derivative_function)(float))
	: LearningRate(learning_rate)
	, DerivativeFunction(derivative_function)
	, ActivationFunction(activation_function) {
	for (size_t iterator = 0; iterator <= output_number; ++iterator) {
		Weights.push_back(0);
	}
}

void Perceptron::Clear() {
	for (size_t iterator = 0; iterator < Weights.size(); ++iterator) {
		Weights[iterator] = 0;
	}
}

std::pair<bool, std::vector<float>> 
Perceptron::TrainPerceptron(const std::vector<std::pair<std::vector<float>, float>> & learning_samples,
	bool show_results, size_t epochs_number) {
	size_t epoch = 0;
	std::pair<bool, std::vector<float>> result;
	result.first = false;
	while (epoch < epochs_number) {
		if (show_results) {
			std::cout << epoch << " (";
			for (auto & i : Weights) {
				std::cout << i << ", ";
			}
			std::cout << ") ";
		}

		std::vector<float> sample;
		std::vector<float> perceptron_results;
		float mistake;
		float summary_mistake = 0;
		for (size_t iterator = 0; iterator < learning_samples.size(); ++iterator) {
			sample = learning_samples[iterator].first;
			if (sample.size() < Weights.size()) {
				std::cout << "incorrect_samples\n";
				result.second = Weights;
				return result;
			}
			perceptron_results.push_back(ActivationFunction(_NetworkInput(sample)));
			mistake = learning_samples[iterator].second - ActivationFunction(_NetworkInput(sample));
			if (mistake != 0) {
				++summary_mistake;
				_WeightingRecalculation(mistake, sample);
			}
		}

		if (show_results) {
			std::cout << " (";
			for (auto & i : perceptron_results) {
				std::cout << i << ", ";
			}
			std::cout << ") ";
			std::cout << summary_mistake << "\n";
		}

		if (summary_mistake == 0) {
			result.first = true;
			break;
		}
		++epoch;
	}
	result.second = Weights;
	if (show_results) {
		std::cout << "\n";
	}
	return result;
}

bool Perceptron::VerifyPerceptron(const std::vector<std::pair<std::vector<float>, float>> & training_samples) const {
	for (size_t iterator = 0; iterator < training_samples.size(); ++iterator) {
		if (training_samples[iterator].first.size() < Weights.size()) {
			std::cout << "incorrect_samples\n";
			return false;
		}
		if (training_samples[iterator].second - ActivationFunction(_NetworkInput(training_samples[iterator].first)) != 0) {
			return false;
		}
	}
	return true;
}

void Perceptron::_WeightingRecalculation(float mistake, const std::vector<float> & sample) {
	float network_input = _NetworkInput(sample);
	for (size_t iterator = 0; iterator < Weights.size(); ++iterator) {
		Weights[iterator] += sample[iterator] * LearningRate * mistake * DerivativeFunction(network_input);
	}
}

float Perceptron::_NetworkInput(const std::vector<float> & sample) const {
	float result(0);
	for (size_t iterator = 0; iterator < Weights.size(); ++iterator) {
		result += sample[iterator] * Weights[iterator];
	}
	return result;
}
