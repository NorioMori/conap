// conap.cpp : ２つの数字を足して100倍するプログラムの例です。
//

#include <stdio.h>
#include <charconv>
#include <iostream>
#include <string>
#include "conap-s.h"

bool readInteger(const char* prompt, int& value)
{
	while (true)
	{
		std::cout << prompt << '\n';

		std::string input;
		if (!std::getline(std::cin, input))
		{
			return false;
		}

		bool digitsOnly = !input.empty();
		for (const char character : input)
		{
			if (character < '0' || character > '9')
			{
				digitsOnly = false;
				break;
			}
		}

		if (!digitsOnly)
		{
			std::cerr << "数字のみ入力してください。もう一度入力してください。\n";
			continue;
		}

		const char* begin = input.data();
		const char* end = begin + input.size();
		const auto result = std::from_chars(begin, end, value);
		if (result.ec == std::errc{} && result.ptr == end)
		{
			return true;
		}

		std::cerr << "入力値が大きすぎます。もう一度入力してください。\n";
	}
}

std::string formatNumber(int value)
{
	std::string formatted = std::to_string(value);
	const std::size_t firstDigit = formatted.front() == '-' ? 1 : 0;

	for (std::size_t position = formatted.size(); position > firstDigit + 3; position -= 3)
	{
		formatted.insert(position - 3, 1, ',');
	}

	return formatted;
}

int main()
{
    std::cout << "Hello World!\n";

	int a{};
	int b{};

	if (!readInteger("a　の数字を入力してください:", a))
	{
		std::cerr << "a の入力を読み取れませんでした。\n";
		return 1;
	}

	if (!readInteger("b　の数字を入力してください:", b))
	{
		std::cerr << "b の入力を読み取れませんでした。\n";
		return 1;
	}

	std::cout << "aとbを足して100倍すればこうなります " << formatNumber(add(a, b) * 100) << '\n';
	std::cout << "驚きです \n";
}

