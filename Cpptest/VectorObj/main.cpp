#include <iostream>
#include <vector>

using namespace std;
const int seq_size = 10;

int main(void){
	vector<int> seq(seq_size);
	int sum;
	cout << "init your seqence1:" << endl;
	for (int i = 0; i < seq_size; i++) {
		cin >>seq[i];	
	}
	for (int i = 0; i < seq_size; i++) {
		sum += seq[i];
	}
	cout << "seq's summary is: " << sum
		<< "  and average is: " << sum/seq_size << endl;

	return 0;
}
