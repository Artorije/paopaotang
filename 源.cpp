#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<opencv.hpp>
#include<opencv\highgui.h>
#include<iostream>
#include<stdio.h>
#include"GameEnergy.h"
using namespace std;

int main()
{
	CGameEnergy energy;
	energy.InitGame();
	energy.Run();
	energy.Releaseimg();
	return 0;
}