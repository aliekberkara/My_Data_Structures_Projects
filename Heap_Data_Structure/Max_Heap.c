#include <stdio.h>
#include <stdlib.h>

int heap[30];
int count = 0;

int GetParentIndex(int index){
	return index/2;
}

int GetLeftChildIndex(int index){
	return index*2;
}

int GetRightChildIndex(int index){
	return index*2 + 1;
}

void UpMaxHeap(int index){
	if(index <= 1){
		return;
	}
	int parent = GetParentIndex(index), temp;
	if(heap[index] > heap[parent]){
		temp = heap[index];
		heap[index] = heap[parent];
		heap[parent] = temp;
		UpMaxHeap(parent);
	}
}

void InsertElement(int element){
	count++;
	heap[count] = element;
	UpMaxHeap(count);
}

void View(){
	int i;
	printf("\n----------------------------\n");
	if(count == 0){
		printf("Heap is empty!");
		return;
	}
	for(i = 1; i <= count; i++){
		printf("%d ", heap[i]);
	}
}

void DownMaxHeap(int index){
	if(index*2 > count){
		return;
	}
	int left = GetLeftChildIndex(index);
	int right = GetRightChildIndex(index);

	int biggest = index;
	if(left <= count && heap[left] > heap[biggest]){
		biggest = left;
	}
	if(right <= count && heap[right] > heap[biggest]){
		biggest = right;
	}
	if(biggest == index){
		return;
	}
	int temp = heap[index];
	heap[index] = heap[biggest];
	heap[biggest] = temp;
	DownMaxHeap(biggest);
}

void DeleteElement(){
	if(count == 0){
		return;
	}
	heap[1] = heap[count];
	count--;
	DownMaxHeap(1);
}

int main()
{
	InsertElement(45);
	InsertElement(9);
	InsertElement(14);
	InsertElement(28);
	InsertElement(39);
	InsertElement(13);
	InsertElement(29);
	View();
	DeleteElement();
	View();
	DeleteElement();
	View();
	DeleteElement();
	View();
	DeleteElement();
	View();
	DeleteElement();
	View();
	DeleteElement();
	View();

    return 0;
}
