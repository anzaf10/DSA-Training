class minHeap {
  private:
    vector<int> heap;

  public:

    // Insert x into the heap
    void push(int x) {
        heap.push_back(x);

        int i = heap.size() - 1;

        // Heapify Up
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    // Remove the minimum element
    void pop() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        int n = heap.size();

        // Heapify Down
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    // Return the minimum element
    int peek() {
        if (heap.empty())
            return -1;

        return heap[0];
    }

    // Return the size of the heap
    int size() {
        return heap.size();
    }
};
