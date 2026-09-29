#include <iostream>
#include <cstddef>

// NOT FULL : 80/100 so sad bro

namespace CP {
    template <typename T>
    class vector {
    protected:
        T* mData; // pointer to data
        size_t mCap;
        size_t mSize;

        void expand(size_t capacity) {
            T* arr = new T[capacity]();

            for (size_t i = 0; i < mSize; ++i) {
                arr[i] = mData[i];
            }

            delete[] mData;
            mData = arr;
            mCap = capacity;
        }

        void ensureCapacity(size_t capacity) {
            if (capacity > mCap) {
                size_t newCap = 2 * mCap;
                if (capacity > newCap) {
                    newCap = capacity;
                }
                expand(newCap);
            }
        }

    public:
        vector() { // default constructor 
            mData = new T[1]();
            mCap = 1;
            mSize = 0;
        }

        ~vector() { // destructor
            delete[] mData;
        }

        size_t size() const {
            return mSize;
        }

        size_t capacity() const {
            return mCap;
        }

        void push_back(const T& value) { // enuseCapacity() to make sure that we allocate memory good enough
            ensureCapacity(mSize + 1);
            mData[mSize] = value;
            mSize++;
        }
    };
}

int main() {
    size_t n;
    std::cin >> n;

    CP::vector<int> dummy_vector;

    // add element to vector (as dummy vector)
    for (size_t i = 0; i < n; ++i) {
        dummy_vector.push_back(0);
    }

    // calculate wasted space 
    std::cout << dummy_vector.capacity() - dummy_vector.size()
              << '\n';
}