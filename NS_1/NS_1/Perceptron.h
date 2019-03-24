#include "vector"
#pragma once

float activation_function(float network_input); // функция возвращает значение пороговой ФА от network_input
float derivative_function(float network_input); // функция возвращает значение производной пороговой ФА от network_input

class Perceptron {
private:
	std::vector<float> Weights; // веса нейрона
	float LearningRate;
	float(*ActivationFunction)(float); // указатель на функцию расчёта функции активации
	float(*DerivativeFunction)(float); // указатель на функцию расчёта производной функции активации
public:
	~Perceptron() = default;
	Perceptron() = delete;
	Perceptron(size_t output_number,
		float learning_rate = 0.3,
		float(*activation_function)(float) = activation_function,
		float(*derivative_function)(float) = derivative_function);
	void Clear(); // метод очищает веса нейрона
	std::pair<bool, std::vector<float>>
		TrainPerceptron(const std::vector<std::pair<std::vector<float>, float>> & learning_samples,
			bool show_results = false, size_t epochs_number = 200); // метод обучет нейрон на обучающей выборке learning_samples
	// не более чем за epochs_number эпох и в случае show_results пошагово выводит результаты эпох обучения 
	// метод возвращает пару значений: результат обучения и веса нейрона
	bool VerifyPerceptron(const std::vector<std::pair<std::vector<float>, float>> & training_samples) const;
	// метод проверяет нейрон на тестовой выборке training_samples и возвращает результат проверки
private:
	void _WeightingRecalculation(float mistake, const std::vector<float> & sample); // метод проводит перерасчёт весов нейрона
	float _NetworkInput(const std::vector<float> & sample) const; // метод возвращает сетевой вход для набора sample
};