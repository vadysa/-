#pragma once
#include "StaticVector.h"
/*
	Шаблонный класс для хранения абстрактных классов
*/
template<class T>
class Container: private StaticVector
{
public:
	void Push(T value) {
		_push(value);
	}
	T At(size_t i) {
		return reinterpret_cast<T>(_at(i));//явное приведение указателей на неродственные типы void* в T
	}
	void Clear() {
		_clear();
	}
	bool Empty() {
		return _empty();
	}
	unsigned int Size() {
		return _size();
	}
	void DeleteAt(size_t index) {
		_deleteAt(index);
	}
};

