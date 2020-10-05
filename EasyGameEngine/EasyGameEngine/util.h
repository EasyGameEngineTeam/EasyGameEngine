#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Windows.h>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <cstdarg>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>

#define DATADEF(type, name)\
private:\
	type name; \
public:\
	type get##name(); \
	void set##name(type name);

#define DATA(type, name, clazz)\
type clazz::get##name() {\
	return name;\
} \
void clazz::set##name(type name) {\
	this -> name = name;\
} 

#define DATAREADDEF(type, name)\
private:\
	type name; \
public:\
	type get##name();

#define DATAREAD(type, name, clazz)\
type clazz::get##name() {\
	return name;\
}

#define DATAWRITEDEF(type, name) \
private:\
	type name;\
public:\
	void set##name(type name);

#define DATAWRITE(type, name, clazz)\
void clazz::set##name(type name) {\
	this -> name = name;\
}

#define interface class

namespace EasyGame {

	inline int lowbit(int x) {
		return x & -x;
	}

	template<typename T> class List {
		T* array;
		int length;
		int size;
	public:
		List() {
			array = new T[20];
			size = 20;
			length = 0;
		}
		List(int size) {
			array = new T[size];
			this->size = size;
			length = 0;
		}
		~List() {
			delete array;
			array = nullptr;
			size = 0;
			length = 0;
		}
		void extends(int num) {
			T* old = array;
			array = new T[size + num];
			for (int i = 0; i < size; i++) {
				array[i] = old[i];
			}
			delete old;
			size += num;
		}
		int getLength() {
			return length;
		}
		int getSize() {
			return size;
		}
		T* getArray() {
			return array;
		}
		T& operator[] (int pos) {
			if (pos > size) {
				extends((pos - size) * 1.5);
			}
			length = max(length, pos);
			return array[pos];
		}
		T& get(int pos) {
			return *this[pos];
		}
		void set(int pos, T value) {
			*this[pos] = value;
		}
		template<typename F> void foreach(const F function) {
			for (int i = 0; i < length; i++) {
				function(array[i]);
			}
		}
	};

	class ResourceLocation {
	public:
		struct TYPE {
			enum Type {
				DATA,
				RESOURCE,
				SOURCE,
				CONFIG,
				SAVE
			};
			static std::string toString(Type type);
		};
	private:
		DATADEF(std::string, ID)
		DATADEF(std::string, Path)
		DATADEF(TYPE::Type, Type)
	public:
		ResourceLocation(std::string ID, std::string Path, TYPE::Type);
		std::string toString();
		std::string toPath();
	};

	ResourceLocation createLocation(std::string ID, std::string Path, ResourceLocation::TYPE::Type Type);
}