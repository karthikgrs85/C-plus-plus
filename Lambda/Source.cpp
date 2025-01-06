//#include <iostream>
//using foo = void(int); // function pointer
//void functional(foo f) {
//	f(1);
//}
//int main() {
//	auto f = [](int value) {
//		std::cout << value << std::endl;
//	};
//	functional(f); // call by function pointer
//	f(1); // call by lambda expression
//	return 0;
//}

#include <string>
#include <map>
#include <iostream>
template <typename Key, typename Value, typename F>
void update(std::map<Key, Value>& m, F foo) {
	// TODO:

	for (auto& [key, value] : m)
		value = foo(key);
}
int main() {
	std::map<std::string, long long int> m{
	{"a", 1},
	{"b", 2},
	{"c", 3}
	};
	update(m, [](std::string key) {
		return std::hash<std::string>{}(key);
		});
	for (auto&& [key, value] : m)
		std::cout << key << ":" << value << std::endl;
}