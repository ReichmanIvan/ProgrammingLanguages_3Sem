#include "..//list/List.h"
 
int main()
{
	List<int> first_list;
	first_list.push_front(1);
	first_list.push_front(2);
	first_list.push_back(3);
	first_list.push_front(4);
	std::cout << first_list.get_size() << "\n";
	std::cout << first_list.to_string() << "\n";
	List<int> second_list;
	second_list = first_list;
	std::cout << second_list.get_size() << "\n";
	std::cout << second_list.to_string();
	return 0;
};
