
#include <iostream>
#include <fstream>
#include <vector>

using std::vector;
using std::fstream;

template<typename T>
struct BandMatrix {
	vector<vector<T>> al;
	vector<vector<T>> au;
	vector<T> di;
};

template<typename T>
BandMatrix<T> read_matrix(ifsteam& stream) {
	int matrix_size = 0,
		band_size = 0;
	stream >> matrix_size >> band_size;
	int half_band_size = band_size / 2;

}

template<typename T>
void function() {

}

template<typename T>
void Main() {
	function<T>();
}

int main() {

	bool flag = true;
	if (flag) {
		Main<float>();
	} else {
		Main<double>();
	}

	return 0;
}