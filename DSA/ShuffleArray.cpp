// -------------------------------------------------------
// do from the beginning but then merge from the end
// ---------------------------------------------------------
void helper(int arr[], const int left, const int right, const int n, int & idx){
  // we have two halves; we assume that n is even,
  // we will start from the beginning of the halves and go forward
  // the recursion should be stopped when right idx achieves n
  if (right == n) {
     // we are remembered everything we needed, we 
     // can start going out of recursion
     return;
  }
	    
  // remember the pair we want to merge when we come back from the call
  int v1 = arr[left];   // first from the left half
  int v2 = arr[right];  // the value from the right half
	    
  helper(arr, left + 1, right + 1, n, idx);
	    
  // ok, we reached the end of recursion; now it is time to merge
  // but remember the last we remebered are the arr[n/2-1] and arr[n-1],
  // so we have to merge from the end of arr, and first goes v2, i.e.,
  // from the right half, and then v1, from the left half
  arr[idx--] = v2;
  arr[idx--] = v1;
}
	
void shuffleArray(int arr[], int n) {
   // we will start merging from the end of arr
   int idx = n - 1;
   // start from the beginning of each half (0 and n/2)
   helper(arr, 0, n/2, n, idx);
}