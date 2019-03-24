#include "vector"
#include "Perceptron.h"
#pragma once

float activation_function_1(float network_input);
// функция возвращает значение логистической ФА от network_input
float derivative_function_1(float network_input);
// функция возвращает значение производной логистической ФА от network_input
std::vector<std::vector<float>> get_combinations(float collection_size, float selected_number);
// функция возвращает все сочетания в лексикографическом порядке из collection_size по selected_number 
// в виде двузначного числа из collection_size разрядов, старший разряд всегда равен 1
std::vector<float> GetSample(size_t dimension, size_t sample_number);
// функция возвращает двоичную запись из dimension + 1 знаков числа 2 * sample_number + 1
void find_minimal_number_of_samples(size_t dimension, Perceptron & perceptron,
	const std::vector<std::pair<std::vector<float>, float>> & learning_samples);
// функция выводит в консоль минимальное кол-во наборов из learning_samples, а также эти наборы
// необходимые для обучения perceptron с dimension двоичных входов