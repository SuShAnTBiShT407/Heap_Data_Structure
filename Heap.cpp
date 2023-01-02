
// ॐ सरस्वति नमस्तुभ्यं वरदे कामरूपिणि ।
// विद्यारम्भं करिष्यामि सिद्धिर्भवतु मे सदा ॐ॥


#include<bits/stdc++.h>
using namespace std;


class Heap{
	
	public:
		int arr[100];
		int size;

		Heap(){
			arr[0] =-1;
			size=0;
		}
		void insert(int val){  // O(logn)
			size = size+1; // increment the size with new insertion
			int index = size;
			arr[index] = val; // ith element at arr[ith] location

			while(index>1){
				int parent = index/2;
				if(arr[parent]<arr[index]){
					swap(arr[parent], arr[index]);
					index = parent;
				}else{
					return;
				}
			}
		}
		void print(){
			for(int i=1;i<=size;i++){
				cout<<arr[i]<<" ";
			}cout<<"\n";
		}
		void delete_val(){ // O(logn)
			if(size==0) {
				cout<<"Nothing to delete";
				return;
			}

			arr[1] = arr[size];
			size--; // not to access last node

			// take root node to its correct position
			int i=1;
			while(i<size){
				int leftindex = 2*i;
				int rightindex = 2*i +1;
				if(leftindex<size && arr[i]<leftindex){
					swap(arr[i], arr[leftindex]);
					i = leftindex;
				}else if(rightindex<size && arr[i]<rightindex){
					swap(arr[i], arr[rightindex]);
					i = rightindex;
				}else{
					return;
				}
			}
		}


};

void heapify(int arr[], int size, int i){ // O(logn)
	int largest = i;
	int leftindex = 2*i;
	int rightindex = 2*i + 1;

	if(leftindex<size && arr[leftindex]> arr[largest]){
		largest = leftindex;
	}
	if(rightindex<size && arr[largest]< arr[rightindex]){
		largest = rightindex;
	}

	if(largest!=i){
		swap(arr[largest], arr[i]);
		heapify(arr, size, largest);
	}
}

int main(){
	Heap h;
	h.insert(81);
	h.insert(89);
	h.insert(9);
	h.insert(11);
	h.insert(14);
	h.insert(76);
	h.insert(54);
	h.insert(22);
	cout<<"Heap array : ";
	h.print();
	h.delete_val();
	cout<<"After deletion : ";
	h.print();

	int arr[6] = {-1, 54, 53, 55, 52, 50};
	int n=5;
	for(int i=n/2;i>0;i--){
		heapify(arr, n, i);
	}
	cout<<"heapify : ";
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}



			//                             ----code by Sushant Bisht-----
