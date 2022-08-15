#include <stdio.h>
#include <stdlib.h>
#include </hash.h>

/* binary search */
int binarysrch(int a[] ,int low, int high, int key){
	if(low > high) return -1;
	else{
	int mid = (low+high)/2;
	if(a[mid] = key)
		return mid;
	else if(a[mid]>key)
		return binarysrch(a,low,mid-1,key);
	else return binarysrch(a,mid+1,high,key);
	}
}
/* hash search */
Hash* hashCreate (int a[], int n, int len) {
	 int pos;
  	 Hash *hash = (Hash*)malloc(sizeof(Hash));
	 hash->table = (int**)malloc(sizeof(int*) * len);
	 memset(hash->table, 0, sizeof(int*) * len);
	 hash->len = len;
	 for (int i = 0; i < n; ++i) {
		 for (pos = a[i] % len; hash->table[pos] && pos < len; ++pos);
		 hash->table[pos] = (int*)malloc(sizeof(int));
		 *hash->table[pos] = a[i];
		 return hash;
	 }
}
