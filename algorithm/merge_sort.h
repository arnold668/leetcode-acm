#pragma once
#include<iostream>
using namespace std;
//-πÈ≤¢≈≈–Ú
void merge ( int *arr, int lo, int mid, int hi )
{
	int *tmp = (int *)malloc ( (hi - lo + 1) * sizeof ( int ) );
	int i = lo, j = mid + 1, k = 0;
	while ( i <= mid && j <= hi )
	{
		if ( arr[i] <= arr[j] ) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	while ( i <= mid ) tmp[k++] = arr[i++];
	while ( j <= hi )  tmp[k++] = arr[j++];
	memcpy ( arr + lo, tmp, k * sizeof ( int ) );
	free ( tmp );
}
void mergeSort ( int *arr, int lo, int hi )
{
	if ( lo == hi ) return;
	int mid = lo + hi >> 1;
	mergeSort ( arr, lo, mid );
	mergeSort ( arr, mid + 1, hi );
	merge ( arr, lo, mid, hi );
}