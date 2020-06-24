#pragma once
/*
	Класс динамический вектор
*/
template<typename T>
class DinamicVector
{
public:
	DinamicVector() {
		_size = 0; _capacity = 2 * _size; _arr = nullptr;
	}
	void resize(size_t _new_size)
	{
		_capacity = 2 * _new_size;
		T* _new_arr = new T[_capacity];
		if(_size > _new_size)_size = _new_size;

		for (size_t i = 0; i != _size; ++i)
			_new_arr[i] = _arr[i];
		
		delete[] _arr;
		_size = _new_size;
		_arr = _new_arr;
	}
	void push_back(T data) {
		if (_size == _capacity)
		{
			resize(_size + 1);
			--_size;
		}
		_arr[_size++] = data;
	}
	void clear() {
		delete[] _arr;
		_arr = nullptr;
		_size = 0;
		_capacity = 0;
	}
	T* at(size_t index) {
		if (index > size()) throw 0;
		T* temp;
		temp = &_arr[index];
		return temp;
	}
	size_t size() {
		return _size;
	}
private:
	size_t _size;
	size_t _capacity;
	T* _arr;
};
