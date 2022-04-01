/**
 * @file Quadrate.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Quadrate.h"

square::square(const double kantenLaege)
{
	kantenLaege_ = kantenLaege;
};

square::square(const square &s)
{
	kantenLaege_ = s.getSquareKantenlaege();
};

double square::getSquareKantenlaege() const
{
	return kantenLaege_;
};

double square::getSquareFlaeche() const
{
	return kantenLaege_ * kantenLaege_;
}

double square::getSquareUmfang() const
{
	return kantenLaege_ * 4;
};
