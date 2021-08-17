// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* product;
					product = new Product(desc[i].desc, price[j].price);
					product->validate();
					priceList += product;
					delete product;
				}
			}
		}
		return priceList;
	}
}