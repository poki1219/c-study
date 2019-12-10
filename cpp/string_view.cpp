#include	<iostream>
#include	<string>

void* operator new(std::size_t count){
	std::cout << count << "bytes allocate" << std::endl;
	return malloc(count);
}

bool contains_very(std::string_view str){
	return str.find("very") != std::string_view::npos;
}

int main(){
	std::cout << std::boolalpha << contains_very("C++ string is very easy to use") << std::endl;

	std::cout << contains_very("c++ string is not easy to use") << std::endl;

	std::string str = "some long long long long long long string";
	std::cout << "---------------------------" << std::endl;
	std::cout << contains_very(str) << std::endl;

	return 0;
}
