#pragma once
#include <random>
#include <chrono>
class RandomManager
{
	DECLARE_SINGLE(RandomManager);

public:
	void Init()
	{
		//srand(time(NULL));
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		_engine.seed(seed);
	}

	int GetInt(int min, int max)
	{
		std::uniform_int_distribution<int> dist(min, max);
		return dist(_engine);
	}

	double GetDouble(double min, double max)
	{
		std::uniform_real_distribution<double> dist(min, max);
		return dist(_engine);
	}

	float GetFloat(float min, float max)
	{
		std::uniform_real_distribution<double> dist(min, max);
		return static_cast<float>(dist(_engine));
	}

private:
	std::mt19937 _engine;
};

#define Random GET_SINGLE(RandomManager)