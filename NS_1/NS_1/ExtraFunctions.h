#include "vector"
#include "Perceptron.h"
#pragma once

float activation_function_1(float network_input);
// ������� ���������� �������� ������������� �� �� network_input
float derivative_function_1(float network_input);
// ������� ���������� �������� ����������� ������������� �� �� network_input
std::vector<std::vector<float>> get_combinations(float collection_size, float selected_number);
// ������� ���������� ��� ��������� � ������������������ ������� �� collection_size �� selected_number 
// � ���� ����������� ����� �� collection_size ��������, ������� ������ ������ ����� 1
std::vector<float> GetSample(size_t dimension, size_t sample_number);
// ������� ���������� �������� ������ �� dimension + 1 ������ ����� 2 * sample_number + 1
void find_minimal_number_of_samples(size_t dimension, Perceptron & perceptron,
	const std::vector<std::pair<std::vector<float>, float>> & learning_samples);
// ������� ������� � ������� ����������� ���-�� ������� �� learning_samples, � ����� ��� ������
// ����������� ��� �������� perceptron � dimension �������� ������