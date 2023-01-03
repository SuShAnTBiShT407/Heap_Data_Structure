
// ॐ सरस्वति नमस्तुभ्यं वरदे कामरूपिणि ।
// विद्यारम्भं करिष्यामि सिद्धिर्भवतु मे सदा ॐ॥


#include<bits/stdc++.h>
using namespace std;


int arr[100];
void insert_heap(int val, int size){
	size = size + 1;
	int index = size;
	arr[index] = val;

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

void kthSmallest(int n, int k){
	priority_queue<int> pq;

	for(int i=0;i<k;i++){
		pq.push(arr[i]);
	}
	for(int i=k;i<=n;i++){
		if(arr[i]<pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}
	int ans = pq.top();
	cout<<ans;

}

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int a[] = {7, 10, 4, 20, 15};
	int n = 5;
	for(int i=0;i<n;i++){
		insert_heap(a[i], i);
	}
	for(int i=1;i<=5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	cout<<"Kth Smallest : ";
	kthSmallest(4, 3);
	
	return 0;
}



			//                             ----code by Sushant Bisht-----
