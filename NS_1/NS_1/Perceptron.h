#include "vector"
#pragma once

float activation_function(float network_input); // ������� ���������� �������� ��������� �� �� network_input
float derivative_function(float network_input); // ������� ���������� �������� ����������� ��������� �� �� network_input

class Perceptron {
private:
	std::vector<float> Weights; // ���� �������
	float LearningRate;
	float(*ActivationFunction)(float); // ��������� �� ������� ������� ������� ���������
	float(*DerivativeFunction)(float); // ��������� �� ������� ������� ����������� ������� ���������
public:
	~Perceptron() = default;
	Perceptron() = delete;
	Perceptron(size_t output_number,
		float learning_rate = 0.3,
		float(*activation_function)(float) = activation_function,
		float(*derivative_function)(float) = derivative_function);
	void Clear(); // ����� ������� ���� �������
	std::pair<bool, std::vector<float>>
		TrainPerceptron(const std::vector<std::pair<std::vector<float>, float>> & learning_samples,
			bool show_results = false, size_t epochs_number = 200); // ����� ������ ������ �� ��������� ������� learning_samples
	// �� ����� ��� �� epochs_number ���� � � ������ show_results �������� ������� ���������� ���� �������� 
	// ����� ���������� ���� ��������: ��������� �������� � ���� �������
	bool VerifyPerceptron(const std::vector<std::pair<std::vector<float>, float>> & training_samples) const;
	// ����� ��������� ������ �� �������� ������� training_samples � ���������� ��������� ��������
private:
	void _WeightingRecalculation(float mistake, const std::vector<float> & sample); // ����� �������� ���������� ����� �������
	float _NetworkInput(const std::vector<float> & sample) const; // ����� ���������� ������� ���� ��� ������ sample
};