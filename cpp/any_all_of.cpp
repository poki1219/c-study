#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>
#include	<functional>

template <typename Iter>
void print(Iter begin, Iter end){
	while(begin != end){
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}

struct User{
	std::string name;
	int level;

	User(std::string name, int level) : name(name), level(level) {}

	bool operator==(const User& user) const{
		if(name == user.name && level == user.level)
			return true;
		return false;
	}
};

class Party{
	std::vector<User> users;

public:
	bool add_user(User& user){
		if(std::find(users.begin(), users.end(), user) != users.end())
			return false;
		users.push_back(user);
		std::cout << "1" << std::endl;
		return true;
	}

	bool add_user(std::string name, int level){
		User new_user(name, level);
		if(std::find(users.begin(), users.end(), new_user) != users.end())
			return false;
		users.push_back(new_user);
		return true;
	}
	

	bool can_join_dungeon(){
		return all_of(users.begin(), users.end(), [] (User& user)-> bool {
					return user.level >= 15;
				});
	}

	bool can_use_special_item(){
		return std::any_of(users.begin(), users.end(), [](User& user)->bool{
					return user.level >= 19;
				});
	}
};

int main(){
	Party party;

	party.add_user("철수", 15);
	party.add_user("영희", 18);
	party.add_user("민수", 12);
	party.add_user("수빈", 19);

	std::cout << std::boolalpha;
	std::cout << party.can_join_dungeon() << std::endl;
	std::cout << party.can_use_special_item() << std::endl;

	return 0;
}
