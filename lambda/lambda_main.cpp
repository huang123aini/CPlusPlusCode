#include <iostream>

void Lambda_by_ref() {
	int price;

	auto total_money = [&](auto a, auto b) {
		return price * (a + b) ;
	};

	price = 5;
	std::cout << "price is 5, total_money is: " << total_money(2,3) << std::endl;
	price = 10;
	std::cout << "price is 10, total_money is: " << total_money(2,3) << std::endl;
}

void Lambda_by_value() {
	int price;

	auto total_money = [=](auto a, auto b) {
		return price * (a + b);
	};

	auto total_money1 = [=](auto a, auto b) {
		return price * (a + b);
	};

	price = 5;
	std::cout << "price is 5, total_money is: " << total_money(2,3) << std::endl;
	price = 10;
	std::cout << "price is 10, total_money is: " << total_money(2,3) << std::endl;
}

void Lambda_no_params() {
	int price;
	auto total_money = [=] {
		return price * 5 ;
	};

	price = 5;
    //当未指定返回类型时，将进行返回值类型推导
    std::cout << "price is 5, total_money is: " << total_money() << std::endl;

}

int main(int argc, char const *argv[])
{
	/**Lambda表达式使用引用捕获*/
	Lambda_by_ref();

	/**Lambda表达式使用值捕获*/
	Lambda_by_value();

	/**当未指定返回值类型时，将进行返回值类型推导*/
	Lambda_no_params();

	return 0;
}