#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>

namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string c_name{};
		T* c_items{};
		size_t arr_size{};
		void (*c_observer)(const Collection<T>&, const T&) {};
	public:
		Collection(const std::string& name) {
			c_name = name;
			c_items = nullptr;
			arr_size = 0;
			c_observer = nullptr;
		}

		~Collection() {
			delete[] c_items;
		}

		const std::string& name() const {
			return c_name;
		}

		size_t size() const{
			return arr_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool exist = false;
			for (size_t i = 0; i < arr_size && !exist; i++) {
				if (c_items[i].title() == item.title()) {
					exist = true;
				}
			}
			if (!exist) {
				T* temp = new T[arr_size + 1];
				for (size_t i = 0; i < arr_size; i++) {
					temp[i] = c_items[i];
				}
				temp[arr_size] = item;
				arr_size++;
				delete[] c_items;
				c_items = new T[arr_size];
				for (size_t i = 0; i < arr_size; i++) {
					c_items[i] = temp[i];
				}
				delete[] temp;
				if (c_observer != nullptr) {
					c_observer(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= arr_size) {
				std::string err;
				err = "Bad index [" + std::to_string(idx) + "]. Collection has ["
					     + std::to_string(arr_size) + "] items.";
				throw std::out_of_range(err);
			}
			else {
				return c_items[idx];
			}
		}

		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < arr_size; i++)	{
				if (c_items[i].title() == title) {
					return &c_items[i];
				}
			}
			return nullptr;
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& col) {
			for (size_t i = 0; i < col.size(); i++) {
				os << col.c_items[i];
			}
			return os;
		}
	};
}
#endif
