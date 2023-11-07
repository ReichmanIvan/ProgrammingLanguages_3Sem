#include "..//list/List.h"
 
int main()
{
	List<std::string> first_list;
	first_list.push_front("my");
	first_list.push_front("name");
	first_list.push_back("is");
	first_list.push_front("Ivan");
	std::cout << first_list.get_size() << "\n";
	std::cout << first_list.to_string() << "\t";
	List<std::string> second_list;
	second_list = first_list;
	std::cout << second_list.to_string();
	return 0;
};
