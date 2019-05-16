#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void swap(double* a, double* b)
{
  /*helps tp swap all the values necessary
   for each sorting algorithm
  */
  int t = *a;
  *a = *b;
  *b = t;
}

int partition ( double list[], int low, int high)
{  /*selects the last element as a pivot and places all the
  smaller values to the right*/
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (list[j] <= pivot)
        {
          i++;
          swap(&list[i], &list[j]);
        }
    }
    swap(&list[i+1], &list[high]);
    return (i+1);


}

void selectionSort(double arr[], int n)
{
  int  minIndex;

  for(int i = 0; i < n-1; i++)
  {
    //Looking for the smallest value
    minIndex = 1;
    for(int j = i+1; j < n; j++ )
    {
        if(arr[j] < arr[minIndex])
        {
          minIndex = j;
          swap(&arr[minIndex], &arr[i]);
        }
    }

  }
}

void quickSort(double arr[], int low, int high)
{
  if(low < high)
  {
    int partitionNumber = partition(arr, low, high);
    quickSort(arr, low, partitionNumber - 1);
    quickSort(arr, partitionNumber + 1, high);
  }
}

void bubbleSort(double arr[], int n)
{
  for(int i = 0; i<n-1; i++)
  {
    for(int j = 0; j < n-i-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void insertionSort(double arr[], int n)
{
  int key;
  for(int i = 0; i<n-1; i++)
  {
    key = arr[i];
    int j = i - 1;
    //go up the list and change the element that are greater to the next position
    while(j >= 0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j = j -1;
    }
    arr[j+1] = key;
  }
}


void bubbleSortSim(double arr[], int n)
{
  double duration;
  clock_t start; //starts the ctime
  clock_t end; //ends the ctime
  start = clock();
  bubbleSort(arr, n);
  end = clock();
  duration = (end - start) / (double) CLOCKS_PER_SEC;
  std::cout << "bubbleSort started at: " << start << "and ended at: "<< end << '\n';
  std::cout << "with a runtime of: " << duration << '\n';
}

void selectionSortSim(double arr[], int n)
{
  double duration;
  clock_t start; //starts then time
  clock_t end; //stops the ctime
  start = clock();
  selectionSort(arr, n);
  end = clock();
  duration = (end - start) / (double) CLOCKS_PER_SEC;
  std::cout << "selectionSort ran started at: " << start << " and ended at: " << end << endl;
  std::cout << "with a runtime of:" << duration << '\n';
}

void insertionSortSim(double arr[], int n)
{
  double duration;
  clock_t start; //starts the  ctime
  clock_t end; //stops the ctime
  start = clock();
  insertionSort(arr, n);
  end = clock();
  duration = (end - start) / (double) CLOCKS_PER_SEC;
  std::cout << "insertionSort ran started at: " << start << " and ended at: " << end << endl;
  std::cout << "with a runtime of: " << duration << '\n';
}

void quickSortSim(double arr[], int high)
{
  double duration;
  clock_t start; //starts the  ctime
  clock_t end; //stops the ctime
  int low = 0;
  start = clock();
  quickSort(arr, low, high);
  end = clock();
  duration = (end - start) / (double) CLOCKS_PER_SEC;
  std::cout << "quickSort ran started at: " << start << " and ended at: " << end << endl;
  std::cout << "with a runtime of: " << duration << '\n';
}

int main(int argc, char** argv)
{
  double input;
  string file;
  if(argc > 1)
  {
  file = argv[1];
  }
  else
  {
  cout << "What is the name of the file you want to include? " << '\n';
  getline(cin, file);
  }
  fstream inputFile(file);
  if(inputFile.is_open())
  {
    string line;
    getline(inputFile,line);
    int data = stoi(line);
    int i = 0;
    double arr1[data];
    double arr2[data];
    double arr3[data];
    double arr4[data];
    while(getline(inputFile, line))
    { //creates a copy for each of the lists
      input = stod(line);
      arr1[i] = input;
      arr2[i] = input;
      arr3[i] = input;
      arr4[i] = input;
      i++;
    }
    bubbleSortSim(arr1, data);
    insertionSortSim(arr2, data);
    selectionSortSim(arr3, data);
    quickSortSim(arr4, data);


  }

}
