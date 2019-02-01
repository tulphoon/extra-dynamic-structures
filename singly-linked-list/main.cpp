typedef int T;

struct item {
    T value;
    item * pNext;
};

void addSortedIter(item * & pHead, const T & value) {
    if(!pHead) {
        pHead = new item { value, nullptr };
        return;
    }
    
    auto p = pHead;
    item * prevElem = nullptr;  
    while(p) {
        if(value <= p->value) {
            if(!prevElem)
                pHead = new item { value, p };
            else {
                p = new item { value, p };
                prevElem->pNext = p;
            }
            break;
        }
        if (p->pNext == nullptr) {
            p->pNext = new item { value, nullptr };
            break;
        }
        prevElem = p;
        p = p->pNext;
    }
}

int main(int argc, char const *argv[])
{
    item * list = nullptr;
    addSortedIter(list, 3); // inserting to empty list
    addSortedIter(list, 1); // inserting on beginning of list
    addSortedIter(list, 2); // inserting in between two elements
    addSortedIter(list, 4); // inserting on the end
    return 0;
}
