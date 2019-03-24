#include "vector"
#pragma once

float activation_function(float network_input); // ôóíêöèÿ âîçâðàùàåò çíà÷åíèå ïîðîãîâîé ÔÀ îò network_input
float derivative_function(float network_input); // ôóíêöèÿ âîçâðàùàåò çíà÷åíèå ïðîèçâîäíîé ïîðîãîâîé ÔÀ îò network_input

class Perceptron { 
private:
	std::vector<float> Weights; // âåñà íåéðîíà
	float LearningRate;
	float(*ActivationFunction)(float); // óêàçàòåëü íà ôóíêöèþ ðàñ÷¸òà ôóíêöèè àêòèâàöèè
	float(*DerivativeFunction)(float); // óêàçàòåëü íà ôóíêöèþ ðàñ÷¸òà ïðîèçâîäíîé ôóíêöèè àêòèâàöèè
public:
	~Perceptron() = default;
	Perceptron() = delete;
	Perceptron(size_t output_number,
		float learning_rate = 0.3,
		float(*activation_function)(float) = activation_function,
		float(*derivative_function)(float) = derivative_function);
	void Clear(); // ìåòîä î÷èùàåò âåñà íåéðîíà
	std::pair<bool, std::vector<float>>
		TrainPerceptron(const std::vector<std::pair<std::vector<float>, float>> & learning_samples,
			bool show_results = false, size_t epochs_number = 200); // ìåòîä îáó÷åò íåéðîí íà îáó÷àþùåé âûáîðêå learning_samples
	// íå áîëåå ÷åì çà epochs_number ýïîõ è â ñëó÷àå show_results ïîøàãîâî âûâîäèò ðåçóëüòàòû ýïîõ îáó÷åíèÿ 
	// ìåòîä âîçâðàùàåò ïàðó çíà÷åíèé: ðåçóëüòàò îáó÷åíèÿ è âåñà íåéðîíà
	bool VerifyPerceptron(const std::vector<std::pair<std::vector<float>, float>> & training_samples) const;
	// ìåòîä ïðîâåðÿåò íåéðîí íà òåñòîâîé âûáîðêå training_samples è âîçâðàùàåò ðåçóëüòàò ïðîâåðêè
private:
	void _WeightingRecalculation(float mistake, const std::vector<float> & sample); // ìåòîä ïðîâîäèò ïåðåðàñ÷¸ò âåñîâ íåéðîíà
	float _NetworkInput(const std::vector<float> & sample) const; // ìåòîä âîçâðàùàåò ñåòåâîé âõîä äëÿ íàáîðà sample
};
