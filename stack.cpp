#include <memory>

template<typename T>
class stack {
    public:
        void push(T ToPush) {
            count_of_operations++; _size_stack++;

            std::unique_ptr<stackMember<T>> buffer = std::make_unique<stackMember<T>>();
            buffer->act = ToPush;
            if (FirstStackMember != nullptr) buffer->Last = std::move(FirstStackMember);
            FirstStackMember = std::move(buffer);
        }

        T pop() {
            count_of_operations++; 

            if (FirstStackMember == nullptr)return T();
            _size_stack--;

            T ToPop = FirstStackMember->act;
            FirstStackMember = std::move(FirstStackMember->Last);
            return ToPop;
        }

        int size() {
            return _size_stack;
        }

    private:
        long long count_of_operations = 0;
        unsigned int _size_stack = 0;

        template<typename T>
        class stackMember {
        public:
            T act;
            std::unique_ptr<stackMember> Last;
        };

        std::unique_ptr<stackMember<T>> FirstStackMember;
};
