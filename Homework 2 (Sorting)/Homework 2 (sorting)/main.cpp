//Tanner Kvarfordt
//A02052217

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<random>
#include<algorithm>
#include<chrono>
#include<functional>
#include<fstream>

//bubble sort
void bubbleSort(std::vector<int> &);
//insertion sort
void insertionSort(std::vector<int> &);
//selection sort
void selectionSort(std::vector<int> &);
//merge sort
void mergeSort(std::vector<int> &);
void mergeSort(std::vector<int> &, int, int);
void merge(std::vector<int> &, int, int, int);
//quick sort
void quickSort(std::vector<int> &);
void quickSort(std::vector<int> &, int, int);
int pickPivot (std::vector<int> &, int, int);
int partition(std::vector<int> &, int, int, int);
//misc
std::vector<int> makeVector(int);
std::chrono::milliseconds timeSort(std::vector<int> &, std::function<void(std::vector<int> &)>);
void stdSort(std::vector<int> & );
//double avgTime(std::vector<int>);

int main() {
	std::ofstream fout("testResults.txt"); //for testing, export to .csv file and seperate values by commas; will open and create an excel file

	//test a given sort
	/*auto test2 = makeVector(26);
	std::cout << "mergeSort test:\n";
	for (auto i = 0u; i < test2.size(); i++) {
		std::cout << test2[i] << ' ';
	}
	std::cout << std::endl;
	mergeSort(test2);
	for (auto i = 0u; i < test2.size(); i++) {
		std::cout << test2[i] << ' ';
	}
	std::cout << std::endl;*/

	//create necessary variables
	auto test = makeVector(1);
	auto msecs = timeSort(test, stdSort);
	//std::vector<int>times, size1, size2, size3, size4;

	//bubbleSort tests
	fout << "Bubble Sort Tests:\n\n";

	test = makeVector(1000);
	msecs = timeSort(test, bubbleSort);
	fout << "\t1000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(10000);
	msecs = timeSort(test, bubbleSort);
	fout << "\t10000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(50000);
	msecs = timeSort(test, bubbleSort);
	fout << "\t50000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(100000);
	msecs = timeSort(test, bubbleSort);
	fout << "\t100000 Elements: " << msecs.count() << " milliseconds" << std::endl;
	fout << std::endl;

	//insertionSort tests
	fout << "Insertion Sort Tests:\n\n";

	test = makeVector(1000);
	msecs = timeSort(test, insertionSort);
	fout << "\t1000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(10000);
	msecs = timeSort(test, insertionSort);
	fout << "\t10000 Elements: " << msecs.count() << " milliseconds" << std::endl;
	
	test = makeVector(50000);
	msecs = timeSort(test, insertionSort);
	fout << "\t50000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(100000);
	msecs = timeSort(test, insertionSort);
	fout << "\t100000 Elements: " << msecs.count() << " milliseconds" << std::endl;
	fout << std::endl;

	//selectionSort tests
	fout << "SelectionSort Tests:\n\n";

	test = makeVector(1000);
	msecs = timeSort(test, selectionSort);
	fout << "\t1000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(10000);
	msecs = timeSort(test, selectionSort);
	fout << "\t10000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(50000);
	msecs = timeSort(test, selectionSort);
	fout << "\t50000 Elements: " << msecs.count() << " milliseconds" << std::endl;
	
	test = makeVector(100000);
	msecs = timeSort(test, selectionSort);
	fout << "\t100000 Elements: " << msecs.count() << " milliseconds" << std::endl;
	fout << std::endl;
	
	//mergeSort tests
	fout << "Merge Sort Tests:" << std::endl << std::endl;

	//for (int size = 1000; size < 1000000; size *= 10) {
	//	for (int runs = 0; runs < 6; runs++) {
	//		test = makeVector(size);
	//		msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(mergeSort));
	//		if (runs > 0) { //to account for warming up my cache
	//			times.push_back(msecs.count());
	//		}
	//	}
	//	if (size = 1000) {
	//		size1 = times;
	//	}
	//	else if (size = 10000) {
	//		size2 = times;
	//	}
	//	else if (size = 100000) {
	//		size3 = times;
	//	}
	//	else if (size = 1000000) {
	//		size4 = times;
	//	}
	//}

	//fout << "\t1000 Elements (avg): " << avgTime(size1) << " milliseconds" << std::endl;
	//csv << avgTime(size1);
	//fout << "\t10000 Elements (avg): " << avgTime(size2) << " milliseconds" << std::endl;
	//csv << avgTime(size2);
	//fout << "\t100000 Elements (avg): " << avgTime(size3) << " milliseconds" << std::endl;
	//csv << avgTime(size3);
	//fout << "\t1000000 Elements (avg): " << avgTime(size4) << " milliseconds" << std::endl;
	//csv << avgTime(size4);

	test = makeVector(10000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(mergeSort));
	fout << "\t10000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(100000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(mergeSort));
	fout << "\t100000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(1000000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(mergeSort));
	fout << "\t1000000 Elements: " << msecs.count() << " milliseconds" << std::endl;

	test = makeVector(2000000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(mergeSort));
	fout << "\t2000000 Elements: " << msecs.count() << " milliseconds\n\n";

	//quickSort tests
	fout << "Quick Sort Tests:\n\n";
	test = makeVector(10000);
	msecs = timeSort(test, static_cast<void (*) (std::vector<int>&)>(quickSort));
	fout << "\t10000 Elements: " << msecs.count() << " milliseconds\n";

	test = makeVector(100000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(quickSort));
	fout << "\t100000 Elements: " << msecs.count() << " milliseconds\n";
	
	test = makeVector(1000000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(quickSort));
	fout << "\t1000000 Elements: " << msecs.count() << " milliseconds\n";

	test = makeVector(2000000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(quickSort));
	fout << "\t2000000 Elements: " << msecs.count() << " milliseconds\n\n";

	//for (int size = 1000; size < 1000000; size *= 10) {
	//	for (int runs = 0; runs < 6; runs++) {
	//		test = makeVector(size);
	//		msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(quickSort));
	//		if (runs > 0) { //to account for warming up my cache
	//			times.push_back(msecs.count());
	//		}
	//	}
	//	if (size = 1000) {
	//		size1 = times;
	//	}
	//	else if (size = 10000) {
	//		size2 = times;
	//	}
	//	else if (size = 100000) {
	//		size3 = times;
	//	}
	//	else if (size = 1000000) {
	//		size4 = times;
	//	}
	//}

	//for (auto && e : size1) {
	//	std::cout << e << ' ';
	//}

	//fout << "\t1000 Elements (avg): " << avgTime(size1) << " milliseconds" << std::endl;
	//csv << avgTime(size1);
	//fout << "\t10000 Elements (avg): " << avgTime(size2) << " milliseconds" << std::endl;
	//csv << avgTime(size2);
	//fout << "\t100000 Elements (avg): " << avgTime(size3) << " milliseconds" << std::endl;
	//csv << avgTime(size3);
	//fout << "\t1000000 Elements (avg): " << avgTime(size4) << " milliseconds" << std::endl;
	//csv << avgTime(size4);

	//std::sort tests
	fout << "std::sort Tests:\n\n";

	//for (int size = 1000; size < 1000000; size *= 10) {
	//	for (int runs = 0; runs < 6; runs++) {
	//		test = makeVector(size);
	//		msecs = timeSort(test, stdSort);
	//		if (runs > 0) { //to account for warming up my cache
	//			times.push_back(msecs.count());
	//		}
	//	}
	//	if (size = 1000) {
	//		size1 = times;
	//	}
	//	else if (size = 10000) {
	//		size2 = times;
	//	}
	//	else if (size = 100000) {
	//		size3 = times;
	//	}
	//	else if (size = 1000000) {
	//		size4 = times;
	//	}
	//}

	//fout << "\t1000 Elements (avg): " << avgTime(size1) << " milliseconds" << std::endl;
	//csv << avgTime(size1);
	//fout << "\t10000 Elements (avg): " << avgTime(size2) << " milliseconds" << std::endl;
	//csv << avgTime(size2);
	//fout << "\t100000 Elements (avg): " << avgTime(size3) << " milliseconds" << std::endl;
	//csv << avgTime(size3);
	//fout << "\t1000000 Elements (avg): " << avgTime(size4) << " milliseconds" << std::endl;
	//csv << avgTime(size4);

	test = makeVector(10000);
	msecs = timeSort(test, static_cast<void (*) (std::vector<int> &)>(stdSort));
	fout << "\t10000 Elements: " << msecs.count() << " milliseconds\n";

	test = makeVector(100000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int> &)>(stdSort));
	fout << "\t100000 Elements: " << msecs.count() << " milliseconds\n";

	test = makeVector(1000000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int> &)>(stdSort));
	fout << "\t1000000 Elements: " << msecs.count() << " milliseconds\n";

	test = makeVector(2000000);
	msecs = timeSort(test, static_cast<void(*) (std::vector<int>&)>(stdSort));
	fout << "\t2000000 Elements: " << msecs.count() << " milliseconds\n\n";

	fout.close();
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

//bubble sort
void bubbleSort(std::vector<int> & container) {
	bool done = false;
	while (done == false) { 
		done = true;
		for (auto index = 0u; index < container.size() - 1; index++) { //Note to self: adding a u after the 0 indicates that it is unsigned
			if (container[index + 1] < container[index]) { 
				std::swap(container[index + 1], container[index]);
				done = false;
			}
		}
	}
}

//insertion sort
void insertionSort(std::vector<int> & container) {
	for (auto element = 1u; element < container.size(); element++) { 
		for (auto index = 0u; index < element; index++) {
			if (container[element] < container[index]) {
				std::swap(container[element], container[index]);
			}
		}
	}
}

//selection sort
void selectionSort(std::vector<int> & container) {
	auto index = 0u;
	while (index < container.size() - 1) {
		auto element = index + 1;
		while (element < container.size()) {
			if (container[element] < container[index]) {
				std::swap(container[element], container[index]);
			}
			element++;
		}
		index++;
	}
}

//merge sort
void mergeSort(std::vector<int> & container) {
	mergeSort(container, 0, container.size() - 1);
}

void mergeSort(std::vector<int> & container, int istart, int iend) {
	if (istart >= iend) return;
	auto imid = (istart + iend) / 2;
	mergeSort(container, istart, imid);
	mergeSort(container, imid + 1, iend);
	merge(container, istart, imid, iend);
}

void merge(std::vector<int> & container, int istart, int imid, int iend) { //here iend is equal to iend (from mergeSort) which is equal to end - 1
	std::vector<int> merged;
	auto s = istart;
	auto m = imid + 1;
	while (s <= imid && m <= iend) {
		if (container[s] <= container[m]) {
			merged.push_back(container[s]);
			s++;
		}
		else {
			merged.push_back(container[m]);
			m++;
		}
	}
	while (s <= imid) { //Note: these handle any leftover values, which are guaranteed to be greater than those already sorted
		merged.push_back(container[s]);
		s++;
	}
	while (m <= iend) {
		merged.push_back(container[m]);
		m++;
	}
	//replacing container values with the sorted merged values
	auto j = 0u;
	for (auto i = istart; j < merged.size(); i++, j++) {
		container[i] = merged[j];
	}
}

//quick sort
void quickSort(std::vector<int> & container) {
	quickSort(container, 0, container.size());
}

void quickSort(std::vector<int> & container, int start, int end) {
	if (end <= start) return;
	auto pivot = pickPivot(container, start, end);
	pivot = partition(container, start, end, pivot);
	quickSort(container, start, pivot);
	quickSort(container, pivot + 1, end);
}

int pickPivot(std::vector<int> & container, int start, int end) {
	if (container[start] < container[end - 1] && container[start] > container[(start + (end - 1)) / 2]) { return start; }
	else if (container[start] > container[end - 1] && container[start] < container[(start + (end-1)) / 2]) { return start; }

	else if (container[end - 1] < container[start] && container[end - 1] > container[(start + end - 1) / 2]) { return end - 1; }
	else if (container[end - 1] > container[start] && container[end - 1] < container[(start + end - 1) / 2]) { return end - 1; }

	else if (container[(start + end - 1) / 2] < container[start] && container[(start + end - 1) / 2] > container[end - 1]) { return (start + end - 1) / 2; }
	else if (container[(start + end - 1) / 2] > container[start] && container[(start + end - 1) / 2] < container[end - 1]) { return (start + end - 1) / 2; }

	else { return (start + end - 1) / 2; }
}

int partition(std::vector<int> & container, int start, int end, int pivot) {
	std::swap(container[pivot], container[end - 1]);
	int less = start;
	for (int index = start; index < end; index++) {
		if (container[index] < container[end - 1]) {
			std::swap(container[index], container[less]);
			less++;
		}
	}
	std::swap(container[end - 1], container[less]);
	return less;
}

//misc
std::vector<int> makeVector(int n) {
	std::vector<int> v(n);
	static std::random_device rd;
	static std::mt19937 mt(rd());
	std::generate(v.begin(), v.end(),
		[&]()
	{
		std::uniform_int_distribution<> dist(1, 2 * n);
		return dist(mt);
	});
	return v;
}

void stdSort(std::vector<int>& container) {
	std::sort(container.begin(), container.end());
}

std::chrono::milliseconds timeSort(std::vector<int> & container, std::function<void(std::vector<int> &)> sort) {
	auto startTime = std::chrono::high_resolution_clock::now();
	sort(container);
	auto endTime = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
}

//double avgTime(std::vector<int> sortTimes) {
//	double total = 0;
//	for (auto && e : sortTimes) {
//		total += e;
//	}
//	return total / sortTimes.size();
//}