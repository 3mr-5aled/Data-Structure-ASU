class PQ_Heap
{
    int heap[100];
    int size;

    void heapifyUp(int i)
    {
        while (i > 0 && heap[(i - 1) / 2] < heap[i])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    PQ_Heap() { size = 0; }

    void insert(int val)
    {
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    int remove()
    {
        if (size == 0)
            return -1;

        int root = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return root;
    }
};