#pragma once
#include <iostream>
#include "polinom.h"
#include "number.h"
#include <math.h>
#include <conio.h>

using namespace std;

class TApplication{
	//argc argv � main
	int Targc;
	char** Targv;
	TPolynom polynom;
	//��������� �������� �
	number xValue;
	//���� ���������� �� �������������������� ����������
	bool polyInited;
	bool xValueInited;
public:
	TApplication(int argc, char *argv[]) {
		Targc = argc;
		Targv = argv;
		polyInited = false;
		xValueInited = false;
	}
	int menu();
	int run();
	//����\��������� �������� �
	void initXValue();
	//����\��������� ������������� ��������
	void initOrRedactCoefs();
	//����� ������ ����������
	void initShowRoots();
	//����� ������� ��� ������� X
	void initSolution();
	//���������� ������ ��������
	void initRoots();
	
};

void TApplication::initXValue() {
	cout << "������� �������� �: ";
	cin >> xValue;
	xValueInited = true;
}

void TApplication::initSolution() {
	polynom.findSolution(xValue);
}

void TApplication::initRoots() {
	polynom.findRoots();
}


void TApplication::initOrRedactCoefs() {
	int val;
	cout << "���� �������� ������������� �����������:" << endl;
	cout << "������� �������� ������������ 2 �������: ";
	cin >> val;
	while (val == 0) 
	{
		cout << "����������� ������ ���� ���������. ������� �������� ������������ 2 �������: ";
		cin >> val;
	}
	polynom.set_polyn_coef_2(val);
	cout << "������� �������� ������������ 1 �������: ";
	cin >> val;
	polynom.set_polyn_coef_1(val);
	cout << "������� �������� ������������ 0 �������: ";
	cin >> val;
	polynom.set_polyn_coef_0(val);
	//������� ���������������
	polyInited = true;
}

void TApplication::initShowRoots() {
	cout << "����� ����������: ";
	polynom.showRoots();
}

int TApplication::menu() {
	system("cls");
	cout << "����:" << endl;
	cout << "1. ���� �������� ������������� ����������" << endl;
	cout << "2. ���� �������� X" << endl;
	cout << "3. ����� ������ ����������" << endl;
	cout << "4. ����� �������� ���������� ��� ���������� X" << endl;
	cout << "5. ����� ���������� � ���������� �������� X" << endl;
	cout << "0. �����" << endl;
	int choi�e;
	cout<< endl << "�������� ��������: ";
	cin >> choi�e;
	return 	choi�e;
}

int TApplication::run()
{
	int ch;
	while (true)
	{
		ch = menu();
		if (ch == 0) break;
		char pause;
		switch (ch) {
		case 1:
			initOrRedactCoefs();
			break;
		case 2:
			initXValue();
			break;
		case 3:
			//�������� ���������� �� �������������������� ����� ������� ��� ������
			if (!polyInited) initOrRedactCoefs();
			initRoots();
			initShowRoots();
			//����� �� ������� �������
			_getch();
			break;
		case 4:
			//�������� ���������� � �������� � �� �������������������� ����� ����������� ��� ��������
			if (!polyInited) initOrRedactCoefs();
			if (!xValueInited) initXValue();
			initSolution();
			cout << "������� ��� x=" << xValue << ": " << polynom.get_solution();
			_getch();
			break;
		case 5:
			if (polyInited) {
				polynom.showPolynom();
			}else cout << "��������� �� ���������������"<<endl;
			if (xValueInited) {
				cout << "x=" << xValue;
			}else cout << "�������� � �� ����������������";
			_getch();
			break;
		default:
			break;
		}
	}
	return 0;
}
