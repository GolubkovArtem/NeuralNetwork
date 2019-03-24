#include "vector"
#pragma once

<<<<<<< HEAD
float activation_function(float network_input); // функция возвращает значение пороговой ФА от network_input
float derivative_function(float network_input); // функция возвращает значение производной пороговой ФА от network_input
=======
float activation_function(float network_input); // ôóíêöèÿ âîçâðàùàåò çíà÷åíèå ïîðîãîâîé ÔÀ îò network_input
float derivative_function(float network_input); // ôóíêöèÿ âîçâðàùàåò çíà÷åíèå ïðîèçâîäíîé ïîðîãîâîé ÔÀ îò network_input
>>>>>>> f5bdb45778b26042c7b72c5306aff9f1b24e142a

class Perceptron { 
private:
<<<<<<< HEAD
	std::vector<float> Weights; // веса нейрона
	float LearningRate;
	float(*ActivationFunction)(float); // указатель на функцию расчёта функции активации
	float(*DerivativeFunction)(float); // указатель на функцию расчёта производной функции активации
=======
	std::vector<float> Weights; // âåñà íåéðîíà
	float LearningRate;
	float(*ActivationFunction)(float); // óêàçàòåëü íà ôóíêöèþ ðàñ÷¸òà ôóíêöèè àêòèâàöèè
	float(*DerivativeFunction)(float); // óêàçàòåëü íà ôóíêöèþ ðàñ÷¸òà ïðîèçâîäíîé ôóíêöèè àêòèâàöèè
>>>>>>> f5bdb45778b26042c7b72c5306aff9f1b24e142a
public:
	~Perceptron() = default;
	Perceptron() = delete;
	Perceptron(size_t output_number,
		float learning_rate = 0.3,
		float(*activation_function)(float) = activation_function,
		float(*derivative_function)(float) = derivative_function);
<<<<<<< HEAD
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
=======
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
>>>>>>> f5bdb45778b26042c7b72c5306aff9f1b24e142a
