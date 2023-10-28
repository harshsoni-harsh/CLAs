#include <iostream>
#include <vector>

using namespace std;
class queue {
    protected:
        vector<int> a;
    public:
        int get(void) {
            int temp = a.front();
            if(a.size() == 1) {
                a.front() = 0;
            } 
            else a.erase(a.begin());
            return temp;
        }
        void put(int item) {
            if(a.size() == 1 && a.front() == 0) a.front() = item;
            else a.push_back(item);
        }
};
class checkbook : public queue {
    public:
        checkbook(int *arr, int len) {
            this->add_items(arr, len);
            cout << "Total: " << this->total() << endl;
        }
        void add_items(int *arr, int len) {
            for (int i=0; i<len ; i++)
                put(arr[i]);
        }
        int total(void) {
            int sum=0;
            for (int i : a) {
                sum+=i;
            }
            return sum;
        }
        void print_last_10_entries() {
            int i = a.size() >= 10 ? a.size() - 10 : 0;
            for (; i<a.size(); i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    int len;
    cout << "Enter number of integers: ";
    cin >> len;
    cout << "\nEnter integers: ";
    int* arr = new int(len);
    for (int i=0; i<len; i++) cin >> arr[i];
    checkbook* c = new checkbook(arr, len);
    cout << "Printing last 10 entries in checkbook " << endl;
    c->print_last_10_entries();
    return 0;
}