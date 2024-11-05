#include "random.hpp"

namespace random {
	int int_32() {
		int r = 0;
		r |= rand();
		r |= rand() << 15;
		r |= (rand() & 3) << 30;
		return r;
	}

	unsigned int uint_32() {
		return int_32() & 0x7FFFFFFF;
	}

	int range(int _min, int _upper) {
		return _min + (uint_32() % (_upper - _min + 1));
	}

	float unit() {
		int r = int_32() & 0x7FFFFFFF;
		return (float)r / (float)0x7FFFFFFF;
	}

	float unit(float _max) {
		int r = int_32() & 0x7FFFFFFF;
		return (float)r / (float)0x7FFFFFFF * _max;
	}

	float unit(float _min, float _max) {
		int r = int_32() & 0x7FFFFFFF;
		r = (float)r / (float)0x7FFFFFFF * _max;
		return r * (_max - _min) + _min;
	}

	bool chance(float _chance) {
		return unit() <= _chance;
	}

	int diceroll(int _count, int _die) {
		int r = 0;
		for (int i = 0; i < _count; i++) {
			r += range(1, _die);
		}
		return r;
	}

	float uniformSum() { return uniformSum(12, 0.f); }
	float uniformSum(float _mean) { return uniformSum(12, _mean); }
	float uniformSum(int _vals, float _mean) {
		float r = 0.f;
		float meanOffset = _mean - (_vals * .5f);
		for (int i = 0; i < _vals; i++) {
			r += unit();
		}
		r += meanOffset;
		return r;
	}
}