
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    ListNode* position_;

  public:
    ListIterator() : position_(NULL) { }
    ListIterator(ListNode* x) : position_(x) { }

    // Pre-Increment, ++iter
    ListIterator& operator++() {
        // @TODO: graded in MP3.1
        if(position_ != nullptr){
            position_ = position_->next;
        }
        return *this;
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int) {
        // @TODO: graded in MP3.1
        // ListNode* temp = position_;
        // position_ = position_->next;
        // return ListIterator(NULL);
        List<T>::ListIterator r(*this);
        this->operator++();
        return r;

    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        // @TODO: graded in MP3.1
        position_ = position_->prev;
        return *this;
        // return position_;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int) {
        // @TODO: graded in MP3.1
        List<T>::ListIterator r(*this);
        this->operator--();
        return r;
        // return ListIterator();
    }

    bool operator!=(const ListIterator& rhs) {
        // @TODO: graded in MP3.1
        // return false;
        if (position_ == rhs.position_)
        {
            return 0;
        } else {
            return 1;
        }
        
    }

    bool operator==(const ListIterator& rhs) {
        return !(*this != rhs);
    }

    const T& operator*() {
        return position_->data;
    }

    const T* operator->() {
        return &(position_->data);
    }
};
