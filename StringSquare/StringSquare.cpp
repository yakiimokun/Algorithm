#include <iostream>
#include <vector>

typedef unsigned int uint16_t;

class StringSquare {
public:
	uint16_t calcSquare(uint16_t shortside, uint16_t square) {
		return shortside * ( 2 * square - shortside);
	}

	/// 
	/// @brief   compare sum of rectangles with square
	/// @param shortside   the  short side of smaller square
	/// @param longside     the short side of bigger    square
	/// @param squareside the side of square
	///
	/// @return 
	///
	bool compareRectangleToSquare(uint16_t shortside, uint16_t longside, uint16_t squareside) {
		uint16_t large  = calcSquare(shortside, squareside);
		uint16_t small = calcSquare(longside, squareside);

		return (large + small == squareside * squareside) ? true : false;
	}

	/// 
	/// @brief    check the side pair whether side pair is common multiple
	/// @param shortside 
	/// @param longside 
	/// @param squareside 
	///
	void evaluateSidePair(uint16_t shortside, uint16_t longside, uint16_t squareside) {
		if (calcMCDFromThree(shortside,  longside, squareside) != 1) {
			return;
		}

		SidePair sidepair;
		sidepair.shortside   = shortside;
		sidepair.longside     = longside;
		sidepair.squareside = squareside;

		sidepair_.push_back(sidepair);
	}

	void showSidePair() {
		std::vector<SidePair>::iterator it;

		for(it = sidepair_.begin(); it != sidepair_.end(); it++) {
			uint16_t shortside   = it->shortside;
			uint16_t longside     = it->longside;
			uint16_t squareside = it->squareside;
			std::cout << "(" << shortside << ", " << longside << ", " << squareside << ") - (" 
					  << calcSquare(shortside,  squareside) << ", " << calcSquare (longside, squareside) << ", " 
					  << squareside * squareside << ")" << std::endl;
		}
	}

private:
	typedef struct {
		uint16_t shortside;
		uint16_t longside;
		uint16_t squareside;
	}SidePair;

	/// 
	/// @brief   calculation of maximum common divisor
	/// @param small 
	/// @param large 
	///
	/// @return 
	///
	uint16_t calcMCD(uint16_t small, uint16_t large) {
		if (large % small == 0) return small;
		return calcMCD(large % small, small);
	}

	uint16_t calcMCDFromThree(uint16_t small, uint16_t middle, uint16_t large) {
		return calcMCD(calcMCD(small, middle), calcMCD(middle, large));
	}

	std::vector<SidePair> sidepair_;
};

int main(int argc, char* argv[])
{
	StringSquare stsq;
	uint16_t  squareside = 500 / 4;

	for (uint16_t i = 1; i <= squareside; i++) {
		for(uint16_t j = 1; j < i; j++) {
			for (uint16_t k = j + 1; k < i; k++) {
				if (stsq.compareRectangleToSquare(j, k, i) == false) {
					continue;
				}

				stsq.evaluateSidePair(j, k, i);
			}
		}
	}

	stsq.showSidePair();
	return 0;
}
