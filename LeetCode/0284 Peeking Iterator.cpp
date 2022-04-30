class PeekingIterator : public Iterator {
public:
    int nextVal;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    nextVal = Iterator::hasNext() ? Iterator::next() : NULL;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextVal;
	}
	
	int next() {
        int next = nextVal;
        nextVal = Iterator::hasNext() ? Iterator::next() : NULL;
        return next;   
	}
	
	bool hasNext() const {
	    return (nextVal != NULL);
	}
};