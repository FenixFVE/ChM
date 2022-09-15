
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::vector;

template<typename T>
class BandMatrix {
public:
	int matrix_size;
	int band_size;
	vector<vector<T>> al;
	vector<vector<T>> au;
	vector<T> di;

	BandMatrix(int matrix_size, int band_size) {
		this->matrix_size = matrix_size;
		this->band_size = band_size;
		int half_band = band_size / 2;
		al = vector<vector<T>>(matrix_size, vector<T>(half_band, 0.0));
		au = vector<vector<T>>(matrix_size, vector<T>(half_band, 0.0));
		di = vector<T>(matrix_size, 0.0);
	}
};

template<typename T>
BandMatrix<T> read_matrix(std::string matrix_file) {

	std::ifstream stream(matrix_file);
	if (!stream.good()) throw std::exception("invalid file");

	int matrix_size, band_size;
	stream >> matrix_size >> band_size;
	BandMatrix<T> matrix(matrix_size, band_size);

	int half_band = matrix.band_size / 2;
	for (int i = 0; i < matrix_size; ++i) {
		for (int j = 0; j < half_band; ++j) {
			stream >> matrix.al[i][j];
		}
	}
	for (int i = 0; i < matrix_size; ++i) {
		stream >> matrix.di[i];
	}
	for (int i = 0; i < matrix_size; ++i) {
		for (int j = 0; j < half_band; ++j) {
			stream >> matrix.au[i][j];
		}
	}

	return matrix;
}

template<typename T>
void _main() {
	auto t = read_matrix<T>("input_matrix.txt");
	
}

int main() {

	bool _float = true;
	if (_float) {
		_main<float>();
	} else {
		_main<double>();
	}

	return 0;
}