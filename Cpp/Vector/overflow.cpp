#include <iostream>
#include <vector>
using namespace std;

int main(void){
	std::vector<int> vec;
	std::cout<<"vector size is:"<<vec.size()<<"Capacity:"<<vec.capacity()<<std::endl;
	//init a empty vector, result: 0,0
	for(int i = 0; i < 10; i++){
		vec.push_back(i);
		if(i==6){	
			std::cout<<"vector size is:"<<vec.size()<<"Capacity:"<<vec.capacity()<<std::endl;
		}
	}
	std::cout<<"vector size is:"<<vec.size()<<"Capacity:"<<vec.capacity()<<std::endl;
	/*
	 * 7 elements, result: 7,8 
	 * 10 elements, result: 10,16
	 * y? cause vector's extending is a doubled-way
	 */

	std::vector<int> vec1;
	vec1.reserve(10);
	std::cout<<"vector size is:"<<vec1.size()<<"Capacity:"<<vec1.capacity()<<std::endl;
	/*
	 * obviously, extend vectors too offen will cause a waste of resouces(relocal-alocal...)
	 * so, using reserve() distribute spaces is neceassary.
	 */
	
	return 0;
}
