#include <chrono>
#include <iostream>
#include <vector>
#include <windows.h>

auto main()->int
{
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	std::chrono::system_clock::time_point  start, end; // 型は auto で可
	double elapsed;

	start = std::chrono::system_clock::now(); // 計測開始時間
	a.assign(10000000, 1);
	for (int i = 0; i < 1000000;i++)
	{
		a[i] = 0;
	}
	a.shrink_to_fit();
	end = std::chrono::system_clock::now();  // 計測終了時間
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
	std::cout << "assign:" << elapsed <<std::endl;

	start = std::chrono::system_clock::now(); // 計測開始時間
	b.reserve(10000000);
	for (int i = 0; i < 1000000;i++)
	{
		b.push_back(0);
	}
	b.shrink_to_fit();
	end = std::chrono::system_clock::now();  // 計測終了時間
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
	std::cout << "reserve:" << elapsed << std::endl;

	start = std::chrono::system_clock::now(); // 計測開始時間
	c.resize(10000000);
	for (int i = 0; i < 1000000; i++)
	{
		c.push_back(0);
	}
	c.shrink_to_fit();
	end = std::chrono::system_clock::now();  // 計測終了時間
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
	std::cout << "resize:" << elapsed << std::endl;

	Sleep(5000);
	return 0;
}