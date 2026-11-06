// conap.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
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

    std::cout << "aとbを足して100倍すればこうなります " << add(a, b) * 100 << '\n';
}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用してビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
