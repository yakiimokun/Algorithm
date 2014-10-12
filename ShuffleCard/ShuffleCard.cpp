#include <vector>
#include <iostream>

class ShuffleCard {
public:
	/// 
	/// @fn    shuffleCard
	/// @brief shuffle the card
	/// @param numbers 
	/// @param modnumbers 
	///
	void shuffleCard(std::vector<int>& numbers, std::vector<int>& modnumbers) {
		int middle_index = numbers.size() / 2;
		std::vector<int> upper;
		std::vector<int> lower;

		modnumbers.clear();
		copy(numbers.begin(), numbers.begin() + middle_index, std::back_inserter(upper));
		copy(numbers.begin() + middle_index, numbers.end(), std::back_inserter(lower));

		for(int i = 0; i < middle_index; i++) {
			std::vector<int>::iterator upp = upper.begin() + i;
			std::vector<int>::iterator lo  = lower.begin() + i; 
			modnumbers.push_back(*upp);
			modnumbers.push_back(*lo);
		}
	}

	/// 
	/// @fn    compare card
	/// @brief shuffle count - 2 times and evaluate array between original sort and shuffled sort
	/// @param count 
	/// @param numbers 
	///
	/// @return 
	///
	bool compareCard(int count, std::vector<int>& numbers) {
		std::vector<int> before, after;

		copy(numbers.begin(), numbers.end(), std::back_inserter(before));
		copy(numbers.begin(), numbers.end(), std::back_inserter(after));

		for(int i = 0; i < count - 2; i++) {
			after.clear();
			shuffleCard(before, after);
			before.clear();
			copy(after.begin(), after.end(), std::back_inserter(before));
		}

		if (numbers == after) {
			return true;
		} else {
			return false;
		}
	}

	/// 
	/// @brief create sort data
	/// @param size 
	/// @param numbers 
	///
	void initData(int size, std::vector<int>& numbers) {
		for(int i = 0; i < size; i++) {
			numbers.push_back(i+1);
		}
	}
};

int main(int argc, char* argv[])
{
	ShuffleCard shuffle;
	std::vector<int> numbers;
	std::vector<int> answer;

	for(int i = 1; i <= 100; i++) {
		shuffle.initData(2 * i, numbers);
		bool result = shuffle.compareCard(2 * i, numbers);

		if (result == true) {
			answer.push_back(i);
		}

		numbers.clear();
	}

	std::cout << "total number of shuffle is same :" << answer.size() << "!!" << std::endl;
	return 0;
}

