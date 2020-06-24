#pragma once
#include <array>

/*
	Контейнерный базовый класс
*/
class StaticVector
{
public:
	StaticVector() {
		_statvector.fill(nullptr);
	}
protected:
	void _push(void* statvector) {
		for (size_t i = 0; i < _statvector.size(); i++) {
			if (_statvector[i] == nullptr) {
				_statvector[i] = statvector;
				break;
			}
		}
	}
	void _deleteAt(size_t index) {
		_statvector[index]= nullptr;
	}
	void _clear() {
		_statvector.fill(nullptr);
	}
	size_t _size() {
		return _statvector.size();
	}
	bool _empty() {
		return _statvector.empty();
	}
	void* _at(size_t index) {
		return _statvector.at(index);
	}
private:
	std::array<void*, 100> _statvector;
};

