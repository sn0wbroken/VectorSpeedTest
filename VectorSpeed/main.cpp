#include <chrono>
#include <iostream>
#include <vector>
#include <windows.h>

auto main()->int
{
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	double elapsed; //�o�ߎ���

	start = std::chrono::system_clock::now(); // �v���J�n����
	a.assign(10000000, 1);
	for (int i = 0; i < 1000000;i++)
	{
		a[i] = 0; //����Ȃ̂͋����Ăق��� ���ꂵ���Ȃ��Ǝv����
	}
	a.shrink_to_fit();
	end = std::chrono::system_clock::now();  // �v���I������
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << "assign:" << elapsed <<std::endl;

	start = std::chrono::system_clock::now(); // �v���J�n����
	b.reserve(10000000);
	for (int i = 0; i < 1000000;i++)
	{
		b.push_back(0);
	}
	b.shrink_to_fit();
	end = std::chrono::system_clock::now();  // �v���I������
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << "reserve:" << elapsed << std::endl;

	start = std::chrono::system_clock::now(); // �v���J�n����
	c.resize(10000000);
	for (int i = 0; i < 1000000; i++)
	{
		c.push_back(0);
	}
	c.shrink_to_fit();
	end = std::chrono::system_clock::now();  // �v���I������
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << "resize:" << elapsed << std::endl;

	//���ʕ\�������邽��
	Sleep(5000);
	return 0;
}